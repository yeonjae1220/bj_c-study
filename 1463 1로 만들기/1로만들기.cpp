#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;

//첫번째 방법 1부터 bottom-up으로 풀기
int save[MAX] = {0, };

int main()
{
    for(int i = 2; i < MAX; i++)
    {
        if(i % 3 == 0 && i % 2 ==0)
        {
            save[i] = min(min(save[i/3], save[i/2]), save[i-1]) + 1;
        }

        else if(i % 3 == 0)
        {
            save[i] = min(save[i/3], save[i-1]) + 1;
        }

        else if(i % 2 == 0)
        {
            save[i] = min(save[i/2], save[i-1]) + 1;
        }

        else
        {
            save[i] = save[i-1] + 1;
        }
    }

    int N;
    cin >> N;
    cout << save[N];

    return 0;
}