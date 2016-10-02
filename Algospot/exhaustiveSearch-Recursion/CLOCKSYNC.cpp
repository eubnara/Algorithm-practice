/*
	�ı�:

	ó������ ������ �ľ��ϸ� �ٸ� ���ٹ��� �õ��Ϸ� ������, �˰��� �����ذ������� å���� ����Ž�� �ܿ��� �����ִ� ���
	�����ϰ� �� �� Ǯ��Ҵ�. ��ǻ�ʹ� ����� ������ ������, �������� �ܼ��� �˰������� Ǯ �� �ִٴ� �� �����ϱ� ����.
	�� ������ Ư���� �� ó���� �ľ����� ��, 8,11,12,13,15�� �ð谡 ����ġ 1������ ������ �޴´ٴ� ���� �˾Ƴ��� �� ���� �̿��Ͽ�
	Ǯ����߾���. ���� �׷� �˰����� ���� �ξ� �� �ݹ� Ǯ�� �� ����. ������, �׷� �˰����� ¥�� �ð���, �����ϰ� ������ �ڵ��� �Ͽ�
	��ǻ�Ͱ� ���� ���� �� �� �ֵ��� �Ͽ���. ���� å ������ �ʹ�� ��������. '�������� ��ǻ�ʹ� ������'

	int watch; ��� ������ 16���� �ð� ���¸� 32��Ʈ�� ��Ÿ���� �õ��� �غ��Ҵ�.
	��վ���. ��Ʈ����ũ ����� ������ �Ẹ�� ó���̾���.
	ó������ main �Լ����� ���������� ����, single rotate�� totalRotate �Լ����� �ּҸ� �Ѱ��־� ����� �� �ֵ��� �Ͽ�����.
	������, �ӵ��� �ϳ� ������ ���������� �ٲپ� �����Ű�� �ð��� ���ݰ��� �پ���.
	�˰��� ��ȸ������ Ȥ�� �����ϴٸ�, �������ظ� ��ġ�� �ʴ� ������ ���������� ������ ����.
	  ��Ʈ����ũ�� ����� ���� ���Ǹ� ���Ѵ�. Ư��, �̹� �������� �Ǽ��� �� �κ��� OR ����� AND ������ ȥ���̴�.
	��ü ��Ʈ ������ �� ������ � �ڷḦ ǥ���ϴ� ����� ����� ��, �� �κи� �ٸ� ������ �ٲ��� ��, �� ��������.
	�� �ڸ��� 0���� �ٲ��ְ�(�ʱ�ȭ�� �����ְ�) ���ϴ� ���� OR������ �ϵ��� ����.
	OR������ �� �ڸ��� �ִ� ���� ���� ���ϴ� ������ �ٲ��ִ� ���� �ƴϴ�!

	- ��Ʈ����ũ ��� ��, �������� �� ��.
	- �����ϸ� �ð��� ���� �� �ֵ��� ���������� ����.
*/

/*
	�����Ʈ:
	- AND, OR ������ �������� �� ��
	- �̹� �������ִ� ��������� ���� ��, �Ǽ����� �ʵ��� ����
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 2147483647

/*
	�Լ���: rotate
	argument: 
		button: �� ��ư�� ������ ��, �����ϴ� �ð��
		watch: �ð��� ���� ���¸� ��Ÿ���� ����, ��Ʈ�� �����Ͽ� ����Ѵ�. 
			0,3,6,9 4���� ���°� �����Ƿ� 32��Ʈ ���� int�� 2��Ʈ�� ������ ���,
			32��Ʈ�� Ȱ���Ѵ�.
*/
void singleRotate(int numOfButton, int numOfRotate, bool dir);
void totalRotate(int curButton, int curClicked);
//���� ã�� ���� ����ġ�� �� �� �� Ŭ���ߴ��� �����ϴ� �Լ�, rotate �Լ� ��� �� INF�� �ʱ�ȭ�Ѵ�.
int clicked = INF;
vector<int> button[10];
int watch;
int main(void) {
	int T; //the number of testcases
	cin >> T;
	//�̹� �������ִ� ��ư���� ������ �̸� �����Ѵ�.
	//vector<vector<int>> button;
	button[0].push_back(0);
	button[0].push_back(1);
	button[0].push_back(2);
	
	button[1].push_back(3);
	button[1].push_back(7);
	button[1].push_back(9);
	button[1].push_back(11);
	
	button[2].push_back(4);
	button[2].push_back(10);
	button[2].push_back(14);
	button[2].push_back(15);

	button[3].push_back(0);	
	button[3].push_back(4);	
	button[3].push_back(5);
	button[3].push_back(6);	
	button[3].push_back(7);

	button[4].push_back(6);	
	button[4].push_back(7);
	button[4].push_back(8);	
	button[4].push_back(10); 
	button[4].push_back(12);

	button[5].push_back(0);
	button[5].push_back(2);
	button[5].push_back(14);
	button[5].push_back(15);

	button[6].push_back(3);
	button[6].push_back(14);
	button[6].push_back(15);

	button[7].push_back(4);
	button[7].push_back(5);
	button[7].push_back(7);
	button[7].push_back(14);
	button[7].push_back(15);

	button[8].push_back(1);
	button[8].push_back(2);
	button[8].push_back(3);
	button[8].push_back(4);
	button[8].push_back(5);

	button[9].push_back(3);
	button[9].push_back(4);
	button[9].push_back(5);
	button[9].push_back(9);
	button[9].push_back(13);

	while (T--) {
		//int watch = 0;	//16���� �ð��� ���¸� ǥ���� 32��Ʈ �������� ����, 2�� ��Ʈ�� 1���� �ð踦 ��Ÿ����.
		watch = 0; //���������� ��ü
		clicked = INF;
		//16���� �ð� ����
		for (int i = 0; i < 16; i++) {
			int input;
			cin >> input;
			switch (input) {
			case 12:
				input = 0;	//0b00
				break;
			case 3:
				input = 1;	//0b01
				break;
			case 6:
				input = 2;	//0b10
				break;
			case 9:
				input = 3;	//0b11
				break;
			default:
				printf("input error\n");
				exit(-1);
			}
			watch |= (input << (2 * i));	//�ش��ϴ� ��ġ�� ��Ʈ�� �̵���Ų �Ŀ� watch�� or�������� �ð� ���¸� �Է��Ѵ�.
		}
		//�ݵ�� clicked ������ ����� INF�� �ʱ�ȭ�� ��
		if (watch==0){
			printf("0\n");
		}
		else{
			totalRotate(0, 0);
			if (clicked == INF)
				printf("-1\n");
			else
				printf("%d\n", clicked);
		}
	}

	return 0;
}

//����: ��ư��ȣ, ���� �ð���� ����, ������ Ƚ�� 90���� ����, dir==1 �ð����, dir==0 �ݽð����
void singleRotate(int numOfButton, int numOfRotate, bool dir) {
	int numOfWatch;	//��ư�� ������ �� ����޴� �ð踦 ����Ų��.
	//������ Ƚ���� 0�� ���
	if (numOfRotate == 0)
		return;

	//�ݽð�������� ������ ���� �ð�������� ������ ���� �ٲ��ش�.
	if (dir == 0)
		numOfRotate = 4 - numOfRotate;
	//��ư�� ������ �� ����޴� �ð���� ��� ������ ���Ͽ� �ݺ���
	for (int i = 0; i < button[numOfButton].size(); i++){
		numOfWatch = button[numOfButton][i];
		//int bitmask = ((curWatch) >> (numOfWatch << 1)) | 3; and���� ��� or������ �ؼ� ������ �¾���.
		int bitmask = ((watch) >> (numOfWatch << 1)) & 3;	//numOfWatch * 2�� ��Ʈ�������� �ٲ� ��, 32��Ʈ �� 2���� ��Ʈ�� 1���� �ð踦 ��Ÿ���ٴ� ���� ������ ��
		bitmask += numOfRotate;
		bitmask &= 3;	//2���� ��Ʈ�� �����.
		//(*watch) |= (bitmask << (numOfWatch << 1)); �߸��� �ڵ�, or������ �ϸ� �ȵȴ�. �װ��� ��ü��Ű�� ���̱⶧����.
		(watch) &= ~(3 << (numOfWatch << 1));	//�ش��ϴ� �ð��� ��Ʈ 2���� 0���� ���� ��
		(watch) |= (bitmask << (numOfWatch << 1));	//������� bitmask �� or����
	}
}

void totalRotate(int curButton, int curClicked) {
	if (curButton == 10){
		if ((watch)==0){
			clicked = min(curClicked, clicked);
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		singleRotate(curButton, i, 1);	//curButton�� i�� Ŭ���Ͽ� �ð���� �ð�������� ����
		totalRotate(curButton + 1, curClicked + i);	//i�� ��ŭ Ŭ���� Ƚ���� �����־� �ڱ� �ڽ��� ȣ��, ���� ��ư�� üũ
		singleRotate(curButton, i, 0);	//curButton�� i�� Ŭ���ϱ� ������ ���ư�
	}
}