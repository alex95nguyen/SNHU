/* Alex Nguyen
*  CS-210
*  01-22-2023
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int hr = 12; //12 hour - format clock 
int minute = 0; //minutes used for both 24 and 12 hr format clocks
int sec = 0; //seconds used for both 24 and 12 hr format clock
int hr24 = 0; // 24 hour format clock
int menuInput; //variable for menu selection input
bool exitChecker = true; //terminates program when user inputs 4
int i = 0; //changes to 1 if hr 24 >= 12



void printTime() {   //outputs time and display AM and PM for 12 hr format
	cout << "***************************  ***************************" << endl; 
	cout << "*       12-Hour Clock     *  *        24-Hour Clock    *" << endl;
	cout << "*       "; if (hr < 10) cout << "0"; cout << hr << ":"; if (minute < 10) cout << "0"; cout << minute << ":"; if (sec < 10) cout << "0"; cout << sec << " "; if (i == 0)cout << "AM"; else if (i == 1)cout << "PM"; cout << "       *  *        "; if (hr24 < 10) cout << "0"; cout << hr24 << ":"; if (minute < 10) cout << "0"; cout << minute << ":"; if (sec < 10) cout << "0"; cout << sec << "         *" << endl;
	cout << "***************************  ***************************" << endl;
}

void displayMenu() { //displays menu

	cout << "***************************\n";
	cout << "* 1 - Add One Hour        *\n";
	cout << "* 2 - Add One Minute      *\n";
	cout << "* 3 - Add One Second      *\n";
	cout << "* 4 - Exit Program        *\n";
	cout << "***************************\n";
}

void menuAction() {  //stores user input and display message based on input
	switch (menuInput) {
	case 1:
		hr24++;
		hr++;
		if (hr24 == 24) {
			hr24 = 0;
		}
		if (hr24 < 12) {
			i = 0;
		}
		if (hr == 13) {
			hr = 1;
		}
		if (hr24 >= 12) {
			i = 1;
		}
		break;
	case 2:
		minute++;
		if (minute == 60) {
			hr++;
			hr24++;
			minute = 0;
			if (hr24 < 12) {
				i = 0;
			}
			if (hr24 >= 12) {
				i = 1;
			}
			if (hr == 13) {
				hr = 1;
			}
			if (hr24 == 24) {
				hr24 = 0;
			}
		}
		break;
	case 3:
		sec++;
		if (sec == 60) {
			minute++;
			sec = 0;
			if (minute == 60) {
				hr++;
				hr24++;
				minute = 0;
				if (hr24 < 12) {
					i = 0;
				}
				if (hr == 13) {
					hr = 1;
				}
				if (hr24 >= 12) {
					i = 1;
				}
				if (hr24 == 24) {
					hr24 = 0;
				}
			}
		}
		break;
	case 4:
		cout << "Ending Clock Program" << endl;    //Outputs termination message
		exitChecker = false;
		break;
	default:
		cout << "Error. Please Enter a Valid Selection." << endl; 
	}

}
int main() {  

	while (exitChecker) {
		

		printTime();
		displayMenu();
		cin >> menuInput;
		menuAction();
	}
	return 0;
}