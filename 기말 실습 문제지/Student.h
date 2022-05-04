#pragma once
#include "IOInterface.h"
#include <iostream>
#include <string>
using namespace std;

class Student :private IOInterface { //IOInterface�� private���� ���
private:
	string _Name; //�л� �̸�
	int _Score; //�л� ����

public:
	Student(); //�ʱ�ȭ�� ���� ������ 
	void PutName(); //_Name�� �� ����
	string GetName(); //_Name ��ȯ 
	void PutScore(); //_Score�� �� ����
	int GetScore(); //_Score ��ȯ
	void PrintData(); // ��ü�� ������ ���
};


Student::Student() {
	_Name = "����Ŭ ����"; //_Name�� "����Ŭ ����"���� �ʱ�ȭ
	_Score = 0; //_Score�� 0���� �ʱ�ȭ
}

void Student::PutName() { //�Է¹��� ���� _Name�� ����
	InputValue(_Name);
}

string Student::GetName() { //_Name�� ��ȯ
	return _Name;
}

void Student::PutScore() { //�Է¹��� ���� _Score�� ����
	InputValue(_Score);
}

int Student::GetScore() { //_Score�� ��ȯ 
	return _Score;
}

void Student::PrintData() { //GetName(), GetScore() �Լ� ȣ���� ���� ��ȯ���� ���� ���
	cout << "* �̸� : " <<GetName() << ", ���� : "<< GetScore()<<"\n";
}