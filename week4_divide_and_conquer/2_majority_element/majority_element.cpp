#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// The faster way to solve this problem (not using divide and conquer technique) is using maps. 
// Scan through the inputs and make pair(value, count)

int get_majority_element(vector<int> &a, int left, int right) {
	if (left == right) return -1;
	if (left + 1 == right) return a[left];

	int mid = floor(left + (right - left) / 2);
	int leftElem = get_majority_element(a, left, mid);
	int rightElem = get_majority_element(a, mid, right);

	int countLeftElem = 0, countRightElem = 0;
	for (int i = left; i < right; i++)
		if (a[i] == leftElem)
			countLeftElem++;
		else if (a[i] == rightElem)
			countRightElem++;

	if (countLeftElem >(right - left) / 2)
		return leftElem;
	else if (countRightElem > (right - left) / 2)
		return rightElem;
	else return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
