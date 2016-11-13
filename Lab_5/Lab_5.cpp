#include "stdafx.h"
#include "stdio.h"
#include "Windows.h"
#include "Math.h"
#include "locale.h"
#include "string.h"
#include "conio.h"

#define pause _pause()
#define cls _cls()
#define arr_size(arr)  (sizeof arr / sizeof arr[0])
#define lab_sel "������� ��� ������"

void _cls() { /*�������� �����*/
	system("cls");
}

void _pause() { /*�����*/
	system("pause");
}


void again();
void start();
void get_chars();
void pidrahunok_aref();

int main()
{
	setlocale(LC_ALL, "RUS");
	start();
	return 0;
}

void choose() { /*����� ������������ ������*/
	char i;
	do {
		i = _getch();
		i = toupper(i);
		switch (i) {
		case 'X':
			cls;
			get_chars();
			pause;
			break;
		case 'C':
			cls;
			pidrahunok_aref();
			pause;
			break;
		default:
			again();
			break;
		}
	} while (i != 'C' || i != 'X');
}

void pidrahunok_aref() { /*������� �������� �������� ��������������� �������� �������*/
	int i = 0, /*������� ������� ������� �������*/
		j = 0, /*������� ������� ������� �������*/
		co = 0 /*����� ������� ���������� ���������*/;
	int x, z, *arr = NULL;
	printf_s("������� ������� ������� ����� ������: ");
	scanf_s("%d %d", &x, &z);
	if (x > 0) {
		arr = (int*)malloc(x*z * sizeof(int));
		do { /*������������ ���� � ������*/
			if (i == x) {
				i = 0;
				j++;
			}
			printf_s("arr[%d][%d] = ", j, i);
			if (!scanf_s("%d", (arr + i * z + j))) { /*�������� �� ������ �����*/
				printf_s("������ �����\n");
				rewind(stdin);
				return;
			}
			i++;
			co++;
		} while (co < x * z);
		for (i = 0; i < x; i++) { /*������� �������� ��������������� ��������*/
			co = 0;
			for (j = 0; j < z; j++) {
				co = co + *(arr + i * z + j);
			}
			co = co / x;
			printf_s("������� �������������� %d-�� ��������: %d\n", i, co);
		}
	}else {
		printf_s("������� ������������ ������� �������\n");
	}
}

void get_chars() { /*������� �������� �� ���������� ������� �������*/
	int i = 0; /*���������� ������ ������*/
	int x; /* ����������� ��������� */
	int *arr = NULL; /* ���������� ������ ��������� */
	int err = 0; /*���������� ���������� �� ���������*/
	printf_s("������� ������� �������: ");
	scanf_s("%d", &x);
	if (x > 0) {
		arr = malloc(x * sizeof(int));
		do {  /*������ ������*/
			printf_s("%d-�� �����: ", i + 1);
			if (!scanf_s("%d", &arr[i])) { /*�������� �� ������ �����*/
				printf_s("������ �����\n");
				rewind(stdin);
				return;
			}
			i++;
		} while (i < x);

		for (int i = 0; i < x; i++) { /*��������� �� ����������*/
			for (int j = 0; j < x; j++) {
				if (arr[i] == arr[j] && i != j) {
					err = 1;
				}
			}
		}
		if (err == 1) { /*����� ����������*/
			printf_s("� ������� ���� ���������� ��������\n");
		}
		else {
			printf_s("� ������� ���� ���������� ���������\n");
		}
	}else {
		printf_s("������� ������������ ������� �������\n");
	}
}

void start() { /*������ ������ ������������ �����*/
	printf("%s : \nX)������� ������� �� ���������� ��������\nC)������� �������������� �������� ������� n ���������", lab_sel);
	choose();
}


void again() {
	cls;
	start();
}
