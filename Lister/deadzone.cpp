#include "stdafx.h"
#include "CMenu.cpp"
#include "Defines.h"
#include "DekH.h"
#include "StekH.h"
#include "ListH.h"

/*����*/
//struct List {
//	int num; /*�����*/
//	struct List *next; /*������ �� ��������� ����*/
//};

//struct List *GList; /*��������� �� ������*/

/*
extern struct List *CreateFirstElem(int num);
extern struct List *AddItem(struct List *list, int num);
extern struct List *ListAddIndexedElement(struct List *list, int index, int number, int method);
extern struct List *RemoveIndexedElement(struct List *list, int index);
extern int GiveCountOfList(struct List *list);
extern int IsListEmpty(struct List *list);
extern void AddIndexedItemList(int mode);
extern void ListShow(struct List *list);
extern void ALU();
extern void ALD();
extern void ListSearchByNum();
extern void GetCountList();
extern void list_glavn();
extern void list_menu_add();
extern void RemoveItemFromList();
extern void list_menu_search();
extern void ListSearchByIndex();
extern void ListGeneration();
extern void AddItemList();
*/

struct List *GList; /*��������� �� ������*/
/*-----DEEP-DEAD-ZONE-----*/

/*------SPISOK-ZONE-------*/

/*�������� ������� �������� ������*/
struct List *CreateFirstElem(int num) {
	/*��������� �� ��������� ������*/
	struct List *list = (struct List*)malloc(sizeof(struct List));
	list->num = num;
	list->next = list;
	return list;
}

/*�������� ������� � ������*/
struct List *AddItem(struct List *list, int num) {
	struct List *item, /*��������� �� ������� ������*/
		*p; /*��������� �� ������� ������*/
	if (IsListEmpty(list)) {
		item = (struct List*)malloc(sizeof(struct List));
		p = list->next;
		item->num = num;
		list->next = item;
		item->next = p;
	}
	else {
		list = CreateFirstElem(num);
	}
	return list;
}

/*������������ �����*/
void ListShow(struct List *list) {
	struct List *p; /*��������� �� ������*/
	int *arra = (int*)malloc(sizeof(int)), /*��������� �� �����*/
		i = 0, /*�������*/
		j = 0; /*�������*/
	p = list;
	if (IsListEmpty(list)) {
		if (GiveCountOfList(list) < 500) {
			if (GiveCountOfList(list) > 1) {
				do {
					arra = (int*)realloc(arra, sizeof(int)*(i + 1));
					arra[i] = p->num;
					p = p->next;
					i++;
				} while (p != list);
				say("������: ");
				while (i != 1) {
					if (j == 0) {
						printf_s("%d,", arra[0]);
						j++;
					}
					i--;
					printf_s("%d,", arra[i]);
				}
			}
			else {
				say("������: ");
				printf_s("%d", list->num);
			}
		}
		else {
			say("������� ����� ��������� ��� ������.");
		}
	}
	else {
		printf_s("������. ���� ������.");
	}
}

/*�������� ������� � ������ �� ��������� �������*/
struct List *ListAddIndexedElement(struct List *list, int index, int number, int method) {
	int i = 0; /*�������*/
	struct List *item, /*��������� �� ������� ������*/
		*p, /*��������� �� ������� ������*/
		*l = list; /*��������� �� ������� ������*/
	item = (struct List*)malloc(sizeof(struct List));

	/*�������� �����*/
	if (method == 0) {
		for (i = 0; i < GiveCountOfList(list) - index + 1; i++) {
			l = l->next;
		}
	}
	else {
		/*�������� �����*/
		for (i = 0; i < GiveCountOfList(list) - index; i++) {
			l = l->next;
		}
	}
	p = l->next;
	item->num = number;
	l->next = item;
	item->next = p;

	return list;
}

/*�������� ��������� �������� �� �������*/
struct List *RemoveIndexedElement(struct List *list, int index) {
	int i; /*�������*/
	struct List *l = list; /*��������� �� ������*/
	if (GiveCountOfList(list) > 1) {
		for (i = 0; i < GiveCountOfList(list) - index; i++) {
			l = l->next;
		}
		l->next = l->next->next;
	}
	else {
		free(list);
		list = NULL;
	}
	return list;
}

/*�������� ����� ���������*/
int GiveCountOfList(struct List *list) {
	struct List *l = list; /*��������� �� ������*/
	int i = 0; /*�������*/
	if (IsListEmpty(list)) {
		do {
			l = l->next;
			i++;
		} while (l != list);
	}
	return i;
}

/*�������� �� ������ ������*/
int IsListEmpty(struct List *list) {
	int i = 1; /*������*/
	if (list == NULL) {
		i = 0;
	}
	return i;
}

/*������ ������� � ������*/
void RemoveItemFromList() {
	int i; /*�������*/
	if (IsListEmpty(GList)) {
		ListShow(GList);
		say("\n������� ����� �������� ������ ������� �� ������ �������: ");
		if (scanf_s("%d", &i)) {
			if (i > 1) {
				if (i <= GiveCountOfList(GList)) {
					GList = RemoveIndexedElement(GList, i);
					printf_s("������� � �������� %d ��� �����.\n", i);
					ListShow(GList);
					_getch();
				}
				else {
					say("������. �� ����� ������ �� ������������� ��������.");
					_getch();
				}
			}
			else if (i == 1) {
				if (GiveCountOfList(GList) == 1) {
					GList = RemoveIndexedElement(GList, i);
					printf_s("������� � �������� %d ��� �����.\n", i);
				}
				else {
					say("������. ������� 1-��� ������� ������ �� ��������.");
				}
				_getch();
			}
			else if (i <= 0) {
				say("������. �� ����� ������ �� ������������� ��������.");
				_getch();
			}
		}
		else {
			error;
		}
	}
	else {
		say("������. ������ ������!");
		_getch();
	}
}

/*�������� ������� � ������*/
void AddItemList() {
	int num;
	say("������� �����: ");
	if (scanf_s("%d", &num)) {
		GList = AddItem(GList, num);
		say("���� ��������!\n");
		ListShow(GList);
		_getch();
	}
	else {
		error;
	}
}

/*�������� ������� � ���������� ����� ������ �� �������*/
void AddIndexedItemList(int mode) {
	int num, /*������ �����*/
		index; /*������ �����/�� �������� ����� ��� �������*/
	ListShow(GList);
	say("\n������� ������ ����: ");
	if (scanf_s("%d", &index)) {
		if (mode == 0) {
			if (index > 1 && index < GiveCountOfList(GList) + 1) {
				say("������� �����: ");
				if (scanf_s("%d", &num)) {
					GList = ListAddIndexedElement(GList, index, num, 0);
					say("���� ��������!\n");
					ListShow(GList);
					_getch();
				}
				else {
					error;
				}
			}
			else {
				say("�� ����� �� ������� ������.");
				_getch();
			}
		}
		else {
			if (index > 0 && index < GiveCountOfList(GList) + 1) {
				say("������� �����: ");
				if (scanf_s("%d", &num)) {
					GList = ListAddIndexedElement(GList, index, num, 1);
					say("���� ��������!\n");
					ListShow(GList);
					_getch();
				}
				else {
					error;
				}
			}
			else {
				say("�� ����� �� ������� ������.");
				_getch();
			}
		}
	}
	else {
		error;
	}
}

/*��������� ���������� ��������� ������*/
void GetCountList() {
	if (IsListEmpty(GList)) {
		printf_s("� ������ %d �������/��/���\n", GiveCountOfList(GList));
		ListShow(GList);
		_getch();
	}
	else {
		say("������. ������ ������!");
		_getch();
	}
}

/*��� ����, ������ ���������� �������� � �����*/
void ALU() {
	AddIndexedItemList(0);
}
/*��� ����, ������ ���������� �������� � �����*/
void ALD() {
	AddIndexedItemList(1);
}

/*����� �������� � ������ �� �������*/
void ListSearchByIndex() {
	int index, /*������*/
		i; /*�������*/
	struct List *l = GList;
	if (GList != NULL) {
		say("������� ������ ��������� ��������: ");
		if (scanf_s("%d", &index)) {
			if (index > 1 && index <= GiveCountOfList(GList)) {
				for (i = 0; i < GiveCountOfList(GList) - index + 1; i++) {
					l = l->next;
				}
				printf_s("������� ������, �������� ��������: %d\n", l->num);
				ListShow(GList);
				_getch();
			}
			else {
				say("������. �� ����� �� ������������ ������.");
				_getch();
			}
		}
		else {
			error;
		}
	}
	else {
		say("������. ������ ������");
		_getch();
	}
}

/*����� �������� � ����� �� ��������*/
void ListSearchByNum() {
	int i, /*�������*/
		num, /*�����*/
		nen = 0, /*����� ��*/
		k = 0, /*���������� �������� ��������*/
		*arr = (int*)malloc(sizeof(int)*GiveCountOfList(GList));
	struct List *l = GList;
	if (GList != NULL) {
		say("������� ����� ������� �������� �������� �������: ");
		if (scanf_s("%d", &num)) {
			for (i = 0; i < GiveCountOfList(GList); i++) {
				if (l->num == num) {
					arr[k] = i + 1;
					k++;
					nen = 1;
				}
				l = l->next;
			}
			if (nen == 0) {
				say("������� �� ������.");
			}
			else {
				if (k > 1) {
					say("�������� �������: [�������] ");
					for (i = 0; i < k; i++) {
						if (i > 0) {
							printf_s("%d,", (GiveCountOfList(GList) + 2 - arr[i]));
						}
						else {
							printf_s("%d,", arr[i]);
						}
					}
				}
				else {
					printf_s("������� ������: [������] %d", arr[0]);
				}
			}
			say("\n");
			ListShow(GList);
			free(arr);
			_getch();
		}
		else {
			error;
		}
	}
	else {
		say("������. ������ ������");
		_getch();
	}
}

/*��������� ���������� ������*/
void ListGeneration() {
	int co, /*���������� ���������*/
		i; /*�������*/
	say("������� ��������� �������������: ");
	if (scanf_s("%d", &co)) {
		if (co > 1) {
			if (co < 25000000) {
				for (i = 0; i < co; i++) {
					GList = AddItem(GList, rand() % co + 1);
				}
			}
			else {
				say("������. ������� ����� ���������.");
				_getch();
			}
		}
		else {
			say("������. ������� ���� ���������.");
			_getch();
		}
	}
	else {
		error;
	}
}

/*��������� ������� ���������*/
void GetListFirstElemt() {
	struct List *l = GList; /*��������� �� ������*/
	int i; /*�������*/
	if (GList != NULL) {
		if (GiveCountOfList(GList) != 0) {
			for (i = 0; i < 1; i++) {
				l = l->next;
			}
			printf_s("������ ������� ������: %d", l->num);
			_getch();
		}
		else {
			say("������. ���� ������.");
			_getch();
		}
	}
	else {
		say("������. ���� ������.");
		_getch();
	}
}