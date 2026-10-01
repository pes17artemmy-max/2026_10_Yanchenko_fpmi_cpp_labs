#include <iostream>
#include <cmath>
#include <random>
void array(int arr[], int n) {
	int choice;
	std::cout << "1-keyboard, 2-random "<<std::endl;
	std::cin >> choice;
	if (choice == 1) {
		for (int i = 0;i < n;++i)
			std::cin >> arr[i];
		}
	else {
		int a, b;
		std::cout << "Interval [a,b]" << std::endl;
		std::cin >> a >> b;
		int range = b - a + 1;
		for (int i = 0;i < n;++i)
			arr[i] = a + std::rand() % (b - a + 1);
	}
	}
void MaxElement(const int arr[], int n) {
	if (n <= 0) {
		std::cout << "Empty array";
	}
	for (int k=1;k<=n;++k){
		int MaxElem = -210000000;
		bool found = false;
	for (int i = 0;i < n;i++) {
		int count = 0;
		for (int c = 0;c < n;c++) {
			if (arr[c] == arr[i]) count++;
		}
		if (count == k && arr[i] > MaxElem) {
			MaxElem = arr[i];
			found = true;
		}
	}
	if (found) {
		std::cout << "Elements"<<MaxElem<<"Count:"<<k<<std::endl;
	}
}
std::cout<< "No Elements";
}
int main() {
	const int Size = 300;
	int arr[Size];
	int n;
	std::cout << "enter a number of elements" << Size << std::endl;
	std::cin >> n;
	if (n>Size ||n <= 0) {
		std::cout << "Need another size!!!";
		return 1;
	}
	array(arr, n);
	std::cout << "Array:";
	for (int i = 0;i < n;++i)
		std::cout << arr[i] << " ";
	std::cout << "";
	MaxElement(arr, n);
	return 0;
}