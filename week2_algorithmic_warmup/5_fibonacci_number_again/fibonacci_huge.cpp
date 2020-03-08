#include <iostream>
#include <vector>

using namespace std;

// Exercise Break
// 1. Prove that F(n) mod m is periodic for every m
// 2. Prove that the period of F(n) mod m does not exceed m^2

long long get_fibonacci_huge_naive(long long a, long long b) {
    if (a <= 1)
        return a;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < a - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % b;
}

long long fibonacci(int n)
{
	vector<long long> F(n + 1);

	F[0] = 0;
	F[1] = 1;

	for (int i = 2; i <= n; i++)
		F[i] = F[i - 1] + F[i - 2];

	return F[n];
}

int getPisanoPeriod(int m)
{	
	int first = 0;
	int second = 1;
	int c = second;
	
	int i = 1;
	while (true)
	{
		c = (first + second) % m;
		first = second;
		second = c;
		
		if (first == 0 && second == 1)
			break;

		i++;
	}

	return i;	
}

long long getFibonacciHugeFast(long long n, long long m)
{
	long long tmpFib = n % getPisanoPeriod(m);

	long long first = 0;
	long long second = 1;
	long long ret = second;

	if (tmpFib > 1)
		for (int i = 2; i <= tmpFib; i++)
		{
			ret = (first + second) % m;
			first = second;
			second = ret;
		}

	return ret;
}

int main() 
{
	///*
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << endl;
	cout << getFibonacciHugeFast(n, m) << endl;
	//*/

	/*
	int n;
	cin >> n;
	cout << getPisanoPeriod(n) << endl;
	*/

	//cout << fibonacci(7) % 3 << endl;

	return 0;
}

