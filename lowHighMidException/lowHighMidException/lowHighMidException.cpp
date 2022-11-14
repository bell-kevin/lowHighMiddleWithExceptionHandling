// lowHighMidException.cpp

#include <iostream>
using namespace std;

class HighLowMid
{
private:
	int high=0;
	int low=0;
	int mid = 0;
	
public:
	//exception classes
	class TooLow {};
	class TooHigh {};
	
	//three member functions
	HighLowMid() {
		low = 0;
		high = -1;
	}
	bool getLow() {
		int temp = 0;
		cin >> temp;
		if (temp <= 0) {
			throw TooLow();
		}
		else {
			low = temp;
			return true;
		} 
	}
	
	bool getHigh() {
		int temp = 0;
		cin >> temp;
		if (temp <= low) {
			throw TooLow();
		}
		else {
			high = temp;
			return true;
		}

	}
	
	bool getMid() {
		int temp = 0;
		cin >> temp;
		if (temp <= low) {
			throw TooLow();
		} else if (temp >= high) {
			throw TooHigh();
		}
		else {
			mid = temp;
			return true;
		}
	}
	// return the mid value
	int getMidValue() {
		return mid;
	}
	
	// return the high value
	int getHighValue() {
		return high;
	}
	
	// return the low value
	int getLowValue() {
		return low;
	}
	
};

int main() {
	
		HighLowMid hlm;
		bool lowValid=false, highValid=false, midValid = false;
		

		cout << "Chapter 16 Low High Mid. by Kevin Bell\n\n";

		do {
			cout << "Enter an integer for the low number: ";
			try {
				lowValid = hlm.getLow();
			}
			catch (HighLowMid::TooLow) {
				cout << "The value is too low.\n";
			}
		} while (!lowValid);

		do {
			cout << "Enter an integer for the high number: ";
			try {
				highValid = hlm.getHigh();
			}
			catch (HighLowMid::TooLow) {
				cout << "The value is too high.\n";
			}
		} while (!highValid);

		do {
			cout << "Enter an integer between " << hlm.getLowValue() << " and " << hlm.getHighValue() << ": ";
			try {
				midValid = hlm.getMid();
			}
			catch (HighLowMid::TooLow) {
				cout << "The value is too low.\n";
			}
			catch (HighLowMid::TooHigh) {
				cout << "The value is too high.\n";
			}
		} while (!midValid);
		
		cout << endl;
		cout << "Low number is " << hlm.getLowValue() << " and high number is " << hlm.getHighValue() << endl;
		cout << "Middle number is " << hlm.getMidValue() << endl;
		system("pause");
		return 0;
} // end main
