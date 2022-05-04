#pragma once
#include <string>
#include <iostream>
using namespace std;


class Subject {
protected:
	string _SubName;
	int _Hakjum;
	string _Grade;
	float _GPA;

private:
	void InputValue(int&);
	void InputValue(string&);

public:
	Subject();
	void modify();
	string GetSubName();
	void InputData();
	void PrintData() const;
	void CalcGPA();
	float GetGPA();
};
