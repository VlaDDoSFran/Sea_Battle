#include <iostream>

char** InitField() {
	int row = 10, column = 10;
	char** field = new char* [row];
	for (int i = 0; i < column; i++) {
		field[i] = new char[column];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			field[i][j] = ' ';
		}
	}
	return field;
}

void PrintField(char** field) {
	for (int k = 0; k < 41; k++) {
		std::cout << "-";
	}
	std::cout << "\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << "| " << field[i][j] << " ";
		}
		std::cout << "|" << "\n";
		for (int k = 0; k < 41; k++) {
			std::cout << "-";
		}
		std::cout << "\n";
	}
}

int main() {
	char** field = InitField();
	PrintField(field);
}