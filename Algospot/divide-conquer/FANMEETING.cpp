#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


vector<int> karatsba(vector<int>& a, vector<int>& b);
void addTo(vector<int>& a, const vector<int>& b, int k);
void subFrom(vector<int>& a, const vector<int>& b);
vector<int> multiply(const vector<int>& a,const vector<int>& b);
void normalize(vector<int>& num);
int solve(const string& members, const string& fans);


int main(void) {
	int T;
	cin >> T; getchar();
	while (T--) {
		string members, fans;
		getline(cin, members);
		getline(cin, fans);
		cout << solve(members, fans) << endl;
	}
	return 0;
}

vector<int> karatsba(vector<int>& a, vector<int>& b) {
	int an, bn;
	an = a.size();
	bn = b.size();
	//base case
	if (an == 0 || bn == 0)
		return vector<int>();
	
	//base case
	if (an < bn) {
		return karatsba(b, a);
	}

	if (an <= 50) return multiply(a, b);

	int half = an / 2;

	//a1, a0, b1, b0
	vector<int> a1(a.begin() + half, a.end());
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> b1(b.begin() + min<int>(b.size(),half), b.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));

	
	vector<int> z2,z1,z0;
	
	//a1*b1
	z2 = karatsba(a1, b1);
	//a0*b0
	z0 = karatsba(a0, b0);
	
	//a1+=a0;
	addTo(a1, a0, 0);
	//b1+=b0;
	addTo(b1, b0, 0);
	//(a1+a0) * (b1+b0)
	z1 = karatsba(a1, b1);
	subFrom(z1, z0);
	subFrom(z1, z2);
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;	
}

//a += b * 10^k
void addTo(vector<int>& a,const vector<int>& b, int k) {
	int an = a.size();
	int bn = b.size();

	if (an < bn) {
		for (int i = 0; i < (bn - an); i++){
			a.push_back(0);
		}
	}

	for (int i = 0; i < bn; i++) {
		a[k + i] += b[i];
	}
	normalize(a);
}

//a -= b		a>=b를 가정한다.
void subFrom(vector<int>& a,const vector<int>& b) {
	int an = a.size();
	int bn = b.size();
	if (an < bn) {
		for (int i = 0; i < (bn - an); i++){
			a.push_back(0);
		}
	}
	for (int i = 0; i < bn; i++) {
		a[i] -= b[i];
	}
	normalize(a);
}

//자릿수가 그렇게 많지 않을 때의 기본 곱셈
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < b.size(); j++)
			c[i + j] += a[i] * b[j];
	normalize(c);
	return c;
}

void normalize(vector<int>& num) {
	int size = num.size();
	num.push_back(0);
	for (int i = 0; i < size; i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += (num[i] / 10);
			num[i] %= 10;
		}
	}
	//비어있는 상태에서 .back() 메소드를 접근하면 undefined behavior
	while (num.size() > 1 && num.back() == 0) { num.pop_back(); }
}

//전체 팀원이 한꺼번에 악수를 한 경우의 수를 반환 함.
int solve(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; i++) A[i] = (members[i] == 'M');
	for (int i = 0; i < M; i++) B[M - i - 1] = (fans[i] == 'M');

	vector<int> C = karatsba(A, B);
	int cn = C.size();
	int allHugs = 0;
	for (int i = N - 1; i < M; i++){
		if (cn <= i){
			++allHugs;
		}
		else if (C[i] == 0)
			++allHugs;
	}
		
	return allHugs;
}