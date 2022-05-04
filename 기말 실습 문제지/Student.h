#pragma once
#include "IOInterface.h"
#include <iostream>
#include <string>
using namespace std;

class Student :private IOInterface { //IOInterface를 private으로 상속
private:
	string _Name; //학생 이름
	int _Score; //학생 점수

public:
	Student(); //초기화를 위한 생성자 
	void PutName(); //_Name에 값 대입
	string GetName(); //_Name 반환 
	void PutScore(); //_Score에 값 대입
	int GetScore(); //_Score 반환
	void PrintData(); // 객체의 정보를 출력
};


Student::Student() {
	_Name = "마이클 조던"; //_Name을 "마이클 조던"으로 초기화
	_Score = 0; //_Score을 0으로 초기화
}

void Student::PutName() { //입력받은 값을 _Name에 대입
	InputValue(_Name);
}

string Student::GetName() { //_Name을 반환
	return _Name;
}

void Student::PutScore() { //입력받은 값을 _Score에 대입
	InputValue(_Score);
}

int Student::GetScore() { //_Score을 반환 
	return _Score;
}

void Student::PrintData() { //GetName(), GetScore() 함수 호출을 통해 반환받은 값을 출력
	cout << "* 이름 : " <<GetName() << ", 점수 : "<< GetScore()<<"\n";
}