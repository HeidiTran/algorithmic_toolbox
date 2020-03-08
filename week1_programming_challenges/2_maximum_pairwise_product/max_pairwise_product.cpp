#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The MaxPairwiseProductFast algorithm finds the largest and the second largest elements in about 2n comparisons
//
// Exercise Break
// 1. Find two largest elements in an array in 1.5n comparisons
// 2. Find two largest elements in an array in n + ceil(log2(n)) - 2
// 3. Prove that no algorithm for finding two largest elements in an array can do this in less than n + ceil(log2(n)) - 2 cmparisons
// 4. What is the fastest algorithm for finding three largest elements?

int64_t MaxPairwiseProductNaive(const std::vector<int64_t>& numbers) {
    int64_t max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

int64_t MaxPairwiseProductFast(const std::vector<int64_t>& numbers)
{
	int index_1 = 0; 
	for (int i = 1; i < numbers.size(); i++)
		if (numbers[i] > numbers[index_1])
			index_1 = i;
	
	int index_2;
	if (index_1 == 0)
		index_2 = 1;
	else
		index_2 = 0;

	for (int i = 0; i < numbers.size(); i++)
		if (i != index_1 && numbers[i] > numbers[index_2])
			index_2 = i;

	return numbers[index_1] * numbers[index_2];
}

int64_t MaxPairwiseProductFastSwap(std::vector<int64_t>& numbers)
{
	int index = 0;
	for (int i = 1; i < numbers.size(); i++)
		if (numbers[i] > numbers[index])
			index = i;

	swap(numbers[index], numbers[numbers.size() - 1]);

	index = 0;
	for (int i = 1; i < numbers.size() - 1; i++)
		if (numbers[i] > numbers[index])
			index = i;

	swap(numbers[index], numbers[numbers.size() - 2]);
	return numbers[numbers.size() - 2] * numbers[numbers.size() - 1];
}

int64_t MaxPairwiseProductFast_1(const std::vector<int64_t>& numbers)
{
	int index_1, index_2;

	if (numbers[0] > numbers[1]) {
		index_1 = 0;
		index_2 = 1;
	}
	else
	{
		index_1 = 1;
		index_2 = 0;
	}

	for (int i = 2; i < numbers.size(); i++)
		if (numbers[i] > numbers[index_2]) 
			if (numbers[i] > numbers[index_1])
			{
				index_2 = index_1;
				index_1 = i;
			}
			else
				index_2 = i;
	
	return numbers[index_1] * numbers[index_2];
}

void stressTest(int N, int M)
{
	while (true)
	{	
		int n = rand() % N;
		while (n < 2)
			n = rand() % N;

		vector<int64_t> A;

		for (int i = 0; i < n; i++)
			A.push_back(rand() % M);

		for (int i = 0; i < A.size(); i++)
			cout << A[i] << " ";

		cout << endl;

		int64_t result_1 = MaxPairwiseProductNaive(A);
		int64_t result_2 = MaxPairwiseProductFast_1(A);

		if (result_1 == result_2)
			cout << "OK" << endl;
		else 
		{
			cout << "Wrong answer: " << result_1 << " " << result_2 << endl;
			return;
		}
			
	}
}

int main()
{
	/*
    int n;
    std::cin >> n;
    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    //int64_t result = MaxPairwiseProductNaive(numbers);
	//int64_t result = MaxPairwiseProductFast_1(numbers);
	int64_t result = MaxPairwiseProductFastSwap(numbers);
    std::cout << result << "\n";
	*/

	stressTest(10, 100000);

    return 0;
}
