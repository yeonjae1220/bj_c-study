#include<iostream>
#include<cmath>

using namespace std;

void string_divide(int len)
{
	if (len == 1)
	{
		printf("-");
	}

	else
	{
		string_divide(len / 3);
		for (int i = 0; i < (len / 3); i++)
		{
			printf(" ");
		}
		string_divide(len / 3);
	}
}


int main()
{
	int n;
	while (cin >> n/*!cin.eof()*/)
	{
		
		string_divide(pow(3, n));
		cout << "\n";
	}


	return 0;
}


