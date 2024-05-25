#include <iostream>
#include <Windows.h>

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

int main() {
	setlocale(LC_ALL, "RU");
	// ���������� ��� ������
	enum{Exit = 0, Play, Options};
	do {
		// ���������� �������� ����
		int SelectInMenu, PlaySet = 0, PlacingSet = 0, BotSet = 0;
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
			// ���� ������ � ���� ����������
			char** field_player = InitField();
			char** field_enemy = InitField();
			PrintField(field_player);
			PrintField(field_enemy);
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
					system("cls");
					do {
						std::cout << "�������� ����� ����:\n0 - ������ ������\n1 - ������ ����������\n";
						std::cin >> PlaySet;
					} while (PlaySet < 0 || PlaySet > 1);
					system("cls");
				}
				else if (SelectInOptions == PlacingSettings) {
					system("cls");
					do {
						std::cout << "�������� ������� ���������� �������� � �������:\n0 - �������\n1 - �������������\n";
						std::cin >> PlacingSet;
					} while (PlacingSet < 0 || PlacingSet > 1);
					system("cls");
				}
				else if (SelectInOptions == BotSettings) {
					system("cls");
					do {
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