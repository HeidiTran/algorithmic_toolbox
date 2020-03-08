#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs2(const vector<int> &a, const vector<int> &b)
{
	vector<vector<int> > D(a.size() + 1, vector<int>(b.size() + 1));
	for (int i = 0; i <= a.size(); i++)
		D[i][0] = 0;
	for (int j = 0; j <= b.size(); j++)
		D[0][j] = 0;

	for (int j = 1; j <= b.size(); j++)
	{
		for (int i = 1; i <= a.size(); i++)
		{
			int takeSeq1 = D[i - 1][j];
			int takeSeq2 = D[i][j - 1];
			int takeBoth = D[i - 1][j - 1] + 1;

			if (a[i - 1] == b[j - 1])	// str1 starts from 1 in the matrix (go to TheAlignmentGame.pdf for more details)
				D[i][j] = max(max(takeSeq1, takeSeq2), takeBoth);
			else
				D[i][j] = max(takeSeq1, takeSeq2);
		}
	}

	/*
	cout << endl;
	for (int i = 0; i <= a.size(); i++)
	{
		for (int j = 0; j <= b.size(); j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	*/

	return D[a.size()][b.size()];
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::cout << lcs2(a, b) << std::endl;
	return 0;
}
