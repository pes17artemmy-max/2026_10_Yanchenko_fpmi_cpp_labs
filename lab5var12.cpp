#include <iostream>
#include <string>
int main() {
	std::string text;
	std::cout << "enter english alfabet: ";
	std::getline(std::cin, text);
	for (int k = 1;k < 26;k++) {
		std::cout << "Key " << k << " : " << std::endl;
		for (size_t i = 0;i < text.length();i++) {
			char sym = text[i];
			if (sym >= 'A' && sym <= 'Z') {
				sym = 'A' + (sym - 'A' - k + 26) % 26;
			}
			else if(sym>='a'&& sym <='z') {
				sym = 'a' + (sym - 'a' - k + 26) % 26;
			}
			std::cout << sym;
		}
		std::cout << std::endl;
	}




	return 0;
}