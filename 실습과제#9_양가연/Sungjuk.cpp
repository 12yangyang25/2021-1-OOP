#include "Subject.h"
#include "Student.h"

inline void InputValue(int& num) {
	cin >> num;
	cin.ignore();
}

inline void InputValue(string& str) {
	getline(cin, str);
}

inline void PrintMenu() { //메뉴 출력 함수
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 정보 수정\n";
	cout << "4. 프로그램 종료\n\n";
}

void PrintAllData(const Student* Std, int StdNum) {
	int i;

	cout.precision(2);
	cout << fixed;

	cout << "              전체 학생 성적 보기\n";
	cout << "==============================================================\n";

	for (i = 0; i < StdNum; i++) {
		(Std + i)->PrintData();
	}

}

void InputData(Student* Std, int StdNum) {
	int i;

	for (i = 0; i < StdNum; i++) {
		cout << "* " << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		(Std + i)->InputData();
		(Std + i)->CalcAveGPA();
	}

}

Student* StdSearch(Student* Std, int StdNum) {
	int i;

	string StdName;
	cout << "검색 할 학생 이름: ";
	InputValue(StdName);

	for (i = 0; i < StdNum; i++) {
		if (StdName == (Std + i)->GetName()) {
			return Std + i;
		}
	}
	cout << "\n";
	cout << "에러가 발생하였습니다.";
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

	cout << "학생수 입력 : ";
	InputValue(StdNum);
	Student* Std = new Student[StdNum];

	while (menu != 4) {

		PrintMenu();

		cout << "원하는 기능을 입력하세요: ";
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
			cout << "프로그램을 종료합니다.\n";

			break;
		}
	}
	return 0;
}
