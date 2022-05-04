#include <iostream>
using namespace std;

int main() {
	char name[10];
	cout << "(cout)이름을 입력하세요.\n";
	cout << "(cin)";
	cin >> name;
	cout << "(cout)당신의 이름은 " << name << " 입니다.";
}