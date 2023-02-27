/*
Alex Nguyen
CS-210
02/05/2023
*/

#include <iostream>             
#include <stdexcept>            
#include <string>				
#include <stdlib.h>
#include <iomanip>				
#include <memory>
#include "Investment.h"


using namespace std;


double getDouble(string t_prompt) {  // Stores and return user number input
	bool validEntry;			// adds exception handling
	string userEntryAsString;	// store user input to convert to double
	double userEntry;			// store user input as double to return

	
	do {
		validEntry = true;		// Starts branch if condition is met
		try {
			cout << t_prompt << endl;
			cin >> userEntryAsString;
			userEntry = stod(userEntryAsString);
		}
		catch (invalid_argument& excpt) {                                              // Catch if user input is string 
			cout << "Invalid entry type, please enter a number." << endl << endl;
			validEntry = false;
		}
	} while (!validEntry);
	return userEntry;
}

double inputInvestment(string t_prompt) {
	bool validEntry;			// adds exception handling
	double investmentAmount;	// store and return the investment amount

	do {
		validEntry = true;		// Starts branch if condition is met
		try {
			investmentAmount = getDouble(t_prompt);
			if (investmentAmount <= 0) {
				throw runtime_error("Invalid entry. Please enter an amount greater than $0.");
			}
		}
		catch (runtime_error& excpt) {                    // Catch if user input value is 0 or less
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while (!validEntry);

	return investmentAmount;
}

double inputDeposit(string t_prompt) {
	bool validEntry;			// adds exception handling
	double depositAmount;		// store and return the deposit amount

	do {
		validEntry = true;		// Starts branch if condition is met
		try {
			depositAmount = getDouble(t_prompt);
			if (depositAmount <= 0) {
				throw runtime_error("Invalid entry. Please enter an amount greater than $0.");
			}
		}
		catch (runtime_error& excpt) {                   // Catch if user input value is 0 or less
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while (!validEntry);

	return depositAmount;
}

double inputInterestRate(string t_prompt) {
	bool validEntry;			// adds exception handling
	double interestRate;		// store and return the interest rate

	do {
		validEntry = true;		// Starts branch if condition is met
		try {
			interestRate = getDouble(t_prompt);
			if (interestRate < 0) {
				throw runtime_error("Invalid entry. Please enter a non-negative interest rate.");
			}
		}
		catch (runtime_error& excpt) {                     // Catch if user input value is less than 0
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while (!validEntry);

	return interestRate;
}


double inputNumberYears(string t_prompt) {
	bool validEntry;			// adds exception handling
	double numberYears;			// store and return the number of years

	
	do {
		validEntry = true;		// Starts branch if condition is met
		try {
			numberYears = getDouble(t_prompt);
			if (numberYears < 1) {
				throw runtime_error("Invalid entry. Please enter 1 year or more.");
			}
		}

		catch (runtime_error& excpt) {             // Catch if user input value is less than 1
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while (!validEntry);

	return numberYears;
}

double grabDepositAmout() {         // Allows user to input value for despots
	bool validEntry;				// adds exception handling
	double depositAmount;			// store and return the number of years
	char userEntry;

	
	do {
		validEntry = true;		// Starts branch if condition is met
		try {
			cout << "Would you like to add a monthly deposit (Y/N)? ";
			cin >> userEntry;
			if ((userEntry != 'N') && (userEntry != 'n') && (userEntry != 'Y') && (userEntry != 'y')) {
				throw runtime_error("Invalid entry. Please enter Y or N.");
			}
		}
	
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl << endl;       // Catch invalid user input
			validEntry = false;
		}

	} while (!validEntry);

	if ((userEntry == 'Y') || (userEntry == 'y')) {
		depositAmount = inputDeposit("Please enter your deposit amount.");
	}
	else {
		depositAmount = 0;
	}
	return depositAmount;
}


void printHorizontalBorder(int t_length, char t_printChar) {
	for (int i = 0; i < t_length; ++i) {
		cout << t_printChar;
	}
	return;
}


void printInvestmentTerminal() {         // Output display menu
	const int MENU_WIDTH = 35;			// Column width of the menu
	string menuTitle = "Data Input";	// Menu title
	char menuChar = '*';
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2) - 1), menuChar);
	cout << " " << menuTitle << " ";
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2)), menuChar);
	cout << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
	system("pause");		// Waits for user input to continue
	return;
}

void printInvestmentTerminal(Investment& t_investment) {
	const int MENU_WIDTH = 35;			// Column width of the menu
	string menuTitle = "Data Input";	// Menu title
	char menuChar = '*';
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2) - 1), menuChar);
	cout << " " << menuTitle << " ";
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2)), menuChar);
	cout << endl;
	cout << "Initial Investment Amount: $" << t_investment.getInvestmentAmount() << endl;
	cout << "Monthly Deposit: $" << t_investment.getMonthlyDeposit() << endl;
	cout << "Annual Interest: " << t_investment.getInterestRate() << "%" << endl;
	cout << "Number of Years: " << t_investment.getNumberYears() << endl;
	system("pause");
	return;
}


void printGrowth(Investment& t_investment, bool t_withMonthly) {  // Default value is false
	const int MENU_WIDTH = 75;
	const double MONTHS_IN_YEAR = 12.00;
	string menuTitleNoDeposit = "Balance and Interest - No Additional Deposits";
	string menuTitleWithDeposits = "Balance and Interest - With Monthly Deposits";
	string menuTitle;
	if (t_withMonthly) {
		menuTitle = menuTitleWithDeposits;
	}
	else {
		menuTitle = menuTitleNoDeposit;
	}
	int menuTitleWhiteSpace = MENU_WIDTH - menuTitle.length();	// Adds whitespace to title
	string headerOne = "Year";
	string headerTwo = "Interest Earned";
	string headerThree = "Year End Balance";
	char menuChar = '=';
	char outputChar = ' ';
	// Print title top border
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((menuTitleWhiteSpace / 2), outputChar);
	cout << menuTitle;   // Outputs menu title
	printHorizontalBorder((menuTitleWhiteSpace / 2), outputChar);
	cout << endl;
	printHorizontalBorder(MENU_WIDTH, menuChar); // Outputs title bottom border
	cout << endl;
	cout << "\t" << headerOne;
	cout << "\t\t" << headerTwo;
	cout << "\t\t" << headerThree;
	cout << endl;
	
	double begBalance = t_investment.getInvestmentAmount();   // Set investment amount
	
	for (int i = 0; i < t_investment.getNumberYears(); ++i) {
		int year = (i + 1);		// Add 1 to i for  year output display
		double interestRate = t_investment.getInterestRate() / 100.00;
		double interestEarned;
		double totalInterest;
		double endBalance;
		double monthEndBalance;
		if (t_withMonthly) {		// Includes monthly deposits in growth output
			interestEarned = 0;
			totalInterest = 0;
			interestRate = interestRate / MONTHS_IN_YEAR;
			for (int i = 0; i < MONTHS_IN_YEAR; ++i) {
				begBalance += t_investment.getMonthlyDeposit();
				interestEarned = (begBalance * (1 + interestRate)) - begBalance;
				monthEndBalance = begBalance + interestEarned;
				begBalance = monthEndBalance;
				totalInterest += interestEarned;
			}
		}
		else {					// Do not include monthly deposits
			totalInterest = (begBalance * (1 + interestRate)) - begBalance;
		}
		if (t_withMonthly) {
			endBalance = begBalance;
		}
		else {
			endBalance = begBalance + totalInterest;
			begBalance = endBalance;	// Sets beginning balance equal to ending balance 
		}
		
		cout << "\t" << year;
		cout << "\t\t" << "$" << setprecision(2) << fixed << totalInterest;
		cout << "\t\t\t" << "$" << setprecision(2) << fixed << endBalance;
		cout << endl;
	}
	return;			
}


void printOptions() {       // Display option menu
	string optionsMenu = "What would you like to do?\n"
		"1 - Change Initial Investment Amount\n"
		"2 - Change Monthly Deposit Amount\n"
		"3 - Change Interest Rate\n"
		"4 - Change Investment Duration (years)\n"
		"5 - Print Investment Growth - No Deposit\n"
		"6 - Print Investment Growth - With Deposits\n"
		"7 - Quit.";
	const int MENU_WIDTH = 50;
	const char MENU_CHAR = '*';
	printHorizontalBorder(MENU_WIDTH, MENU_CHAR);
	cout << endl;
	cout << optionsMenu;
	cout << endl;
	printHorizontalBorder(MENU_WIDTH, MENU_CHAR);
	cout << endl;
	return;
}


void investmentSimulation(Investment& t_investment, std::shared_ptr<double> t_investmentAmount,
	std::shared_ptr<double> t_interestRate, std::shared_ptr<double> t_numberYears,
	std::shared_ptr<double> t_depositAmount) {

	bool validEntry;			// adds drive exception handling
	string userEntryAsString;	// store user input to convert to double
	int userEntry = 0;			// store user input as int to drive case statement and intialize to 0
	

	while (userEntry != 7) {  //loops until user enter command 7 to terminate
		
		do {
			validEntry = true;		// Starts branch if condition is met
			try {
				printOptions();
				cin >> userEntryAsString;
				userEntry = stoi(userEntryAsString);	
				if ((userEntry < 1) || (userEntry > 7)) {
					throw runtime_error("Invalid entry. Please enter a number between 1 and 7");
				}
			}
			catch (invalid_argument& excpt) {     // Catch if user input is a string
				cout << "Invalid entry type, please enter a number." << endl << endl;
				validEntry = false;
			}
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl << endl;
				validEntry = false;
			}
		} while (!validEntry);
		cout << endl;
	

		switch (userEntry) {
		case 1:	// Change the investment amount
			printInvestmentTerminal(t_investment); // Print current Terminal
			*t_investmentAmount = inputInvestment("Enter new investment amount: ");
			t_investment.setInvestmentAmount(*t_investmentAmount);
			printInvestmentTerminal(t_investment);
			break;		// if a case is executed, break out of the switch statement so other cases aren't executed
		case 2:	// Change the deposit amount
			printInvestmentTerminal(t_investment);
			*t_depositAmount = inputDeposit("Enter new deposit amount: ");
			t_investment.setMonthlyDeposit(*t_depositAmount);
			printInvestmentTerminal(t_investment);
			break;
		case 3:	// Change the interest rate
			printInvestmentTerminal(t_investment);
			*t_interestRate = inputInterestRate("Enter new interest rate: ");
			t_investment.setInterestRate(*t_interestRate);
			printInvestmentTerminal(t_investment);
			break;
		case 4:	// Change the investment duration
			
			printInvestmentTerminal(t_investment);
			*t_numberYears = inputNumberYears("Enter new duration: ");
			t_investment.setNumberYears(*t_numberYears);
			printInvestmentTerminal(t_investment);
			break;
		case 5:
			printGrowth(t_investment, false);
			cout << endl << endl;
			break;
		case 6:
			printGrowth(t_investment, true);
			cout << endl << endl;
			break;
		default:		// If no other cases are executed, program will quit
			break;
		}
	}
	return;
}