#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void PrintMenu() {
	cout << "===== 메뉴 =====" << endl;
	cout << "1. 학생 정보 추가 입력" << endl;
	cout << "2. 학생 정보 출력" << endl;
	cout << "3. 프로그램 종료" << endl << endl;
	cout << "원하는 기능을 입력하세요 : ";
}

void InputData(Student* pStTmp) {

	cout << "추가 학생 이름 : ";
	pStTmp->PutName();
	cout << "성적 : ";
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


