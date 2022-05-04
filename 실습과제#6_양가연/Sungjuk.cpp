#include "Subject.h"
#include "Student.h"

void InputValue(int& num) {
	cin >> num;
	cin.ignore();
}

void InputValue(string& str) {
	getline(cin, str);
}

inline void PrintMenu() { //�޴� ��� �Լ�
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. ���α׷� ����\n\n";
}

int StdNum;
int menu = 0;

int main() {
	int i, j;

	cout << "�л��� �Է� : ";
	InputValue(StdNum);
	Student* Std = new Student[StdNum];

	while (menu != 3) {

		PrintMenu();

		cout << "���ϴ� ����� �Է��ϼ���: ";
		InputValue(menu);
		cout << "\n";

		switch (menu) {
		case 1:

			for (i = 0; i < StdNum; i++) {
				cout << "* " << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
				(Std + i)->InputData();
				(Std + i)->CalcAveGPA();
			}

			break;

		case 2:

			cout.precision(2);
			cout << fixed;

			cout << "              ��ü �л� ���� ����\n";
			cout << "==============================================================\n";

			for (i = 0; i < StdNum; i++) {
				(Std + i)->PrintData();
			}

			break;

		case 3:
			cout << "���α׷��� �����մϴ�.\n";

			break;
		}
	}

	return 0;

}
