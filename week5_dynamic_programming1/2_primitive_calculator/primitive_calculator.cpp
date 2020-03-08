#include <iostream>
#include <vector>
#include <algorithm>

// SLOW FOR NUMBERS WITH 6 DIGITS

using namespace std;

vector<int> optimal_sequence(int number)
{
	vector<vector<int> > minOperations(number + 1);
	minOperations[1].push_back(1);
	
	int i = 1;
	while (pow(3, i) + 1 <= number)	// 3^i + 1
	{
		for (int j = 0; j <= i; j++)
			minOperations[pow(3, i) + 1].push_back(pow(3, j));
		minOperations[pow(3, i) + 1].push_back(pow(3, i) + 1);

		i++;
	}

	for (int n = 2; n <= number; n++)
	{
		if (minOperations[n].empty())
		{
			if (n % 3 == 0)
				minOperations[n] = minOperations[n / 3];
			else if (n % 2 == 0)
				minOperations[n] = minOperations[n / 2];
			else
				minOperations[n] = minOperations[n - 1];

			minOperations[n].push_back(n);
		}
	}

	return minOperations[number];
}

vector<int> optimal_sequence_incorrect(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

void test(int min, int max)
{
	if (min < 1) {
		cout << "min must be greater than 1" << endl;
		return;
	}
	
	int n = min;
	while (n <= max)
	{
		vector<int> sequence = optimal_sequence(n);
		std::cout << sequence.size() - 1 << std::endl;
		for (size_t i = 0; i < sequence.size(); ++i) 
			std::cout << sequence[i] << " ";
		cout << endl;
		n++;
	}
}

int main() {
	int n;
	std::cin >> n;
	//vector<int> sequence = optimal_sequence_incorrect(n);
	vector<int> sequence = optimal_sequence(n);

	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) 
		std::cout << sequence[i] << " ";

	cout << endl;
	return 0;
} 

/*
int main()
{
	test(1000, 10000);
}
*/

