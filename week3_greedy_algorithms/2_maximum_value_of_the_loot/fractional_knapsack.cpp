#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getObjNum(const vector<double>& vpw, double value)
{
	for (int i = 0; i < vpw.size(); i++)
		if (vpw[i] == value)
			return i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) 
{
	double value = 0.0;

	vector<double> valuePerWeight;
	for (int i = 0; i < weights.size(); i++)
		valuePerWeight.push_back((double)values[i] / weights[i]);

	vector<double> sortedValuePerWeight = valuePerWeight;
	sort(sortedValuePerWeight.rbegin(), sortedValuePerWeight.rend());
  
	for (int i = 0; i < weights.size(); i++)
	{
		if (capacity == 0)
			return value;
		else
		{
			int objectNum = getObjNum(valuePerWeight, sortedValuePerWeight[i]);
			int a = min(weights[objectNum], capacity);
			value += a * valuePerWeight[objectNum];
			capacity -= a;
		}
	}

	return value;
}

double get_optimal_value_fast(int capacity, vector<int> weights, vector<int> values)
{
	double value = 0.0;

	vector<pair<double, int> > valuePerWeightForObjNum;
	for (int i = 0; i < weights.size(); i++)
		valuePerWeightForObjNum.push_back(make_pair((double)values[i] / weights[i], i));

	sort(valuePerWeightForObjNum.rbegin(), valuePerWeightForObjNum.rend());

	for (int i = 0; i < weights.size(); i++)
	{
		if (capacity == 0)
			return value;
		else
		{
			int objectNum = valuePerWeightForObjNum[i].second;
			int a = min(weights[objectNum], capacity);
			value += a * valuePerWeightForObjNum[i].first;
			capacity -= a;
		}
	}

	return value;
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

	//double optimal_value = get_optimal_value(capacity, weights, values);
	double optimal_value = get_optimal_value_fast(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
