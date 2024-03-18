#include <iostream>

#define MAX 21 // 0보다 같거나 작거나, 20보다 크면 바로 상수값임

int w[MAX][MAX][MAX] = { 1, };//이렇게 하면 전체 초기화가 안되는 듯

using namespace std;

int main()
{

	//이렇게 일일히 초기화 해줬음 일단
	for (int a = 0; a <= 20; a++)
	{
		for (int b = 0; b <= 20; b++)
		{
			for (int c = 0; c <= 20; c++)
			{
				w[a][b][c] = 1;
			}
		}
	}

	//값 저장하고 있는 배열 만들기
	for (int a = 1; a <= 20; a++)
	{
		for (int b = 1; b <= 20; b++)
		{
			for (int c = 1; c <= 20; c++)
			{
				if (a < b && b < c)
				{
					w[a][b][c] = w[a][b][c - 1] + w[a][b - 1][c - 1] - w[a][b - 1][c];
				}

				else
				{
					w[a][b][c] = w[a - 1][b][c] + w[a - 1][b - 1][c] + w[a - 1][b][c - 1] - w[a - 1][b - 1][c - 1];
				}
			}
		}
	}
	//출력
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << "\n";
		}

		else if (a > 20 || b > 20 || c > 20)
		{
			cout << "w(" << a << ", " << b << ", " << c << ") = " << w[20][20][20] << "\n";
		}

		else
			cout << "w(" << a << ", " << b << ", " << c << ") = " << w[a][b][c] << "\n";
	}

	




	return 0;
}