#include <iostream>
int sum_div(int num) {
	int sum = 0;
	for (int i = 1; i < num;i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	return sum;
}
int main() {
	int a, b;
	std::cout << "Enter a:";
	std::cin >> a;
	std::cout << "Enter b:";
	std::cin >> b;
	for (int i = a;i <= b;i++) {
		int para_num = sum_div(i);
		if (para_num > i && para_num <= b) {
			if (sum_div(para_num) == i) {
				std::cout << " para_nums: " << i << " and " << para_num;
			}
		}
	}
	return 0;

}