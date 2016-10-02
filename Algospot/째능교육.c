#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int translate(char* inputs);

int main(){
	int cases;
	int i;
	scanf("%d", &cases);
	int* result = (int*)malloc(sizeof(int)*cases);
	char num1[11];
	char num2[11];
	char oper1;
	char oper2;
	char num3[11];
	for(i=0;i<cases;i++){
		num1[0] = '\0';
		num2[0] = '\0';
		num3[0] = '\0';
		oper1 = '\0';
		oper2 = '\0';
		scanf("%s %c %s %c %s", num1, &oper1, num2, &oper2, num3);
		if (oper1 == '+' && oper2 == '=' ){
			if ((translate(num1) + translate(num2)) == translate(num3))
				result[i] = 1;
			else
				result[i] = -100;
		}
		else if (oper1 == '-'&&oper2 == '='){
			if ((translate(num1) - translate(num2)) == translate(num3))
				result[i] = 1;
			else
				result[i] = -100;
		}
		else if (oper1 == '*' && oper2 == '='){
			if ((translate(num1) * translate(num2)) == translate(num3))
				result[i] = 1;
			else
				result[i] = -100;
		}
		else{
			result[i] = -100;
		}
	}
	for (i = 0; i < cases; i++){
		if (result[i] == 1)
			printf("Yes\n");
		else if (result[i] == -100)
			printf("No\n");
		else
			printf("ERROR\n");
	}
	free(result);
	return 0;
}

int translate(char* inputs){
	int alpha[26] = { 0, };
	int i;
	for (i = 0; i < strlen(inputs); i++){
		if (inputs[i] >= 'a' || inputs[i] <= 'z'){
		}
		switch (inputs[i]){
		case 'a':
			alpha[0]++;
			break;

		case 'b':
			alpha[1]++;
			break;

		case 'c':
			alpha[2]++;
			break;

		case 'd':
			alpha[3]++;
			break;

		case 'e':
			alpha[4]++;
			break;

		case 'f':
			alpha[5]++;
			break;

		case 'g':
			alpha[6]++;
			break;

		case 'h':
			alpha[7]++;
			break;

		case 'i':
			alpha[8]++;
			break;

		case 'j':
			alpha[9]++;
			break;

		case 'k':
			alpha[10]++;
			break;

		case 'l':
			alpha[11]++;
			break;

		case 'm':
			alpha[12]++;
			break;

		case 'n':
			alpha[13]++;
			break;

		case 'o':
			alpha[14]++;
			break;

		case 'p':
			alpha[15]++;
			break;

		case 'q':
			alpha[16]++;
			break;

		case 'r':
			alpha[17]++;
			break;

		case 's':
			alpha[18]++;
			break;

		case 't':
			alpha[19]++;
			break;

		case 'u':
			alpha[20]++;
			break;

		case 'v':
			alpha[21]++;
			break;

		case 'w':
			alpha[22]++;
			break;

		case 'x':
			alpha[23]++;
			break;

		case 'y':
			alpha[24]++;
			break;

		case 'z':
			alpha[25]++;
			break;
		
		}
	}
	if (strlen(inputs) > 5 || strlen(inputs) < 3){
		return -1;
	}
	else if (strlen(inputs) == 3){
		if (alpha[4] == 1 && alpha[13] == 1 && alpha[14] == 1){
			return 1;
		}
		else if (alpha[19] == 1 && alpha[22] == 1 && alpha[14] == 1){
			return 2;
		}
		else if (alpha[18] == 1 && alpha[8] == 1 && alpha[23] == 1){
			return 6;
		}
		else if (alpha[19] == 1 && alpha[4] == 1 && alpha[13] == 1){
			return 10;
		}
	}
	else if (strlen(inputs) == 4){
		if (alpha[25] == 1 && alpha[4] == 1 && alpha[17] == 1 && alpha[14] == 1){
			return 0;
		}
		else if (alpha[5] == 1 && alpha[14] == 1 && alpha[20] == 1 && alpha[17] == 1){
			return 4;
		}
		else if (alpha[5] == 1 && alpha[8] == 1 && alpha[21] == 1 && alpha[4] == 1){
			return 5;
		}
		else if (alpha[13] == 2 && alpha[8] == 1 && alpha[4] == 1){
			return 9;
		}
	}
	else if (strlen(inputs) == 5){
		if (alpha[19] == 1 && alpha[7] == 1 && alpha[17] == 1 && alpha[4] == 2){
			return 3;
		}
		else if (alpha[18] == 1 && alpha[4] == 2 && alpha[21] == 1 && alpha[13] == 1){
			return 7;
		}
		else if (alpha[4] == 1 && alpha[8] == 1 && alpha[6] == 1 && alpha[7] == 1 && alpha[19] == 1){
			return 8;
		}
	}
	return -100;
}