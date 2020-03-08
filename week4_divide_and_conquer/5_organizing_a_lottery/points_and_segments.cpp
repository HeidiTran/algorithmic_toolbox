#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numStartsLessThanOrEqualToPoint(const vector<int> &a, int x)
{
	int left = 0, right = (int)a.size();
	while (true)
	{
		if (left == right)
			return (left - 1) + 1;	// (index of the largest elem that's less than x) + 1 = number of elements smaller than x
		int mid = floor(left + (right - left) / 2);
		if (x == a[mid]) {
			while (mid + 1 < a.size() && x == a[mid + 1])
				mid = mid + 1;
			return mid + 1;	// (index of the elem that's equal to x) + 1 = number of elements less than or equal to x
		}
		else if (x < a[mid])
			right = mid;
		else
			left = mid + 1;
	}
}
int numEndsLessThanPoint(const vector<int> &a, int x)
{
	int left = 0, right = (int)a.size();
	while (true)
	{
		if (left == right)
			return (left - 1) + 1;	// (index of the largest elem that's less than x) + 1 = number of elements smaller than x
		int mid = floor(left + (right - left) / 2);
		if (x == a[mid]) {
			while (mid - 1 >= 0 && x == a[mid - 1])
				mid = mid - 1;
			return mid;		// index of the elem that's equal to x = number of elements that's less than x
		}
		else if (x < a[mid])
			right = mid;
		else
			left = mid + 1;
	}
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());
	for (size_t i = 0; i < points.size(); i++)
		cnt[i] = numStartsLessThanOrEqualToPoint(starts, points[i]) - numEndsLessThanPoint(ends, points[i]);
	
	return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      //Equivalent to: cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
		if (starts[j] <= points[i] && points[i] <= ends[j])
			cnt[i]++;
    }
  }
  return cnt;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	vector<int> starts(n), ends(n);
	for (size_t i = 0; i < starts.size(); i++) {
		std::cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	for (size_t i = 0; i < points.size(); i++) {
		std::cin >> points[i];
	}

	//vector<int> cnt = naive_count_segments(starts, ends, points);
	vector<int> cnt = fast_count_segments(starts, ends, points);
	for (size_t i = 0; i < cnt.size(); i++) {
		std::cout << cnt[i] << ' ';
	}
}



