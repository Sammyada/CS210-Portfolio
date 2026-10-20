#ifndef CORNERGROCER_H
#define CORNERGROCER_H

#include <string>
#include <map>

class CornerGrocer {
private:
    std::map<std::string, int> itemCounts;

    /*
     * Description: Reads the input file and tallies item frequencies using a map.
     * Parameters: const std::string& inputFilename - name of the text file to read.
     * Return: None
     */
    void loadData(const std::string& inputFilename);

public:
    /*
     * Description: Constructor that initializes the object by loading data and creating the backup.
     * Parameters: const std::string& inputFilename - name of the primary input text file.
     * Return: None
     */
    CornerGrocer(const std::string& inputFilename);

    /*
     * Description: Prompts the user for a specific item and displays its purchase frequency.
     * Parameters: None
     * Return: None
     */
    void searchItemFrequency() const;

    /*
     * Description: Prints a comprehensive list of all unique items and their frequencies.
     * Parameters: None
     * Return: None
     */
    void printFrequencyList() const;

    /*
     * Description: Prints a text-based histogram using asterisks matching each item's frequency.
     * Parameters: None
     * Return: None
     */
    void printHistogram() const;

    /*
     * Description: Automatically creates a frequency.dat backup file containing all item counts.
     * Parameters: const std::string& outputFilename - name of the backup file to create.
     * Return: None
     */
    void backupData(const std::string& outputFilename) const;
};

#endif