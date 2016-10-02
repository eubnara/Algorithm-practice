/*
	후기:

	처음에는 문제를 파악하며 다른 접근법을 시도하려 했으나, 알고리즘 문제해결전략의 책에서 완전탐색 단원에 나와있는 대로
	무식하게 한 번 풀어보았다. 컴퓨터는 충분히 빠르기 때문에, 생각보다 단순한 알고리즘으로 풀 수 있다는 걸 간과하기 쉽다.
	이 문제의 특성을 맨 처음에 파악했을 때, 8,11,12,13,15번 시계가 스위치 1개에만 영향을 받는다는 점을 알아내고 그 점을 이용하여
	풀어보려했었다. 물론 그런 알고리즘을 쓰면 훨씬 더 금방 풀릴 것 같다. 하지만, 그런 알고리즘을 짜는 시간에, 무식하게 빠르게 코딩을 하여
	컴퓨터가 힘든 일을 할 수 있도록 하였다. 정말 책 설명이 와닿는 문제였다. '생각보다 컴퓨터는 빠르다'

	int watch; 라는 변수로 16개의 시계 상태를 32비트로 나타내는 시도를 해보았다.
	재밌었다. 비트마스크 기법을 스스로 써보긴 처음이었다.
	처음에는 main 함수에서 지역변수로 선언, single rotate와 totalRotate 함수에서 주소를 넘겨주어 사용할 수 있도록 하였었다.
	하지만, 속도가 꽤나 느려서 전역변수로 바꾸어 실행시키니 시간이 절반가량 줄었다.
	알고리즘 대회에서는 혹시 가능하다면, 문제이해를 해치지 않는 선에서 전역변수를 사용토록 하자.
	  비트마스크를 사용할 때는 주의를 요한다. 특히, 이번 문제에서 실수한 두 부분은 OR 연산과 AND 연산의 혼동이다.
	전체 비트 내에서 한 구역을 어떤 자료를 표현하는 기법을 사용할 시, 그 부분만 다른 값으로 바꿔줄 때, 꼭 주의하자.
	그 자리를 0으로 바꿔주고(초기화를 시켜주고) 원하는 값을 OR연산을 하도록 하자.
	OR연산은 그 자리에 있는 값을 내가 원하는 값으로 바꿔주는 것이 아니다!

	- 비트마스크 사용 시, 착각하지 말 것.
	- 가능하면 시간을 줄일 수 있도록 전역변수를 쓰자.
*/

/*
	오답노트:
	- AND, OR 연산을 착각하지 말 것
	- 이미 정해져있는 상수값들을 넣을 때, 실수하지 않도록 주의
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 2147483647

/*
	함수명: rotate
	argument: 
		button: 각 버튼을 눌렀을 때, 동작하는 시계들
		watch: 시계의 현재 상태를 나타내는 변수, 비트를 조작하여 사용한다. 
			0,3,6,9 4가지 상태가 있으므로 32비트 정수 int를 2비트씩 나누어 사용,
			32비트를 활용한다.
*/
void singleRotate(int numOfButton, int numOfRotate, bool dir);
void totalRotate(int curButton, int curClicked);
//답을 찾기 위해 스위치를 총 몇 번 클릭했는지 저장하는 함수, rotate 함수 사용 전 INF로 초기화한다.
int clicked = INF;
vector<int> button[10];
int watch;
int main(void) {
	int T; //the number of testcases
	cin >> T;
	//이미 정해져있는 버튼들의 동작을 미리 저장한다.
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
		//int watch = 0;	//16개의 시계의 상태를 표현할 32비트 정수형의 변수, 2개 비트당 1개의 시계를 나타낸다.
		watch = 0; //전역변수로 대체
		clicked = INF;
		//16개의 시계 세팅
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
			watch |= (input << (2 * i));	//해당하는 위치로 비트를 이동시킨 후에 watch와 or연산으로 시계 상태를 입력한다.
		}
		//반드시 clicked 변수는 사용전 INF로 초기화할 것
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

//인자: 버튼번호, 현재 시계들의 상태, 돌리는 횟수 90도씩 돌림, dir==1 시계방향, dir==0 반시계방향
void singleRotate(int numOfButton, int numOfRotate, bool dir) {
	int numOfWatch;	//버튼을 눌렀을 때 영향받는 시계를 가리킨다.
	//돌리는 횟수가 0인 경우
	if (numOfRotate == 0)
		return;

	//반시계방향으로 돌리는 경우는 시계방향으로 돌렸을 때로 바꿔준다.
	if (dir == 0)
		numOfRotate = 4 - numOfRotate;
	//버튼을 눌렀을 때 영향받는 시계들을 모두 돌리기 위하여 반복문
	for (int i = 0; i < button[numOfButton].size(); i++){
		numOfWatch = button[numOfButton][i];
		//int bitmask = ((curWatch) >> (numOfWatch << 1)) | 3; and연산 대신 or연산을 해서 오류를 냈었다.
		int bitmask = ((watch) >> (numOfWatch << 1)) & 3;	//numOfWatch * 2를 비트연산으로 바꾼 것, 32비트 중 2개의 비트씩 1개의 시계를 나타낸다는 점에 유의할 것
		bitmask += numOfRotate;
		bitmask &= 3;	//2개의 비트만 남긴다.
		//(*watch) |= (bitmask << (numOfWatch << 1)); 잘못된 코드, or연산을 하면 안된다. 그값을 대체시키는 것이기때문에.
		(watch) &= ~(3 << (numOfWatch << 1));	//해당하는 시계의 비트 2개를 0으로 만든 후
		(watch) |= (bitmask << (numOfWatch << 1));	//만들어진 bitmask 로 or연산
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
		singleRotate(curButton, i, 1);	//curButton을 i번 클릭하여 시계들을 시계방향으로 돌림
		totalRotate(curButton + 1, curClicked + i);	//i번 만큼 클릭한 횟수를 더해주어 자기 자신을 호출, 다음 버튼을 체크
		singleRotate(curButton, i, 0);	//curButton을 i번 클릭하기 전으로 돌아감
	}
}