#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs3(const vector<int> &a, const vector<int> &b, const vector<int> &c)
{
	vector<vector<vector<int> > > D(a.size() + 1, vector<vector<int> >(b.size() + 1, vector<int>(c.size() + 1)));
	
	for (int k = 1; k <= c.size(); k++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			for (int i = 1; i <= a.size(); i++)
			{
				int takeSeq1 = D[i - 1][j][k];
				int takeSeq2 = D[i][j - 1][k];
				int takeSeq3 = D[i][j][k - 1];
				int takeAll = D[i - 1][j - 1][k - 1] + 1;

				if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1] && b[j - 1] == c[k - 1])
					D[i][j][k] = max(max(max(takeSeq1, takeSeq2), takeSeq3), takeAll);
				else
					D[i][j][k] = max(max(takeSeq1, takeSeq2), takeSeq3);
			}
		}
	}

	return D[a.size()][b.size()][c.size()];
}

int main() {
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) {
		std::cin >> a[i];
	}
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) {
		std::cin >> b[i];
	}
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; i++) {
		std::cin >> c[i];
	}
	std::cout << lcs3(a, b, c) << std::endl;
}
