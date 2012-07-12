#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
	vector<unsigned int> primes;
	primes.push_back(2);

	unsigned int n = 3;

	while( primes.size() <= 10001 )
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
			cout << n << endl;
		}

		n++;
	}

	cout << "10001th prime = " << primes[10000] << endl;


	return 0;
}
