#include <iostream>
#include <math.h>

#define MAXIT 45

using namespace std;

/*int nbAdjPairs(unsigned long n)
{
	int res = 0;

	bool previousOne = false;
	while( n != 0 )
	{
		unsigned long lastBit = n&1;
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

unsigned long nbAdjPairs(unsigned long n)
{
	unsigned long res = 0L;
	unsigned long m = n;
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
	fib[0] = 1L;
	fib[1] = 1L;
	for(int i=2; i<=MAXIT; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}


	unsigned long occurences[MAXIT];
	for(int j=0; j<MAXIT-1; j++)
	{
		occurences[j] = 0L;
	}

	unsigned long res = 0L;
	unsigned long n = 0L;
	unsigned long sumB = 0L;
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
				if(sumB == fib[j+2])
				{
					occurences[j]++;
					break;
				}
			}


			n++;
		}

		res += n;
		cout << "iteration " << i << endl;
	}

	cout << "sum = " << res << endl;

	return 0;
}
