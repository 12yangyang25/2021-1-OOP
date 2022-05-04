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

inline void PrintMenu() { //메뉴 출력 함수
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 정보 입력\n";
	cout << "2. 학생 정보 보기\n";
	cout << "3. 학생 정보 삭제\n";
	cout << "4. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요 : ";
}

void InputData(Students& St) {
	string Name;
	int Hakbun;
	cout << "이름 : ";
	InputValue(Name);
	cout << "학번 : ";
	InputValue(Hakbun);
	cout << "\n\n";
	St.Names.push_back(Name);
	St.Hakbuns.push_back(Hakbun);
}

void PrintData(const Students& St) {
	int i;
		cout << "      학생 정보 보기\n";
		cout << " ===============================\n";
		cout << "      이름            학번\n";
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

			cout << "프로그램을 종료합니다.\n";
			break;
		}
	}
	return 0;
}
