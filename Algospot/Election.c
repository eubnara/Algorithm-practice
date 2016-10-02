#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//structure 내부에선 동적할당이 안되는듯?
//candidate 수는 5명이 최고니까, 5개까지 받을 수 있는 정수형 변수를 선언.
typedef struct group{
	int total;
	int preferSeq[5];
	//기본 초기화는 0? 초기화가 안되네

}GROUP;

int main(){
	int answer[100] = { 0 };
	int check = 0;
	while (1){
		unsigned int i, j;
		//candidate 수, Group 수를 받는다.
		unsigned int G;
		unsigned int N;
		scanf("%d %d", &G, &N);
		if (G == 0 || N == 0){
			break;
		}
		//candidate가 줄어갈 때, 남은 candidate 수를 세기위한 변수
		unsigned int leftN = N;

		//순위를 정하기 위한 각 candidate의 득표비교용 변수
		//N+1을 곱해준 이유는 기호번호랑 배열번호랑 맞춰주려는 편의상. (따라서, 0번째 배열은 의미없는자리)
		int* cmpCand = (int*)malloc(sizeof(int)*(N + 1));
		//cmpCand의 초기화, 나중에 제거되면 -1을 넣을거다.
		for (i = 0; i < N + 1; i++){
			*(cmpCand + i) = 0;
		}
		//라인마다 Group의 총 인원과 preference 순서를 보여줌
		GROUP* groupPtr = (GROUP*)malloc(sizeof(GROUP)*G);
		for (i = 0; i < G; i++){
			scanf("%d", &((groupPtr + i)->total)); //&뒤에 괄호를 써줘야하는지 체크
			for (j = 0; j < N; j++){
				scanf("%d", &((groupPtr + i)->preferSeq[j]));
			}
		}

		while (leftN != 1){
			//first choices of M people을 일단 대입
			for (i = 0; i < G; i++){
				for (j = 0; j < N; j++){
					if ((groupPtr + i)->preferSeq[j] == 0){
						continue;
					}
					else{
						cmpCand[((groupPtr + i)->preferSeq[j])] += (groupPtr + i)->total;
						break;
					}
				}
			}


			//least popular 찾기 cmpCand는 1부터 시작(기호 번호와 동일), num은 least popular가 저장될 해당 기호번호
			//cmpPtr은 해당 값을 -1로 바꿔주기위함.
			int* cmpPtr = NULL;
			int num = 1;
			for (i = 1; i < N + 1; i++){
				if (cmpCand[i] == -1){
					continue;
				}
				else{
					cmpPtr = &cmpCand[i];
				}
				for (j = i + 1; j < N + 1; j++){
					if (cmpCand[j] == -1){
						continue;
					}
					else if (*cmpPtr >= cmpCand[j]){
						cmpPtr = &cmpCand[j];
						num = i;
					}
				}
				break;

			}
			//least popular 없애기 cmpCand는 1부터 시작(기호 번호와 동일)
			//각 구조체의 preferSequence는 0으로, cmpCand 값은 -1로 변화
			for (i = 0; i < G; i++){
				for (j = 0; j < N; j++){
					if (num == (groupPtr + i)->preferSeq[j]){
						(groupPtr + i)->preferSeq[j] = 0;
					}
				}
			}
			*(cmpPtr) = -1;

			//한 바퀴를 돌때마다 candidate는 줄어감
			leftN--;
			//없앤 candidate빼고는 투표수 다시 측정해야함
			for (i = 1; i < N + 1; i++){
				if (*(cmpCand + i) != -1){
					*(cmpCand + i) = 0;

				}

			}

		}
		
		for (i = 1; i < N + 1; i++){
			if (cmpCand[i] != -1){
				//printf("%d\n", i);
				answer[check] = i;
				check++;
			}
		}
		
		


		free(cmpCand);
		free(groupPtr);
	}
	int i;
	for (i = 0; i < 100; i++){
		if (answer[i] != 0)
			printf("%d\n", answer[i]);
	}
	return 0;
}