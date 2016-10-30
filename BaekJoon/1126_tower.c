/*
 * 2016-10-29 백준 1126번 문제
 * 풀이: 이유비
 *
 * 이 문제의 힌트는 조건에 있었다.
 * 0 < N <= 50
 * 0 < 각 블럭의 높이 <= 50만
 * 0 < 총합 <= 50만
 * 총합이 50만을 넘지 않으므로, 50만 짜리의 배열에 저장할 수 있겠다 싶었다.
 * 그 값을 만드는 형태 중, 여러 블럭을 사용하는 것을 저장한다. (타워의 높이를 최대로 하는 것이 목표이므로)
 *
 *
 * 부분문제를 만들어 보았다.
 * cache[N][dif]
 * N번째 까지의 블럭을 사용해서 dif만큼의 차이를 만드는데 사용한 블럭의 총합을 저장한다.
 * 만일 현재 조사하는 N번째 블럭의 크기 x에 대해서
 * cache[N-1][x] > 0 이라면, 같은 높이를 만들 수 있다는 것을 의미한다.
 * cache[][]값을 갱신할 때에도 크기가 큰 값으로 하고,
 * 최종 답인 height의 답을 갱신할 때도 크기가 큰 값으로 한다.
 *
 */
#include <stdio.h>
#include <stdlib.h> //abs()

#define MAX_VAL 500000
int height = -1;	//탑의 높이의 최대값

int cache[50+5][MAX_VAL+5];	//최대값 500,000, cache[N][dif] N개의 블럭까지 사용해서 dif값만큼의 차이를 만들 수 있다면, 현재까지 고른 블럭들의 총합을 저장(총합을 저장하므로 어떻게 선택하는지는 중요하지 않음), 저장하려는 값이 저장되어 있는 값보다 클 때만 갱신한다 N이 하나 늘어나서 조사할 때마다, 3가지 경우씩이 존재한다. 따라서, 많아야 150만개를 갱신하게 됨
//dif가 늘어나게 하는 경우와
//그대로인 경우와
//|dif - 현재값|의 경우가 존재함.
//|dif - 현재값|이 0이되는 경우는 이미 cache[N-1][현재값] 체크하는 경우에 고려되므로 따로 추가하지 않는다.

//다음 블럭을 조사할 때 마다, cache[][] 에서 값이 존재하는 것만 추가 cache[][]>0인 경우들만

//현재조사하는 N번째 블럭까지 모두 더한 값을 저장해두고 50만까지가 아니라 그 값까지만 조사할 수 있도록 하여 시간절약


int totalSum;
int input[50+5];
int main(void) {
	int N;
	//initialize
	totalSum = 0;
	scanf("%d",&N);
	//input의 조건은 50보다 작거나 같은 자연수, 0이 나올 수 없음에 유의
	for(int i=0;i<N;i++) 
		scanf("%d",&input[i]);
	//초기값 처리
	cache[0][input[0]] = input[0];
	totalSum = input[0];

	//i는 1부터시작함에 유의
	for(int i=1;i<N;i++) {
		int curVal = input[i];
		totalSum += curVal;
		if(totalSum > MAX_VAL)
			totalSum = MAX_VAL;
		//만일 N-1번째 까지의 블럭으로 현재값을 만들 수 있다면
		if(cache[i-1][curVal] > 0 ) {
			int tmp = (cache[i-1][curVal] + curVal) / 2; 
			if(height < tmp)
				height = tmp;
		}
		//i-1번째 블럭까지 모두 선택되지 않고, 현재블럭만 선택된 경우
		cache[i][curVal] = curVal;

		//cache에 존재하는 값들에 대해서 갱신
		for(int j=0;j<=totalSum;j++) { //j는 0부터!, 그전에 높이가 같아지는 경우가 생길 수도 있다.
			if(cache[i-1][j] > 0) {	// >= 0 이 아니라 > 0 왜냐하면, 기본적으로 0값이 초기화되어 있기 때문(방문안한상태)
			 	int tmp = cache[i-1][j];
			 	if(j + curVal <= MAX_VAL && cache[i][j + curVal] < tmp + curVal)
			 		cache[i][j + curVal] = tmp + curVal;	//모두 다 골랐을 때의 값을 저장함
				if(cache[i][abs(j - curVal)] < tmp + curVal)
					cache[i][abs(j - curVal)] = tmp + curVal;	//현재 값을 역시나 선택한 경우니까 들어가는 값은 합을 해야한다.
				if(cache[i][j] < tmp)
					cache[i][j] = tmp;		//현재 값은 선택 안함
			}
		}
	}

	printf("%d\n", height);

	return 0;
}
