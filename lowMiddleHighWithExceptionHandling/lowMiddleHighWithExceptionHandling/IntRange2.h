#ifndef INTRANGE2_H
#define	INTRANGE2_H
	
#include <iostream>
using namespace std;



class IntRange2
{
private:
	int input;
	int lower;
	int upper;
public:
	class TooLow {};
	class TooHigh {};
	IntRange2(int low, int high)
	{
		lower = low;
		upper = high;
	}
	int getInput()
	{
		cin >> input;
		if (input < lower)
			throw TooLow();
		else if (input > upper)
			throw TooHigh();
		return input;
	}
};
#endif
