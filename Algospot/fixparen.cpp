//switch Ȱ��
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
		for (int i = 3; i >= 0; i--)			//���߿� �ε��� ��ȣ�� ū ���� priority �� ���� ���� ��Ÿ���� ���� �Ųٷ� for ���� ���ȴ�. ���� �����ϴ� ������ ��ȣ�鵵 ������־���.
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
		�Ʒ� ������ �Է¹��� transcribed ������ŭ �ݺ��Ѵ�.

		1. �� ���ڸ� doubly linked list �� �ִ´�.(front ��)
		2. ���� ��ȣ�� ������ ��ȣ�� ������ ������ �� ���� ����Ʈ�� �ִ´�.
		3. ������ Ȯ�εǸ�, �� �ڷ� �ϳ��� �����Ͽ� �����ش�.
		4. �� ��ģ �Ŀ�, ����Ѵ�.
		
		*/
		std::list<char> leftList;
		std::list<char> rightList;
		int len = strlen(transcribed);
		int left = 0, right = 0;
		for (int i = 0; i < len; i++)
		{
			//�� for ������ ���۵� ��, left, right �� 0 ������, �ϴ� � ��ȣ�� �ϳ��� �ְ� �����ϸ� left == right == 0 �� ���� switch ���� ���Ŀ� ���ܳ� �� ����.
			switch (transcribed[i])
			{
			case '{':
			case '<':
			case '[':
			case '(':
				left++;
				leftList.push_back(transcribed[i]);		//���� ��ȣ�� ���ʿ� �־��ش�.
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
				back--;	//���ڰ� ����Ǿ��ִ� �κк��� �����ϱ� ���ؼ�
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
							*back = priorListRight[leftPriority];		//*back �� ���ʿ��� �ٰ����� ���̹Ƿ� ������ ��ȣ�� �����Ǵ� priorListRight �迭���� �켱������ �ش��ϴ� ���� �����´�.		
						else
							*front = priorListLeft[rightPriority];		//*front �� *back �� �ݴ�
					}
					
					
					front++;
					if (front == leftList.end())
						break;
					back--;
				}
				std::list<char>::iterator it = leftList.begin();
				for (; it != leftList.end(); it++)	//��ȯ�� ��ȣ���� ��� ���
				{
					cout << *it;
				}
				it = rightList.begin();
				for (; it != rightList.end(); it++)	//��ȯ�� ��ȣ���� ��� ���
				{
					cout << *it;
				}

				right = left = 0;		//ó���� ��, ����Ʈ�� ����, ������ ��ȣ�� ������� ������ ��Ÿ���� ���Ͽ� right, left �� 0���� �ʱ�ȭ�ϰ�, ����Ʈ�� �ʱ�ȭ�Ѵ�.
				leftList.clear();
				rightList.clear();
			}
		}
		cout << endl;
	}

	return 0;
}