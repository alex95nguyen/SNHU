/*
Alex Nguyen
CS-210
02/05/2023
*/

#include <iostream>
#include <memory>
#include "Investment.h"


Investment::Investment() {          // Constructors 
	this->m_investmentAmount = 0;
	this->m_monthlyDeposit = 0;
	this->m_interestRate = 0;
	this->m_numberYears = 1;
}


Investment::Investment(double t_investmentAmount, double t_interestRate, double t_numberYears, double t_monthlyDeposit ) {    // default value is 0
	this->m_investmentAmount = t_investmentAmount;
	this->m_monthlyDeposit = t_monthlyDeposit;
	this->m_interestRate = t_interestRate;
	this->m_numberYears = t_numberYears;
}


double Investment::getInvestmentAmount() const {                    // Getters
	return this->m_investmentAmount;
}

double Investment::getMonthlyDeposit() const {
	return this->m_monthlyDeposit;
}

double Investment::getInterestRate() const {
	return this->m_interestRate;
}

double Investment::getNumberYears() const {
	return this->m_numberYears;
}


void Investment::setInvestmentAmount(double t_investmentAmount) {          //Setters
	this->m_investmentAmount = t_investmentAmount;
}

void Investment::setMonthlyDeposit(double t_monthlyDeposit) {
	this->m_monthlyDeposit = t_monthlyDeposit;
}

void Investment::setInterestRate(double t_interestRate) {
	this->m_interestRate = t_interestRate;
}

void Investment::setNumberYears(double t_numberYears) {
	this->m_numberYears = t_numberYears;
}