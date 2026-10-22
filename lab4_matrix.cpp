#include <iostream>
#include <iomanip>
#include <ctime>
int**matrix(int stroky, int stolby){
	int** matr = new int* [stroky];
	for (int i = 0; i < stroky; i++) {
		matr[i] = new int[stolby];
	}
	return matr;

}
void DeleteMatrix(int** matr, int stroky, int stolby) {
	for (int i = 0; i < stroky; i++) {
		delete[]matr[i];
	}
	delete[] matr;
}
void EnterMatrix(int** matr, int stroky, int stolby) {
	std::cout << "Enter elements of matrix: " << std::endl;
	for (int i = 0; i < stroky; i++) {
		for (int j = 0; j < stolby; j++) {
			std::cin >> matr[i][j];
		}
	}
}
void RandomMatrix(int** matr, int stroky, int stolby) {
	int a, b;
	std::cout << "Enter a: ";
		std::cin >> a;
		std::cout << "Enter b: ";
		std::cin >> b;
		srand(time(NULL));
		for (int i = 0; i < stroky; i++) {
			for (int j = 0; j < stolby; j++) {
				matr[i][j] = a + std::rand() % (b-a + 1);
			}
			}
		}
void PrintMatrix(int** matr, int stroky, int stolby) {
	for (int i = 0; i < stroky; i++) {
		for (int j = 0; j < stolby; j++) {
			std::cout << std::setw(5) << matr[i][j];
		}
		std::cout << std::endl;
	}
}
void ReduceMatrix(int** A, int n, int m) {
	int new_n = 0;
	int new_m = 0;
	bool* row = new bool[n]();
	bool* col = new bool[m]();

	for (int i = 0; i < n;i++) {
		int sum = 0;
		for (int j = 0; j < m;j++) {
			sum += A[i][j];
		}
		if (sum != 0) {
			row[i] = true;
			new_n++;
		}
	}

	for (int j = 0; j < m;j++) {
		int sum = 0;
		for (int i = 0; i < n;i++) {
			sum += A[i][j];
		}
		if (sum != 0) {
			col[j] = true;
			new_m++;
		}
	}
	std::cout << "First Matrix: " << std::endl;
	PrintMatrix(A, n, m);
	if (new_n == 0 || new_m == 0) {
		std::cout << "There is not sollution" << std::endl;
	}
	else {
		int** B = matrix(new_n, new_m);
		int b_i = 0;
		for (int i = 0; i < n;i++) {
			if (!row[i]) {
				continue;
			}
			int b_j = 0;
			for (int j = 0; j < m;j++) {
				if (!col[i]) {
					continue;
				}
				B[b_i][b_j] = A[i][j];
				b_j++;
			}
			b_i++;
		}
		std::cout << "Finish matrix: " << std::endl;
		PrintMatrix(B, new_n, new_m);
		DeleteMatrix(B, new_n, new_m);
	}
	delete[] row;
	delete[] col;
				
}
int main() {
	int n, m;
	std::cout << "Enter n: " << std::endl;
	std::cin >> n;
	std::cout << "Enter m: " << std::endl;
	std::cin >> m;
	int** A = matrix(n, m);
	int choice;
	std::cout << "Enter: 1-keyboard, 2-random " << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		EnterMatrix(A, n, m);
	}
	else {
		RandomMatrix(A, n, m);
	}
	ReduceMatrix(A, n, m);
	DeleteMatrix(A, n,m);
	return 0;
}