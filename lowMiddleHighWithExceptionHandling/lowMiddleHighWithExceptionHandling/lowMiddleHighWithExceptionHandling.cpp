// lowMiddleHighWithExceptionHandling.cpp

#include <iostream>
#include "IntRange2.h"
using namespace std;

int main()
{
	cout << "Chapter 16 Low High Middle by Kevin Bell \n\n";

	IntRange2 range(5, 10);
	int userValue;

	cout << "Enter a value between " << range.getLow() << " and " << range.getHigh() << ": ";

	try
	{
		userValue = range.getInput();
		cout << "You entered " << userValue << endl;
	}
	catch (IntRange2::TooLow)
	{
		cout << "That value is too low.\n";
	}
	catch (IntRange2::TooHigh)
	{
		cout << "That value is too high.\n";
	}

	cout << "End of program.\n";
	return 0;
}