#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Similar to change_dp (dynamic programming)
int get_optimal_value_knapsack_with_reps(int capacity, vector<int> weights, vector<int> values)
{
	vector<int> value(capacity + 1);
	value[0] = 0;
	for (int w = 1; w <= capacity; w++)
	{
		value[w] = 0;
		for (int i = 0; i < weights.size(); i++)
		{
			if (weights[i] <= w)
			{
				int val = value[w - weights[i]] + values[i];
				if (val > value[w])
					value[w] = val;
			}
		}
	}
	return value[capacity];
}

vector<int> reconstructASolutionForKnapsackWithoutReps(int capacity, vector<int> weights, vector<int> values, const vector<vector<int> > value)
{
	int i = weights.size(), w = capacity;
	vector<int> solution(weights.size() + 1);

	while (i > 0)
	{
		if (w - weights[i - 1] >= 0 && value[i][w] == value[i - 1][w - weights[i - 1]] + values[i - 1])
		{
			solution[i] = 1;	// item ith is used
			w = w - weights[i - 1];
		}
		else
			solution[i] = 0;

		i = i - 1;
	}

	return solution;
}

int get_optimal_value_knapsack_without_reps(int capacity, vector<int> weights, vector<int> values)
{
	vector<vector<int> > value(weights.size() + 1, vector<int>(capacity + 1));
	for (int i = 0; i <= capacity; i++)
		value[0][i] = 0;
	for (int i = 0; i <= weights.size(); i++)
		value[i][0] = 0;
	
	for (int i = 1; i <= weights.size(); i++)
	{
		for (int w = 1; w <= capacity; w++)
		{
			value[i][w] = value[i - 1][w];	// value if doesn't take the ith item
			if (weights[i - 1] <= w)
			{
				int val = value[i - 1][w - weights[i - 1]] + values[i - 1];	// value if take the ith item
				if (value[i][w] < val)	// value[i][w] equal to maximum of (value if doesn't take the ith item, value if take the ith item)
					value[i][w] = val;
			}
		}
	}

	// Print value 2D array
	/*
	cout << endl;
	for (int i = 0; i <= weights.size(); i++)
	{
		for (int w = 0; w <= capacity; w++)
		{
			cout << value[i][w] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/

	// Reconstruct a solution
	vector<int> solution = reconstructASolutionForKnapsackWithoutReps(capacity, weights, values, value);
	std::cout << "Solution: ";
	for (int i = 1; i < solution.size(); i++)
		std::cout << solution[i] << " ";
	std::cout << endl;

	return value[weights.size()][capacity];
}

int main()
{
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++)
		std::cin >> values[i] >> weights[i];

	//int optimal_value = get_optimal_value_knapsack_with_reps(capacity, weights, values);
	int optimal_value = get_optimal_value_knapsack_without_reps(capacity, weights, values);
	std::cout << optimal_value << std::endl;
	return 0;
}

/* SAMPLE INPUT -> EXPECTED OUTPUT FOR KNAPSACK W REPS: 48, EXPECTED OUTPUT FOR KNAPSACK W/O REPS: 46
4 10
30 6
14 3
16 4
9 2
*/