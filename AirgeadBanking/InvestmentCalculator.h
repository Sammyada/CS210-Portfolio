/*AirGead Banking
 Author: Sam'Myada Gamble
 Date: October 2, 2026*/
#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

/**
 * @class InvestmentCalculator
 * @brief Manages financial inputs and calculates annual compound interest reports.
 */
class InvestmentCalculator {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_years;

public:
    // Default Constructor
    InvestmentCalculator();

    // Setter methods for input data
    void setInitialInvestment(double t_initialInvestment);
    void setMonthlyDeposit(double t_monthlyDeposit);
    void setAnnualInterest(double t_annualInterest);
    void setYears(int t_years);

    // Getter methods for input data
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterest() const;
    int getYears() const;

    // Display and reporting methods
    void displayInputScreen() const;
    void printReportWithoutMonthlyDeposits() const;
    void printReportWithMonthlyDeposits() const;
};

#endif
