#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// i = str1.length(), j = str2.length()
void outputAlignment(const string &str1, int i, const string &str2, int j, const vector<vector<int> >& D)
{
	if (i == 0 && j == 0)
		return;
	if (i > 0 && D[i][j] == D[i - 1][j] + 1)
	{
		outputAlignment(str1, i - 1, str2, j, D);
		cout << str1[i - 1] << endl;
		cout << "-" << endl;
		cout << endl;
	}
	else if (j > 0 && D[i][j] == D[i][j - 1] + 1)
	{
		outputAlignment(str1, i, str2, j - 1, D);
		cout << "-" << endl;
		cout << str2[j - 1] << endl;
		cout << endl;
	}
	else
	{
		outputAlignment(str1, i - 1, str2, j - 1, D);
		cout << str1[i - 1] << endl;
		cout << str2[j - 1] << endl;
		cout << endl;
	}
}

int countCommonSubsequences(const string &str1, int i, const string &str2, int j, const vector<vector<int> >& D)
{
	int cnt = 0;
	if (i == 0 && j == 0)
		return 0;
	if (i > 0 && D[i][j] == D[i - 1][j] + 1)	// deletion
		cnt += countCommonSubsequences(str1, i - 1, str2, j, D);
	else if (j > 0 && D[i][j] == D[i][j - 1] + 1)	// insertion
		cnt += countCommonSubsequences(str1, i, str2, j - 1, D);
	else
	{
		cnt += countCommonSubsequences(str1, i - 1, str2, j - 1, D);
		if (str1[i - 1] == str2[j - 1])
			cnt++;
	}

	return cnt;
}

int edit_distance(const string &str1, const string &str2) 
{
	vector<vector<int> > D(str1.size() + 1, vector<int>(str2.size() + 1));
	for (int i = 0; i <= str1.length(); i++)
		D[i][0] = i;
	for (int j = 0; j <= str2.length(); j++)
		D[0][j] = j;

	for (int j = 1; j <= str2.length(); j++)
	{
		for (int i = 1; i <= str1.length(); i++)
		{
			int insertion = D[i][j - 1] + 1;
			int deletion = D[i - 1][j] + 1;
			int match = D[i - 1][j - 1];
			int mismatch = D[i - 1][j - 1] + 1;

			if (str1[i - 1] == str2[j - 1])	// str1 starts from 1 in the matrix (go to TheAlignmentGame.pdf for more details)
				D[i][j] = min(min(insertion, deletion), match);
			else
				D[i][j] = min(min(insertion, deletion), mismatch);
		}
	}

	/*
	cout << endl;
	for (int i = 0; i <= str1.length(); i++)
	{
		for (int j = 0; j <= str2.length(); j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	*/
	
	//outputAlignment(str1, str1.length(), str2, str2.length(), D);

	cout << "Longest Common Sequences: " << countCommonSubsequences(str1, str1.length(), str2, str2.length(), D) << endl;

	return D[str1.length()][str2.length()];
}

int main() 
{
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}

