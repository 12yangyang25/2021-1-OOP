#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

int StdNum = 2;
int menu = 0;
int i, j;

struct Subject { //학생 정보 구조체
	char SubName[30];
	int Hakjum;
	char Grade[10];
	float GPA;
};

struct Student { //과목 정보 구조체
	char StdName[30];
	int Hakbun;
	Subject Sub[3];
	float AveGPA = 0.0;
};

Student Std[2];

inline void PrintMenu() { //메뉴 출력 함수

	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n\n";
}

inline void InputValue(char* str) {
	cin >> str;
}

inline void InputValue(int& i) {
	cin >> i;
}

void PrintOneData(const Student& rSt) { //개인 학생 정보 출력

	cout << "이름 : " << rSt.StdName << "  학번 : " << rSt.Hakbun << "\n";
	cout << "==============================================================\n";
	cout << "     과목명        과목학점    과목등급   과목평점\n";
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
	cout << "                                              평균평점: ";
	cout << rSt.AveGPA << "\n";
}

Student* StdSearch(Student* pSt, int StudentNum) { //학생 이름 검색 함수

	char StdName[30];
	cout << "검색 할 학생 이름: ";
	cin >> StdName;

	for (i = 0; i < StudentNum; i++) {
		if (strcmp(StdName, pSt[i].StdName) == 0) {
			return &pSt[i];
		}
	}
	cout << "\n";
	cout << "에러가 발생하였습니다.";
	return NULL;
}

void PrintAllData(const Student* pSt, int StudentNum) { //전체 학생 정보 출력

	cout.precision(2);
	cout << fixed;

	cout << "              전체 학생 성적 보기\n";
	cout << "==============================================================\n";

	for (i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i]);
	}
}

void CalcGPA(Subject& Sub) { //평점계산함수
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

float CalcAveGPA(Subject* Sub) { //교과목 평점 계산 함수
	return (Sub[0].GPA + Sub[1].GPA + Sub[2].GPA) / 3.0;
}

void PrintAllStdList(const Student* pSt, int StudentNum = 2) {
	cout << "==============================================================\n";
	cout << "        학번        이름\n";
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
		cout << "* <" << SearchStd->StdName << ", " << SearchStd->Hakbun << ">의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputValue(SearchStd->StdName);
		cout << "학번 : ";
		InputValue(SearchStd->Hakbun);
	}
}

int main() {

	while (menu != 6) {

		PrintMenu();

		cout << "원하는 기능을 입력하세요: ";
		cin >> menu;
		cout << "\n";

		switch (menu) {
		case 1:

			for (i = 0; i < StdNum; i++) {
				cout << "* " << i+1 << "번째 학생 이름과 학번을 입력하세요.\n";
				cout << "이름: ";
				InputValue(Std[i].StdName);
				cout << "학번: ";
				InputValue(Std[i].Hakbun);
				cout << "\n\n";

				cout << "* 수강한 과목3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

				for (j = 0; j < 3; j++) {
					cout << "교과목명: ";
					InputValue(Std[i].Sub[j].SubName);
					cout << "과목학점수: ";
					InputValue(Std[i].Sub[j].Hakjum);
					cout << "과목등급(A+ ~ F): ";
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

			Student * SearchStd; // 학생이름 탐색 결과를 받을 구조체
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

			cout << "프로그램을 종료합니다.\n";
			break;
		}



	}
	return 0;
}