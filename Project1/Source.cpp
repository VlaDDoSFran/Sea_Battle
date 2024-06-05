#include <iostream>
#include <stdlib.h>
#include "windows.h"

// ������� ������������� ����
char** InitField() {
	// ���������� ���, ������� � ����.
	int row = 10, column = 10;
	char** field = new char* [row];
	for (int i = 0; i < row; i++) {
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
	std::cout << "� ��� ����:\n";
	Sleep(1000);
	std::cout << "�������������� - 1\n����������� - 2\n������������ - 3\n������������ - 4\n";
	Sleep(1000);
	std::cout << "����������� � �����������!\n";
	if (SetForPlacing == 0) {
		while (*four_deck != 0) {
			std::cout << "��������� 4-�������� �������:\n";
			int x, y;
			char RotateSelect;
			do {
				std::cout << "������� ������� ������ ������� (������ - ������� ����� �������): \n";
				std::cin >> x >> y;
			} while ((x < 0 && x > 9) && (y < 0 && y > 9));
			PlaceShip(field_player, 4, x, y);
			PrintField(field_player);
			std::cout << "��� ������� ������: |. ������� ��������� �������? (r, �� �������-�������� ����������): ";
			std::cin >> RotateSelect;
			if (RotateSelect == 'r' || RotateSelect == 'R') {
				RotateShip(field_player, 4, x, y);
			}
			(*four_deck)--;
			PrintField(field_player);
			Sleep(1000);
		}
		while (*three_deck != 0) {
			std::cout << "��������� 3-�������� �������:\n";
			int x, y;
			char RotateSelect;
			do {
				std::cout << "������� ������� ������ ������� (������): \n";
				std::cin >> x >> y;
			} while ((x < 0 && x > 9) && (y < 0 && y > 9));
			PlaceShip(field_player, 3, x, y);
			PrintField(field_player);
			std::cout << "��� ������� ������: |. ������� ��������� �������? (r, �� �������-�������� ����������): ";
			std::cin >> RotateSelect;
			if (RotateSelect == 'r' || RotateSelect == 'R') {
				RotateShip(field_player, 3, x, y);
			}
			(*three_deck)--;
			PrintField(field_player);
			Sleep(1000);
		}
		while (*two_deck != 0) {
			std::cout << "��������� 2-�������� �������:\n";
			int x, y;
			char RotateSelect;
			do {
				std::cout << "������� ������� ������ ������� (������): \n";
				std::cin >> x >> y;
			} while ((x < 0 && x > 9) && (y < 0 && y > 9));
			PlaceShip(field_player, 2, x, y);
			PrintField(field_player);
			std::cout << "��� ������� ������: |. ������� ��������� �������? (r, �� �������-�������� ����������): ";
			std::cin >> RotateSelect;
			if (RotateSelect == 'r' || RotateSelect == 'R') {
				RotateShip(field_player, 2, x, y);
			}
			(*two_deck)--;
			PrintField(field_player);
			Sleep(1000);
		}
		while (*one_deck != 0) {
			std::cout << "��������� 1-�������� �������:\n";
			int x, y;
			do {
				std::cout << "������� ������� ������ ������� (������): \n";
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
					std::cout << "�������, ���� �� ������� ��� ������ �������.\n";
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

// ������� ������� �� ���������� ��� ���� 

void GoPlay(int SetForPlay, int SetForPlacing, int SetForBot) {
	// ���� ������ � ���� ����������
	char** field_player1 = InitField();
	char** field_enemy1 = InitField();
	char** field_player2 = InitField();
	char** field_enemy2 = InitField();
	int four_deck1 = 1, three_deck1 = 2, two_deck1 = 3, one_deck1 = 4;
	int four_deck2 = 1, three_deck2 = 2, two_deck2 = 3, one_deck2 = 4;
	int turn = 1, i_ready;
	do {
		while (turn == 1) {
			std::cout << "������� " << turn << " ������.\n�� ������?\n(����� �����, ���� �� | 0 - ���, � ����):\n";
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
				std::cout << "������� " << turn << " ������.\n�� ������?\n(����� �����, ���� �� | 0 - ���, � ����):\n";
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
				std::cout << "������� ����.\n";
			}
		}
	} while (i_ready != 0);
}

int main() {
	setlocale(LC_ALL, "RU");
	// ���������� ��� ������
	enum{Exit = 0, Play, Options};
	// ���������� �������� ����
	int SelectInMenu, PlaySet = 0, PlacingSet = 0, BotSet = 0;
	do {
		// ���������� ��� ������
		enum{ExitOfOptions = 0, PlayMode, PlacingSettings, BotSettings};
		std::cout << "����� ���������� � ������� ���!";
		std::cout << "\n1 - ������\n2 - ���������\n0 - �����\n";
		std::cin >> SelectInMenu;
		if (SelectInMenu == Exit) {
			system("cls");
			std::cout << "�����...";
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
				std::cout << "�������� ���������:\n1 - ����� ����\n2 - ��������� ���������� ��������\n3 - ��������� ����\n0 - �����\n";
				std::cin >> SelectInOptions;
				if (SelectInOptions == ExitOfOptions) {
					system("cls");
					break;
				}
				else if (SelectInOptions == PlayMode) {
					do {
						system("cls");
						std::cout << "�������� ����� ����:\n0 - ������ ������\n1 - ������ ����������\n";
						std::cin >> PlaySet;
					} while (PlaySet < 0 || PlaySet > 1);
					system("cls");
				}
				else if (SelectInOptions == PlacingSettings) {
					do {
						system("cls");
						std::cout << "�������� ������� ���������� �������� � �������:\n0 - �������\n1 - �������������\n";
						std::cin >> PlacingSet;
					} while (PlacingSet < 0 || PlacingSet > 1);
					system("cls");
				}
				else if (SelectInOptions == BotSettings) {
					do {
						system("cls");
						std::cout << "�������� ����� ���� ��� ����������:\n0 - ��������� ��������\n1 - ���������������� ����\n";
						std::cin >> BotSet;
					} while (BotSet < 0 || BotSet > 1);
					system("cls");
				}
				else {
					system("cls");
					std::cout << "�������� �����!\n";
					continue;
				}
			}
		}
		else {
			system("cls");
			std::cout << "�������� �����!\n";
			continue;
		}
		
	} while (true);
}