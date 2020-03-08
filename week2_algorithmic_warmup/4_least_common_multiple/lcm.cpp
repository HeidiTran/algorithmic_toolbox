#include <iostream>

using namespace std;

long long gcd_fast(int a, int b)
{
	if (b == 0)
		return a;

	int a_tmp = a % b;

	return gcd_fast(b, a_tmp);
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(long long a, long long b)
{
	long long gcdAB = gcd_fast(a, b);

	return (a * b) / gcdAB;

}

int main() {
  long long a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
