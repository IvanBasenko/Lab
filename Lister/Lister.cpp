// Lister.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CMenu.cpp"

#define error _error()
#define say(text) _say(text);

void _error() {
	printf_s("������ �����!\n ");
	rewind(stdin);
}

void _say(char *text) {
	printf_s(text);
}

typedef struct {
	int number; /*��������*/
	int *previus; /*���������� �������*/
} StekItem;

typedef struct {
	StekItem *first; /*������ �������*/
	int count; /*������*/
} StekDescr;

typedef struct {
	int number; /*��������*/
	int *previus; /*��������� �������*/
	int *after; /*���������� �������*/
} DekItem;

typedef struct {
	DekItem *first; /*������ �������*/
	DekItem *last; /*��������� �������*/
	int count; /*������*/
} DekDescr;

typedef struct {
	int number;
	int *next;
} SpisItem;

typedef struct {
	int count;
	SpisItem *first;
} SpisDescr;

StekDescr *StekCreateItem(int, StekDescr*);
StekDescr* StekDeletItem(StekDescr*);

DekDescr* DekCreateItem(int, int , DekDescr*);

void sap();
void stek_menu();
void stek_glavn();
void dek_glavn();
void dek_menu();
void DPD();
void DPU();
void DOU();
void DOD();
void dek_menu_push();
void dek_menu_pop();
int SetkError(StekDescr*);
int DekError(DekDescr*);
void StekShow();
void DekPush(int);
void DekPop(int);
void DekCount();
void StekGeneration(int);
void StekGenerations();
void spis_glavn();

void DekShow();

int menu_mode;
StekDescr *SDes;
DekDescr *DDes;

int main()
{
	int slots = 0;
	Menu *menu = NULL;

	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SDes = (StekDescr*)malloc(sizeof(StekDescr));
	SDes->count = 0;

	DDes = (DekDescr*)malloc(sizeof(DekDescr));
	DDes->count = 0;
	DDes->last = NULL;

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	menu = CMenu(menu, 3);

	menu->text[menu->slots].str = "D)����";
	menu->binds[menu->slots].binds = "D�";
	menu->pointers[menu->slots] = (int)(void*)&stek_glavn;
	menu->slots++;

	menu->text[menu->slots].str = "F)���";
	menu->binds[menu->slots].binds = "F�";
	menu->pointers[menu->slots] = (int)(void*)&dek_glavn;
	menu->slots++;

	menu->text[menu->slots].str = "G)����";
	menu->binds[menu->slots].binds = "G�";
	menu->pointers[menu->slots] = (int)(void*)&spis_glavn;

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

void StekGeneration(int count) {
	int i;
	for (i = 0; i < count; i++) {
		StekCreateItem(rand() % count + 1, SDes);
	}
}

void StekGenerations() {
	int num;
	say("������� ��������� �������������: ");
	if (scanf_s("%d", &num)) {
		if (num < 25000000) {
			StekGeneration(num);
			say("���� ������������ �������.");
		} else {
			say("������� ����� ���������!");
			_getch();
		}
	} else {
		error;
	}
}

StekDescr* StekCreateItem(int number, StekDescr *des) {
	StekItem* item = (StekItem*)malloc(sizeof(StekItem));
	item->previus = (int*)des->first;
	item->number = number;

	des->first = item;
	des->count++;
	return des;
}

StekDescr* StekDeletItem(StekDescr *des) {
	StekItem *last;
	last = des->first;
	des->first = (StekItem*)des->first->previus;
	free(last);
	des->count--;
	return des;
}

int SetkError(StekDescr *des) {
	if (des->count != 0) {
		if (des->count < 2) {
			say("������. � ����� 1 �������, ������ �� ��������!");
			_getch();
			return 0;
		} else { return 1; }
	} else {
		say("������. ���� ������!");
		_getch();
		return 0;
	}
}

void StekPush() {
	int num;
	say("������� �����: ");
	if (scanf_s("%d", &num)) {
		SDes = StekCreateItem(num, SDes);
		say("����� ������� ��������!\n");
		StekShow();
	} else {
		error;
	}
	_getch();
}

void StekPop() {
	if (SetkError(SDes)) {
		SDes = StekDeletItem(SDes);
		printf_s("������� ������� �����, ������ ����� ������� �������: %d\n", SDes->first->number);
		StekShow();
		_getch();
	} else {
		
	}
}

void StekShow() {
	FILE *file;
	StekItem *dl = SDes->first;
	int i, count = 0, *arr;
	if (SDes->count < 500) {
		arr = (int*)malloc(sizeof(int)*SDes->count);
		for (i = 0; i < SDes->count; i++) {
			arr[i] = dl->number;
			dl = (StekItem*)dl->previus;
		}
		say("����: ");
		for (i = SDes->count - 1; i >= 0; i--) {
			printf_s("%d,", arr[i]);
		}
	} else {
		dl = SDes->first;
		arr = (int*)malloc(sizeof(int)*SDes->count);
		for (i = 0; i < SDes->count; i++) {
			arr[i] = dl->number;
			dl = (StekItem*)dl->previus;
		}
		fopen_s(&file, "StekElems.txt", "w");
		for (i = SDes->count - 1; i >= 0; i--) {
			if (count >= 40) {
				fprintf_s(file, "\n");
				count = 0;
			}
			fprintf_s(file, "%d,", arr[i]);
			count++;
		}
		fclose(file);
		say("������� ����� ��������� ��� ������, ����� ��������� � ���� StekElems.txt � ����� � ����������");
	}
}

void StekCount() {
	printf_s("� �����: %d ���������.\n", SDes->count);
	StekShow();
	_getch();
}

/*DECK ZONE*/

void DekGeneration(int count) {
	int i;
	for (i = 0; i < count; i++) {
		DekCreateItem(rand() % count + 1,0,DDes);
	}
}

void DekGenerations() {
	int num;
	say("������� ��������� �������������: ");
	if (scanf_s("%d", &num)) {
		if (num < 25000000) {
			DekGeneration(num);
			say("��� ������������ �������.");
		} else {
			say("������� ����� ���������!");
			_getch();
		}
	} else {
		error;
	}
}

DekDescr* DekCreateItem(int number,int type,DekDescr *des) {
	DekItem* item = (DekItem*)malloc(sizeof(DekItem));
	DekItem* iteml;
	switch (type) {
		case 0:
			if (des->last == NULL) {
				des->last = item;
			} else {
				iteml = des->first;
				iteml->previus = (int*)item;
				item->after = (int*)iteml;
			}
			item->number = number;

			des->first = item;
			des->count++;
			break;
		case 1:
			if (des->last == NULL) {
				des->last = item;
				des->first = item;
			} else {
				iteml = des->last;
				iteml->after = (int*)item;
				item->previus = (int*)iteml;
			}
			item->number = number;

			des->last = item;
			des->count++;
			break;
	}
	return des;
}

DekDescr* DekDeletItem(DekDescr *des,int type) {
	DekItem *last;
	switch (type)
	{
		case 0:
			last = des->first;
			des->first = (DekItem*)des->first->after;
			free(last);
			des->count--;
			break;
		case 1:
			last = des->last;
			des->last = (DekItem*)des->last->previus;
			free(last);
			des->count--;
			break;
	}
	return des;
}

int DekError(DekDescr *des) {
	if (des->count != 0) {
		if (des->count < 2) {
			say("������. � ���� 1 �������, ������ �� ��������!");
			_getch();
			return 0;
		} else { return 1; }
	} else {
		say("������. ��� ������!");
		_getch();
		return 0;
	}
}

void DPU() { DekPush(0); }
void DPD() { DekPush(1); }
void DOU() { DekPop(0); }
void DOD() { DekPop(1); }

void DekPush(int type) {
	int num;
	say("������� �����: ");
	if (scanf_s("%d", &num)) {
		DDes = DekCreateItem(num, type, DDes);
		say("����� ������� ��������!\n");
		DekShow();
	} else {
		error;
	}
	_getch();
}

void DekPop(int type) {
	int last;
	DekItem *now;
	if (DekError(DDes)) {
		if (type == 0) {
			printf_s("������");
			last = DDes->first->number;
			DDes = DekDeletItem(DDes, type);
			now = (DekItem*)DDes->first->number;
		} else {
			printf_s("���������");
			last = DDes->last->number;
			DDes = DekDeletItem(DDes, type);
			now = (DekItem*)DDes->last->number;
		}
		printf_s(" ������� %d ����, ����� ��������� ������� %d\n", (int)last, (int)now);
		DekShow();
		_getch();
	}
}

void DekShow() {
	FILE *file;
	DekItem *dl;
	int i, count = 0;
	if (DDes->count < 500) {
	    dl = DDes->last;
		say("���: ");
		for (i = 0; i < DDes->count; i++) {
			printf_s("%d,", dl->number);
			dl = (DekItem*)dl->previus;
		}
	} else {
		dl = DDes->last;
		fopen_s(&file, "DekElems.txt", "w");
		for (i = 0; i < DDes->count; i++) {
			if (count >= 40) {
				fprintf_s(file, "\n");
				count = 0;
			}
			fprintf_s(file, "%d,",dl->number);
			dl = (DekItem*)dl->previus;
			count++;
		}
		fclose(file);
		say("������� ����� ��������� ��� ������, ����� ��������� � ���� DekElems.txt � ����� � ����������");
	}
}

void DekCount() {
	printf_s("� ���� %d ���������.\n",DDes->count);
	DekShow();
	_getch();
}

void sap() {

}

/*���� �����*/
void stek_glavn() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 5);

	menu->text[menu->slots].str = "D)������������� ��������� ����";
	menu->binds[menu->slots].binds = "D�";
	menu->pointers[menu->slots] = (int)(void*)&StekGenerations;
	menu->slots++;

	menu->text[menu->slots].str = "F)PUSH(�������� � ����)";
	menu->binds[menu->slots].binds = "F�";
	menu->pointers[menu->slots] = (int)(void*)&StekPush;
	menu->slots++;

	menu->text[menu->slots].str = "G)POP(����� � �����)";
	menu->binds[menu->slots].binds = "G�";
	menu->pointers[menu->slots] = (int)(void*)&StekPop;
	menu->slots++;

	menu->text[menu->slots].str = "C)��������� ������� �����";
	menu->binds[menu->slots].binds = "C�";
	menu->pointers[menu->slots] = (int)(void*)&StekCount;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "������� ������� �����:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 20;
	menu->properties.size.width = 35;
	menu->properties.dbreak.binds = "Z�";
	menu->properties.prioritet = 2;

	SmartChoose(menu);
}

/*���� ����*/
void dek_glavn() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 5);

	menu->text[menu->slots].str = "D)������������� ��������� ���";
	menu->binds[menu->slots].binds = "D�";
	menu->pointers[menu->slots] = (int)(void*)&DekGenerations;
	menu->slots++;

	menu->text[menu->slots].str = "F)PUSH(�������� � ���)";
	menu->binds[menu->slots].binds = "F�";
	menu->pointers[menu->slots] = (int)(void*)&dek_menu_push;
	menu->slots++;

	menu->text[menu->slots].str = "G)POP(����� � ����)";
	menu->binds[menu->slots].binds = "G�";
	menu->pointers[menu->slots] = (int)(void*)&dek_menu_pop;
	menu->slots++;

	menu->text[menu->slots].str = "C)��������� ������� ����";
	menu->binds[menu->slots].binds = "C�";
	menu->pointers[menu->slots] = (int)(void*)&DekCount;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "������� ������� ����:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 20;
	menu->properties.size.width = 34;
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
	menu->pointers[menu->slots] = (int)(void*)&DPU;
	menu->slots++;

	menu->text[menu->slots].str = "C)�������� � ����";
	menu->binds[menu->slots].binds = "C�";
	menu->pointers[menu->slots] = (int)(void*)&DPD;
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

/*Dek_pop_vib*/
void dek_menu_pop() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 3);

	menu->text[menu->slots].str = "X)����� � �����";
	menu->binds[menu->slots].binds = "X�";
	menu->pointers[menu->slots] = (int)(void*)&DOU;
	menu->slots++;

	menu->text[menu->slots].str = "C)����� � ����";
	menu->binds[menu->slots].binds = "C�";
	menu->pointers[menu->slots] = (int)(void*)&DOD;
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

/*���� ������*/
void spis_glavn() {
	int slots = 0;
	Menu *menu = NULL;

	menu = CMenu(menu, 5);

	menu->text[menu->slots].str = "D)������������� ��������� ������";
	menu->binds[menu->slots].binds = "D�";
	menu->pointers[menu->slots] = (int)(void*)&sap;
	menu->slots++;

	menu->text[menu->slots].str = "F)����� ������� � ������� ���������";
	menu->binds[menu->slots].binds = "F�";
	menu->pointers[menu->slots] = (int)(void*)&sap;
	menu->slots++;

	menu->text[menu->slots].str = "F)�������� ���� � ������";
	menu->binds[menu->slots].binds = "F�";
	menu->pointers[menu->slots] = (int)(void*)&sap;
	menu->slots++;

	menu->text[menu->slots].str = "G)������ ���� � ������";
	menu->binds[menu->slots].binds = "G�";
	menu->pointers[menu->slots] = (int)(void*)&sap;
	menu->slots++;

	menu->text[menu->slots].str = "C)��������� ������� ������";
	menu->binds[menu->slots].binds = "C�";
	menu->pointers[menu->slots] = (int)(void*)&sap;
	menu->slots++;

	menu->text[menu->slots].str = "Z)�����";
	menu->binds[menu->slots].binds = NULL;
	menu->pointers[menu->slots] = (int)NULL;

	menu->properties.header = "������� ������� ������:";
	menu->properties.height = 0;
	menu->properties.coords.x = 7;
	menu->properties.coords.y = 4;
	menu->properties.size.height = 23;
	menu->properties.size.width = 40;
	menu->properties.dbreak.binds = "Z�";
	menu->properties.prioritet = 2;

	SmartChoose(menu);
}