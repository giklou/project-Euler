#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
	vector<unsigned int> primes;
	primes.push_back(2);

	unsigned int n = 3;
	double sum = 2;

	while( n < 2000000 )
	{
		unsigned int squareRoot = sqrt(n);
		bool divisible = false;

		for(unsigned int i=0; i<primes.size(); i++)
		{
			if( primes[i] > squareRoot )
				break;

			if( n%primes[i] == 0)
			{
				divisible = true;
				break;
			}
		}

		if(!divisible)
		{
			primes.push_back(n);
			sum += n;
			cout << n << endl;
			cout << sum << endl;
		}

		n++;
	}

	cout << "sum = " << setprecision(20) << sum << endl;


	return 0;
}
