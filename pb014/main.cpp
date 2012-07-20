#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace std;

static const long int MAX_NUMBER = 1000000;

long int next(long int n)
{
	if(n%2 == 0)
		return n/2;
	else
		return 3*n + 1;
}

int main(int argc, char* argv[])
{
	vector<long int> chainSizes(MAX_NUMBER,-1);
	chainSizes[0]=1;

	for(long int n=2; n<=MAX_NUMBER; ++n)
	{
		long int temp = n;
		long int size = 0;

		while(temp >=n)
		{
			temp = next(temp);
			size++;
		}

		chainSizes[n-1] = size + chainSizes[temp-1];
	}

	cout << "The starting number " << distance(chainSizes.begin(), max_element(chainSizes.begin(), chainSizes.end()))+1 << " produces the longest chain." << endl;


	return 0;
}
