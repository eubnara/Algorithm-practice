#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct use{
	int goal;
	int input[9];
}USE;
int main(){
	int T;
	scanf("%d", &T);
	USE* building = (USE*)malloc(sizeof(USE)*T);
	int i,j;
	for (i = 0; i < T; i++){
		scanf("%d", &building[i].goal);
		for (j = 0; j < 9; j++){
			scanf("%d", &building[i].input[j]);
		}
	}

	for (i = 0; i < T; i++){
		int check = 0;
		for (j = 0; j < 9; j++){
			check+= building[i].input[j];
		}
		if (building[i].goal >= check){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	free(building);
	return 0;
}