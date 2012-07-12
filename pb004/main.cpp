#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int n)
{
	int quotient = 100000;
	vector<int> nDigits;
	bool firstZero = true;

	while( quotient!=0 )
	{
		int digit = n/quotient;
		if( !(firstZero && digit==0) )
		{
			firstZero = false;
			nDigits.push_back(digit);
		}
		
		n = n-digit*quotient;
		quotient = quotient/10;
	}

	int ind = 0;
	bool res = true;
	while( ind < (nDigits.size()-1) )
	{
		res = res && (nDigits[ind] == nDigits[nDigits.size()-ind-1]);
		ind++;
	}

	return res;
}

int main(int argc, char* argv[])
{
	int a = 999;
	int b = 999;
	int bmin = 99;
	int n;
	int maxPalindrome = 0;

	while( a>bmin )
	{
		b=a;
		while( b>bmin )
		{
			n = a*b;

			if(isPalindrome(n) && n>maxPalindrome)
			{
				maxPalindrome = n;
				bmin = b;
				break;
			}

			b--;
		}

		a--;
	}

	cout << "Max palindrome = " << maxPalindrome << endl;


	return 0;
}
