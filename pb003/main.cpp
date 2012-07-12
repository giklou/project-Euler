#include <iostream>
#include <math.h>
#include <algorithm>


using namespace std;

bool millerRabinTest(long double p)
{
	if(p==2 || p==3)
		return true;

	if( fmod(p,2) == 0 )
		return false;

	int s=0;
	long double d=p-1;
	while( fmod(d,2) == 0 )
	{
		s++;
		d = d/2;
	}

	cout << "s= " << s << endl;	

	int a = 2;

	for(int i=0; i<2; i++)
	{

		long double x = pow(a,d);
	cout << x << endl;	
		x = fmod(x, p);
	cout << "aie "<< x << endl;	
		if( x==1 || x==p-1 )
		{
			if(a==3)
				return true;
			
			a = 3;
			continue;
		}
	
		int r;	
		for(r=0; r<s; r++)
		{		
			x = x*x;
			x = fmod(x, p);

	cout << x << endl;	
			if( x==p-1 )
			{
				if(a==3)
					return true;

				r=s+1;
			}
			
		}
		if(r==s)
			return false;

		a = 3;
	}

	return false;
}

int main(int argc, char* argv[])
{
	long double n = 600851475143;
	int divisor = sqrt(n);

	cout << millerRabinTest(643) << endl;

	return 0;
}
