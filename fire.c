#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N	100010
#define MAX_INT	((1<<(sizeof(int)*8 - 1))-1)

int cost[MAX_N];	//N개의 각 봉화대 후보지점의 공사비용
int result[MAX_N];
int N;	//봉화대의 개수	2<=N<=100000
int P;	//봉화대의 시야	1<=P<N
//인덱스가 N에 다다르면 return;
void dfs(int index, int cur_cost) {
	if (index > N)
		return;
	if (result[index] == 0 || (cost[index] + cur_cost < result[index])) {
		if (index > P)
			result[index] = cost[index] + cur_cost;
		else
			result[index] = cost[index];
		for (int i = P; i >= 1; i--)
			dfs(index + i, result[index]);
	}
	else {
		return;
	}
}

int main(void) {

	int T;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &P);

		//헷갈리지 않게 index는 1부터 시작한다.
		for (int i = 1; i <= N; i++)
			scanf("%d", &cost[i]);


	//	for (int i = 1; i <= P; i++)
	//		result[i] = cost[i];
		dfs(1, 0);

		/*
		//dynamic programming, memoization
		//시작점에서 P번째까지는 도달할 수 있으니까, P+1부터 시작.
		for (int i = P+1; i <= N; i++) {
		int min = MAX_INT;
		for (int j = 1; j <= P; j++) {
		int tmp = cost[i - j];
		if (tmp < min)
		min = tmp;
		}
		cost[i] += min;
		}
		*/
		int min = MAX_INT;
		for (int i = 0; i < P; i++){
			int tmp = result[N - i];
			if (tmp < min)
				min = tmp;
		}

		printf("%d\n", min);
	}

	return 0;
}