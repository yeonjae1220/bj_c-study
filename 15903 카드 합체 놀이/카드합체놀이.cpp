#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long int, vector<long long int>, greater<long long int>> pq; // 가운데 vector는 왜 들어감?
long long int n, m;


int main()
{
	cin >> n >> m;
	long long int input;
	long long int a1, a2;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		pq.push(input);
	}

	for (int i = 0; i < m; i++)
	{
		a1 = pq.top();
		pq.pop();
		a2 = pq.top();
		pq.pop();
		pq.push(a1 + a2);
		pq.push(a1 + a2);
	}

	long long int sum = 0;
	
	while(pq.size() != 0)
	{
		sum += pq.top();
		pq.pop();
		
	}

	
	cout << sum;



	return 0;
}