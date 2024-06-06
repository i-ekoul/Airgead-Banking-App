/* Mod5 Assignment: Airgead Banking App
CS210 @ SNHU
Date: 06.06.2024
Author: Emmalie Cole*/

#include <iostream>
#include "Investment.h"

int main() {
    std::cout << "Welcome to Airgead Banking Investment Calculator\n";

    // Variables to hold user input
    double initial_investment, monthly_deposit, annual_interest;
    int years;
    char user_choice;

    do {
        // Prompt the user for the initial investment amount
        std::cout << "Enter Initial Investment Amount: $";
        std::cin >> initial_investment;

        // Prompt the user for the monthly deposit amount
        std::cout << "Enter Monthly Deposit: $";
        std::cin >> monthly_deposit;

        // Prompt the user for the annual interest rate
        std::cout << "Enter Annual Interest Rate (in %): ";
        std::cin >> annual_interest;

        // Prompt the user for the number of years
        std::cout << "Enter Number of Years: ";
        std::cin >> years;

        // Create an Investment object with the user input
        Investment investment(initial_investment, monthly_deposit, annual_interest, years);

        // Calculate the year-end balances without monthly deposits
        investment.calculate_year_end_balance();

        // Calculate the year-end balances with monthly deposits
        investment.calculate_year_end_balance_with_deposits();

        // Display the reports to the user
        investment.display_report();

        // Ask the user if they want to test another scenario
        std::cout << "Do you want to test another scenario? (yes/no): ";
        std::cin >> user_choice;
    } while (user_choice == 'yes' || user_choice == 'y' || user_choice == 'Y');

    std::cout << "Thank you for using Airgead Banking Investment Calculator\n";
    return 0;
}
