#include "stdafx.h"

void NIsPalendomizm() {
	char *chr; /*�����*/
	int err = 0, /* ���� 1 �� �� ���������*/
		lengh; /*������ �����*/
	chr = (char*)malloc(sizeof(chr));
	say("������� ����� �� ������ 3 ��������: ");
	if (fgets(chr, 100, stdin)) {
		lengh = strlen(chr);
		if (lengh < 3) {
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