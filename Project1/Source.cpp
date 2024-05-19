#include <iostream>

// ������� ������������� ����
char** InitField() {
	// ���������� ���, ������� � ����.
	int row = 10, column = 10;
	char** field = new char* [row];
	for (int i = 0; i < column; i++) {
		field[i] = new char[column];
	}
	// ���������� ����� ������� ��������
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			field[i][j] = ' ';
		}
	}
	return field;
}

// ������� ������ ����
void PrintField(char** field) {
	// ����� ������ ����
	std::cout << "    ";
	for (int k = 0, counter = 0; k < 41 && counter < 10; k++) {
		if (k % 3 == 0) {
			std::cout << counter++ << " ";
			continue;
		}
		std::cout << " ";
	}
	std::cout << "\n";
	// ������� ������� ������
	std::cout << "  ";
	for (int k = 0; k < 41; k++) {
		std::cout << "-";
	}
	std::cout << "\n";
	// ���� ������� �������� � �� (����� �������� ����)
	for (int i = 0; i < 10; i++) {
		// ����� ����� ����
		std::cout << i << " ";
		// ��� �� ������
		for (int j = 0; j < 10; j++) {
			std::cout << "| " << field[i][j] << " ";
		}
		std::cout << "|" << "\n  ";
		// ������� ������
		for (int k = 0; k < 41; k++) {
			std::cout << "-";
		}
		std::cout << "\n";
	}
	// ������ ��� ���������� ����
	std::cout << "\n\n";
}

int main() {
	setlocale(LC_ALL, "RU");
	// ���� ������ � ���� ����������
	char** field_player = InitField();
	char** field_enemy = InitField();
	PrintField(field_player);
	PrintField(field_enemy);

}