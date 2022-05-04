#pragma once
#include <iostream>
#include <string>
#include "Subject.h"
#include "IOInterface.h"

using namespace std;

class Student:IOInterface {
protected:
	int _Hakbun;
	int _SubNum;
	Subject* _Sub;
	float _AveGPA;

public:
	Student();
	~Student();
	void modify();
	void InputData();
	void PrintData() const;
	string GetName();
	Subject* SubSearch();
	void CalcAveGPA();
};
