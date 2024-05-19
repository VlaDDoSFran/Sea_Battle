#include <iostream>

// Функция инициализации поля
char** InitField() {
	// Переменные ряд, колонна и поле.
	int row = 10, column = 10;
	char** field = new char* [row];
	for (int i = 0; i < column; i++) {
		field[i] = new char[column];
	}
	// Заполнение полей пустыми ячейками
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			field[i][j] = ' ';
		}
	}
	return field;
}

// Функция печати поля
void PrintField(char** field) {
	// Цифры сверху поля
	std::cout << "    ";
	for (int k = 0, counter = 0; k < 41 && counter < 10; k++) {
		if (k % 3 == 0) {
			std::cout << counter++ << " ";
			continue;
		}
		std::cout << " ";
	}
	std::cout << "\n";
	// Верхняя граница клеток
	std::cout << "  ";
	for (int k = 0; k < 41; k++) {
		std::cout << "-";
	}
	std::cout << "\n";
	// Цикл повтора действий в нём (чтобы получить поле)
	for (int i = 0; i < 10; i++) {
		// Цифры сбоку поля
		std::cout << i << " ";
		// Ряд из колонн
		for (int j = 0; j < 10; j++) {
			std::cout << "| " << field[i][j] << " ";
		}
		std::cout << "|" << "\n  ";
		// Границы клеток
		for (int k = 0; k < 41; k++) {
			std::cout << "-";
		}
		std::cout << "\n";
	}
	// Отступ для следующего поля
	std::cout << "\n\n";
}

int main() {
	setlocale(LC_ALL, "RU");
	// Поле игрока и поле противника
	char** field_player = InitField();
	char** field_enemy = InitField();
	PrintField(field_player);
	PrintField(field_enemy);

}