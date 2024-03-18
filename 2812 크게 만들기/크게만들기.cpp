#include<iostream>
#include<string>
#include<queue>

using namespace std;

int N, K;
string input;
deque<char> q;

int main()
{
	cin >> N >> K;
	cin >> input;

	for (int i = 0; i < N; i++)
	{
		while (K && q.size() && q.back() < input[i])
		{
			q.pop_back();
			K--;
		}

		q.push_back(input[i]);

	}

	for (int i = 0; i < q.size() - K; i++)
	{
		cout << q[i];
	}

	return 0;
}
