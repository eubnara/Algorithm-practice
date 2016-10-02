#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int halfUp(int a);


typedef struct company{
	int member;
	int budget;
	int* per;

}COMPANY;
int main(){
	int testCases;
	int i,j,k;
	scanf("%d", &testCases);
	COMPANY* com = (COMPANY*)malloc(sizeof(COMPANY)*testCases);
	
	
	for (i = 0; i < testCases; i++){
		scanf("%d %d", &com[i].member, &com[i].budget);
		com[i].per = (int*)malloc(sizeof(int)*com[i].member);
		for (j = 0; j < com[i].member; j++){
			scanf("%d", &com[i].per[j]);
		}
	}

	for (i = 0; i < testCases; i++){
		int percent=0;

		while (1){
			for (j = 0; j < com[i].member; j++){
				for (k = j + 1; k < com[i].member; k++){
					if (com[i].per[j] < com[i].per[k]){
						int temp = com[i].per[j];
						com[i].per[j] = com[i].per[k];
						com[i].per[k] = temp;
					}
				}
			}






			int wage = 0;
			
			for (j = 0; j < com[i].member; j++){
				wage += halfUp((int)(com[i].budget*((double)com[i].per[j] / 100)));
			}
			if (wage == com[i].budget){
				printf("%d\n", percent);
				break;
			}
			else if (wage > com[i].budget){
				int* smallestP = &com[i].per[com[i].member-1];
				(*smallestP)--;
				com[i].per[1]++;
				percent++;
			}
			else if (wage < com[i].budget){
				int* largestP = &com[i].per[0];
				(*largestP)++;
				com[i].per[com[i].member - 2]--;
				percent++;
			}

			
		}
	}






	for (i = 0; i < testCases; i++){
		free(com[i].per);
	}
	free(com);
	return 0;
}

int halfUp(int a){
	int quotient;
	quotient = a / 100;
	if (a % 100 >= 50){
		quotient +=1;
		return quotient * 100;
	}
	else{
		return quotient*100;
	}
}
