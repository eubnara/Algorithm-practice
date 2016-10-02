/*
	���������˰����� ����

	�ϳ��� �����ϰ� Ž���غ��� O(n^2) �˰��� ���� ��𿡼� ������ �Ǵ°ɱ�?
	����� ���� �� ������ �ǳʰ��� ���簢���� ���̸� ���ϴµ� �ִ�.
	���ʰ� ������ �� ���̰� ū ���� �����ؼ� Ȯ���� ������, ���� ������ n��ŭ ������ �Ǵ��غ��� �ȴ�.
	������, �����ϰ� Ž���غ��� ���� �ʺ� ���� ��츦 ��� üũ�غ��� �ȴ�.
	���� ���, ��ü ���̰� 8�ε�, �ʺ� 3�� ��츦 ��� ��ĭ�� ������ 2���� ��츦 ��� üũ�Ѵ�.
	�ݸ�, �������� �˰��򿡼��� �ʺ� 3�� ���� �Ѱ����� Ž���ϸ� �ȴ�. ���̰� ū ���� �����ϴ� ���� ���� ū �ʺ� ��Ÿ���ٴ� ���� ������ �� �����ϱ�(�ͷ���)

	����ư �� �����ϴ� �������� ������ �߻��Ͽ�, ��ü������ �������� ���̴�.

	���������� Ǯ��� Ȯ���ѵ� �� �̷��� �ʹ��� ������?
	���������� Ǯ��� ����� �ŷ��غ���?
	�̷��� �̹� ��� �� ����, �̷��� �ߺ��� �����ϴ� ����� ���� �˾Ƴ� �� ������?
	ó������ �ߺ��̶�� �������� �ʾҴ�.

	��� �߰��ұ�?

	���� �ӿ� ���� �ִ� ���ϱ�?
	������ ���� ��, �ش� �ʺ񿡼� ���� ���� ���̸� �������� ���̰� �����Ǵϱ�?
	���̰� ū ������ Ŀ�� �� �ۿ� ����?

	���� �ӿ��� ���� ã���� �غ���, �� �κп��� ���� �̵��� ������ üũ�غ���.

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
	�ӽ��� �κ������� �߶� ���� �� �ִ� ���簢���� �ִ� ũ�⸦ ��ȯ�Ѵ�.
	 �� �ӽ����� ���̴� �������� height[MAX+10]�� ����Ǿ� �ִ�.
	 left, right�� ���� ���簢���� �غ��� ���� ���� ������ �� ������ ��Ÿ����.

	 basecase�� �غ��� 1�� ���
*/
int solve(int left, int right) {
	//basecase
	if (left == right)
		return height[left];
	int midPos = (left + right) / 2;
	int maxVal;	//�ʱ�ȭ�� ���̷������ ������ �Ʒ� ����� ������� ó������ ���� �����̴�.

	//������ ���� �� ������ ���������� ���簢���� ���̸� ���ϴ� �κ�
	int start, end;
	start = midPos;
	end = midPos + 1;
	int curWidth = 2;	//���� �غ�
	int curHeight = min(height[start], height[end]);	//���� �ּ� ����, ������ �ӽ� ���� �� ��, ���� ���� �ӽ��� ���̿� ������ ���߾�� ��.
	int curSize = 0;
	while (1) {
		curSize = max(curSize, curWidth*curHeight);


		if (start == left && end == right) {
			break;
		}
		else {
			curWidth++;	//���� ĭ�� ���̸� ����� ��, �غ��� 1 �þ��.

			
			if (start == left) {
				end++;	//������ ���� ���������Ƿ� �������� �ø���.
				curHeight = min(curHeight, height[end]);	//���� ����
			}
			else if (end == right) {
				start--;	//�������� ���� ���������Ƿ� ������ �ø���. start--; �ӿ� ����
				curHeight = min(curHeight, height[start]);	//���� ����
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