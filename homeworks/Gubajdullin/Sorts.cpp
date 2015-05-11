//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>
using namespace std;
void Start();
void Settings();
void Opisanie();
void Time();
void ShellSettings();
void Out();
void TimerFile();
void test();
void Output(vector<int>);
vector<int> Input(int ch);
vector<int> InsertionSort(vector<int> vect);
vector<int> BubbleSort(vector<int> vect);
vector<int> ShellSort(vector<int> vect);
vector<int> ShellSortPhase(vector<int> vect, int length, int gap);
vector<int> SelectSort(vector<int> vect);
vector<int> QuickSort(vector<int> vect);
vector<int> QS(vector<int> vect, int first, int last);
ifstream input("2kints.txt");
ofstream output("output.txt");
bool timer = 0, file = 1,timerfile=0;
int mas[]={ 1, 4, 10, 23, 57, 132, 301, 701 };
vector<int> shell(mas[7]);
time_t time1, time2;
int main()
{
	setlocale(LC_ALL, "Russian");
	int ch;
	bool exit = 0;
	while (!exit){
		system("cls");
		cout << "����� ���������� � SortSort ver0.5\n"
			<< "1.���������\n"
			<< "2.��������\n"
			<< "3.���������\n"
			<< "4.�����\n"
			<< "(������� ����� ���������� ������ ����)\n"
			<< ">";
			cin >> ch;
			switch (ch){
			case 1: Start(); exit = 1; break;
			case 2: Opisanie(); break;
			case 3: Settings(); break;
			case 4: exit = 1; return 0;  break;
			default: cout << "������! �������� ��������.\n";
		}
	}

	system("pause");
	input.close();
	input.close();
	return 0;
}
void Opisanie(){
	system("cls");
	cout << "��������.\n"
	<<
	system("pause");
}
void Settings(){
	int ch;
	bool exit = 0;
	while (!exit){
		system("cls");
		cout << "���������\n"
			<< "1.���������� ����� ����������\n"
			<< "2.����� ����� ��� ���������� �����\n"
			<< "3.����/����� �� �����/����������\n"
			<< "4.����� ������� ���������� � ����/�� �������\n"
			<< "5.�����\n" 
			<< ">";
		cin >> ch;
		switch (ch){
			case 1: Time(); break;
			case 2: ShellSettings(); break;
			case 3: Out(); break;
			case 4: TimerFile(); break;
			case 5: exit = 1; break;
			default: cout << "������! �������� ��������.\n";
		}
	}
	cout << "��������� �������.\n";
		system("pause");
}
void Time(){
	int ch;
	cout << "������\n"
		<< "1.��������\n"
		<< "2.��������� (�� ���������)\n"
		<< ">";
	cin >> ch;
	switch (ch){
	case 1: timer = true; break;
	case 2: timer = false; break;
	default: cout << "������! �������� ��������.\n";
	}
}
void ShellSettings(){
	int ch;
	system("cls");
	int n;
	shell.clear();
	cout << "����� ����� ��� ���������� �����\n"
		 << "������ ���������� ����� � ���� ����� (� ������� �����������!)\n" 
		 << ">";
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> ch;
		shell.push_back(ch);
	}
	cout << "��������� �������.\n";
	system("pause");
}
void Out(){
	int ch;
	cout << "����/�����\n"
		<< "1.�� ����� (�� ���������)\n"
		<< "2.� ����������\n"
		<< ">";
	cin >> ch;
	switch (ch){
	case 1: file = true; break;
	case 2: file = false; break;
	default: cout << "������! �������� ��������.\n";
	}
}
void TimerFile(){
	int ch;
	cout << "����� �������\n"
		<< "1.� ����\n"
		<< "2.�� ������� (�� ���������)\n"
		<< ">";
	cin >> ch;
	switch (ch){
	case 1: timerfile = true; break;
	case 2: timerfile = false; break;
	default: cout << "������! �������� ��������.\n";
	}
}
void Start(){
	int ch;
	bool exit=0;
	vector<int> vect;
	system("cls");
	cout << "����� ����������\n"
		<< "1.���������\n"
		<< "2.���������\n"
		<< "3.�����\n"
		<< "4.�������\n"
		<< "5.�������\n"
		<< "6.���(����� �������)\n"
		<< "7.�����\n"
		<< "8.����\n"
		<< ">";
	cin >> ch;
	switch (ch){
	case 1: Output(InsertionSort(Input(ch))); break;
	case 2: Output(BubbleSort(Input(ch))); break;
	case 3: Output(ShellSort(Input(ch)));  break;
	case 4: Output(SelectSort(Input(ch))); break;
	case 5: {
		vect = Input(ch);
		Output(QuickSort(vect)); 
	}
		break;
	case 6: {
		timer = 1;
		vect=Input(ch);
		BubbleSort(vect);
		ShellSort(vect);
		SelectSort(vect);
		QuickSort(vect);
		InsertionSort(vect);
	}
		break;
	case 7: exit = 1; break;
	case 8: test(); break;
	default: cout << "������! �������� ��������.\n";
	}
}
void OutputTime(time_t time, int n){
	if (timerfile == 0){
		cout << "����� ���������� ���������� ";
		switch (n){
			case 1:cout << "���������: "; break;
			case 2:cout << "���������: "; break;
			case 3:cout << "�����: "; break;
			case 4:cout << "�������: "; break;
			case 5:cout << "�������: "; break;
		}
		cout << time << endl;
	}

	else{
		output << "����� ���������� ���������� ";
		switch (n){
			case 1:output << "���������: "; break;
			case 2:output << "���������: "; break;
			case 3:output << "�����: "; break;
			case 4:output << "�������: "; break;
			case 5:output << "�������: "; break;
		} output << time << endl;
	}
}
vector<int> Input(int ch){
	vector<int> vect;
	vect.clear();
	if (!file){
		system("cls");
		cout << "��������� ���������� - ";
		switch (ch){
		case 1: cout << "���������\n"; break;
		case 2: cout << "�����������\n"; break;
		case 3: cout << "�����\n";  break;
		case 4: cout << "�������\n"; break;
		case 5: cout << "�������\n"; break;
		case 6: cout << "���\n"; break;
		}
		cout << "������ ���������� ����� � ���� �����\n"
			<< ">";
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> ch;
			vect.push_back(ch);
		}
	}
	else{
		int n;
		input >> n;
		for (int i = 1; i <= n; i++){
			input >> ch;
			vect.push_back(ch);
		}
	}
	return vect;
}
void Output(vector<int> vect){
	if (file == 0)
		for (unsigned int i = 0; i < vect.size(); i++)
			cout << vect[i];
	else
		for (unsigned int i = 0; i < vect.size(); i++)
			output << vect[i];
	system("pause");
}
vector<int> InsertionSort(vector<int> vect){
	time(&time1);
	int i, j, current;
	int length = vect.size();
	for (i = 1; i < length; i++){
		current = vect[i];
		for (j = i - 1; j >= 0 && vect[j] > current; j--){
			vect[j + 1] = vect[j];
		}
		vect[j + 1] = current;
	}
	time(&time2);
	if (timer) OutputTime(time2-time1,1);
	return vect;
}
vector<int> BubbleSort(vector<int> vect){
	time(&time1);
	int length = vect.size();
	for (int i = length - 1; i >= 0; i--)
			for (int j = 0; j < i; j++)
				if (vect[j] > vect[j + 1])
					swap(vect[j],vect[j + 1]);

	time(&time2);
	if (timer) OutputTime(time2 - time1, 2);
	return vect;
}
vector<int> ShellSortPhase(vector<int> vect, int length, int gap) {
	int i;
	for (i = gap; i < length; ++i) {
		int current = vect[i];
		int j;
		for (j = i - gap; j >= 0 && vect[j] > current; j -= gap) {
			vect[j + gap] = vect[j];
		}
		vect[j + gap] = current;
	}
	return vect;
}
vector<int> ShellSort(vector<int> vect){
	time(&time1);
	int sizeIndex;
	int length = vect.size();
	for (sizeIndex = sizeof(shell) / sizeof(shell[0]) - 1;sizeIndex >= 0;--sizeIndex)
		vect = ShellSortPhase(vect, length, shell[sizeIndex]);
	
	time(&time2);
	if (timer) OutputTime(time2 - time1, 3);
	return vect;
}
vector<int> SelectSort(vector<int> vect){
	time(&time1);
	int length = vect.size();
	for (int i = 0; i < length - 1; i++) {
		int min_i = i;
		for (int j = i + 1; j < length; j++)
			if (vect[j] < vect[min_i]) 
				min_i = j;
		swap(vect[i],vect[min_i]);
	}
	time(&time2);
	if (timer) OutputTime(time2 - time1, 4);
	return vect;
}
vector<int> QuickSort(vector<int> vect){
	time(&time1);
	vect = QS(vect, 0, vect.size()-1);
	time(&time2);
	if (timer) OutputTime(time2 - time1, 5);
	return vect;
}
vector<int> QS(vector<int> vect, int first, int last){
	int i = first, j = last, x = vect[(first + last) / 2];
	while (i <= j){
		while (vect[i] < x) i++;
			while (vect[j] > x) j--;
				if (i <= j) {
					if (vect[i] > vect[j]) swap(vect[i], vect[j]);
						i++;
					j--;
				}
	}
	if (i < last)
		vect = QS(vect, i, last);
	if (first < j)
		vect = QS(vect, first, j);

	return vect;
}
void test(){
	int ch = 1;
	vector<int> vect;
	vect = Input(ch);
	if (InsertionSort(vect) != BubbleSort(vect))  cout << "Bubble\n";
	if (InsertionSort(vect) != ShellSort(vect))  cout << "Shell\n";
	if (InsertionSort(vect) != SelectSort(vect))  cout << "Select\n";
	if (InsertionSort(vect) != QuickSort(vect))  cout << "Quick\n";
	system("pause");
}
