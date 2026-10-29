#include <iostream>
#include <random>
#include <iomanip>
int *MakingArray(int &n) {
	std::cout << "enter n: ";
	std::cin >> n;
	int* arr = new int[n];
	int choice;
	std::cout << "enter 1 or 2: ";
	std::cin >> choice;
	if (choice == 1) {
		for (int i = 0; i < n;i++) {
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
			std::cout << std::setw(4) << arr[i];
		}
		std::cout << std::endl;
		return arr;
	}
}
int FindMin(int* arr, int n) {
	int min = arr[0];
	for (int i = 1;i < n;i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}
int FindMax(int* arr, int n) {
	int max = arr[0];
	for (int i = 1;i < n;i++) {
		if (arr[i] >max) {
			max = arr[i];
		}
	}
	return max;
}
int FinalMark(int* arr, int n, int min, int max) {
	int summa = 0;
	for (int i = 0;i < n;i++) {
		summa += arr[i];
	}
	int fsumma = summa - min - max;
	return fsumma / (n - 2);
}
void Results(int* arr, int n) {
	int min = FindMin(arr, n);
	int max = FindMax(arr, n);
	int res = FinalMark(arr, n, min, max);
	std::cout << "The final mark is: " << res << std::endl;
}
int main() {
	int n = 0;
	int *arr = MakingArray(n);
	Results(arr, n);
	delete[] arr;
	return 0;
}
