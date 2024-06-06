#ifndef AIRGEAD_BANKING_INVESTMENT_H
#define AIRGEAD_BANKING_INVESTMENT_H

#include <vector>

// Define the Investment class to handle investment calculations
class Investment {
private:
    // These are the attributes to store the investment details
    double m_initial_investment;      // Initial amount of investment
    double m_monthly_deposit;         // Amount deposited every month
    double m_annual_interest;         // Annual interest rate in percentage
    int m_years;                      // Number of years for the investment
    std::vector<double> m_balance_without_deposits; // Year-end balances without monthly deposits
    std::vector<double> m_balance_with_deposits;    // Year-end balances with monthly deposits

public:
    // Constructor to initialize the Investment object with user input
    Investment(double t_initial_investment, double t_monthly_deposit, double t_annual_interest, int t_years);

    // Method to calculate year-end balances without monthly deposits
    void calculate_year_end_balance();

    // Method to calculate year-end balances with monthly deposits
    void calculate_year_end_balance_with_deposits();

    // Method to display the investment reports
    void display_report() const;
};

#endif // AIRGEAD_BANKING_INVESTMENT_H