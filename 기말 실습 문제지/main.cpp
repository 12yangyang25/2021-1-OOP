#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void PrintMenu() {
	cout << "===== �޴� =====" << endl;
	cout << "1. �л� ���� �߰� �Է�" << endl;
	cout << "2. �л� ���� ���" << endl;
	cout << "3. ���α׷� ����" << endl << endl;
	cout << "���ϴ� ����� �Է��ϼ��� : ";
}

void InputData(Student* pStTmp) {

	cout << "�߰� �л� �̸� : ";
	pStTmp->PutName();
	cout << "���� : ";
	pStTmp->PutScore();
}


int main()
{
	Student* StTmp;

	vector<Student> vec;
	vector<Student>::iterator it;

	int selected_menu = 0;

	while (selected_menu != 3) {
		PrintMenu();
		cin >> selected_menu;
		cout << endl;

		switch (selected_menu) {
		case 1:
			StTmp = new Student();
			InputData(StTmp);
			vec.push_back(*StTmp);

			break;
		case 2:
			for (it = vec.begin(); it < vec.end(); it++) {
				it->PrintData();
			}

		case 3:
			break;

		default:
			cout << "Error" << endl;
		}
	}
	return 0;
}


