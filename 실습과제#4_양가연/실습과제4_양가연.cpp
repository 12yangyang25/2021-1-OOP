#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int StdNum;
int menu = 0;

struct Subject { //�л� ���� ����ü
	char SubName[30];
	int Hakjum;
	char Grade[10];
	float GPA;
};

struct Student { //���� ���� ����ü
	char StdName[30];
	int Hakbun;
	Subject* Sub;
	int SubNum;
	float AveGPA = 0.0;
};



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


void PrintOneData(const Student& rSt, int SubNum) { //���� �л� ���� ���
	int i;

	cout << "�̸� : " << rSt.StdName << "  �й� : " << rSt.Hakbun << "\n";
	cout << "==============================================================\n";
	cout << "     �����        ��������    ������   ��������\n";
	cout << "==============================================================\n";
	for (i = 0; i < SubNum; i++) {
		cout.width(12);
		cout << rSt.Sub[i].SubName;
		cout.width(12);
		cout << rSt.Sub[i].Hakjum;
		cout.width(12);
		cout << rSt.Sub[i].Grade;
		cout.width(12);
		cout << rSt.Sub[i].GPA << "\n";
	}
	cout << "==============================================================\n";
	cout << "                                              �������: ";
	cout << rSt.AveGPA << "\n";
}

Student* StdSearch(Student* pSt, int StudentNum) { //�л� �̸� �˻� �Լ�
	int i;

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
	int i;

	cout.precision(2);
	cout << fixed;

	cout << "              ��ü �л� ���� ����\n";
	cout << "==============================================================\n";

	for (i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i], pSt[i].SubNum);
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

float CalcAveGPA(Subject* Sub, int SubNum) { //������ ���� ��� �Լ�
	float sum = 0;
	int i;

	for (i = 0; i < SubNum; i++) {
		sum += Sub[i].GPA;
	}
	return sum / (float)SubNum;
}

void InputData(Student* pSt, int StdNum) {
	int i, j;

	for (i = 0; i < StdNum; i++) {
		cout << "* " << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸�: ";
		InputValue(pSt[i].StdName);
		cout << "�й�: ";
		InputValue(pSt[i].Hakbun);
		cout << "�����  : ";
		InputValue(pSt[i].SubNum);
		pSt[i].Sub = new Subject[pSt[i].SubNum];
		cout << "\n\n";

		cout << "* ������ ���� " << pSt[i].SubNum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";

		for (j = 0; j < pSt[i].SubNum; j++) {
			cout << "�������: ";
			InputValue(pSt[i].Sub[j].SubName);
			cout << "����������: ";
			InputValue(pSt[i].Sub[j].Hakjum);
			cout << "������(A+ ~ F): ";
			InputValue(pSt[i].Sub[j].Grade);
			CalcGPA(pSt[i].Sub[j]);
			cout << "\n\n";
		}pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum);
	}
}

void PrintAllStdList(const Student* pSt, int StudentNum = 2) {
	int i;

	cout << "==============================================================\n";
	cout << "        �й�        �̸�\n";
	cout << "==============================================================\n";

	for (i = 0; i < StudentNum; i++) {
		cout.width(12);
		cout << (pSt + i)->Hakbun;
		cout.width(12);
		cout << (pSt + i)->StdName;
		cout << "\n";
	}
	cout << "==============================================================\n";
}

void ModifyStdInfo(Student* pSt) {

	Student* SearchStd;
	SearchStd = StdSearch(pSt, StdNum);
	if (SearchStd != NULL) {
		cout << "* <" << SearchStd->StdName << ", " << SearchStd->Hakbun << ">�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(SearchStd->StdName);
		cout << "�й� : ";
		InputValue(SearchStd->Hakbun);
	}
}

int main() {

	cout << "�л��� �Է� : ";
	cin >> StdNum;
	Student* Std = new Student[StdNum];

	while (menu != 6) {

		PrintMenu();

		cout << "���ϴ� ����� �Է��ϼ���: ";
		cin >> menu;
		cout << "\n";

		switch (menu) {
		case 1:
			InputData(Std, StdNum);

			break;


		case 2:

			PrintAllData(Std, StdNum);

			break;

		case 3:

			Student * SearchStd; // �л��̸� Ž�� ����� ���� ����ü
			SearchStd = StdSearch(Std, StdNum);
			if (SearchStd != NULL) {
				PrintOneData(*SearchStd, SearchStd->SubNum);
			}

			break;

		case 4:

			PrintAllStdList(Std, StdNum);
			break;

		case 5:

			ModifyStdInfo(Std);

			break;

		case 6:

			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
	}
	return 0;
}