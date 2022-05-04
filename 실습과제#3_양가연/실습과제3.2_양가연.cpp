#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int StdNum = 2;
int menu = 0;
int i, j;

struct Subject { //�л� ���� ����ü
	char SubName[30];
	int Hakjum;
	char Grade[10];
	float GPA;
};

struct Student { //���� ���� ����ü
	char StdName[30];
	int Hakbun;
	Subject Sub[3];
	float AveGPA = 0.0;
};

Student Std[2];

inline void PrintMenu() { //�޴� ��� �Լ�

	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n";
	cout << "5. �л� ���� ����\n";
	cout << "6. ���α׷� ����\n\n";
}

inline void InputValue(char* str) {
	cin >> str;
}

inline void InputValue(int& i) {
	cin >> i;
}

void PrintOneData(const Student& rSt) { //���� �л� ���� ���

	cout << "�̸� : " << rSt.StdName << "  �й� : " << rSt.Hakbun << "\n";
	cout << "==============================================================\n";
	cout << "     �����        ��������    ������   ��������\n";
	cout << "==============================================================\n";
	cout.width(12);
	cout << rSt.Sub[0].SubName;
	cout.width(12);
	cout << rSt.Sub[0].Hakjum;
	cout.width(12);
	cout << rSt.Sub[0].Grade;
	cout.width(12);
	cout << rSt.Sub[0].GPA << "\n";
	cout.width(12);
	cout << rSt.Sub[1].SubName;
	cout.width(12);
	cout << rSt.Sub[1].Hakjum;
	cout.width(12);
	cout << rSt.Sub[1].Grade;
	cout.width(12);
	cout << rSt.Sub[1].GPA << "\n";
	cout.width(12);
	cout << rSt.Sub[2].SubName;
	cout.width(12);
	cout << rSt.Sub[2].Hakjum;
	cout.width(12);
	cout << rSt.Sub[2].Grade;
	cout.width(12);
	cout << rSt.Sub[2].GPA << "\n";
	cout << "==============================================================\n";
	cout << "                                              �������: ";
	cout << rSt.AveGPA << "\n";
}

Student* StdSearch(Student* pSt, int StudentNum) { //�л� �̸� �˻� �Լ�

	char StdName[30];
	cout << "�˻� �� �л� �̸�: ";
	cin >> StdName;

	for (i = 0; i < StudentNum; i++) {
		if (strcmp(StdName, pSt[i].StdName) == 0) {
			return &pSt[i];
		}
	}
	cout << "\n";
	cout << "������ �߻��Ͽ����ϴ�.";
	return NULL;
}

void PrintAllData(const Student* pSt, int StudentNum) { //��ü �л� ���� ���

	cout.precision(2);
	cout << fixed;

	cout << "              ��ü �л� ���� ����\n";
	cout << "==============================================================\n";

	for (i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i]);
	}
}

void CalcGPA(Subject& Sub) { //��������Լ�
	if (strcmp(Sub.Grade, "A+") == 0) {
		Sub.GPA = 4.5 * Sub.Hakjum;
	}
	else if (strcmp(Sub.Grade, "A0") == 0) {
		Sub.GPA = 4.0 * Sub.Hakjum;
	}
	else if (strcmp(Sub.Grade, "B+") == 0) {
		Sub.GPA = 3.5 * Sub.Hakjum;
	}
	else if (strcmp(Sub.Grade, "B0") == 0) {
		Sub.GPA = 3.0 * Sub.Hakjum;
	}
	else if (strcmp(Sub.Grade, "C+") == 0) {
		Sub.GPA = 2.5 * Sub.Hakjum;
	}
	else if (strcmp(Sub.Grade, "C0") == 0) {
		Sub.GPA = 2.0 * Sub.Hakjum;
	}
	else if (strcmp(Sub.Grade, "D+") == 0) {
		Sub.GPA = 1.5 * Sub.Hakjum;
	}
	else if (strcmp(Sub.Grade, "D0") == 0) {
		Sub.GPA = 1.0 * Sub.Hakjum;
	}
	else if (strcmp(Sub.Grade, "F") == 0) {
		Sub.GPA = 0 * Sub.Hakjum;
	}
}

float CalcAveGPA(Subject* Sub) { //������ ���� ��� �Լ�
	return (Sub[0].GPA + Sub[1].GPA + Sub[2].GPA) / 3.0;
}

void PrintAllStdList(const Student* pSt, int StudentNum = 2) {
	cout << "==============================================================\n";
	cout << "        �й�        �̸�\n";
	cout << "==============================================================\n";

	for (i = 0; i < StudentNum; i++) {
		cout.width(12);
		cout << (pSt+i)->Hakbun;
		cout.width(12);
		cout << (pSt+i)->StdName;
		cout << "\n";
	}
	cout << "==============================================================\n";
}

void Modify(Student* pSt) {

	Student* SearchStd; 
	SearchStd = StdSearch(Std, StdNum);
	if (SearchStd != NULL) {
		cout << "* <" << SearchStd->StdName << ", " << SearchStd->Hakbun << ">�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(SearchStd->StdName);
		cout << "�й� : ";
		InputValue(SearchStd->Hakbun);
	}
}

int main() {

	while (menu != 6) {

		PrintMenu();

		cout << "���ϴ� ����� �Է��ϼ���: ";
		cin >> menu;
		cout << "\n";

		switch (menu) {
		case 1:

			for (i = 0; i < StdNum; i++) {
				cout << "* " << i+1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
				cout << "�̸�: ";
				InputValue(Std[i].StdName);
				cout << "�й�: ";
				InputValue(Std[i].Hakbun);
				cout << "\n\n";

				cout << "* ������ ����3���� �� �������, ��������, �������� �Է��ϼ���.\n";

				for (j = 0; j < 3; j++) {
					cout << "�������: ";
					InputValue(Std[i].Sub[j].SubName);
					cout << "����������: ";
					InputValue(Std[i].Sub[j].Hakjum);
					cout << "������(A+ ~ F): ";
					InputValue(Std[i].Sub[j].Grade);
					CalcGPA(Std[i].Sub[j]);
					cout << "\n\n";
				}Std[i].AveGPA = CalcAveGPA(Std[i].Sub);
			}

			break;


		case 2:

			PrintAllData(Std, 2);

			break;

		case 3:

			Student * SearchStd; // �л��̸� Ž�� ����� ���� ����ü
			SearchStd = StdSearch(Std, StdNum);
			if (SearchStd != NULL) {
				PrintOneData(*SearchStd);
			}

			break;

		case 4:

			PrintAllStdList(Std);
			break;

		case 5:

			Modify(Std);

			break;

		case 6:

			cout << "���α׷��� �����մϴ�.\n";
			break;
		}



	}
	return 0;
}