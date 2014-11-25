#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream ifile("dictionary.txt");
	string word = "";
	int expectedNum = 5;

	vector<char> expectedChars;
	expectedChars.push_back('�');
	expectedChars.push_back('�');
	expectedChars.push_back('�');
	expectedChars.push_back('�');
	expectedChars.push_back('�');
	expectedChars.push_back('�');
	expectedChars.push_back('�');

	bool flag = true, isPresent = false;
	
	while (ifile >> word)
	{
		if (word.length() == expectedNum)
		{
			flag = true;
			vector<char> temp = expectedChars;
			for (int i = 0; i < word.length(); i++)
			{
				vector<char>::iterator tempIt = find(temp.begin(), temp.end(), word[i]);
				if (tempIt != temp.end())
				{
					temp.erase(tempIt);
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				isPresent = true;
				cout << word << endl;
			}
		}
	}
	if (isPresent == false)
	{
		cout << "����" << endl;
	}
	system("pause");
	return 0;
}

