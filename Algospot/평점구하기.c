#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
	int num;
	printf("�� ����? : ");
	scanf("%d", &num);
	printf("\n4.5���� ���� ���α׷�\n");
	printf("-----------\n");
	printf("A+ : 4.5\n");
	printf("A  : 4.0\n");
	printf("B+ : 3.5\n");
	printf("B  : 3.0\n");
	printf("C+ : 2.5\n");
	printf("C  : 2.0\n");
	printf("D+ : 1.5\n");
	printf("D  : 1.0\n");
	printf("F  : 0\n");
	printf("-----------\n");
	printf("�� �ٴ� �� ���� ������ ������ �Է��ϼ���. \n ex)3���� ¥�� A+�̶��  3 A+ �̶�� �Է�(�ҹ��ڵ� ����)\n");
	int i;

	double totalGrade=0;
	double totalScore = 0;

	for (i = 0; i < num; i++){
		int grade=0;
		char score[3] = { '\0' };
		double x=0;
		scanf("%d %s",&grade, score);
		score[0] = toupper(score[0]);
		totalGrade += grade;
		switch (score[0]){
		case 'A':
			x += 4.0 ;
			break;
		case 'B':
			x += 3.0 ;
			break;
		case 'C':
			x += 2.0 ;
			break;
		case 'D':
			x += 1.0;
			break;
		case 'F':
			break;
		}
		if (strlen(score) == 2 && score[1] == '+'){
			x += 0.5;
		}
		totalScore = totalScore + (x*grade);
	}
	printf("�� ���� : %.5lf\n", totalScore / totalGrade);

	return 0;
}