#include "stdafx.h"

void NIsPalendomizm() {
	char *chr; /*�����*/
	int err = 0, /* ���� 1 �� �� ���������*/
		lengh; /*������ �����*/
	chr = (char*)malloc(sizeof(chr));
	say("������� ����� �� ������ 3 ��������: ");
	if (fgets(chr, 100, stdin)) {
		lengh = strlen(chr);
		if (lengh - 1 >= 3) {
				for (int i = 0; i <= lengh - 2 && err == 0; i++) {
					if (toupper(chr[i]) != toupper(chr[lengh - i - 2])) {
						err = 1;
					}
				}
			if (err == 0) {
				say("YES");
			} else { say("NO"); }
		}else{
			say("������, ����� ������ 3 ��������.");
		}
	} else {
		error;
	}
	wt;
}

int checkisdigit(unsigned char *str) {
	int i,err = 1 ;
	for (i = 0; i < strlen(str) - 2; i++) {
		if (isdigit(str[i])) {
			err = 0;
		}
	}
	return err;
}

void RecurStart() {
	unsigned char *chr; /*�����*/
	int err = 0, /* ���� 1 �� �� ���������*/
		lengh; /*������ �����*/
	chr = (char*)malloc(sizeof(chr));
	say("������� ����� �� ������ 3 ��������: ");
	if (fgets(chr, 100, stdin)) {
		lengh = strlen(chr);
		if (lengh - 1 >= 3) {
			if (checkisdigit(chr)) {
				if (RecurPalen(0, lengh, chr)) {
					say("YES");
				} else {
					say("NO");
				}
			}
			else {
				say("������ �� ����� �����!");
			}
		}
		else {
			say("������, ����� ������ 3 ��������.");
		}
	}
	else {
		error;
	}
	wt;
}

int RecurPalen(int i,int lengh,char *chr) {
	if (i <= lengh - 2) {
		if (toupper(chr[i]) != toupper(chr[lengh - i - 2])) {
			i = lengh;
			return 0;
		}
		i++;
		RecurPalen(i, lengh, chr);
	}
}