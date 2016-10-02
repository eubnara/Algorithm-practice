#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100


//global variable
int map[MAX][MAX];	//�� ĭ�� ���� ����
int n;	//������ ũ��
bool isVisited[MAX][MAX];	//�湮�ߴ��� ǥ��, �湮�ߴٸ� 1 ���ߴٸ� 0


//function
bool jump(int y, int x);


int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {		
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		memset(isVisited, 0, sizeof(bool)*MAX*MAX);

		if (jump(0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

/*
	jump�� �س����� �Լ�, ���� �Լ������� 0,0���� �����Ѵٴ� �ǹ̷� jump(0,0)���� ȣ���Ѵ�. 
	��������� ȣ���ϵ�, ��ȯ���� true��� �ٷ� ��ȯ�Ѵ�.

*/
bool jump(int y, int x) {
	//base case: ��谪�� �Ѿ�� ���
	if (y >= n || x >= n)
		return false;

	//base case: �̹� �湮�� ���
	if (isVisited[y][x])
		return false;

	//base case: �������� ������ ���, map[][]�� 0���� ���� ���� �������� ������ ��� �ۿ� ������ ����
	if (map[y][x] == 0)
		return true;

	if (jump(y + map[y][x], x))
		return true;

	if (jump(y, x + map[y][x]))
		return true;

	isVisited[y][x] = true;
	return false;
}