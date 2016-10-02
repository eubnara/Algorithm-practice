//switch 활용
#include <iostream>
#include <list>
#include <cstring>
using namespace std;


int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		char transcribed[100];
		char priorListLeft[4];
		char priorListRight[4];
		cin >> transcribed;
		for (int i = 3; i >= 0; i--)			//나중에 인덱스 번호가 큰 것이 priority 가 높은 것을 나타내기 위해 거꾸로 for 문을 돌렸다. 또한 상응하는 오른쪽 괄호들도 만들어주었다.
		{
			cin >> priorListLeft[i];
			switch (priorListLeft[i])
			{
			case '{':
				priorListRight[i] = '}';
				break;
			case '[':
				priorListRight[i] = ']';
				break;
			case '<':
				priorListRight[i] = '>';
				break;
			case '(':
				priorListRight[i] = ')';
				break;
			}
		}
		
		/*
		아래 과정을 입력받은 transcribed 개수만큼 반복한다.

		1. 한 글자를 doubly linked list 에 넣는다.(front 에)
		2. 왼쪽 괄호와 오른쪽 괄호의 개수가 같아질 때 까지 리스트에 넣는다.
		3. 개수가 확인되면, 앞 뒤로 하나씩 접근하여 고쳐준다.
		4. 다 고친 후에, 출력한다.
		
		*/
		std::list<char> leftList;
		std::list<char> rightList;
		int len = strlen(transcribed);
		int left = 0, right = 0;
		for (int i = 0; i < len; i++)
		{
			//위 for 구문이 시작될 때, left, right 는 0 이지만, 일단 어떤 괄호든 하나를 넣고 시작하면 left == right == 0 인 경우는 switch 구문 이후에 생겨날 수 없다.
			switch (transcribed[i])
			{
			case '{':
			case '<':
			case '[':
			case '(':
				left++;
				leftList.push_back(transcribed[i]);		//왼쪽 괄호는 앞쪽에 넣어준다.
				break;
			case '}':
			case '>':
			case ']':
			case ')':
				right++;
				rightList.push_back(transcribed[i]);
				break;
			}
			if (left == right)
			{
				std::list<char>::iterator front,back;
				front = leftList.begin();
				back = rightList.end();
				back--;	//문자가 저장되어있는 부분부터 시작하기 위해서
				while (1)
				{
					int leftPriority, rightPriority;
					for (int i = 0; i < 4; i++)
					{
						if (priorListLeft[i] == *front)
							leftPriority = i;
						if (priorListRight[i] == *back)
							rightPriority = i;
					}
					if (leftPriority != rightPriority)
					{
						
						if (leftPriority > rightPriority)
							*back = priorListRight[leftPriority];		//*back 은 뒤쪽에서 다가오는 값이므로 오른쪽 괄호에 대응되는 priorListRight 배열에서 우선순위에 해당하는 값을 가져온다.		
						else
							*front = priorListLeft[rightPriority];		//*front 는 *back 과 반대
					}
					
					
					front++;
					if (front == leftList.end())
						break;
					back--;
				}
				std::list<char>::iterator it = leftList.begin();
				for (; it != leftList.end(); it++)	//변환한 괄호들을 모두 출력
				{
					cout << *it;
				}
				it = rightList.begin();
				for (; it != rightList.end(); it++)	//변환한 괄호들을 모두 출력
				{
					cout << *it;
				}

				right = left = 0;		//처리한 뒤, 리스트에 왼쪽, 오른쪽 괄호가 들어있지 않음을 나타내기 위하여 right, left 를 0으로 초기화하고, 리스트를 초기화한다.
				leftList.clear();
				rightList.clear();
			}
		}
		cout << endl;
	}

	return 0;
}