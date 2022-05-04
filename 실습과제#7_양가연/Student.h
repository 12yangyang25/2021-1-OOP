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
	Student();
	~Student();
	void modify();
	void InputData();
	void PrintData() const;
	string GetStdName();
	Subject* SubSearch();
	void CalcAveGPA();
};
