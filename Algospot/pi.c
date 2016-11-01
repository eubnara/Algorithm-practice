#include <stdio.h>
#include <string.h>

#define MAX_VAL 987654321
#define MIN(x,y) ((x) < (y) ? (x) : (y))
int cache[10000+50];		//해당 문자열의 위치까지 최소 몇 난이도가 걸리는지 저장
char input[10000+50];

int totalLen;	//입력받은 숫자의 최대 길이
/* 
 * start의 위치부터 len 길이 테스트, len = 3,4 or 5
 * 난이도 반환
 */
int testDiff(char* start, int len);

int main(void) {
	int testCases;

	scanf("%d",&testCases);
	while(testCases--) {
		//초기화, 인덱스는 1부터 시작하는 것으로 통일
		scanf("%s",input+1);
		totalLen = strlen(input+1);
		cache[0] = 0; //실제 문자열은 아니지만, for문의 계산에서 필요
		cache[1] = 0;
		cache[2] = 0;
		for(int i=3;i<=totalLen;i++) 
			cache[i] = MAX_VAL;

		cache[3] = testDiff(input+1,3);
		cache[4] = testDiff(input+1,4);
		cache[5] = testDiff(input+1,5);
		cache[6] = testDiff(input+4,3) + cache[3];
		cache[7] = MIN(cache[3] + testDiff(input+4,4), cache[4] + testDiff(input+5,3));
		for(int i=8;i<=totalLen;i++) {
			cache[i] = MIN(cache[i], cache[i-3] + testDiff(input+i-2,3));
			cache[i] = MIN(cache[i], cache[i-4] + testDiff(input+i-3,4));
			cache[i] = MIN(cache[i], cache[i-5] + testDiff(input+i-4,5));
		}
		
		printf("%d\n",cache[totalLen]);
	}

	

	return 0;
}


//입력받은 숫자의 범위체크는 이 함수를 호출하기 전에 이루어진다.
int testDiff(char* start, int len) {
	char cur = start[0];
	int dif;	//숫자의 차이

	//같은 숫자인 경우
	if(cur == start[1]) {
		for(int i=2; i < len; i++) {
			if(cur != start[i])
				return 10;
		}
		return 1;
	}

	dif = start[1] - cur;

	
	if(dif == (start[2] - start[1])) {
		//등차수열, 1씩 단조증가, 단조감소 포함
		for(int i = 3; i < len; i++) {
			if(dif != (start[i] - start[i-1]))
				return 10;
		}
		if((1==dif) || (-1==dif))
			return 2;
		else
			return 5;
	} 
	else if( (-dif) == (start[2] - start[1])) {
		//dif = -dif; //오류 이게 여기 있으면 안돼, 반복문 안으로 들어가야 해
		//두 개의 숫자가 번갈아 나타나는가?
		for(int i = 3; i < len; i++) {
			dif = -dif;
			if((-dif) != (start[i] - start[i-1]))
				return 10;
		}
		return 4;
	}
	else
		return 10;
}
