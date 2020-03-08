#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_last_digit_naive(int n) 
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int getFibonacciLastDigitFast(int n)
{
	int first = 0;
	int second = 1;
	
	if (n == 0)
		return first;
	else if (n == 1)
		return second;
	else
	{
		int ret;
		for (int i = 2; i <= n; i++)
		{
			ret = (first + second) % 10;
			first = second;
			second = ret;
		}

		return ret;
	}
}

int getFibonacciLastDigitSuperFast(int n)
{
	const int PERIOD = 60;		// The last number of Fibonacci series starts repeating itself after every 60 elements
	vector<int> F(PERIOD);
	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i < PERIOD; i++)
		F[i] = (F[i - 1] + F[i - 2]) % 10;

	return F[n % PERIOD];
}

int main() 
{

    int n;
    std::cin >> n;
    //cout << get_fibonacci_last_digit_naive(n) << endl;
	cout << getFibonacciLastDigitFast(n) << endl;
	cout << getFibonacciLastDigitSuperFast(n) << endl;
    
	
	return 0;
}
