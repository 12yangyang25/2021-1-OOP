#include "Student.h"
#include "Subject.h"

void Student::InputValue(int& num) {
	cin >> num;
	cin.ignore();
}

void Student::InputValue(string& str) {
	getline(cin, str);
}

void Student::Initialize() {
	_StdName = "ȫ�浿";
	_Hakbun = 2019000000;
	_SubNum = 1;
}

void Student::Initialize(string StdName, int Hakbun, int SubNum) {
	_StdName = StdName;
	_Hakbun = Hakbun;
	_SubNum = SubNum;
}

void Student::Remove() {
	delete[] _Sub;
}

void Student::InputData() {
	int i;

	cout << "�̸�: ";
	InputValue(_StdName);
	cout << "�й�: ";
	InputValue(_Hakbun);
	cout << "�����  : ";
	InputValue(_SubNum);
	_Sub = new Subject[_SubNum];
	cout << "\n\n";

	for (i = 0; i < _SubNum; i++) {
		(_Sub + i)->InputData();
	}

}

void Student::PrintData() const {
	int i;

	cout << "�̸� : " << _StdName << "  �й� : " << _Hakbun << "\n";
	cout << "==============================================================\n";
	cout << "     �����        ��������    ������   ��������\n";
	cout << "==============================================================\n";

	for (i = 0; i < _SubNum; i++) {
		(_Sub + i)->PrintData();
	}
	cout << "==============================================================\n";
	cout << "                                              �������: ";
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