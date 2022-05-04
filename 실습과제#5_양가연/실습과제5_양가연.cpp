#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int StdNum;
int menu = 0;

struct Subject { //학생 정보 구조체
	string SubName;
	int Hakjum;
	string Grade;
	float GPA;
};

struct Student { //과목 정보 구조체
	string StdName;
	int Hakbun;
	Subject* Sub;
	int SubNum;
	float AveGPA = 0.0;
};



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
	cin.ignore();
}

inline void InputValue(string& str) {
	getline(cin, str);
}


void PrintOneData(const Student& rSt, int SubNum) { //개인 학생 정보 출력
	int i;

	cout << "이름 : " << rSt.StdName << "  학번 : " << rSt.Hakbun << "\n";
	cout << "==============================================================\n";
	cout << "     과목명        과목학점    과목등급   과목평점\n";
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
	cout << "                                              평균평점: ";
	cout << rSt.AveGPA << "\n";
}

Student* StdSearch(Student* pSt, int StudentNum) { //학생 이름 검색 함수
	int i;

	string StdName;
	cout << "검색 할 학생 이름: ";
	InputValue(StdName);

	for (i = 0; i < StudentNum; i++) {
		if (StdName == pSt[i].StdName) {
			return &pSt[i];
		}
	}
	cout << "\n";
	cout << "에러가 발생하였습니다.";
	return NULL;
}

Subject* SubSearch(const Student& pSt) {
	int i;
	string SubName;
	cout << "검색 할 과목 이름: ";
	InputValue(SubName);

	for (i = 0; i < pSt.SubNum; i++) {
		if (SubName == pSt.Sub[i].SubName) {
			return &pSt.Sub[i];
		}
	}
	cout << "\n";
	cout << "에러가 발생하였습니다.";
	return NULL;
}


void PrintAllData(const Student* pSt, int StudentNum) { //전체 학생 정보 출력
	int i;

	cout.precision(2);
	cout << fixed;

	cout << "              전체 학생 성적 보기\n";
	cout << "==============================================================\n";

	for (i = 0; i < StudentNum; i++) {
		PrintOneData(pSt[i], pSt[i].SubNum);
	}
}

void CalcGPA(Subject& Sub) { //평점계산함수
	if (Sub.Grade == "A+") {
		Sub.GPA = 4.5 * Sub.Hakjum;
	}
	else if (Sub.Grade == "A0") {
		Sub.GPA = 4.0 * Sub.Hakjum;
	}
	else if (Sub.Grade == "B+") {
		Sub.GPA = 3.5 * Sub.Hakjum;
	}
	else if (Sub.Grade == "B0") {
		Sub.GPA = 3.0 * Sub.Hakjum;
	}
	else if (Sub.Grade == "C+") {
		Sub.GPA = 2.5 * Sub.Hakjum;
	}
	else if (Sub.Grade == "C0") {
		Sub.GPA = 2.0 * Sub.Hakjum;
	}
	else if (Sub.Grade == "D+") {
		Sub.GPA = 1.5 * Sub.Hakjum;
	}
	else if (Sub.Grade == "D0") {
		Sub.GPA = 1.0 * Sub.Hakjum;
	}
	else if (Sub.Grade == "F") {
		Sub.GPA = 0 * Sub.Hakjum;
	}
}

float CalcAveGPA(Subject* Sub, int SubNum) { //교과목 평점 계산 함수
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
		cout << "* " << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름: ";
		InputValue(pSt[i].StdName);
		cout << "학번: ";
		InputValue(pSt[i].Hakbun);
		cout << "과목수  : ";
		InputValue(pSt[i].SubNum);
		pSt[i].Sub = new Subject[pSt[i].SubNum];
		cout << "\n\n";

		cout << "* 수강한 과목 " << pSt[i].SubNum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

		for (j = 0; j < pSt[i].SubNum; j++) {
			cout << "교과목명: ";
			InputValue(pSt[i].Sub[j].SubName);
			cout << "과목학점수: ";
			InputValue(pSt[i].Sub[j].Hakjum);
			cout << "과목등급(A+ ~ F): ";
			InputValue(pSt[i].Sub[j].Grade);
			CalcGPA(pSt[i].Sub[j]);
			cout << "\n\n";
		}pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum);
	}
}

void PrintAllStdList(const Student* pSt, int StudentNum = 2) {
	int i;

	cout << "==============================================================\n";
	cout << "        학번        이름\n";
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

void ModifyStdInfo(Student* pSt, int StdNum) {

	Student* SearchStd;
	SearchStd = StdSearch(pSt, StdNum);
	if (SearchStd != NULL) {
		string Type;
		cout << "수정(학생정보/과목정보) : ";
		InputValue(Type);

		if (Type == "학생정보") {
			cout << "* <" << SearchStd->StdName << ", " << SearchStd->Hakbun << ">의 정보를 수정하세요\n";
			cout << "이름 : ";
			InputValue(SearchStd->StdName);
			cout << "학번 : ";
			InputValue(SearchStd->Hakbun);
		}

		else if (Type == "과목정보") {
			Subject* SearchSub = SubSearch(SearchStd[0]);
			cout << "*< " << SearchSub->SubName << ", 학점 : " << SearchSub->Hakjum << ", 등급: " << SearchSub->Grade << ">의 정보를 수정하세요\n";
			cout << "교과목명: ";
			InputValue(SearchSub->SubName);
			cout << "과목학점: ";
			InputValue(SearchSub->Hakjum);
			cout << "과목등급: ";
			InputValue(SearchSub->Grade);
			CalcGPA(*SearchSub);
			SearchStd->AveGPA = CalcAveGPA(SearchStd->Sub, SearchStd->SubNum);
		}
	}
}

int main() {

	cout << "학생수 입력 : ";
	InputValue(StdNum);
	Student* Std = new Student[StdNum];

	while (menu != 6) {

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

			Student * SearchStd; // 학생이름 탐색 결과를 받을 구조체
			SearchStd = StdSearch(Std, StdNum);
			if (SearchStd != NULL) {
				PrintOneData(*SearchStd, SearchStd->SubNum);
			}

			break;

		case 4:

			PrintAllStdList(Std, StdNum);
			break;

		case 5:

			ModifyStdInfo(Std, StdNum);

			break;

		case 6:

			cout << "프로그램을 종료합니다.\n";
			break;
		}
	}
	return 0;
}