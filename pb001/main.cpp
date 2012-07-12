#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int sum = 0;
	int mul3=3;
	int mul5=5;

	while(mul3!=1002)
	{
		sum += mul3;

		if(mul5 <= mul3)
		{
			if(mul5!=mul3)
				sum += mul5;

			mul5 += 5;
		}
			
		mul3 += 3;
	}

	cout << "sum = " << sum << endl;

	return 0;
}
