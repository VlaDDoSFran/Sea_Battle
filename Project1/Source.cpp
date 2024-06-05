#include <iostream>
#include <stdlib.h>
#include "windows.h"

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

void PlaceShip(char** field_player, int type, int x, int y) {
	if (type == 4) {
		for (int i = 0; i < type; i++) {
			field_player[y++][x] = 'x';
		}
	}
	else if (type == 3) {
		for (int i = 0; i < type; i++) {
			field_player[y++][x] = 'x';
		}
	}
	else if (type == 2) {
		for (int i = 0; i < type; i++) {
			field_player[y++][x] = 'x';
		}
	}
	else if (type == 1) {
		field_player[y][x] = 'x';
	}
	else {
		return;
	}
}

void RotateShip(char** field_player, int type, int x, int y) {
	int prev_y = y;
	if (type == 4) {
		for (int i = 0; i < type; i++) {
			field_player[y++][x] = ' ';
		}
		for (int i = 0; i < type; i++) {
			field_player[x][prev_y++] = 'x';
		}
	}
	else if (type == 3) {
		for (int i = 0; i < type; i++) {
			field_player[y++][x] = ' ';
		}
		for (int i = 0; i < type; i++) {
			field_player[x][prev_y++] = 'x';
		}
	}
	else if (type == 2) {
		for (int i = 0; i < type; i++) {
			field_player[y++][x] = ' ';
		}
		for (int i = 0; i < type; i++) {
			field_player[x][prev_y++] = 'x';
		}
	}
	else {
		return;
	}
}

void PlayerIsPlace(char** field_player, char** field_enemy, int* four_deck, int* three_deck, int* two_deck, int* one_deck, int SetForPlacing) {
	std::cout << "У вас есть:\n";
	Sleep(1000);
	std::cout << "Четырёхпалубные - 1\nТрёхпалубные - 2\nДвухпалубные - 3\nОднопалубные - 4\n";
	Sleep(1000);
	std::cout << "Приступайте к расстановке!\n";
	if (SetForPlacing == 0) {
		while (*four_deck != 0) {
			std::cout << "Поставьте 4-палубные корабли:\n";
			int x, y;
			char RotateSelect;
			do {
				std::cout << "Введите позицию вашего корабля (начало - верхняя точка корабля): \n";
				std::cin >> x >> y;
			} while ((x < 0 && x > 9) && (y < 0 && y > 9));
			PlaceShip(field_player, 4, x, y);
			PrintField(field_player);
			std::cout << "Ваш корабль сейчас: |. Желаете повернуть корабль? (r, на взаимно-обратные координаты): ";
			std::cin >> RotateSelect;
			if (RotateSelect == 'r' || RotateSelect == 'R') {
				RotateShip(field_player, 4, x, y);
			}
			(*four_deck)--;
			PrintField(field_player);
			Sleep(1000);
		}
		while (*three_deck != 0) {
			std::cout << "Поставьте 3-палубные корабли:\n";
			int x, y;
			char RotateSelect;
			do {
				std::cout << "Введите позицию вашего корабля (начало): \n";
				std::cin >> x >> y;
			} while ((x < 0 && x > 9) && (y < 0 && y > 9));
			PlaceShip(field_player, 3, x, y);
			PrintField(field_player);
			std::cout << "Ваш корабль сейчас: |. Желаете повернуть корабль? (r, на взаимно-обратные координаты): ";
			std::cin >> RotateSelect;
			if (RotateSelect == 'r' || RotateSelect == 'R') {
				RotateShip(field_player, 3, x, y);
			}
			(*three_deck)--;
			PrintField(field_player);
			Sleep(1000);
		}
		while (*two_deck != 0) {
			std::cout << "Поставьте 2-палубные корабли:\n";
			int x, y;
			char RotateSelect;
			do {
				std::cout << "Введите позицию вашего корабля (начало): \n";
				std::cin >> x >> y;
			} while ((x < 0 && x > 9) && (y < 0 && y > 9));
			PlaceShip(field_player, 2, x, y);
			PrintField(field_player);
			std::cout << "Ваш корабль сейчас: |. Желаете повернуть корабль? (r, на взаимно-обратные координаты): ";
			std::cin >> RotateSelect;
			if (RotateSelect == 'r' || RotateSelect == 'R') {
				RotateShip(field_player, 2, x, y);
			}
			(*two_deck)--;
			PrintField(field_player);
			Sleep(1000);
		}
		while (*one_deck != 0) {
			std::cout << "Поставьте 1-палубные корабли:\n";
			int x, y;
			do {
				std::cout << "Введите позицию вашего корабля (начало): \n";
				std::cin >> x >> y;
				if (field_player[y][x] == 'x' ||
					field_player[y][x - 1] == 'x' ||
					field_player[y + 1][x - 1] == 'x' ||
					field_player[y + 1][x] == 'x' ||
					field_player[y + 1][x + 1] == 'x' ||
					field_player[y][x + 1] == 'x' ||
					field_player[y - 1][x + 1] == 'x' ||
					field_player[y - 1][x] == 'x' ||
					field_player[y - 1][x - 1] == 'x') {
					std::cout << "Область, куда вы ставите уже занята кораблём.\n";
					continue;
				}
				else {
					PlaceShip(field_player, 1, x, y);
					(*one_deck)--;
					break;
				}
			} while ((x < 0 && x > 9) && (y < 0 && y > 9));
			PrintField(field_player);
			Sleep(1000);
		}
	}
}

// Сделать функции по настройкам для бота 

void GoPlay(int SetForPlay, int SetForPlacing, int SetForBot) {
	// Поле игрока и поле противника
	char** field_player1 = InitField();
	char** field_enemy1 = InitField();
	char** field_player2 = InitField();
	char** field_enemy2 = InitField();
	int four_deck1 = 1, three_deck1 = 2, two_deck1 = 3, one_deck1 = 4;
	int four_deck2 = 1, three_deck2 = 2, two_deck2 = 3, one_deck2 = 4;
	int turn = 1, i_ready;
	do {
		while (turn == 1) {
			std::cout << "Очередь " << turn << " игрока.\nВы готовы?\n(Любое число, если да | 0 - нет, в меню):\n";
			std::cin >> i_ready;
			Sleep(1000);
			system("cls");
			PrintField(field_player1);
			PrintField(field_enemy1);
			PlayerIsPlace(field_player1, field_enemy1, &four_deck1, &three_deck1, &two_deck1, &one_deck1, SetForPlacing);
			system("cls");
			turn = 2;
		}
		while (turn == 2) {
			if (SetForPlay == 0) {
				std::cout << "Очередь " << turn << " игрока.\nВы готовы?\n(Любое число, если да | 0 - нет, в меню):\n";
				std::cin >> i_ready;
				Sleep(1000);
				system("cls");
				PrintField(field_player2);
				PrintField(field_enemy2);
				PlayerIsPlace(field_player2, field_enemy2, &four_deck2, &three_deck2, &two_deck2, &one_deck2, SetForPlacing);
				system("cls");
				turn = 1;
			}
			else if (SetForPlay == 1) {
				std::cout << "Очередь бота.\n";
			}
		}
	} while (i_ready != 0);
}

int main() {
	setlocale(LC_ALL, "RU");
	// Переменные для выбора
	enum{Exit = 0, Play, Options};
	// Переменные настроек игры
	int SelectInMenu, PlaySet = 0, PlacingSet = 0, BotSet = 0;
	do {
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
			GoPlay(PlaySet, PlacingSet, BotSet);
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
					do {
						system("cls");
						std::cout << "Выберите режим игры:\n0 - Против Игрока\n1 - Против Компьютера\n";
						std::cin >> PlaySet;
					} while (PlaySet < 0 || PlaySet > 1);
					system("cls");
				}
				else if (SelectInOptions == PlacingSettings) {
					do {
						system("cls");
						std::cout << "Выберите вариант размещения кораблей у игроков:\n0 - Вручную\n1 - Автоматически\n";
						std::cin >> PlacingSet;
					} while (PlacingSet < 0 || PlacingSet > 1);
					system("cls");
				}
				else if (SelectInOptions == BotSettings) {
					do {
						system("cls");
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