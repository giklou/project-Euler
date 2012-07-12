#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	for(unsigned int a=1; a<1000; a++)
	{
		unsigned int temp = a*a + 500000 - 1000*a;
		if( temp%(1000-a) == 0 )
		{
			unsigned int c = temp/(1000-a);
			unsigned int b = 1000 - a - c;
			cout << "a*b*c = " << a*b*c << endl;
			return 0;
		}


	}

	return 0;
}
