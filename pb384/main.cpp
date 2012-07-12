#include <iostream>
#include <iomanip>
#include <math.h>

#define MAXIT 45

using namespace std;

/*unsigned long nbAdjPairs(double n)
{
	unsigned long res = 0L;

	bool previousOne = false;
	while( n != 0 )
	{
		unsigned long lastBit = n&1L;
		if( lastBit == 0)
			previousOne = false;
		else
		{
			if( previousOne )
				res++;
			previousOne = true;
		}

		n = n>>1;
	}

	return res;
}*/

unsigned long nbAdjPairs(double n)
{
	unsigned long res = 0L;
	double m = n;
	while( m!=0 )
	{
		unsigned int s=0;
		while( fmod(m,2) == 0 )
		{
			s++;
			m = m/2;
		}

		if( fmod(m,4) == 1 )
		{
			m = (m-1)/4;
		}
		else
		{
			res++;
			m = (m-1)/2;
		}
	}

	return res;
}


int main(int argc, char* argv[])
{
	/* Fibonacci */
	unsigned long fib[MAXIT+1];
	fib[0] = 1;
	fib[1] = 1;
	for(int i=2; i<=MAXIT; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}


	unsigned long occurences[MAXIT];
	for(int j=0; j<MAXIT-1; j++)
	{
		occurences[j] = 0;
	}

	double res = 0;
	double n = 0;
	double sumB = 0;
	for(int i=2; i<=MAXIT; i++)
	{
		while( occurences[i-2] < fib[i-1] )
		{
			unsigned long a = nbAdjPairs(n);
			if( fmod(a,2) == 0)
				sumB += 1;
			else
				sumB -= 1;

			for(int j=0; j<MAXIT-1; j++)
			{
				if(sumB == static_cast<double>(fib[j+2]) )
				{
					occurences[j]++;
					break;
				}
			}

			n++;
		}

		res += n;
		cout << setprecision(20) << "n: " << n << endl;
		cout << "iteration " << i << endl;
	}

	cout << setprecision(20) << "sum = " << res << endl;

	return 0;
}
