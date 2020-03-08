#include <iostream>
#include <vector>

// Number of Inversions = Number of shifts an Insertion Sort performs when sorting an array

using namespace std;

long long countInversionAndMerge(vector<int>& list1, vector<int>& list2, vector<int>& b)
{
	long long count = 0;
	b.clear();
	int i = 0, j = 0;
	while (i < list1.size() && j < list2.size())
	{
		if (list1[i] <= list2[j])
		{
			b.push_back(list1[i]);
			i++;
		}
		else
		{
			b.push_back(list2[j]);
			j++;
			count += list1.size() - i;	
		}
	}

	b.insert(b.end(), list1.begin() + i, list1.end());
	b.insert(b.end(), list2.begin() + j, list2.end());

	return count;
}

// b: sortedList
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	long long number_of_inversions = 0;
	if (right <= left + 1) return number_of_inversions;
	size_t ave = left + (right - left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, ave);
	number_of_inversions += get_number_of_inversions(a, b, ave, right);
	//write your code here

	vector<int> firstHalf(a.begin() + left, a.begin() + ave);
	vector<int> secondHalf(a.begin() + ave, a.begin() + right);

	number_of_inversions += countInversionAndMerge(firstHalf, secondHalf, b);

	for (size_t i = 0; i < right - left; i++)
		a[left + i] = b[i];

	return number_of_inversions;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	
	for (size_t i = 0; i < a.size(); i++)
		std::cin >> a[i];

	vector<int> b(a.size());

	std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';

	return 0;
}





