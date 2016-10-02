#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct group{
	int total;
	int preferSeq[5];


}GROUP;

int main(){
	int answer[100] = { 0 };
	int check = 0;
	while (1){
		int i, j;

		int G;
		int N;
		scanf("%d %d", &G, &N);
		if (G == 0 || N == 0){
			break;
		}

		int leftN = N;


		int* cmpCand = (int*)malloc(sizeof(int)*(N + 1));

		for (i = 0; i < N + 1; i++){
			*(cmpCand + i) = 0;
		}

		GROUP* groupPtr = (GROUP*)malloc(sizeof(GROUP)*G);
		for (i = 0; i < G; i++){
			scanf("%d", &((groupPtr + i)->total));
			for (j = 0; j < N; j++){
				scanf("%d", &((groupPtr + i)->preferSeq[j]));
			}
		}

		while (leftN != 1){

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



			int *cmpPtr = NULL;
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

			for (i = 0; i < G; i++){
				for (j = 0; j < N; j++){
					if (num == (groupPtr + i)->preferSeq[j]){
						(groupPtr + i)->preferSeq[j] = 0;
					}
				}
			}
			*(cmpPtr) = -1;


			leftN--;

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
	for (i = 0; i < check; i++){
		if (answer[i] != 0)
			printf("%d\n", answer[i]);
	}
	return 0;
}

