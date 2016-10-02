/*
	분할정복알고리즘의 적용

	하나씩 무식하게 탐색해보는 O(n^2) 알고리즘 보다 어디에서 절약이 되는걸까?
	비밀은 나눈 두 영역을 건너가는 직사각형의 넓이를 구하는데 있다.
	왼쪽과 오른쪽 중 높이가 큰 쪽을 선택해서 확장해 나가면, 가로 길이인 n만큼 개수만 판단해보게 된다.
	하지만, 무식하게 탐색해보는 경우는 너비가 같은 경우를 모두 체크해보게 된다.
	예를 들면, 전체 길이가 8인데, 너비가 3인 경우를 가운데 두칸을 포함한 2가지 경우를 모두 체크한다.
	반면, 분할정복 알고리즘에서는 너비가 3인 경우는 한가지만 탐색하면 된다. 높이가 큰 쪽을 선택하는 것이 가장 큰 너비를 나타낸다는 것을 증명할 수 있으니까(귀류법)

	여하튼 이 선택하는 과정에서 절약이 발생하여, 전체적으로 빨라지는 것이다.

	수식적으로 풀어보면 확실한데 왜 이렇게 와닿지 않을까?
	수식적으로 풀어보는 방법을 신뢰해볼까?
	이렇게 이미 배운 것 말고도, 이러한 중복을 무시하는 방법을 내가 알아낼 수 있을까?
	처음에는 중복이라고 느껴지지 않았다.

	어떻게 발견할까?

	문제 속에 답이 있는 것일까?
	문제의 조건 상, 해당 너비에서 가장 작은 높이를 기준으로 넓이가 생성되니까?
	높이가 큰 쪽으로 커질 수 밖에 없는?

	문제 속에서 답을 찾으려 해보고, 그 부분에서 취할 이득이 없는지 체크해보자.

*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 20000



int height[MAX+10];

int solve(int left, int right);

int main(void){
	int T,N;	//T: num. of testcases, N: num. of fences
	cin >> T;
	while (T--) {
		cin >> N;
		memset(height, 0, sizeof(int)*N);
		for (int i = 0; i < N; i++) {
			cin >> height[i];
		}
		cout << solve(0, N-1) << endl;
	}

	return 0;
}


/*
	휀스를 부분적으로 잘라 만들 수 있는 직사각형의 최대 크기를 반환한다.
	 각 휀스들의 높이는 전역변수 height[MAX+10]에 저장되어 있다.
	 left, right는 각각 직사각형의 밑변의 왼쪽 끝과 오른쪽 끝 범위를 나타낸다.

	 basecase는 밑변이 1인 경우
*/
int solve(int left, int right) {
	//basecase
	if (left == right)
		return height[left];
	int midPos = (left + right) / 2;
	int maxVal;	//초기화가 안이루어지는 이유는 아래 계산의 결과값이 처음으로 들어가기 때문이다.

	//반으로 나눈 두 영역을 가로지르는 직사각형의 넓이를 구하는 부분
	int start, end;
	start = midPos;
	end = midPos + 1;
	int curWidth = 2;	//현재 밑변
	int curHeight = min(height[start], height[end]);	//현재 최소 높이, 합쳐진 휀스 여러 장 중, 가장 작은 휀스의 높이에 기준을 맞추어야 함.
	int curSize = 0;
	while (1) {
		curSize = max(curSize, curWidth*curHeight);


		if (start == left && end == right) {
			break;
		}
		else {
			curWidth++;	//다음 칸의 넓이를 계산할 때, 밑변이 1 늘어난다.

			
			if (start == left) {
				end++;	//왼쪽은 끝에 도달했으므로 오른쪽을 늘린다.
				curHeight = min(curHeight, height[end]);	//높이 갱신
			}
			else if (end == right) {
				start--;	//오른쪽은 끝에 도달했으므로 왼쪽을 늘린다. start--; 임에 유의
				curHeight = min(curHeight, height[start]);	//높이 갱신
			}
			else {
				if (height[start - 1] < height[end + 1]) {
					end++;
					curHeight = min(curHeight, height[end]);
				}
				else {
					start--;
					curHeight = min(curHeight, height[start]);
				}
			}
		}
	}


	maxVal = max(solve(left, midPos), solve(midPos + 1, right));
	maxVal = max(maxVal, curSize);
	return maxVal;
}