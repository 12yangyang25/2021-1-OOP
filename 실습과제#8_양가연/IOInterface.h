#pragma once
#include <iostream>
#include <string>
using namespace std;

class IOInterface {
protected:
	void InputValue(int& num) {
		cin >> num;
		cin.ignore();
	}
	void InputValue(string& str) {
		getline(cin, str);
	}
};
