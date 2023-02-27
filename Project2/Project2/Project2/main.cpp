/* 
Alex Nguyen
CS-210
02/05/2023
*/
#include <iostream>
#include <memory>	
#include "Investment.h"
#include "bankFunctions.h"

using namespace std;

int main() {

	

	// Open the program with menu
	printInvestmentTerminal();
	
	shared_ptr<double> investmentAmount(new double(inputInvestment("Enter initial investment amount: ")));       // Store user input for intial amounts 
	shared_ptr<double> interestRate(new double(inputInterestRate("Enter rate of interest: ")));
	shared_ptr<double> numberYears(new double(inputNumberYears("Enter investment duration (in years): ")));
	shared_ptr<double> depositAmount(new double(grabDepositAmout()));
	Investment myInvestment(*investmentAmount, *interestRate, *numberYears, *depositAmount);
	// Display the terminal with updated investment values
	printInvestmentTerminal(myInvestment);
	printGrowth(myInvestment, false);  // Outputs initial investment growth with and without deposits
	cout << endl;
	printGrowth(myInvestment, true);
	cout << endl << endl << endl;
	investmentSimulation(myInvestment, investmentAmount, interestRate, numberYears, depositAmount);  // Displays menu and allow user to loop through options until user terminates program
	cout << endl << "Goodbye.";
	return 0;
}