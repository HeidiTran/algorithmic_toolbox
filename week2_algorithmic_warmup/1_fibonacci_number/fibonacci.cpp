#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// fibonancciFast() & fibonacciSuperFast BASED ON THE SAME IDEA, but faster in the implementation

int fibonacci_naive(int n) 
{
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacciFast(int n) 
{
	vector<long long> F(n + 1);

	F[0] = 0;

	if (n > 0)
	{
		F[1] = 1;

		for (int i = 2; i <= n; i++)
			F[i] = F[i - 1] + F[i - 2];
	}
    return F[n];
}

long long fibonacciSuperFast(int n)
{
	long long first = 0;
	long long second = 1;
	long long ret = second;

	if (n > 1)
		for (int i = 2; i <= n; i++)
		{
			ret = (first + second) % m;
			first = second;
			second = ret;
		}

	return ret;
}

void test_solution() {
    assert(fibonacciFast(3) == 2);
    assert(fibonacciFast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacciFast(n) == fibonacci_naive(n));
}

int main()
{
    int n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << fibonacciFast(n) << '\n';

    return 0;
}
