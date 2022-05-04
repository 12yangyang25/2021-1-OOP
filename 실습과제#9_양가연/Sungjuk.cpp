#include "Subject.h"
#include "Student.h"

inline void InputValue(int& num) {
	cin >> num;
	cin.ignore();
}

inline void InputValue(string& str) {
	getline(cin, str);
}

inline void PrintMenu() { //�޴� ��� �Լ�
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� ���� ����\n";
	cout << "4. ���α׷� ����\n\n";
}

void PrintAllData(const Student* Std, int StdNum) {
	int i;

	cout.precision(2);
	cout << fixed;

	cout << "              ��ü �л� ���� ����\n";
	cout << "==============================================================\n";

	for (i = 0; i < StdNum; i++) {
		(Std + i)->PrintData();
	}

}

void InputData(Student* Std, int StdNum) {
	int i;

	for (i = 0; i < StdNum; i++) {
		cout << "* " << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		(Std + i)->InputData();
		(Std + i)->CalcAveGPA();
	}

}

Student* StdSearch(Student* Std, int StdNum) {
	int i;

	string StdName;
	cout << "�˻� �� �л� �̸�: ";
	InputValue(StdName);

	for (i = 0; i < StdNum; i++) {
		if (StdName == (Std + i)->GetName()) {
			return Std + i;
		}
	}
	cout << "\n";
	cout << "������ �߻��Ͽ����ϴ�.";
	return NULL;
}

void Modify(Student* Std, int StdNum) {

	Student* SearchStd;
	SearchStd = StdSearch(Std, StdNum);
	if (SearchStd != NULL) {
		SearchStd->modify();
	}

}

int StdNum;
int menu = 0;

int main() {

	cout << "�л��� �Է� : ";
	InputValue(StdNum);
	Student* Std = new Student[StdNum];

	while (menu != 4) {

		PrintMenu();

		cout << "���ϴ� ����� �Է��ϼ���: ";
		InputValue(menu);
		cout << "\n";

		switch (menu) {
		case 1:

			InputData(Std, StdNum);

			break;

		case 2:

			PrintAllData(Std, StdNum);

			break;

		case 3:

			Modify(Std, StdNum);
			break;

		case 4:
			cout << "���α׷��� �����մϴ�.\n";

			break;
		}
	}
	return 0;
}
