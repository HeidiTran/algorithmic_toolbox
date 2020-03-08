#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

bool compareSegmentEnd(const Segment& x, const Segment& y)
{
	return x.end < y.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
  
	sort(segments.begin(), segments.end(), compareSegmentEnd);

	int point = segments[0].end;
	points.push_back(point);

  for (size_t i = 0; i < segments.size(); ++i) 
  {
	  if (point < segments[i].start)
	  {
		  point = segments[i].end;
		  points.push_back(point);
	  }
  }

	return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}


