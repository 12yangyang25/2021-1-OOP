#include "Subject.h"
#include "Student.h"

void InputValue(int& num) {
	cin >> num;
	cin.ignore();
}

void InputValue(string& str) {
	getline(cin, str);
}

inline void PrintMenu() { //메뉴 출력 함수
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 프로그램 종료\n\n";
}

int StdNum;
int menu = 0;

int main() {
	int i, j;

	cout << "학생수 입력 : ";
	InputValue(StdNum);
	Student* Std = new Student[StdNum];

	while (menu != 3) {

		PrintMenu();

		cout << "원하는 기능을 입력하세요: ";
		InputValue(menu);
		cout << "\n";

		switch (menu) {
		case 1:

			for (i = 0; i < StdNum; i++) {
				cout << "* " << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
				(Std + i)->InputData();
				(Std + i)->CalcAveGPA();
			}

			break;

		case 2:

			cout.precision(2);
			cout << fixed;

			cout << "              전체 학생 성적 보기\n";
			cout << "==============================================================\n";

			for (i = 0; i < StdNum; i++) {
				(Std + i)->PrintData();
			}

			break;

		case 3:
			cout << "프로그램을 종료합니다.\n";

			break;
		}
	}

	return 0;

}
