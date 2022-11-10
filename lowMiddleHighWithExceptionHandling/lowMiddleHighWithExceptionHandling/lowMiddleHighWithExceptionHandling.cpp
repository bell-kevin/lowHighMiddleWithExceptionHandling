// lowMiddleHighWithExceptionHandling.cpp

#include <iostream>
using namespace std;

class IntRange2 {
private:
	int input;
	int lower;
	int upper;
public:
	//exception classes
	class TooLow {};
	class TooHigh {};
	//member functions

	IntRange2() {
		lower = 0;
		upper = -1;
	}
	int getInput(int high, int low)
	{
		cin >> input;
		if (input <= 0) {
			throw TooLow();
		}
		else if (input <= lower) {
			throw TooHigh();
		}
		else {
			return input;
		}
	} 
};

int main() {
			
	cout << "Chapter 16 Low High Mid. by Kevin Bell\n\n";
	
	IntRange2 range;
	
	int lowValue = 0, highValue = 0, middleValue = 0, userValue=0, input=0;

	// enter an integer for the low number
	//do while loop to check for valid input
	do {
		cout << "Enter an integer for the low number: ";
		try {
			lowValue = range.getInput(lowValue, highValue);
		}
		catch (IntRange2::TooLow) {
			cout << "The value is too low. Try again." << endl;
		}
	} while (lowValue <= 0);

	// enter an integer for the high number
	//do while loop to check for valid input
	do {
		cout << "Enter an integer for the high number: ";
		try {
			highValue = range.getInput(highValue, input);
		}
		catch (IntRange2::TooLow) {
			cout << "The value you entered is too low. Try again." << endl;
		}
		catch (IntRange2::TooHigh) {
			cout << "The value you entered is too high. Try again." << endl;
		}
	} while (highValue >= lowValue);
	
	// enter an integer between the low and high numbers
	//do while loop to check for valid input
	do {
		cout << "Enter an integer between " << lowValue << " and " << highValue << ": ";
		try {
			userValue = range.getInput(userValue, input);
		}
		catch (IntRange2::TooLow) {
			cout << "The value you entered is too low. Try again." << endl;
		}
		catch (IntRange2::TooHigh) {
			cout << "The value you entered is too high. Try again." << endl;
		}
	} while (userValue <= lowValue || userValue >= highValue);
	
	cout << "Low number is " << lowValue << " and high number is " << highValue << endl;
	cout << "Middle number is " << userValue << endl;
	
	system("pause");
	return 0;
} // end of main
