#include <iostream>
void MakingArray(int arr[], int n) {
	int choice;
	std::cout << "enter 1 or 2: ";
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "enter the elements of array: " << std::endl;
		for (int i = 0;i < n;i++) {
			std::cin >> arr[i];
		}
	}
	else {
		srand(time(NULL));
		int a, b;
		std::cout << "enter a and b: " << std::endl;
		std::cin >> a >> b;
		std::cout << "first array: ";
		for (int i = 0;i < n;i++) {
			arr[i] = a + rand() % (b-a+1);
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
}
void FindingMax(int arr[], int n) {
	for (int k = 1;k <= n; k++) {
		int MaxElem = 0;
		bool found = false;
		for (int i = 0;i < n;i++) {
			int count = 0;
			for (int j = 0;j < n;j++) {
				if(arr[i]==arr[j]{
				count++;
				}
			}
			if (count == k && (!found || arr[i] > MaxElem)) {
				MaxElem = arr[i];
				found = true;
				if (found) {
					std::cout << "max element: " << MaxElem << " kratnost: " << k;
					break;
				}

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
