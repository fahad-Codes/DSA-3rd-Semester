#include<iostream>
using namespace std;

int main()
{
	char arr[50] = "Hi! I'm Fahad";
	char ia[50] = "Fahad";

	
		int n = strlen(ia);
		for (int i = 0; i < 50; i++)
		{			
			if (arr[i] == ia[0])
			{
				int x = i;
				int y = 0;
				for (int j = 0; j < n; j++)
				{
					if (ia[j] == arr[x])
					{
						x++;
						y++;
					}
				}
				if (y == n)
				{
					cout << "Entered string is found";
				}
				else if (i == 50 - 1 && y < n)
				{
					cout << "Entered string is not found";
				}
			}

		}
}
