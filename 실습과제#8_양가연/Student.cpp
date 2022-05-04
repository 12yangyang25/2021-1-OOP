#include "Student.h"
#include "Subject.h"

Student::Student() {
	_StdName = "홍길동";
	_Hakbun = 2019000000;
	_SubNum = 1;
	_Sub = new Subject[_SubNum];
}

Student::~Student() {
	delete[] _Sub;
}


string Student::GetStdName() {
	return _StdName;
}

Subject* Student::SubSearch() {

	int i;
	string SubName;
	cout << "검색 할 과목 이름: ";
	InputValue(SubName);

	for (i = 0; i < _SubNum; i++) {
		if (SubName == (_Sub + i)->GetSubName()) {
			return (_Sub+i);
		}
	}

	cout << "\n";
	cout << "에러가 발생하였습니다.";
	return NULL;
}

void Student::modify() {

	string Type;
	cout << "수정(학생정보/과목정보) : ";
	InputValue(Type);

	if (Type == "학생정보") {
		
		cout << "* <" << _StdName << ", " << _Hakbun << ">의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputValue(_StdName);
		cout << "학번 : ";
		InputValue(_Hakbun);
	}

	else if (Type == "과목정보") {
		Subject* SearchSub = SubSearch();
		SearchSub->modify();
		CalcAveGPA();
	}
}


void Student::InputData() {
	int i;

	cout << "이름: ";
	InputValue(_StdName);
	cout << "학번: ";
	InputValue(_Hakbun);
	cout << "과목수  : ";
	InputValue(_SubNum);
	_Sub = new Subject[_SubNum];
	cout << "\n\n";

	for (i = 0; i < _SubNum; i++) {
		(_Sub + i)->InputData();
	}

}

void Student::PrintData() const {
	int i;

	cout << "이름 : " << _StdName << "  학번 : " << _Hakbun << "\n";
	cout << "==============================================================\n";
	cout << "     과목명        과목학점    과목등급   과목평점\n";
	cout << "==============================================================\n";

	for (i = 0; i < _SubNum; i++) {
		(_Sub + i)->PrintData();
	}
	cout << "==============================================================\n";
	cout << "                                              평균평점: ";
	cout << _AveGPA << "\n";
}

void Student::CalcAveGPA() {
	float sum = 0;

	int i;
	for (i = 0; i < _SubNum; i++) {
		float GPA = 0;
		GPA = (_Sub + i)->GetGPA();
		sum += GPA;
		_AveGPA = sum /_SubNum;

	}
}