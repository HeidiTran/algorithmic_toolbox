#include <iostream>
#include <vector>

using namespace std;

int get_change(int money) {
	int coins[3] = { 1, 3, 4 };
	vector<int> minNumCoins(money + 1);	// Index from 0 to money
	minNumCoins[0] = 0;
	for (int m = 1; m <= money; m++) {
		minNumCoins[m] = 0;
		for (int i = 0; i < 3; i++)
			if (m >= coins[i])
			{
				int numCoins = minNumCoins[m - coins[i]] + 1;
				if (numCoins < minNumCoins[m])
					minNumCoins[m] = numCoins;
			}
	}
	return minNumCoins[money];
}

int getChangeForDiffCoinArr(int money, const vector<int>& coins)
{
	vector<int> minNumCoins(money + 1);	// Index from 0 to money
	minNumCoins[0] = 0;
	for (int m = 1; m <= money; m++)
		for (int i = 0; i < coins.size(); i++)
			if (m >= coins[i])
			{
				int numCoins = minNumCoins[m - coins[i]] + 1;
				if (minNumCoins[m] == 0)
					minNumCoins[m] = numCoins;
				if (numCoins < minNumCoins[m])
					minNumCoins[m] = numCoins;
			}
	return minNumCoins[money];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

/*
int main() {
	int m, n;
	std::cin >> m >> n;
	vector<int> coinArray(n);
	for (int i = 0; i < n; i++)
		cin >> coinArray[i];
	
	std::cout << getChangeForDiffCoinArr(m, coinArray) << '\n';
}
*/
