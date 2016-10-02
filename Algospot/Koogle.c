#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int main(){
	int i,j,k,testcase;
	scanf("%d", &testcase);
	char** result = (char**)malloc(sizeof(char*)*testcase);
	for (i = 0; i < testcase; i++){
		result[i] = (char*)malloc(sizeof(char) * 1000);
	}
	
	for (i = 0; i < testcase; i++){
		int N;
		scanf("%d", &N);
		
		char** pw = (char**)malloc(sizeof(char*)*N);
		for (j = 0; j < N; j++){
			pw[j] = (char*)malloc(sizeof(char) * 1000);
		}
		for (j = 0; j < N; j++){
			scanf("%s", pw[j]);
		}

		int* pwPower = (int*)malloc(sizeof(int)*N);
		//세기 측정해서 넣기

		for (j = 0; j < N; j++){

			int alpha = 0;
			int num = 0;
			int result = 0;
			for (k = 0; k < strlen(pw[j]); k++){
				if (isalpha(pw[j][k])){
					alpha++;
					continue;
				}
				else if (isdigit(pw[j][k])){
					num++;
					continue;
				}
			}
			result = (pow(25, alpha)) * (pow(10, num));
	
			//여기에 마지막엔 결과를 pwPower에 순서대로 넣어야 함.
			pwPower[j] = result;	

		}
		int key=0;
		for (j = 1; j < N; j++){
			if (pwPower[key] < pwPower[j]){
				key = j;
			}
			else if (pwPower[key] == pwPower[j]){
				if (strcmp(pw[key], pw[j]) > 0){
					key = j;
				}
			}
		}

		strncpy(result[i], pw[key], strlen(pw[key])+1);

		//저장된 pwPower를 비교하여 가장 큰( 같다면 사전순) 암호를 result에 넣어야함. strncpy?

		
		for (j = 0; j < N; j++){
			free(pw[j]);
		}
		free(pw);
		free(pwPower);
		
	}
	
	for (i = 0; i < testcase; i++){
		printf("%s\n", result[i]);
	}
	for (i = 0; i < testcase; i++){
		free(result[i]);
	}
	free(result);
	return 0;
}