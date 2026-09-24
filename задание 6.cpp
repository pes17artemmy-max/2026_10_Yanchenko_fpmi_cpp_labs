#include <iostream>
int main() {
	int a, b, d;
	std::cout << "enter start a: ";
	std::cin >> a;
	std::cout << "enter finish b: " ;
	std::cin >> b;
	std::cout << "enter difference d: " ;
	std::cin >> d;
	for (int i = a; i <= b;i +=d) {
		if (b % 3 == 0)
			std::cout << i <<" ";
		else {
			std::cout << "enter other numbers";
			return 1;
		}
	}

	return 0;
}