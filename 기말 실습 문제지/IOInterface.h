#pragma once
#include <iostream>
#include <string>
using namespace std;

  
class IOInterface {
	protected:
		void InputValue(string&);
		void InputValue(int&);
		virtual void PrintData() = 0;
};

void IOInterface::InputValue(int& ref) {
	cin >> ref;
}

void IOInterface::InputValue(string& ref) {
	getline(cin, ref);
	if (ref.empty()) getline(cin, ref);
}
void IOInterface::PrintData() {}







