// Algoritm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Defines.h"
#include "SDek.cpp"

/*--------Functions----------*/
void StekPush();
void StekCreateStek();
void StekDopRandElems();
void StekShowElems();
void StekHowMuchElems();
void StekPop();
void sap();
void stek_menu();
void stek_glavn();
void stek_dop();
void DekCreateDek();
void dek_glavn();
void dek_menu();
void DekPush(int);
void DekHowMuchElems();
void dek_menu_push();
void dek_push_up();
void dek_push_down();
void DekShowElems();
void dek_dop();
void DekPop(int);
void dek_pop_up();
void dek_menu_pop();
void dek_pop_down();
/*--------------------------*/

/*-----Globals----*/
Stek *GStek = NULL;
Dek *GDek = NULL;
int menu_mode = 0;
/*----------------*/

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251);

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 3);

	menu->text[menu->slots].str = "D)����";
	menu->binds[menu->slots].binds = "D�";
	
	menu->pointers[menu->slots] = (int)(void*)&stek_menu;
	menu->slots++;

	menu->text[menu->slots].str = "F)���";
	menu->binds[menu->slots].binds = "F�";
	
	menu->pointers[menu->slots] = (int)(void*)&dek_menu;
	menu->slots++;

	menu->text[menu->slots].str = "G)����";
	menu->binds[menu->slots].binds = "G�";
	
	menu->pointers[menu->slots] = (int)(void*)&sap;

	menu->properties.header = "���� ���������:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 14;
	menu->properties.size.width = 30;
	menu->properties.dbreak.binds = "P�";
	
	menu->properties.prioritet = 0;

	SmartChoose(menu);

	_getch();
    return 0;
}

void StekDopRandElems() {
	cls(hStdout);
	int nums;
	say("��������� �������� �� 0 �� ");
	if (scanf_s("%d", &nums)) {
		GStek = GenerateNumsStek(GStek, nums);
	}
	else { error; }
}

void StekShowElems() {
	cls(hStdout);
	int nums;
	say("0:�������� ������ ������� �������� �����\n1:�������� ��� �������� �����\n�������� �����: ");
	if (scanf_s("%d", &nums)) {
		ShowStek(GStek, nums);
	}
	else { error; }
}

void StekCreateStek() {
	cls(hStdout);
	int nums;
	say("������� ���������� ��������� �����: ");
	if (scanf_s("%d", &nums)) {
		if (nums > 0) {
			GStek = CreateStek(nums);
			say("���� ������!");
			wt;
		}
		else {
			error1;
		}
	}
	else {
		error;
	}
}

void StekPush(){
	cls(hStdout);
	int nums;
	if (CheckFreeStek(GStek, 1)) {
		say("������� �����: ");
		if (scanf_s("%d", &nums)) {
			GStek = PushStek(GStek, nums);
			say("������� ��������");
			wt;
		}
		else {
			error;
		}
	}
}

void StekPop() {
	int last;
	cls(hStdout);
	err = 0;
	if (CheckFreeStek(GStek, 0)) {
		last = GetStekFirst(GStek);
		StekLoos(GStek);
		if (CheckFreeStek(GStek, 1)) {
			if (err == 0) {
				printf_s("���� ����� ����� %d � ������ �����, (������) ����� %d",last, GetStekFirst(GStek));
				wt;
			}
		}
	}
}

void StekHowMuchElems() {
	cls(hStdout);
	if (CheckFreeStek(GStek, 1)) {
		printf_s("\n�����: %d ��������� � �����\n", GStek->top);
		wt;
	}
}

void sap() {
	printf_s("���!!!\n");
	wt;
}

/*������� ����*/
void stek_menu() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 3);

	menu->text[menu->slots].str = "X)������� �������";
	menu->binds[menu->slots].binds = "X�";
	
	menu->pointers[menu->slots] = (int)(void*)&stek_glavn;
	menu->slots++;

	menu->text[menu->slots].str = "C)�������������� �������";
	menu->binds[menu->slots].binds = "C�";
	
	menu->pointers[menu->slots] = (int)(void*)&stek_dop;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "����:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 14;
	menu->properties.size.width = 29;
	menu->properties.dbreak.binds = "Z�";
	
	menu->properties.prioritet = 1;

	SmartChoose(menu);
}

/*���� �����*/
void stek_glavn() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 5);

	menu->text[menu->slots].str = "D)������� ����";
	menu->binds[menu->slots].binds = "D�";
	
	menu->pointers[menu->slots] = (int)(void*)&StekCreateStek;
	menu->slots++;

	menu->text[menu->slots].str = "F)PUSH";
	menu->binds[menu->slots].binds = "F�";
	
	menu->pointers[menu->slots] = (int)(void*)&StekPush;
	menu->slots++;

	menu->text[menu->slots].str = "G)POP";
	menu->binds[menu->slots].binds = "G�";
	
	menu->pointers[menu->slots] = (int)(void*)&StekPop;
	menu->slots++;

	menu->text[menu->slots].str = "C)��������� ������� �������";
	menu->binds[menu->slots].binds = "C�";
	
	menu->pointers[menu->slots] = (int)(void*)&StekHowMuchElems;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "������� �������:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 20;
	menu->properties.size.width = 32;
	menu->properties.dbreak.binds = "Z�";
	
	menu->properties.prioritet = 2;

	SmartChoose(menu);
}

/*��� ���� �����*/
void stek_dop() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 3);

	menu->text[menu->slots].str = "D)������������� ��������� ��������";
	menu->binds[menu->slots].binds = "D�";
	
	menu->pointers[menu->slots] = (int)(void*)&StekDopRandElems;
	menu->slots++;

	menu->text[menu->slots].str = "F)�������� ���� ����";
	menu->binds[menu->slots].binds = "F�";
	
	menu->pointers[menu->slots] = (int)(void*)&StekShowElems;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "�������������� �������:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 22;
	menu->properties.size.width = 39;
	menu->properties.dbreak.binds = "Z�";
	
	menu->properties.prioritet = 2;

	SmartChoose(menu);
}

/*Dek global menu*/
void dek_menu() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 3);

	menu->text[menu->slots].str = "X)������� �������";
	menu->binds[menu->slots].binds = "X�";
	
	menu->pointers[menu->slots] = (int)(void*)&dek_glavn;
	menu->slots++;

	menu->text[menu->slots].str = "C)�������������� �������";
	menu->binds[menu->slots].binds = "C�";
	
	menu->pointers[menu->slots] = (int)(void*)&dek_dop;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "���:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 14;
	menu->properties.size.width = 29;
	menu->properties.dbreak.binds = "Z�";
	
	menu->properties.prioritet = 1;

	SmartChoose(menu);
}

/*���� ����*/
void dek_glavn() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 5);

	menu->text[menu->slots].str = "D)������� ���";
	menu->binds[menu->slots].binds = "D�";
	
	menu->pointers[menu->slots] = (int)(void*)&DekCreateDek;
	menu->slots++;

	menu->text[menu->slots].str = "F)PUSH";
	menu->binds[menu->slots].binds = "F�";
	
	menu->pointers[menu->slots] = (int)(void*)&dek_menu_push;
	menu->slots++;

	menu->text[menu->slots].str = "G)POP";
	menu->binds[menu->slots].binds = "G�";
	
	menu->pointers[menu->slots] = (int)(void*)&dek_menu_pop;
	menu->slots++;

	menu->text[menu->slots].str = "C)��������� ������� �������";
	menu->binds[menu->slots].binds = "C�";
	
	menu->pointers[menu->slots] = (int)(void*)&DekHowMuchElems;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "������� �������:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 20;
	menu->properties.size.width = 32;
	menu->properties.dbreak.binds = "Z�";
	
	menu->properties.prioritet = 2;

	SmartChoose(menu);
}

/*Dek_push_vib*/
void dek_menu_push() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 3);

	menu->text[menu->slots].str = "X)�������� �� ����";
	menu->binds[menu->slots].binds = "X�";
	
	menu->pointers[menu->slots] = (int)(void*)&dek_push_up;
	menu->slots++;

	menu->text[menu->slots].str = "C)�������� � ����";
	menu->binds[menu->slots].binds = "C�";
	
	menu->pointers[menu->slots] = (int)(void*)&dek_push_down;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "Push:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 14;
	menu->properties.size.width = 29;
	menu->properties.dbreak.binds = "Z�";
	
	menu->properties.prioritet = 1;

	SmartChoose(menu);
}

/*��� ���� ����*/
void dek_dop() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 2);

	menu->text[menu->slots].str = "F)�������� ���� ����";
	menu->binds[menu->slots].binds = "F�";
	
	menu->pointers[menu->slots] = (int)(void*)&DekShowElems;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "�������������� �������:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 22;
	menu->properties.size.width = 39;
	menu->properties.dbreak.binds = "Z�";
	
	menu->properties.prioritet = 2;

	SmartChoose(menu);
}

/*Dek_pop_vib*/
void dek_menu_pop() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 3);

	menu->text[menu->slots].str = "X)����� � �����";
	menu->binds[menu->slots].binds = "X�";
	
	menu->pointers[menu->slots] = (int)(void*)&dek_pop_up;
	menu->slots++;

	menu->text[menu->slots].str = "C)����� � ����";
	menu->binds[menu->slots].binds = "C�";
	
	menu->pointers[menu->slots] = (int)(void*)&dek_pop_down;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "Pop:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 14;
	menu->properties.size.width = 29;
	menu->properties.dbreak.binds = "Z�";
	
	menu->properties.prioritet = 1;

	SmartChoose(menu);
}

void dek_push_up() {
	DekPush(0);
}

void dek_push_down() {
	DekPush(1);
}

void DekCreateDek() {
		cls(hStdout);
		int nums;
		say("������� ���������� ��������� ����: ");
		if (scanf_s("%d", &nums)) {
			if (nums > 0) {
				GDek = CreateDek(nums);
				say("��� ������!");
				wt;
			}
			else {
				error1;
			}
		}
		else {
			error;
		}
}

void DekPush(int l) {
	cls(hStdout);
	int nums;
	if (CheckFreeDek(GDek, 1)) {
		say("������� �����: ");
		if (scanf_s("%d", &nums)) {
			GDek = PushDek(GDek, nums, l);
			say("������� ��������");
			wt;
		} else {
			error;
		}
	}
}

void DekHowMuchElems() {
	cls(hStdout);
	if (CheckFreeDek(GDek, 1)) {
		printf_s("\n�����: %d ��������� � �����\n", (GDek->top - GDek->bottom));
		wt;
	}
}

void DekShowElems() {
	cls(hStdout);
	int nums;
	say("0:�������� ������ ������� �������� �����\n1:�������� ��� �������� �����\n�������� �����: ");
	if (scanf_s("%d", &nums)) {
		ShowDek(GDek, nums);
	}
	else { error; }
}


void dek_pop_up() {
	DekPop(0);
}

void dek_pop_down() {
	DekPop(1);
}

/*��������, ��� �� ���������� �������� ��������*/
void DekPop(int l) {
	int last;
	cls(hStdout);
	err = 0;
	if (CheckFreeDek(GDek, 0)) {
		if (l == 0) {
			last = GDek->nums[GDek->top - 1];
			GDek = PopDek(GDek, 0);
			if (err == 0) {
				printf_s("���� ����� ����� %d � ������ �����,(� ������) ����� %d", last, GDek->nums[GDek->top - 1]);
			}
			wt;
		} else {
			last = GDek->nums[GDek->bottom];
			GDek = PopDek(GDek, l);
			if (err == 0) {
				printf_s("���� ����� ����� %d � ������ �����,(� �����) ����� %d", last, GDek->nums[GDek->bottom]);
			}
			wt;
		}
	}
}