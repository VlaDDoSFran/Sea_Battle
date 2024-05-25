#include <iostream>
#include <Windows.h>

// Функция инициализации поля
char** InitField() {
	// Переменные ряд, колонна и поле.
	int row = 10, column = 10;
	char** field = new char* [row];
	for (int i = 0; i < row; i++) {
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
	// Переменные для выбора
	enum{Exit = 0, Play, Options};
	do {
		// Переменные настроек игры
		int SelectInMenu, PlaySet = 0, PlacingSet = 0, BotSet = 0;
		// Переменные для выбора
		enum{ExitOfOptions = 0, PlayMode, PlacingSettings, BotSettings};
		std::cout << "Добро пожаловать в морской бой!";
		std::cout << "\n1 - Играть\n2 - Настройки\n0 - Выход\n";
		std::cin >> SelectInMenu;
		if (SelectInMenu == Exit) {
			system("cls");
			std::cout << "Выход...";
			break;
		}
		else if (SelectInMenu == Play) {
			system("cls");
			// Поле игрока и поле противника
			char** field_player = InitField();
			char** field_enemy = InitField();
			PrintField(field_player);
			PrintField(field_enemy);
		}
		else if (SelectInMenu == Options) {
			system("cls");
			while (true) {
				int SelectInOptions;
				std::cout << "Выберите настройки:\n1 - Режим игры\n2 - Настройки размещения кораблей\n3 - Настройки бота\n0 - Выход\n";
				std::cin >> SelectInOptions;
				if (SelectInOptions == ExitOfOptions) {
					system("cls");
					break;
				}
				else if (SelectInOptions == PlayMode) {
					system("cls");
					do {
						std::cout << "Выберите режим игры:\n0 - Против Игрока\n1 - Против Компьютера\n";
						std::cin >> PlaySet;
					} while (PlaySet < 0 || PlaySet > 1);
					system("cls");
				}
				else if (SelectInOptions == PlacingSettings) {
					system("cls");
					do {
						std::cout << "Выберите вариант размещения кораблей у игроков:\n0 - Вручную\n1 - Автоматически\n";
						std::cin >> PlacingSet;
					} while (PlacingSet < 0 || PlacingSet > 1);
					system("cls");
				}
				else if (SelectInOptions == BotSettings) {
					system("cls");
					do {
						std::cout << "Выберите режим игры для компьютера:\n0 - Случайные выстрелы\n1 - Интеллектуальная игра\n";
						std::cin >> BotSet;
					} while (BotSet < 0 || BotSet > 1);
					system("cls");
				}
				else {
					system("cls");
					std::cout << "Неверный выбор!\n";
					continue;
				}
			}
		}
		else {
			system("cls");
			std::cout << "Неверный выбор!\n";
			continue;
		}
		
	} while (true);
}