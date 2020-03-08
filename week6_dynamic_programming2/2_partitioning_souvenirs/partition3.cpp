#include <iostream>
#include <vector>

using namespace std;

vector<int> reconstructASolution(int sum, const vector<int> &A, const vector<vector<vector<int> > >& partition)
{
	int i = A.size(), j = sum, k = sum;
	vector<int> solution(i + 1);

	while (j != 0 || k != 0)
	{
		if (j > 0 && j - A[i - 1] >= 0 && partition[i - 1][j - A[i - 1]][k] == 1)
		{
			solution[i] = 1;	// Bag 1 take the ith item
			j = j - A[i - 1];
		}
		else if (k > 0 && k - A[i - 1] >= 0 && partition[i - 1][j][k - A[i - 1]] == 1)
		{
			solution[i] = 2;	// Bag 2 take the ith item
			k = k - A[i - 1];
		}
		else 
			solution[i] = 0;	// Neither bag take the ith item

		i = i - 1;
	}

	return solution;
}

int partition3(const vector<int> &A)
{
	int sumSet = 0;
	for (int i = 0; i < A.size(); i++)
		sumSet += A[i];

	if (sumSet % 3 != 0)
		return 0;

	int sumOfSubset = sumSet / 3;
	vector<vector<vector<int> > > partition(A.size() + 1, vector<vector<int> >(sumOfSubset + 1, vector<int>(sumOfSubset + 1)));
	
	partition[0][0][0] = 1;
	for (int i = 1; i <= A.size(); i++)
	{
		partition[i][0][0] = 1;		// Using to any ith item, it's always possible to partition into 2 group with equal sum 0 
		partition[i][A[i - 1]][0] = 1;	// Using to any ith item, it's always possible to partition into 2 group, one with sum = value of ith item and one with sum = 0
		partition[i][0][A[i - 1]] = 1;
	}

	for (int i = 1; i <= A.size(); i++)
	{
		for (int j = 1; j <= sumOfSubset; j++)
		{
			for (int k = 1; k <= sumOfSubset; k++)
			{
				if ((j - A[i - 1] >= 0 && partition[i - 1][j - A[i - 1]][k] == 1 )||
					(k - A[i - 1] >= 0 && partition[i - 1][j][k - A[i - 1]] == 1) ||
					partition[i - 1][j][k] == 1)
				{
					partition[i][j][k] = 1;
				}
			}
		}
	}
	
	// Print partition 3D array
	/*
	for (int i = 0; i <= A.size(); i++)
		for (int j = 0; j <= sumOfSubset; j++)
			for (int k = 0; k <= sumOfSubset; k++)
				cout << "partition[" << i << "][" << j << "][" << k << "] = " << partition[i][j][k] << endl;
	*/

	// Reconstruct a solution
	/*
	if (partition[A.size()][sumOfSubset][sumOfSubset] == 1)
	{
		vector<int> solution = reconstructASolution(sumOfSubset, A, partition);
		cout << "Solution: ";
		for (int i = 1; i < solution.size(); i++)
			cout << solution[i] << " ";
		cout << endl;
	}
	*/

	return partition[A.size()][sumOfSubset][sumOfSubset];
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
