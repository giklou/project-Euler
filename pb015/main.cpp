#include <iostream>
#include <vector>

using namespace std;

static const long int GRID_SIZE = 20;

vector<long int> nextSize(vector<long int> nbPaths)
{
	int size = nbPaths.size();
	vector<long int> res(size+1,0);
	
	res[0] =  nbPaths[0];
	for(int i=1; i<size; ++i)
	{
		res[i] = res[i-1] + nbPaths[i];
	}
	res[size] = 2*res[size-1];

	return res;
}

int main(int argc, char* argv[])
{
	vector<long int> nbPaths(2,1);
	nbPaths[1] = 2;

	for(int gridSize=2; gridSize<=GRID_SIZE; ++gridSize)
	{
		nbPaths = nextSize(nbPaths);
	}

for(int i=0; i<nbPaths.size(); ++i)
{
cout << nbPaths[i] << endl;
}

	cout << "Starting in the top left corner of a " << GRID_SIZE << "x" << GRID_SIZE << " grid, there are " << nbPaths.back() << " routes (without backtracking) to the bottom right corner." << endl;


	return 0;
}
