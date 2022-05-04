#pragma once
#include <iostream>
#include <string>
#include "Subject.h"

using namespace std;

class Student {
protected:
	string _StdName;
	int _Hakbun;
	int _SubNum;
	Subject* _Sub;
	float _AveGPA;

private:
	void InputValue(int&);
	void InputValue(string&);

public:
	void Initialize();
	void Initialize(string, int, int);
	void Remove();
	void InputData();
	void PrintData() const;
	void CalcAveGPA();
};
