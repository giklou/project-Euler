#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

static const unsigned int RANGE = 4;


unsigned int max4D(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
	return std::max(a1, std::max(a2, std::max(a3,a4)));
}


unsigned int computeRight(boost::numeric::ublas::matrix<unsigned int>& m, unsigned int i, unsigned int j)
{
	using namespace boost::numeric::ublas;

	//if(i >= m.size1() || j > m.size2()-RANGE)
	//	return 0;
	//else
	//{
		unsigned int rangeMax = std::min(RANGE, static_cast<unsigned int>(m.size2()-j));
		unsigned int res = 1;
		for(unsigned int k=0; k<rangeMax; ++k)
		{
			res *= m(i,j+k);
		}
		return res;
	//}
}

unsigned int computeDown(boost::numeric::ublas::matrix<unsigned int>& m, unsigned int i, unsigned int j)
{
	using namespace boost::numeric::ublas;

	//if(i > m.size1()-RANGE || j >= m.size2())
	//	return 0;
	//else
	//{
		unsigned int rangeMax = std::min(RANGE, static_cast<unsigned int>(m.size1()-i));
		unsigned int res = 1;
		for(unsigned int k=0; k<rangeMax; ++k)
		{
			res *= m(i+k,j);
		}
		return res;
	//}
}

unsigned int computeDiag1(boost::numeric::ublas::matrix<unsigned int>& m, unsigned int i, unsigned int j)
{
	using namespace boost::numeric::ublas;

	//if(i > m.size1()-RANGE || j > m.size2()-RANGE)
	//	return 0;
	//else
	//{
		unsigned int rangeMax = std::min(RANGE, static_cast<unsigned int>(m.size1()-i));
		rangeMax = std::min(rangeMax, static_cast<unsigned int>(m.size2()-j));
		unsigned int res = 1;
		for(unsigned int k=0; k<rangeMax; ++k)
			{
			res *= m(i+k,j+k);
		}
		return res;
	//}
}

unsigned int computeDiag2(boost::numeric::ublas::matrix<unsigned int>& m, unsigned int i, unsigned int j)
{
	using namespace boost::numeric::ublas;

	//if(i > m.size1()-RANGE || j > m.size2()-RANGE)
	//	return 0;
	//else
	//{
		unsigned int rangeMax = std::min(RANGE, static_cast<unsigned int>(m.size1()-i));
		rangeMax = std::min(rangeMax, j+1);
		unsigned int res = 1;
		for(unsigned int k=0; k<rangeMax; ++k)
			{
			res *= m(i+k,j-k);
		}
		return res;
	//}
}

int main(int argc, char* argv[])
{
	if( argc < 2)
	{
		std::cerr << "Usage:  " << argv[0] << " input.txt" << std::endl;
	}

	using namespace boost::numeric::ublas;
    matrix<unsigned int> m (20, 20);

	std::ifstream input(argv[1]);
	if(input.is_open())
	{
		for (unsigned int i = 0; i < m.size1 (); ++i)
			for (unsigned int j = 0; j < m.size2 (); ++j)
			{
				input >> m(i,j);
			}

    	input.close();
  	}
	else
		std::cout << "Unable to open " << argv[1] << std::endl; 

	unsigned res = 0;

	for (unsigned int i = 0; i < m.size1 (); ++i)
		for (unsigned int j = 0; j < m.size2 (); ++j)
		{
			unsigned int temp = max4D(computeRight(m, i, j), computeDown(m, i, j), computeDiag1(m, i, j), computeDiag2(m, i, j));
			if(temp > res)
				res = temp;
		}

	std::cout << "res = " << res << std::endl;

	return 0;
}
