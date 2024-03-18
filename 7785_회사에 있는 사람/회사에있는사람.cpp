#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, string, greater<>> map_nc;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string name, commute;
		cin >> name >> commute;
		map_nc[name] = commute;
	}

	//map<string, string> temp;
	for (auto temp = map_nc.begin(); temp != map_nc.end(); temp++)
	{
		if (temp->second == "enter")
		{
			cout << temp->first << "\n";
		}
		
	}
	

	return 0;


}
