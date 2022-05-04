#include "Student.h"
#include "Subject.h"

Student::Student() {
	_StdName = "ȫ�浿";
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
	cout << "�˻� �� ���� �̸�: ";
	InputValue(SubName);

	for (i = 0; i < _SubNum; i++) {
		if (SubName == (_Sub + i)->GetSubName()) {
			return (_Sub+i);
		}
	}

	cout << "\n";
	cout << "������ �߻��Ͽ����ϴ�.";
	return NULL;
}

void Student::modify() {

	string Type;
	cout << "����(�л�����/��������) : ";
	InputValue(Type);

	if (Type == "�л�����") {
		
		cout << "* <" << _StdName << ", " << _Hakbun << ">�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(_StdName);
		cout << "�й� : ";
		InputValue(_Hakbun);
	}

	else if (Type == "��������") {
		Subject* SearchSub = SubSearch();
		SearchSub->modify();
		CalcAveGPA();
	}
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