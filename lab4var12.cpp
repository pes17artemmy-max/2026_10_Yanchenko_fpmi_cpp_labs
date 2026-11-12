#include <iostream>
#include <iomanip>
#include <ctime>
int** MakingMatrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}
	return matrix;

}
void DeleteMatrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
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
	srand(time(NULL));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = a + std::rand() % (b-a+1);
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
int getRowSum(int** matrix, int row, int cols) {
	int sum = 0;
	for (int j = 0; j < cols; j++) {
		sum += matrix[row][j];
	}
	return sum;
}
int getColSum(int** matrix, int rows, int col) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		sum += matrix[i][col];
	}
	return sum;
}
void removeRow(int** matrix, int& rows, int dRow) {
	delete[] matrix[dRow];
	for (int i = dRow; i < rows - 1; i++) {
		matrix[i] = matrix[i + 1];
	}
	rows--;
}
void removeCol(int** matrix, int rows, int& cols, int dCol) {
	for (int i = 0; i < rows; i++) {
		for (int j = dCol; j < cols - 1; j++) {
			matrix[i][j] = matrix[i][j + 1];
		}
	}
	cols--;
}
void PressMatrix(int** matrix, int& rows, int& cols) {
	for (int i = 0; i < rows; i++) {
		if (getRowSum(matrix, i, cols) == 0) {
			removeRow(matrix, rows, i);
			i--;
		}
	}
	for (int j = 0; j < cols; j++) {
		if (getColSum(matrix, rows, j) == 0) {
			removeCol(matrix, rows, cols, j);
			j--;
		}
	}
}



int main() {
	int rows, cols;
	std::cout << "Enter rows and cols: " << std::endl;
	std::cin >> rows>>cols;
	int** matrix = MakingMatrix(rows, cols);
	int choice;
	std::cout << "Enter: 1 or 2: ";
	std::cin >> choice;
	if (choice == 1) {
		EnterMatrix(matrix, rows, cols);
	}
	else {
		int a, b;
		std::cout << "Enter a and b: " << std::endl;
		std::cin >> a>>b;
		RandomMatrix(matrix, rows, cols, a, b);
	}
	std::cout << "First matrix: "<<std::endl;
	PrintMatrix(matrix, rows, cols);
	PressMatrix(matrix, rows, cols);
	if (rows == 0 || cols == 0) {
		std::cout << "Empty matrix" << std::endl;
	}
	else {
		std::cout << "Finish matrix: " << std::endl;
		PrintMatrix(matrix, rows, cols);
	}
	DeleteMatrix(matrix, rows);
	
	return 0;
}
