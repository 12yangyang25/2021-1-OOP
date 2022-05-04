#pragma once
#include <string>
#include <iostream>
#include "IOInterface.h"
using namespace std;


class Subject:IOInterface {
protected:
	string _SubName;
	int _Hakjum;
	string _Grade;
	float _GPA;

public:
	Subject();
	void modify();
	string GetSubName();
	void InputData();
	void PrintData() const;
	void CalcGPA();
	float GetGPA();
};
