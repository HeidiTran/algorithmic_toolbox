#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_partial_sum_last_digit_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int getFibonacciPartialSumLastDigitFast(long long from, long long to)
{
	from--;		// getFibonacciPartialSumLastDigitFast(5, 7) = getFibonacciSumLastDigitFast(7) - getFibonacciSumLastDigitFast(4)

	const int PERIOD = 60;		// The last number of Fibonacci series starts repeating itself after every 60 elements
	vector<int> F(PERIOD);
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < PERIOD; i++)
		F[i] = (F[i - 1] + F[i - 2]) % 10;

	int lastDigitOfSumFrom = F[(from + 2) % PERIOD] - 1;
	int lastDigitOfSumTo = F[(to + 2) % PERIOD] - 1;

	return (lastDigitOfSumTo + 10 - lastDigitOfSumFrom) % 10;
}

void stressTest(int N)
{
	while (true)
	{
		long long from = rand() % N;
		long long to = rand() % N;

		while (from >= to)
		{
			from = rand() % N;
			to = rand() % N;
		}

		cout << "from " << from << " to " << to << endl;

		int result1 = get_fibonacci_partial_sum_last_digit_naive(from, to);
		int result2 = getFibonacciPartialSumLastDigitFast(from, to);

		cout << result1 << " " << result2 << endl;

		if (result1 == result2)
			cout << "OK" << endl;
		else
		{
			cout << "Wrong answer: " << endl;
			break;
		}
	}
}

int main() 
{
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << endl;
	std::cout << getFibonacciPartialSumLastDigitFast(from, to) << endl;

	//stressTest(80);

	return 0;
}


