#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define TRUE	1
#define FALSE	0

struct pos{
	int x;
	int y;
};
typedef struct pos Pos;
int search(char map[5][5], char* word, int len, int curStrPos, Pos pos);

Pos move[8] = { 
	{ 1, 0 },
	{ 1, 1 },
	{ 0, 1 },
	{ -1, 1 },
	{ -1, 0 },
	{ -1, -1 },
	{ 0, -1 },
	{ 1, -1 }
};

int main(void) {
	char map[5][5];
	char words[10 + 10][10 + 10];
	int T;

	scanf("%d", &T);
	while (T--) {
		int numOfWords;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				char tmp;
				while (1){
					tmp = getchar();
					if (tmp == '\n')
						continue;
					else
						break;
				}
				map[i][j] = tmp;
			}
		}

		scanf("%d", &numOfWords);
		for (int i = 0; i < numOfWords; i++) {
			scanf("%s", words[i]);
		}
		Pos start = { 0, 0 };
		for (int i = 0; i < numOfWords; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					start.x = j;
					start.y = k;
					if (search(map, words[i], strlen(words[i]), 0, start)){
						printf("%s YES\n", words[i]);
						goto OUT;
					}
				}	
			}
			printf("%s NO\n", words[i]);
		OUT:
			;
		}
	}


	return 0;
}

/*
x,y: 현재 위치 좌표, 맨 좌측상단이 0,0 우측 하단이 4,4
*/
int search(char map[5][5], char* word, int len, int curStrPos, Pos pos) {
	if (pos.x < 0 || pos.x>4 || pos.y < 0 || pos.y>4)
		return FALSE;
	if (len - 1 == curStrPos){
		if (map[pos.x][pos.y] == word[curStrPos])
			return TRUE;
		else
			return FALSE;
	}
	if (map[pos.x][pos.y] == word[curStrPos])
	{
		for (int k = 0; k < 8; k++){
			Pos next = { pos.x + move[k].x, pos.y + move[k].y };
			if (search(map, word, len, curStrPos + 1, next))
				return TRUE;
			//else: FALSE 가 반환되면 계속 탐색
		}
	}
	return FALSE;
}