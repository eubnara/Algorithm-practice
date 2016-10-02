#include <iostream>
#include <cstring>
using namespace std;

char percntEncdURI[80 + 1];
int main(void)
{
	int C;
	cin >> C;
	while (C--)
	{
		cin >> percntEncdURI;
		int len = strlen(percntEncdURI);
		for (int i = 0; i < len; i++)
		{
			bool decoded = false;
			switch (percntEncdURI[i])
			{
			case '%':
				if (i<=len-3)
					if (percntEncdURI[i + 1] == '2')
					{
						decoded = true;
						switch (percntEncdURI[i + 2])
						{
						case '0':
							cout << ' ';
							break;
						case '1':
							cout << '!';
							break;
						case '4':
							cout << '$';
							break;
						case '5':
							cout << '%';
							break;
						case '8':
							cout << '(';
							break;
						case '9':
							cout << ')';
							break;
						case 'a':
							cout << '*';
							break;
						default:
							decoded = false;
							i -= 3;
							break;
						}
						i += 2;
					}
						
			default:
				break;
			}
			if (decoded==false)
				cout << percntEncdURI[i];
		}
		cout << endl;
	}


	return 0;
}