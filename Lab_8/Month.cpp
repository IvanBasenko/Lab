#include "stdafx.h"

typedef struct{
	char name[40];
}Word;

void _say(char *str) {
	printf_s("%s", str);
}

void NReTranslateToString() {
	int num; /*����� ������*/
	/*������*/
	Word month[] = {"NULL","������","�������","����","������","���","����","����","������","��������","�������","������","�������"};
	say("������� ����� ������: ");
	if (scanf_s("%d", &num)) {
		if (num > 12 || num < 1) {
			say("�� ��������, � ������� ������ ������ �� ����������!");
		} else {
			say("�������� �����: ");
			printf_s("%s", month[num].name);
		}
	} else {
		error;
	}
	wt;
}