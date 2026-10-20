/*AirGead Banking
 Author: Sam'Myada Gamble
 Date: October 2, 2026*/
#include "InvestmentCalculator.h"
#include <iostream>
#include <limits>

// Helper function to prompt and validate positive double input
double getValidDouble(const std::string& t_prompt) {
    double value;
    while (true) {
        std::cout << t_prompt;
        if (std::cin >> value && value >= 0.0) {
            return value;
        }
        std::cout << "Invalid input. Please enter a non-negative number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Helper function to prompt and validate positive integer input
int getValidInt(const std::string& t_prompt) {
    int value;
    while (true) {
        std::cout << t_prompt;
        if (std::cin >> value && value > 0) {
            return value;
        }
        std::cout << "Invalid input. Please enter a positive integer greater than 0." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    char userChoice = 'y';

    while (userChoice == 'y' || userChoice == 'Y') {
        InvestmentCalculator calc;

        std::cout << "**********************************" << std::endl;
        std::cout << "////////// Data Input //////////" << std::endl;
        std::cout << "**********************************" << std::endl;

        calc.setInitialInvestment(getValidDouble("Initial Investment Amount: $"));
        calc.setMonthlyDeposit(getValidDouble("Monthly Deposit: $"));
        calc.setAnnualInterest(getValidDouble("Annual Interest (%): "));
        calc.setYears(getValidInt("Number of years: "));

        std::cout << "\nPress Enter to view balance reports...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();

        calc.displayInputScreen();
        calc.printReportWithoutMonthlyDeposits();
        calc.printReportWithMonthlyDeposits();

        std::cout << "\nWould you like to calculate another investment scenario? (y/n): ";
        std::cin >> userChoice;
        std::cout << std::endl;
    }

    std::cout << "Thank you for using the Airgead Banking Investment Calculator!" << std::endl;
    return 0;
}
