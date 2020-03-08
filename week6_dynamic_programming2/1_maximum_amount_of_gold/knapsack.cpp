#include <iostream>
#include <vector>

using namespace std;

int optimal_weight_greedy_fail(int W, const vector<int>& w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) 
      current_weight += w[i];
  }
  return current_weight;
}

int optimal_weight(int W, const vector<int>& w)
{
	vector<int> values = w;

	vector<vector<int> > value(w.size() + 1, vector<int>(W + 1));
	for (int i = 0; i <= W; i++)
		value[0][i] = 0;
	for (int i = 0; i <= w.size(); i++)
		value[i][0] = 0;

	// i: only use items from 0 to ith
	// curW: to reach this weight
	for (int i = 1; i <= w.size(); i++)
	{
		for (int curW = 1; curW <= W; curW++)
		{
			value[i][curW] = value[i - 1][curW];
			if (w[i - 1] <= curW)
			{
				int val = value[i - 1][curW - w[i - 1]] + values[i - 1];
				if (value[i][curW] < val)
					value[i][curW] = val;
			}
		}
	}

	cout << endl;

	for (int i = 0; i < w.size() + 1; i++)
	{
		for (int j = 0; j < W + 1; j++)
		{
			cout << value[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	return value[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) 
    std::cin >> w[i];
  
  std::cout << optimal_weight(W, w) << '\n';
  return 0;
}
