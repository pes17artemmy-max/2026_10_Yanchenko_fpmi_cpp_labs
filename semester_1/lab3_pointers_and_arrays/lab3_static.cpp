#include <iostream>
#include <random>
#include <iomanip>
void MakingArray(int arr[], int n) {
	int choice;
	std::cout << "enter 1 or 2: ";
	std::cin >> choice;
	if (choice == 1) {
		for (int i = 0;i < n;i++) {
			std::cout << "enter the elements of array: " << std::endl;
			std::cin >> arr[i];
		}
	}
	else {
		srand(time(NULL));
		int a, b;
		std::cout << "enter a and b: " << std::endl;
		std::cin >> a >> b;
		for (int i = 0;i < n;i++) {
			arr[i] = a + rand() % b;
		}
		std::cout << "first array: ";
		for (int i = 0;i < n;i++) {
	     std::cout << std::setw(4)<< arr[i];
		}
		std::cout << std::endl;
	}
}
void FindingMax(int arr[], int n) {
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < n - 1 - i;j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int k = 1;k <= n; k++) {
		int MaxElem = 0;
		for (int i = 0;i < n;i++) {
			int current = arr[i];
			int count = 0;
			for (int j = 0;j < n;j++) {
				if (arr[j] == current) {
					count++;
				}
			}
			if (count == k && current > MaxElem) {
				MaxElem = current;
				std::cout << "max element: " << MaxElem << " kratnost: " << k << std::endl;
			}

		}
	}
}
int main() {
	const int n = 5;
	int arr[n];
	MakingArray( arr, n);
	FindingMax(arr, n);

	return 0;
}
