#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int C;
	cin >> C;
	int* ans = new int[C];
	int idx = 0;
	while (C-idx)
	{
		int A, B, N;
		long long unsigned int sum = 0;
		cin >> A >> B >> N;

		for (int i = A; i <= B; i++)
		{
			sum = (sum  + (long long)pow(N, i));	//(int)pow(N, i) �� ����.. int �� ĳ�����ϴϱ� �ڲ� truncate �� ��. ������ ū ������ long long �� ����ϴµ�.
		}
		ans[idx] = sum % 1000000007;
		idx++;
	}
	for (int j = 0; j < idx; j++)
		cout << ans[j]<<endl;
	
	return 0;
}