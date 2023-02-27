/*
Alex Nguyen
CS-210
02/05/2023
*/

#ifndef PROJECTTWO_SRC_BANKFUNCTIONS_H_
#define PROJECTTWO_SRC_BANKFUNCTIONS_H_


double getDouble(std::string t_prompt);									// Store user input as type double
double inputInvestment(std::string t_prompt);							// Store investment amount from user
double inputDeposit(std::string t_prompt);								// Store monthly deposit amount from user
double inputInterestRate(std::string t_prompt);							// Store interest rate from user
double inputNumberYears(std::string t_prompt);							// Store number of years from user
double grabDepositAmout();												// Prompt user for and return a deposit amount
void printHorizontalBorder(int t_length, char t_printChar);				// Display borders in output
void printInvestmentTerminal();											// Print an empty snapshot (i.e. program start)
void printInvestmentTerminal(Investment& t_investment);					// Outputs terminal displaying investment attributes
void printGrowth(Investment& t_investment, bool t_withMonthly = false);	// Display growth
void investmentSimulation(Investment& t_investment, 					// Display result and allow user to make adjustments
	std::shared_ptr<double> t_investmentAmount,
	std::shared_ptr<double> t_interestRate,
	std::shared_ptr<double> t_numberYears,
	std::shared_ptr<double> t_depositAmount);

#endif 