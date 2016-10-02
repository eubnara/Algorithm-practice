#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100


//global variable
int map[MAX][MAX];	//각 칸에 쓰인 숫자
int n;	//격자의 크기
bool isVisited[MAX][MAX];	//방문했는지 표시, 방문했다면 1 안했다면 0


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
	jump를 해나가는 함수, 메인 함수에서는 0,0에서 시작한다는 의미로 jump(0,0)으로 호출한다. 
	재귀적으로 호출하되, 반환값이 true라면 바로 반환한다.

*/
bool jump(int y, int x) {
	//base case: 경계값을 넘어가는 경우
	if (y >= n || x >= n)
		return false;

	//base case: 이미 방문한 경우
	if (isVisited[y][x])
		return false;

	//base case: 목적지에 도달한 경우, map[][]에 0값이 들어가는 경우는 목적지에 도달한 경우 밖에 없음에 유의
	if (map[y][x] == 0)
		return true;

	if (jump(y + map[y][x], x))
		return true;

	if (jump(y, x + map[y][x]))
		return true;

	isVisited[y][x] = true;
	return false;
}