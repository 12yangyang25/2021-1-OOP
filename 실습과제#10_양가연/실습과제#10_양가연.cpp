#include <iostream>
#include<vector>
#include <string>
using namespace std;

struct Students {
	vector<string> Names;
	vector<int> Hakbuns;
};

inline void InputValue(int& ref) {
	cin >> ref;
	cin.ignore();
}

inline void InputValue(string& ref) {
	getline(cin, ref);
	if (ref.empty()) getline(cin, ref);
}

inline void PrintMenu() { //�޴� ��� �Լ�
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. �л� ���� ����\n";
	cout << "3. �л� ���� ����\n";
	cout << "4. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ��� : ";
}

void InputData(Students& St) {
	string Name;
	int Hakbun;
	cout << "�̸� : ";
	InputValue(Name);
	cout << "�й� : ";
	InputValue(Hakbun);
	cout << "\n\n";
	St.Names.push_back(Name);
	St.Hakbuns.push_back(Hakbun);
}

void PrintData(const Students& St) {
	int i;
		cout << "      �л� ���� ����\n";
		cout << " ===============================\n";
		cout << "      �̸�            �й�\n";
		cout << " ===============================\n";
		for (i = 0; i < St.Names.size(); i++) {
		cout.width(10);
		cout << St.Names[i];
		cout.width(20);
		cout << St.Hakbuns[i];
		cout << "\n";
	}	cout << " ===============================\n\n";
}

void DeleteData(Students& St) {
	St.Names.pop_back();
	St.Hakbuns.pop_back();
}

int main() {

	Students St;
	int selected_menu = 0;

	while (selected_menu != 4) {

		PrintMenu();
		InputValue(selected_menu);
		cout << "\n";

		switch (selected_menu) {
		case 1:

			InputData(St);
			break;

		case 2:

			PrintData(St);
			break;

		case 3:

			DeleteData(St);
			break;

		case 4:

			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
	}
	return 0;
}
