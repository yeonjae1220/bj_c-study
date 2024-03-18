/*
1T
일단 2차원 배열 인덱스 돌면서 Land 만나면 Land 탐색하면서
탐색한 지역을 전부 Sea로 만들고, 이런식으로 Land탐색 할때마다
cnt++해주면 될 거 같다

*/
#include<iostream>

#define MAX 51
#define PASSED 1

using namespace std;


int w, h;

int x_mov[4] = { 0, 1, 0, -1 };
int y_mov[4] = { -1, 0, 1, 0 };



int cnt;



void count_land(int Map[][MAX], int passed[][MAX], int w, int h);
void land_to_sea(int Map[][MAX], int passed[][MAX], int x, int y);

int main()
{
	while (1)
	{

		int Map[MAX][MAX] = { 0, };
		int passed[MAX][MAX] = { 0, };
		cnt = 0;

		cin >> w >> h;
		if (w == 0 && h == 0)
			break;


		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> Map[i][j];
			}
		}


		count_land(Map, passed, w, h);
		cout << cnt << "\n";
	}




	return 0;
}

void count_land(int Map[][MAX], int passed[][MAX], int w, int h)
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			//만약 인덱스가 섬이라면 섬 찾기, 그 해당 인덱스들 값 0으로 만들기
			if (Map[i][j] == 1)
			{
				cnt++;
				/*passed[i][j] = PASSED;*/
				Map[i][j] = 0;
				land_to_sea(Map, passed, j, i);
			}
		}
	}
}


void land_to_sea(int Map[][MAX], int passed[][MAX], int x, int y)
{

	passed[y][x] = PASSED;
	

	if (y - 1 > 0 && passed[y - 1][x] == 0 && Map[y - 1][x] == 1)//N방향 검사
	{
		Map[y - 1][x] = 0;
		land_to_sea(Map, passed, x, y - 1);
	}
	if (y - 1 > 0 && x + 1 <= w && passed[y - 1][x + 1] == 0 && Map[y - 1][x + 1] == 1)
	{
		Map[y - 1][x + 1] = 0;
		land_to_sea(Map, passed, x + 1, y - 1);
	}
	if (x + 1 <= w && passed[y][x + 1] == 0 && Map[y][x + 1] == 1)//E방향 검사
	{
		Map[y][x + 1] = 0;
		land_to_sea(Map, passed, x + 1, y);
	}
	if (x + 1 <= w && y + 1 <= h && passed[y + 1][x + 1] == 0 && Map[y + 1][x + 1] == 1)
	{
		Map[y + 1][x + 1] = 0;
		land_to_sea(Map, passed, x + 1, y + 1);
	}
	if (y + 1 <= h && passed[y + 1][x] == 0 && Map[y + 1][x] == 1)//S방향 검사
	{
		Map[y + 1][x] = 0;
		land_to_sea(Map, passed, x, y + 1);
	}
	if (y + 1 <= h && x - 1 > 0 && passed[y + 1][x - 1] == 0 && Map[y + 1][x - 1] == 1)
	{
		Map[y + 1][x - 1] = 0;
		land_to_sea(Map, passed, x - 1, y + 1);
	}
	if (x - 1 > 0 && passed[y][x - 1] == 0 && Map[y][x - 1] == 1)//W방향 검사
	{
		Map[y][x - 1] = 0;
		land_to_sea(Map, passed, x - 1, y);
	}
	if (x - 1 > 0 && y - 1 > 0 && passed[y - 1][x - 1] == 0 && Map[y - 1][x - 1] == 1)
	{
		Map[y - 1][x - 1] = 0;
		land_to_sea(Map, passed, x - 1, y - 1);
	}
}


