#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}
*/

bool isGreaterOrEqual(const string& number, const string& maxNumber)
{
	string digitMaxDigit = number + maxNumber;
	string MaxDigitDigit = maxNumber + number;
	return digitMaxDigit >= MaxDigitDigit;
}

string largest_number(vector<string> a) 
{
	string result;
	while (!a.empty())
	{
		string maxNumber;
		int maxNumberIndex;
		for (int i = 0; i < a.size(); i++)
			if (isGreaterOrEqual(a[i], maxNumber))
			{
				maxNumber = a[i];
				maxNumberIndex = i;
			}
		
		result += maxNumber;
		a.erase(a.begin() + maxNumberIndex);
	}
	return result;
}

int main() {
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	
	std::cout << largest_number(a) << endl;
}
