#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ==========================================
// Part 1 & 2: MoodEntry Class Definition
// ==========================================
class MoodEntry {
private:
    string date;
    int rating;
    string note;

public:
    // Default constructor
    MoodEntry() {
        date = "";
        rating = 1;
        note = "";
    }

    // Parameterized constructor
    MoodEntry(string d, int r, string n) {
        date = d;
        // Basic safety validation matching assignment constraints
        if (r >= 1 && r <= 5) {
            rating = r;
        } else {
            rating = 1;
        }
        note = n;
    }

    // Getters
    string getDate() const { return date; }
    int getRating() const { return rating; }
    string getNote() const { return note; }

    // Setters with validation logic
    void setDate(string d) { date = d; }
   
    void setRating(int r) {
        if (r >= 1 && r <= 5) {
            rating = r;
        } else {
            cout << "Invalid rating! Keeping current rating.\n";
        }
    }
   
    void setNote(string n) { note = n; }

    // Translates integer rating into its matching descriptive text label
    string getMoodLabel() const {
        if (rating == 1) return "Very Bad";
        if (rating == 2) return "Bad";
        if (rating == 3) return "Okay";
        if (rating == 4) return "Good";
        if (rating == 5) return "Great";
        return "Unknown";
    }

    // Displays individual mood logs cleanly formatted
    void printEntry() const {
        cout << "Date: " << date << "\n";
        cout << "Mood Rating: " << rating << "\n";
        cout << "Mood: " << getMoodLabel() << "\n";
        cout << "Note: " << note << "\n";
    }
};

// ==========================================
// Part 3 & 4: MoodTracker Class Definition
// ==========================================
class MoodTracker {
private:
    MoodEntry entries[20];
    int entryCount;

public:
    // Constructor initializes accurate tracker boundary values
    MoodTracker() {
        entryCount = 0;
    }

    // Adds a newly instantiated object block to array structures
    void addEntry(const MoodEntry& entry) {
        if (entryCount < 20) {
            entries[entryCount] = entry;
            entryCount++;
        } else {
            cout << "Tracker is full! Cannot add more entries.\n";
        }
    }

    // Loops over structural collection elements sequentially
    void displayEntries() const {
        if (entryCount == 0) {
            cout << "No entries recorded yet.\n";
            return;
        }
        for (int i = 0; i < entryCount; i++) {
            entries[i].printEntry();
            cout << "\n"; // Clean visual separation matching prompt expectations
        }
    }

    // Computes double floating average metric out to a single decimal precision point
    double calculateAverage() const {
        if (entryCount == 0) return 0.0;
       
        double sum = 0;
        for (int i = 0; i < entryCount; i++) {
            sum += entries[i].getRating();
        }
        return sum / entryCount;
    }

    // Iteratively evaluates arrays searching for maximum score item positions
    MoodEntry getHighestMood() const {
        // Fallback default placeholder if empty
        if (entryCount == 0) return MoodEntry();
       
        int highestIndex = 0;
        for (int i = 1; i < entryCount; i++) {
            if (entries[i].getRating() > entries[highestIndex].getRating()) {
                highestIndex = i;
            }
        }
        return entries[highestIndex];
    }

    // Iteratively evaluates arrays searching for minimum score item positions
    MoodEntry getLowestMood() const {
        // Fallback default placeholder if empty
        if (entryCount == 0) return MoodEntry();
       
        int lowestIndex = 0;
        for (int i = 1; i < entryCount; i++) {
            if (entries[i].getRating() < entries[lowestIndex].getRating()) {
                lowestIndex = i;
            }
        }
        return entries[lowestIndex];
    }

    // Returns structural collection scale values
    int getEntryCount() const {
        return entryCount;
    }
};

// ==========================================
// Part 5 & 6: Main Operational Control Block
// ==========================================
int main() {
    MoodTracker tracker;
    int choice = 0;

    // Setting single decimal notation profile for math metrics
    cout << fixed << setprecision(1);

    while (choice != 6) {
        // Precise structural reproduction of the expected prompt menu panel layout
        cout << "===============================\n";
        cout << "           MOODMATE            \n";
        cout << "===============================\n";
        cout << "1. Add Mood Entry\n";
        cout << "2. View All Entries\n";
        cout << "3. View Average Mood\n";
        cout << "4. View Highest Mood\n";
        cout << "5. View Lowest Mood\n";
        cout << "6. Exit\n";
        cout << "===============================\n";
        cout << "Enter choice: ";
        cin >> choice;
        cout << "\n";

        if (choice == 1) {
            string dateInput, noteInput;
            int ratingInput;

            cout << "Enter date: ";
            cin >> dateInput;
           
            cout << "Enter mood rating (1-5): ";
            cin >> ratingInput;
           
            // Validating inputs match specifications
            while (ratingInput < 1 || ratingInput > 5) {
                cout << "The mood rating must be between 1 and 5.\n";
                cout << "Enter mood rating (1-5): ";
                cin >> ratingInput;
            }

            // Clearing buffer sequences safely to ingest full-string text lines
            cin.ignore();
            cout << "Enter note: ";
            getline(cin, noteInput);

            // Construct and inject the record explicitly via standard constructor workflows
            MoodEntry newEntry(dateInput, ratingInput, noteInput);
            tracker.addEntry(newEntry);
            cout << "\nMood entry added!\n\n";

        } else if (choice == 2) {
            tracker.displayEntries();

        } else if (choice == 3) {
            if (tracker.getEntryCount() == 0) {
                cout << "Average Mood: 0.0\n\n";
            } else {
                cout << "Average Mood: " << tracker.calculateAverage() << "\n\n";
            }

        } else if (choice == 4) {
            if (tracker.getEntryCount() == 0) {
                cout << "No entries found.\n\n";
            } else {
                cout << "----- Highest Mood -----\n";
                tracker.getHighestMood().printEntry();
                cout << "\n";
            }

        } else if (choice == 5) {
            if (tracker.getEntryCount() == 0) {
                cout << "No entries found.\n\n";
            } else {
                cout << "----- Lowest Mood -----\n";
                tracker.getLowestMood().printEntry();
                cout << "\n";
            }

        } else if (choice == 6) {
            cout << "Thank you for using MoodMate!\n";
        } else {
            cout << "Invalid selection. Please input a choice between 1 and 6.\n\n";
        }
    }

    return 0;
}
