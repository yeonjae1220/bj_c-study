#include <iostream>

#define MAX 101
using namespace std;

long long int arr[MAX];

int main()
{
	arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2; arr[5] = 2; arr[6] = 3;
	arr[7] = 4; arr[8] = 5; arr[9] = 7; arr[10] = 9;

	int cnt = 6;

	for (int i = 11; i <= 100; i++)
	{
		arr[i] = arr[cnt++] + arr[i - 1];
	}

	int N;
	cin >> N;
	int input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		cout << arr[input] << "\n";
	}



	return 0;
}