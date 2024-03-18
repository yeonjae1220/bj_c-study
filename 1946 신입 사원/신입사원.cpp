/*
그러면 위에 애들 값을 읽을 때 max값을 저장하는 변수를 하나 만들어서 비교하면
서칭하는 시간이 사라져서 좋을 듯 함
*/


#include<iostream>
#include<map>
#include<vector>

using namespace std;


int n;
int input1, input2;
int cnt = 0;



map<int, int>m;
vector<int> answer;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	while (n)
	{
		int number_of_applicants;
		cin >> number_of_applicants;
		for (int i = 0; i < number_of_applicants; i++)
		{
			cin >> input1 >> input2;
			m[input1] = input2;
		}

		int min;

		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			if (iter->first == 1)
			{
				min = iter->second;
				cnt++;
				continue;
			}
			auto iter2 = --iter;
			iter++;
			if (iter->first == 2)
			{
				if (iter->second < iter2->second)
				{
					if (iter->second < min)
						min = iter->second;
					cnt++;
					continue;
				}
			}

			if (iter->second < min)
			{
				cnt++;
				min = iter->second;
			}

		}
		answer.push_back(cnt);
		m.clear();
		cnt = 0;

		n--;
	}


	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}


	return 0;

}
