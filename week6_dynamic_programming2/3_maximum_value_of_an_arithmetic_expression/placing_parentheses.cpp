#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long eval(long long a, long long b, char op) {
	if (op == '*') 
		return a * b;
	else if (op == '+') 
		return a + b;
	else if (op == '-') 
		return a - b;
	else
		assert(0);
}

void updateMinAndMax(int i, int j, vector<vector<long long> >& m, vector<vector<long long> >& M, const vector<char>& ops)
{
	long long Min = 50, Max = -50;
	long long a, b, c, d;
	for (int k = i; k <= j - 1; k++)
	{
		long long a = eval(M[i][k], M[k + 1][j], ops[k]);
		long long b = eval(M[i][k], m[k + 1][j], ops[k]);
		long long c = eval(m[i][k], M[k + 1][j], ops[k]);
		long long d = eval(m[i][k], m[k + 1][j], ops[k]);

		Min = min(Min, (min(min(a, b), min(c, d))));
		Max = max(Max, (max(max(a, b), max(c, d))));
	}

	m[i][j] = Min;
	M[i][j] = Max;
}

long long get_maximum_value(const string &exp) 
{
	vector<int> digits;
	vector<char> ops;
	for (int i = 0; i < exp.size(); i++)
	{
		if (i % 2 == 0)
			digits.push_back(exp[i] - '0');	// Convert char '5' to int 5
		else
			ops.push_back(exp[i]);
	}

	int n = digits.size();
	vector<vector<long long> > m(n, vector<long long>(n));
	vector<vector<long long> > M(n, vector<long long>(n));

	for (int i = 0; i < n; i++)
		m[i][i] = M[i][i] = digits[i];
	
	for (int s = 1; s < n; s++)
		for (int i = 0; i < n - s; i++)
		{
			int j = i + s;
			updateMinAndMax(i, j, m, M, ops);
		}

	return M[0][n - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}

// SAMPLE INPUT: 5-8+7*4-8+9 -> OUTPUT: 200