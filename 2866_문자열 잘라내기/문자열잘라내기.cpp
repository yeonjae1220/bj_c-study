#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<map>

//#define fastio() ios::sync_with_stdio(0),cin.tie(0);

using namespace std;

vector<string> input_str;
vector<string> col;

map<string, int> m;

int main()
{
	//fastio();

	int N, M;
	string input;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		input_str.push_back(input);
	}

	int start = 0, end = N - 1, mid = 0;

	vector<string> comp;
	bool trace;
	while (start <= end)
	{
		comp.clear();
		mid = (start + end) / 2;
		bool check = true;

		for (int i = 0; i < M; i++)
		{
			string temp = "";
			for (int j = mid; j <= N-1/*end*/; j++)
				temp += input_str[j][i];

			comp.push_back(temp);
		}

		for (int i = 0; i < comp.size(); i++)//이부분 블로그 코드 map으로 동일 원소 확인하는법 & 2진탐색 인사이트 참고함 걍 내가 못품
		{
			if (m[comp[i]])
			{
				check = false;
				break;
			}

			m[comp[i]]++;
		}

		if (!check)
		{
			end = mid - 1;
		}

		else
		{
			start = mid + 1;
		}

		trace = check;
		m.clear();

	}

	if (!trace)
		cout << mid - 1 << endl;
	else
		cout << mid << endl;
	return 0;


}
