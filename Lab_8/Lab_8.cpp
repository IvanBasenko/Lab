// Lab_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CMenu.cpp"
#include "Defs.h"

void _say(char *str) {
	printf_s("%s", str);
}

int main() {
	int slots = 0;
	Menu *menu = NULL;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	menu = CMenu(menu, 2);

	menu->text[menu->slots].str = "D)��������������� ������ ������ � ��� ��������";
	menu->binds[menu->slots].binds = "D�";
	menu->binds[menu->slots].count = 2;
	menu->pointers[menu->slots] = (int)(void*)&NReTranslateToString;
	menu->slots++;

	menu->text[menu->slots].str = "F)�������� ����� �� ������������";
	menu->binds[menu->slots].binds = "F�";
	menu->binds[menu->slots].count = 2;
	menu->pointers[menu->slots] = (int)(void*)&NIsPalendomizm;

	menu->properties.header = "���� ���������:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 11;
	menu->properties.size.width = 51;
	menu->properties.dbreak.binds = "P�";
	menu->properties.dbreak.count = 2;
	menu->properties.prioritet = 0;

	SmartChoose(menu);

	_getch();

	return 1;
}