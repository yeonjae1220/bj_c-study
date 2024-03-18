#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//vector<string> string_input;
vector<string> string_compare;

int cnt = 0;

int main()
{
	int N, M;
	string input;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		string_compare.push_back(input);
	}

	sort(string_compare.begin(), string_compare.end());
	//sort 문자열 확인용
	/*for (int i = 0; i <= string_compare.size(); i++)
	{
		cout << string_compare[i] << endl;
	}*/

	for (int i = 0; i < M; i++)
	{
		cin >> input;
		if (binary_search(string_compare.begin(), string_compare.end(), input))
			cnt++;
	}

	cout << cnt;

	return 0;





}
