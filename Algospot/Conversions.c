#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void unit_conv(double* num, char* unit);
int main(void) {

	int testcase;
	int datasetNum = 1;
	double num;
	char unit[3];
	scanf("%d", &testcase);
	while (testcase--){
		unit[0] = 0;	//null 문자로 세팅
		scanf("%lf %s", &num, unit);
		unit_conv(&num, unit);
		printf("%d %.4lf %s\n",datasetNum, num, unit);
		datasetNum++;
	}
	return 0;
}

void unit_conv(double* num, char* unit) {
	if (strcmp("kg", unit) == 0) {
		unit[0] = 'l';
		unit[1] = 'b';
		*num *= 2.2046;
	}
	else if (strcmp("lb", unit) == 0){
		unit[0] = 'k';
		unit[1] = 'g';
		*num *= 0.4536;
	}
	else if (strcmp("l", unit) == 0) {
		unit[0] = 'g';
		*num *= 0.2642;
	}
	else if (strcmp("g", unit) == 0){
		unit[0] = 'l';
		*num *= 3.7854;
	}
}