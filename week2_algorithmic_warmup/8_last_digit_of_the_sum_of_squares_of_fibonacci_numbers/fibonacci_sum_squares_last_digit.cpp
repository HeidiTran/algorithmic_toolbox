#include <iostream>
#include <vector>

using namespace std;

// Fibonacci Sum Squares(n) = Fib(n) * Fib(n + 1)

int fibonacci_sum_squares_last_digit_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

// Calculate fibonacciSumLastDigit by using the same method as getFibonacciLastDigitSuperFast()
int fibonacciSumSquaresLastDigitFast(long long n)
{
	const int PERIOD = 60;		// The last number of Fibonacci series starts repeating itself after every 60 elements
	vector<int> F(PERIOD);
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < PERIOD; i++)
		F[i] = (F[i - 1] + F[i - 2]) % 10;

	return (F[n % PERIOD] * F[(n + 1) % PERIOD]) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
	//std::cout << fibonacci_sum_squares_last_digit_naive(n) << endl;
	cout << fibonacciSumSquaresLastDigitFast(n) << endl;

	return 0;
}
