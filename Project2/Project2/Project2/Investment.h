/*
Alex Nguyen
CS-210
02/05/2023
*/

#ifndef PROJECTTWO_SRC_INVESTMENT_H_
#define PROJECTTWO_SRC_INVESTMENT_H_


class Investment {
	                                                              
public:                                                          //Public members set to double
	
	Investment();                                                //Constructor
	Investment(double t_investmentAmount, double t_interestRate, double t_numberYears, double t_monthlyDeposit = 0);

	
	 
	double getInvestmentAmount() const;                          //Getters
	double getMonthlyDeposit() const;
	double getInterestRate() const;
	double getNumberYears() const;

	
	void setInvestmentAmount(double t_investmentAmount);        //Setters
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setInterestRate(double t_interestRate);
	void setNumberYears(double t_numberYears);

	
private:                                                      //Private members set to double
	 
	double m_investmentAmount;
	double m_monthlyDeposit;
	double m_interestRate;
	double m_numberYears;
};

#endif 