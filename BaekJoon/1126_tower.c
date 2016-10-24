/*
 * author: yubi Lee
 * date: 2016-10-22
 * problem: 1126
 *
 * idea:
 * [전수조사]
 * 	각 블럭에 대해서 3가지 경우로 나눈 뒤, 모든 경우를 고려해 본다.
 * 		0번 타워에 선택된 경우
 * 		1번 타워에 선택된 경우
 * 		선택되지 않은 경우
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 50

int towerHeight[2];
int N;
int ans;
int arr[MAX_BLOCKS];
void DFS(int n){
	int i;
	if((towerHeight[0] == towerHeight[1]) && (ans < towerHeight[0])) 
		ans = towerHeight[0];
	if(n == N)
		return;

	//타워에 집어넣어보는 경우
	for(i=0;i<2;i++) {
		towerHeight[i] += arr[n];
		DFS(n+1);
		towerHeight[i] -= arr[n];
	}
	//선택을 안해보는 경우
	DFS(n+1);
}

int main(void) {
	int i;	//index
	ans = -1;
	scanf("%d",&N);
	for(i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	DFS(0);

	printf("%d\n",ans);

	return 0;
}
