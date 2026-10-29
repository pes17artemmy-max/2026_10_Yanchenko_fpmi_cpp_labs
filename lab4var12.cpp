#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
int** MakingMatrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
	return matrix;

}
void DeleteMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < cols; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
void EnterMatrix(int** matrix, int rows, int cols) {
	std::cout << "Enter elements of matrix: " << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cin >> matrix[i][j];
		}
	}
}
void RandomMatrix(int** matrix, int rows, int cols,int a,int b) {
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = a + std::rand() % b;
		}
	}
}
void PrintMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << std::endl;
	}
}
int** PressMatrix(int** matrix, int rows, int cols, int& n, int& m) {
	int* row = new int[rows];
	int* col = new int[cols];

	n = 0;
	for (int i = 0; i < rows;i++) {
		int sum = 0;
		for (int j = 0; j < cols;j++) {
			sum += matrix[i][j];
		}
		if (sum == 0) {
			row[i] = 0;
		}
		else {
			row[i] = 1;
			n++;
		}
	}
	m = 0;
	for (int j = 0; j < cols;j++) {
		int sum = 0;
		for (int i = 0; i < rows;i++) {
			sum += matrix[i][j];
		}
		if (sum == 0) {
			col[j] = 0;
		}
		else {
			col[j] = 1;
			m++;
		}
	}
	int** press = MakingMatrix(n, m);
	int r = 0;
	for (int i = 0;i < rows;i++) {
		if (row[i] == 0) {
			continue;
		}
		int c = 0;
		for (int j = 0;j < cols;j++) {
			if (col[j] == 0) {
				continue;
			}
			press[r][c] = matrix[i][j];
			c++;
		}
		r++;
	}
	delete[] row;
	delete[] col;
	return press;
}
int main() {
	srand(time(NULL));
	int rows, cols;
	std::cout << "Enter rows: " << std::endl;
	std::cin >> rows;
	std::cout << "Enter cols: " << std::endl;
	std::cin >> cols;
	int** matrix = MakingMatrix(rows, cols);
	int choice;
	std::cout << "Enter: 1-keyboard, 2-random " << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		EnterMatrix(matrix, rows, cols);
	}
	else {
		int a, b;
		std::cout << "Enter a: " << std::endl;
		std::cin >> a;
		std::cout << "Enter b: " << std::endl;
		std::cin >> b;
		RandomMatrix(matrix, rows, cols, a, b);
	}
	std::cout << "First: ";
	PrintMatrix(matrix, rows, cols);
	int n = 0;
	int m = 0;
	int** press = PressMatrix(matrix, rows, cols, n, m);
	std::cout << "Finish: ";
	PrintMatrix(press, n, m);
	DeleteMatrix(matrix, rows, cols);
	DeleteMatrix(press, n, m);

	return 0;
}