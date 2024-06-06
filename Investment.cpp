#include "Investment.h"
#include <iostream>
#include <iomanip>

// Constructor implementation to initialize the Investment object with user input
Investment::Investment(double t_initial_investment, double t_monthly_deposit, double t_annual_interest, int t_years)
    : m_initial_investment(t_initial_investment), m_monthly_deposit(t_monthly_deposit),
    m_annual_interest(t_annual_interest), m_years(t_years) {}

// Method to calculate year-end balances without monthly deposits
void Investment::calculate_year_end_balance() {
    double opening_amount = m_initial_investment;  // Start with the initial investment
    double total, interest;
    for (int year = 1; year <= m_years; ++year) {
        total = opening_amount;  // Total starts as the opening amount
        interest = total * (m_annual_interest / 100);  // Calculate interest for the year
        total += interest;  // Add interest to the total
        m_balance_without_deposits.push_back(total);  // Save the total for the year
        opening_amount = total;  // Set the opening amount for the next year
    }
}

// Method to calculate year-end balances with monthly deposits
void Investment::calculate_year_end_balance_with_deposits() {
    double opening_amount = m_initial_investment;  // Start with the initial investment
    double total, interest;
    for (int year = 1; year <= m_years; ++year) {
        for (int month = 1; month <= 12; ++month) {
            total = opening_amount + m_monthly_deposit;  // Add the monthly deposit
            interest = total * ((m_annual_interest / 100) / 12);  // Calculate monthly interest
            total += interest;  // Add interest to the total
            opening_amount = total;  // Update the opening amount for the next month
        }
        m_balance_with_deposits.push_back(opening_amount);  // Save the total for the year
    }
}

// Method to display the investment reports
void Investment::display_report() const {
    std::cout << "Year-End Balances and Interest without Monthly Deposits:\n";
    for (int year = 1; year <= m_years; ++year) {
        std::cout << "Year " << year << ": $" << std::fixed << std::setprecision(2) << m_balance_without_deposits[year - 1] << "\n";
    }

    std::cout << "\nYear-End Balances and Interest with Monthly Deposits:\n";
    for (int year = 1; year <= m_years; ++year) {
        std::cout << "Year " << year << ": $" << std::fixed << std::setprecision(2) << m_balance_with_deposits[year - 1] << "\n";
    }
}
