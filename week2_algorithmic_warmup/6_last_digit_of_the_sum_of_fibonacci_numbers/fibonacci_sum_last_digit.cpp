#include <iostream>
#include <vector>
#include <numeric>
#include <time.h>

using namespace std;

// Fibonacci Sum(n) = Fib(n + 2) - 1

int fibonacci_sum_last_digit_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

// Calculate fibonacciSumLastDigit based on definition
int fibonacciSumLastDigitSlow(long long n)
{
	// Difference in Fibonacci Sum is a Fibonacci Sequence 

	vector<int> DFibSumLastDigit(n + 1);

	DFibSumLastDigit[0] = 0;

	if (n > 0)
	{
		DFibSumLastDigit[1] = 1;

		for (int i = 2; i <= n; i++) 
			DFibSumLastDigit[i] = (DFibSumLastDigit[i - 1] + DFibSumLastDigit[i - 2]) % 10;
			
	}

	return accumulate(DFibSumLastDigit.begin(), DFibSumLastDigit.end(), 0) % 10;
}

// Calculate fibonacciSumLastDigit by using the same method as getFibonacciLastDigitFast()
/*
int fibonacciSumLastDigitFast_1(long long n)
{
	int m = n + 2;	// m is the (n + 2)th element 
	int lastDigitOfm;	// lastDigitOfm is the last digit of the (n + 2)th element

	int first = 0;
	int second = 1;

	for (int i = 2; i <= m; i++)
	{
		lastDigitOfm = (first + second) % 10;
		first = second;
		second = lastDigitOfm;
	}

	if (lastDigitOfm != 0)
		return lastDigitOfm - 1;
	else
		return 9;
}
*/

// Calculate fibonacciSumLastDigit by using the same method as getFibonacciLastDigitSuperFast()
int fibonacciSumLastDigitFast(long long n)
{
	const int PERIOD = 60;		// The last number of Fibonacci series starts repeating itself after every 60 elements
	vector<int> F(PERIOD);
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < PERIOD; i++)
		F[i] = (F[i - 1] + F[i - 2]) % 10;

	if (F[(n + 2) % PERIOD] != 0)	// F[(n + 2) % PERIOD] is the last digit of the (n + 2)th element
		return F[(n + 2) % PERIOD] - 1;
	else
		return 9;
}

void stressTest(int N)
{
	while (true)
	{
		int n = rand() % N;

		while (n == 0)
			n = rand() % N;

		cout << "n = " << n << endl;

		int result1 = fibonacci_sum_last_digit_naive(n);
		int result2 = fibonacciSumLastDigitFast(n);

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
	
    long long n = 0;
    std::cin >> n;
	//std::cout << fibonacci_sum_last_digit_naive(n) << endl;
	std::cout << fibonacciSumLastDigitFast(n) << endl;

	return 0;
}






