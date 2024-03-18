#include<iostream>
#include<string>
#include<queue>

using namespace std;

#define WALL 0
#define PATH 1
#define PASSED 2
#define PATH_WRONG 3

#define MAX 111
string input_num;

queue<pair<int, int>> que;


int maze[MAX][MAX] = { 0, };//미로
int passed[MAX][MAX] = { 0, };//지나간 경로 표시해주는 비열
int distan[MAX][MAX] = { 0, };//너비 탐색 하면서 거기까지 경로 거리를 기록

//E W S N 방향으로 이동하기 위한 배열
int x_mov[4] = { 0, 1, 0, -1 };
int y_mov[4] = { -1, 0, 1, 0 };

int N, M;

int find_exit(int x, int y)
{

	que.push(make_pair(x, y));//queue에 (1, 1) 즉 출발지점을 넣어준다
	passed[y][x] = PASSED;//해당 경로 지나감을 표시

	distan[y][x]++;//출발 지점도 거리에 포함해서 +1 해준다

	while (!que.empty())
	{
		int x_input = que.front().first;
		int y_input = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int x_temp = x_input + x_mov[i];
			int y_temp = y_input + y_mov[i];

			if (x_temp > 0 && x_temp <= M && y_temp > 0 && y_temp <= N && passed[y_temp][x_temp] == 0 && maze[y_temp][x_temp] == PATH)
			{
				que.push(make_pair(x_temp, y_temp));
				passed[y_temp][x_temp] = PASSED;
				distan[y_temp][x_temp] = distan[y_input][x_input] + 1;//인접한 루트이므로 거리는 +1이 된다			
				//최종 경로 찾으면 리턴
				if (y_temp == N && x_temp == M)
					return distan[N][M];
			}
		}
	}

}



int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> input_num;
		for (int j = 0; j < M; j++)
		{
			maze[i][j + 1] = input_num[j] - '0';
		}
	}

	//출발지 1, 1
	cout << find_exit(1, 1);//출구까지의 거리가 담겨있는 배열 인덱스


	return 0;
}