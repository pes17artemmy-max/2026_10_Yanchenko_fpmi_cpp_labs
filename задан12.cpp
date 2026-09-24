#include <iostream>
int main() {
	int a, b;
	std::cout << "enter start a:"<<endl;
	std::cin >> a;
	std::cout << "enter finish b:"<<endl;
	std::cin >> b;
	for (int i = a;i <= b;i++) {
		int sum_i = 0;
		for (int d = 1; d < i;d++) {
			if (i % d == 0) {
				sum_i += d;
			}
		}
		int c = sum_i;
		if (c > i && c <= b) {
			int sum_c = 0;
			for (int d = 1;d < c;d++) {
				if (c % d == 0) {
					sum_c += d;
				}
			}
			if (sum_c == i) {
				std::cout << i << "i" << c<<endl;
			}
			}
			}
	return 0;
}