#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int cases,i,j;
	scanf("%d", &cases);
	char** result = (char**)malloc(sizeof(char*)*cases);
	for (i = 0; i < cases; i++){
		result[i] = (char*)malloc(sizeof(char) * 80);
	}
	char inputStr[80];
	char resultStr[80];
	for(i=0;i<cases;i++){
		inputStr[0] = '\0';
		resultStr[0] = '\0';
		scanf("%s", inputStr);		
		int k=0;
		for (j = 0; j < strlen(inputStr); j++){
			if (inputStr[j] == '%'){
				if (inputStr[j + 1] == '2'){
					switch (inputStr[j + 2]){
					case '0':
						resultStr[k] = ' ';
						break;
					case '1':
						resultStr[k] = '!';
						break;
					case '4':
						resultStr[k] = '$';
						break;
					case '5':
						resultStr[k] = '%';
						break;
					case '8':
						resultStr[k] = '(';
						break;
					case '9':
						resultStr[k] = ')';
						break;
					case 'a':
						resultStr[k] = '*';
						break;						
					}
				}
				j += 2;
			}
			else{
				resultStr[k] = inputStr[j];
			}
			k++;
		}
		resultStr[k] = '\0';

		strncpy(result[i], resultStr,strlen(resultStr)+1);
	}
	for (i = 0; i < cases; i++){
		printf("%s\n", result[i]);
	}
	

	for (i = 0; i < cases; i++){
		free(result[i]);
	}
	free(result);
	return 0;
}