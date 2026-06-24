#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>
using namespace std;

// The InventoryTracker class stores and reports item frequencies for Corner Grocer.
class InventoryTracker {
public:
    InventoryTracker(const string& inputFileName, const string& backupFileName);
    int GetItemFrequency(const string& itemName) const;
    void PrintAllFrequencies() const;
    void PrintHistogram() const;
    void RunMenu();

private:
    map<string, int> itemFrequency;
    string sourceFile;
    string backupFile;

    void LoadInputFile();
    void CreateBackupFile() const;
    void PrintMenu() const;
    int GetMenuChoice() const;
};

// Constructor loads the input data and creates the required backup file.
InventoryTracker::InventoryTracker(const string& inputFileName, const string& backupFileName) {
    sourceFile = inputFileName;
    backupFile = backupFileName;
    LoadInputFile();
    CreateBackupFile();
}

// Reads each grocery item from the input file and counts how many times it appears.
void InventoryTracker::LoadInputFile() {
    ifstream inFile(sourceFile);
    string itemName;

    if (!inFile.is_open()) {
        cout << "Error: Could not open " << sourceFile << endl;
        return;
    }

    while (inFile >> itemName) {
        itemFrequency[itemName]++;
    }

    inFile.close();
}

// Writes the accumulated frequency data to frequency.dat for backup purposes.
void InventoryTracker::CreateBackupFile() const {
    ofstream outFile(backupFile);

    if (!outFile.is_open()) {
        cout << "Error: Could not create " << backupFile << endl;
        return;
    }

    for (const auto& item : itemFrequency) {
        outFile << item.first << " " << item.second << endl;
    }

    outFile.close();
}

// Returns the number of times a requested item appears in the data.
int InventoryTracker::GetItemFrequency(const string& itemName) const {
    auto item = itemFrequency.find(itemName);

    if (item != itemFrequency.end()) {
        return item->second;
    }

    return 0;
}

// Prints each item with its numeric frequency.
void InventoryTracker::PrintAllFrequencies() const {
    for (const auto& item : itemFrequency) {
        cout << item.first << " " << item.second << endl;
    }
}

// Prints each item with a text-based histogram using asterisks.
void InventoryTracker::PrintHistogram() const {
    for (const auto& item : itemFrequency) {
        cout << item.first << " ";

        for (int i = 0; i < item.second; ++i) {
            cout << "*";
        }

        cout << endl;
    }
}

// Displays the menu choices to the user.
void InventoryTracker::PrintMenu() const {
    cout << endl;
    cout << "Corner Grocer Item Tracker" << endl;
    cout << "1. Search for an item" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display item histogram" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Gets and validates a menu choice from the user.
int InventoryTracker::GetMenuChoice() const {
    int choice;

    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid choice. Please enter a number from 1 to 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return choice;
}

// Runs the menu until the user chooses to exit.
void InventoryTracker::RunMenu() {
    int choice = 0;
    string itemName;

    while (choice != 4) {
        PrintMenu();
        choice = GetMenuChoice();

        if (choice == 1) {
            cout << "Enter item to search for: ";
            cin >> itemName;
            cout << itemName << " appears " << GetItemFrequency(itemName) << " time(s)." << endl;
        }
        else if (choice == 2) {
            cout << endl << "Item Frequencies" << endl;
            PrintAllFrequencies();
        }
        else if (choice == 3) {
            cout << endl << "Item Histogram" << endl;
            PrintHistogram();
        }
        else if (choice == 4) {
            cout << "Exiting program." << endl;
        }
    }
}

int main() {
    InventoryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");
    tracker.RunMenu();

    return 0;
}
