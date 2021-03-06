#include "Subject.h"
#include "Student.h"

Subject::Subject() {
	_Name = "국어";
	_Hakjum = 3;
	_Grade = "A";
}

string Subject::GetName() {
	return _Name;
}

void Subject::modify() {
	cout << "*< " << _Name << ", 학점 : " << _Hakjum << ", 등급: " << _Grade << ">의 정보를 수정하세요\n";
	cout << "교과목명: ";
	InputValue(_Name);
	cout << "과목학점: ";
	InputValue(_Hakjum);
	cout << "과목등급: ";
	InputValue(_Grade);
	CalcGPA();

}

void Subject::CalcGPA() {

	if (_Grade == "A+") {
		_GPA = 4.5 * _Hakjum;
	}
	else if (_Grade == "A0") {
		_GPA = 4.0 * _Hakjum;
	}
	else if (_Grade == "B+") {
		_GPA = 3.5 * _Hakjum;
	}
	else if (_Grade == "B0") {
		_GPA = 3.0 * _Hakjum;
	}
	else if (_Grade == "C+") {
		_GPA = 2.5 * _Hakjum;
	}
	else if (_Grade == "C0") {
		_GPA = 2.0 * _Hakjum;
	}
	else if (_Grade == "D+") {
		_GPA = 1.5 * _Hakjum;
	}
	else if (_Grade == "D0") {
		_GPA = 1.0 * _Hakjum;
	}
	else if (_Grade == "F") {
		_GPA = 0 * _Hakjum;
	}
}

void Subject::InputData() {

	cout << "교과목명: ";
	InputValue(_Name);
	cout << "과목학점수: ";
	InputValue(_Hakjum);
	cout << "과목등급(A+ ~ F): ";
	InputValue(_Grade);
	CalcGPA();
	cout << "\n\n";
}

void Subject::PrintData() const {

	cout.width(12);
	cout << _Name;
	cout.width(12);
	cout << _Hakjum;
	cout.width(12);
	cout << _Grade;
	cout.width(12);
	cout << _GPA << "\n";
}

float Subject::GetGPA() {
	return _GPA;
}