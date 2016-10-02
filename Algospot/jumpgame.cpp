#include <iostream>
#include <cstring>
using namespace std;

int size,map[100][100];

int visit(int x, int y)
{
	//char c;
	if (x >= size || y >= size) return false;
	int& ref = map[x][y];
	if (ref == 0) return true;

	if (ref == -1) return false;

	if (visit(x + ref, y) || visit(x, y + ref))
		ref = 0;
	else
		ref = -1;
	/*
	for (int i = 0; i < size; i++)
	{	
		for (int j = 0; j < size; j++)
				cout << map[i][j]<<' ';
		cout << endl;
	}
	cout << endl;
	scanf_s("%c", &c);
	*/
	return ref+1;
}


int main(void)
{
	int T;
	scanf("%d", &T);
	//cin >> T;
	while (T--)
	{
		//memset(map, -1, sizeof(map));
	
		scanf("%d", &size);
		for (int x = 0; x < size; x++)
			for (int y = 0; y < size; y++)
				scanf("%d", &map[x][y]);
		if (visit(0, 0))
			printf("YES\n");
		else
			printf("NO\n");
		/*
		cin >> size;
		for (int x = 0; x < size; x++)
			for (int y = 0; y < size; y++)
				cin >> map[x][y];
		
		if (visit(0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		*/
	}

	return 0;
}