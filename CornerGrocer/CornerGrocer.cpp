#include "CornerGrocer.h"
#include <iostream>
#include <fstream>
#include <iomanip>

/*
 * Description: Constructor that initializes the object by loading data and creating the backup file.
 * Parameters: const std::string& inputFilename - name of the primary input text file.
 * Return: None
 */
CornerGrocer::CornerGrocer(const std::string& inputFilename) {
    loadData(inputFilename);
    backupData("frequency.dat");
}

/*
 * Description: Reads the input file line-by-line and tallies item frequencies using a map.
 * Parameters: const std::string& inputFilename - name of the text file to read.
 * Return: None
 */
void CornerGrocer::loadData(const std::string& inputFilename) {
    std::ifstream inFile(inputFilename);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file " << inputFilename << std::endl;
        return;
    }

    std::string item;
    while (inFile >> item) {
        itemCounts[item]++;
    }
    inFile.close();
}

/*
 * Description: Prompts the user for a specific item name and displays its exact purchase frequency.
 * Parameters: None
 * Return: None
 */
void CornerGrocer::searchItemFrequency() const {
    std::string item;
    std::cout << "Enter the item name you wish to look for: ";
    std::cin >> item;

    auto it = itemCounts.find(item);
    if (it != itemCounts.end()) {
        std::cout << "\n" << it->first << " was purchased " << it->second << " time(s).\n\n";
    }
    else {
        std::cout << "\nItem '" << item << "' not found in the records.\n\n";
    }
}

/*
 * Description: Prints a comprehensive list of all unique grocery items paired with their total frequencies.
 * Parameters: None
 * Return: None
 */
void CornerGrocer::printFrequencyList() const {
    std::cout << "\n--- Daily Item Purchase Frequencies ---\n";
    for (const auto& pair : itemCounts) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
    std::cout << "--------------------------------------\n\n";
}

/*
 * Description: Prints a text-based histogram displaying item names and rows of asterisks representing counts.
 * Parameters: None
 * Return: None
 */
void CornerGrocer::printHistogram() const {
    std::cout << "\n--- Purchase Frequency Histogram ---\n";
    for (const auto& pair : itemCounts) {
        std::cout << std::left << std::setw(15) << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    std::cout << "------------------------------------\n\n";
}

/*
 * Description: Creates a frequency.dat backup file containing every item paired with its total count.
 * Parameters: const std::string& outputFilename - name of the backup file to create.
 * Return: None
 */
void CornerGrocer::backupData(const std::string& outputFilename) const {
    std::ofstream outFile(outputFilename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create backup file " << outputFilename << std::endl;
        return;
    }

    for (const auto& pair : itemCounts) {
        outFile << pair.first << " " << pair.second << "\n";
    }
    outFile.close();
}

// ==========================================
// MAIN FUNCTION & MENU INTERFACE
// ==========================================

/*
 * Description: Displays the interactive menu options for the user.
 * Parameters: None
 * Return: None
 */
void displayMenu() {
    std::cout << "========== CORNER GROCER SYSTEM ==========\n";
    std::cout << "1. Look up item frequency\n";
    std::cout << "2. Print all item frequencies\n";
    std::cout << "3. Print histogram of frequencies\n";
    std::cout << "4. Exit program\n";
    std::cout << "Enter your choice (1-4): ";
}

/*
 * Description: Main entry point that handles program execution and user menu choices.
 * Parameters: None
 * Return: int - Exit status code
 */
int main() {
    CornerGrocer grocer("CS210_Project_Three_Input_File.txt");
    int choice = 0;

    do {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\nInvalid input. Please enter a number between 1 and 4.\n\n";
            continue;
        }

        switch (choice) {
        case 1:
            grocer.searchItemFrequency();
            break;
        case 2:
            grocer.printFrequencyList();
            break;
        case 3:
            grocer.printHistogram();
            break;
        case 4:
            std::cout << "\nExiting program. Goodbye!\n";
            break;
        default:
            std::cout << "\nInvalid choice. Please select an option from 1 to 4.\n\n";
        }
    } while (choice != 4);

    return 0;
}
