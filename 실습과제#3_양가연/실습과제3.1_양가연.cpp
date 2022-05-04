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
		cout << "1. ���� ����" << endl;
		cout << "2. �Ǽ� ����" << endl;
		cout << "3. ����" << endl;
		cout << "�޴� ����: ";
		cin >> menu;

		if (menu == 1 || menu == 2 || menu == 3) {
			switch (menu) {
			case 1:
				cout << "5���� ������ �Է��ϼ���: ";
				for (i = 0; i < 5; i++) {
					cin >> IntArray[i];
				}

				Sort(IntArray, SIZE);

				cout << "���İ��: ";
				for (i = 0; i < 5; i++) {
					cout << IntArray[i] << " ";
				}cout << "\n\n";

				break;

			case 2:
				cout << "5���� �Ǽ��� �Է��ϼ���: ";
				for (i = 0; i < 5; i++) {
					cin >> FloatArray[i];
				}

				Sort(FloatArray, SIZE);

				cout << "���İ��: ";
				for (i = 0; i < 5; i++) {
					cout << FloatArray[i] << " ";
				}cout << "\n\n";

				break;

			case 3:
				break;
			}
		}

		else {
			cout << "������ �߻��Ͽ����ϴ�.\n\n";
		}


	}

	return 0;

}