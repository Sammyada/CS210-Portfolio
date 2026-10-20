/*AirGead Banking
 Author: Sam'Myada Gamble
 Date: October 2, 2026*/
#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor initializes all financial variables to zero
InvestmentCalculator::InvestmentCalculator() {
    m_initialInvestment = 0.0;
    m_monthlyDeposit = 0.0;
    m_annualInterest = 0.0;
    m_years = 0;
}

// Setters
void InvestmentCalculator::setInitialInvestment(double t_initialInvestment) {
    m_initialInvestment = t_initialInvestment;
}

void InvestmentCalculator::setMonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentCalculator::setAnnualInterest(double t_annualInterest) {
    m_annualInterest = t_annualInterest;
}

void InvestmentCalculator::setYears(int t_years) {
    m_years = t_years;
}

// Getters
double InvestmentCalculator::getInitialInvestment() const {
    return m_initialInvestment;
}

double InvestmentCalculator::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

double InvestmentCalculator::getAnnualInterest() const {
    return m_annualInterest;
}

int InvestmentCalculator::getYears() const {
    return m_years;
}

// Displays the user input summary screen
void InvestmentCalculator::displayInputScreen() const {
    cout << "=================================\n";
    cout << "========== Data Input ===========\n";
    cout << "Initial Investment Amount: $" << m_initialInvestment << endl;
    cout << "Monthly Deposit: $" << m_monthlyDeposit << endl;
    cout << "Annual Interest: %" << m_annualInterest << endl;
    cout << "Number of years: " << m_years << endl;
}

// Calculates and prints year-end balances without any monthly deposits added
void InvestmentCalculator::printReportWithoutMonthlyDeposits() const {
    double totalAmount = m_initialInvestment;
    double monthlyInterestRate = (m_annualInterest / 100.0) / 12.0;

    cout << "\n  Balance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year        Year End Balance        Year End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    // Loop through each year
    for (int i = 1; i <= m_years; ++i) {
        double interestEarned = 0.0;
        // Compound interest calculated monthly
        for (int j = 1; j <= 12; ++j) {
            double monthlyInterest = totalAmount * monthlyInterestRate;
            interestEarned += monthlyInterest;
            totalAmount += monthlyInterest;
        }

        cout << right << setw(4) << i
            << setw(20) << fixed << setprecision(2) << totalAmount
            << setw(24) << interestEarned << endl;
    }
}

// Calculates and prints year-end balances including monthly deposits
void InvestmentCalculator::printReportWithMonthlyDeposits() const {
    double totalAmount = m_initialInvestment;
    double monthlyInterestRate = (m_annualInterest / 100.0) / 12.0;

    cout << "\n  Balance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year        Year End Balance        Year End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    // Loop through each year
    for (int i = 1; i <= m_years; ++i) {
        double interestEarned = 0.0;
        // Add monthly deposit and compound interest monthly
        for (int j = 1; j <= 12; ++j) {
            totalAmount += m_monthlyDeposit;
            double monthlyInterest = totalAmount * monthlyInterestRate;
            interestEarned += monthlyInterest;
            totalAmount += monthlyInterest;
        }

        cout << right << setw(4) << i
            << setw(20) << fixed << setprecision(2) << totalAmount
            << setw(24) << interestEarned << endl;
    }
}
