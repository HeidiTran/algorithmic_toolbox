#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

double minimal_distance_fast(vector<int> x, vector<int> y) 
{
	if (x.size() == 2) return sqrt(pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2));
	if (x.size() == 3)
	{
		double d1 = sqrt(pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2));
		double d2 = sqrt(pow((x[0] - x[2]), 2) + pow((y[0] - y[2]), 2));
		double d3 = sqrt(pow((x[1] - x[2]), 2) + pow((y[1] - y[2]), 2));

		return min(min(d1, d2), d3);
	}

	vector<pair<int, int> > setSortedX(x.size());
	for (int i = 0; i < setSortedX.size(); i++)
		setSortedX[i] = make_pair(x[i], y[i]);
	sort(setSortedX.begin(), setSortedX.end());
	for (int i = 0; i < setSortedX.size(); i++) {
		x[i] = setSortedX[i].first;
		y[i] = setSortedX[i].second;
	}
	
	int mid = x.size() / 2;

	vector<int> set1X(x.begin(), x.begin() + mid);
	vector<int> set1Y(y.begin(), y.begin() + mid);
	double d1 = minimal_distance_fast(set1X, set1Y);

	vector<int> set2X(x.begin() + mid, x.end());
	vector<int> set2Y(y.begin() + mid, y.end());
	double d2 = minimal_distance_fast(set2X, set2Y);

	double d = min(d1, d2);

	double partitionMid = x[mid] - (double)(x[mid] - x[mid - 1]) / 2;	// Distance from the left end to the strip line
	vector<pair<int, int> > stripSortedY;
	for (int i = 0; i < x.size(); i++) {
		if (abs(partitionMid - x[i]) <= d)
			stripSortedY.push_back(make_pair(y[i], x[i]));
	}
	sort(stripSortedY.begin(), stripSortedY.end());

	for (int i = 0; i < stripSortedY.size(); i++) {
		for (int j = i + 1; j < stripSortedY.size(); j++) {
			if (abs(stripSortedY[i].first - stripSortedY[j].first) < d)
				d = min(d, sqrt(pow((stripSortedY[i].first - stripSortedY[j].first), 2) 
					+ pow((stripSortedY[i].second - stripSortedY[j].second), 2)));
		}
	}

	return d;
}

double minimal_distance_slow(vector<int> x, vector<int> y)
{
	double d = sqrt(pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2));

	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x.size(); j++) {
			if (i != j)
				d = min(d, sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2)));
		}
	}

	return d;
}

void stresstest(int maxNumCoor, int maxCoorValue)
{
	while (true)
	{
		int n = rand() % maxNumCoor;
		while (n < 2)
			n = rand() % maxNumCoor;

		vector<int> x(n);
		vector<int> y(n);

		for (size_t i = 0; i < n; i++) {
			x[i] = rand() % maxCoorValue;
			y[i] = rand() % maxCoorValue;
		}

		if (minimal_distance_fast(x, y) == minimal_distance_slow(x, y))
			cout << "OK" << endl;
		else
		{
			cout << "Wrong " << endl;
			for (int i = 0; i < x.size(); i++)
				cout << x[i] << " " << y[i] << endl;
		}
	}
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance_fast(x, y) << "\n";
  //std::cout << std::setprecision(9) << minimal_distance_slow(x, y) << "\n";
}

/*
int main()
{
	stresstest(70, 1000);
}
*/





