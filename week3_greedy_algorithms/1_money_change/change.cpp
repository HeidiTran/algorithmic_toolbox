#include <iostream>
#include <cmath>

using namespace std;

// Runtime O(n)
int getChangeFast(int m) 
{
	int numCoins = 0;
	while (m > 0)
	{
		if (m >= 10)
			m = m - 10;
		else if (m >= 5)
			m = m - 5;
		else
			m = m - 1;
		numCoins++;
	}

	return 0;
}

int getChangeSuperFast(int m)
{
	return floor(m / 10) + floor((m % 10) / 5) + (m % 5);
}

int main() 
{
  int m;
  std::cin >> m;
  //std::cout << getChangeFast(m) << endl;
  cout << getChangeSuperFast(m) << endl;
}
