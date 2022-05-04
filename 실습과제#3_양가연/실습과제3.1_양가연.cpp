#include <iostream>
using namespace std;

template < typename T > void Sort(T arr[], int SIZE) {
	int minindex, i, j;
	T temp;

	for (i = 0; i < SIZE-1; i++) {
		minindex = i;
		for (j = i + 1; j < SIZE; j++) {
			if (arr[minindex] > arr[j]) {
				minindex = j;

				temp = arr[i];
				arr[i] = arr[minindex];
				arr[minindex] = temp;

			}
		}
	}
}
int main() {
	int IntArray[5];
	float FloatArray[5];
	int i, menu = -1, SIZE = 5;

	while (menu != 3) {
		cout << "1. 정수 정렬" << endl;
		cout << "2. 실수 정렬" << endl;
		cout << "3. 종료" << endl;
		cout << "메뉴 선택: ";
		cin >> menu;

		if (menu == 1 || menu == 2 || menu == 3) {
			switch (menu) {
			case 1:
				cout << "5개의 정수를 입력하세요: ";
				for (i = 0; i < 5; i++) {
					cin >> IntArray[i];
				}

				Sort(IntArray, SIZE);

				cout << "정렬결과: ";
				for (i = 0; i < 5; i++) {
					cout << IntArray[i] << " ";
				}cout << "\n\n";

				break;

			case 2:
				cout << "5개의 실수를 입력하세요: ";
				for (i = 0; i < 5; i++) {
					cin >> FloatArray[i];
				}

				Sort(FloatArray, SIZE);

				cout << "정렬결과: ";
				for (i = 0; i < 5; i++) {
					cout << FloatArray[i] << " ";
				}cout << "\n\n";

				break;

			case 3:
				break;
			}
		}

		else {
			cout << "에러가 발생하였습니다.\n\n";
		}


	}

	return 0;

}