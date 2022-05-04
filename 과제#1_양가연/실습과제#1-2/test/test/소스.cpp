#include <iostream>
using namespace std;

int main() {
	int i1 = 10;
	int i2 = 20;
	const int* const p = &i2;
	p = &i1;
	*p = 40;

}