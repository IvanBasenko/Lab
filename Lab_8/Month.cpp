#include "stdafx.h"
void NReTranslateToString() {
	int num; /*����� ������*/
	say("������� ����� ������: ");
	if (scanf_s("%d", &num)) {
		say("�������� �����: ");
		switch (num)
		{
		case 1:
			say("������");
			break;
		case 2:
			say("�������");
			break;
		case 3:
			say("����");
			break;
		case 4:
			say("������");
			break;
		case 5:
			say("���");
			break;
		case 6:
			say("����");
			break;
		case 7:
			say("����");
			break;
		case 8:
			say("������");
			break;
		case 9:
			say("��������");
			break;
		case 10:
			say("�������");
			break;
		case 11:
			say("������");
			break;
		case 12:
			say("�������");
			break;
		default:
			say("�� ��������� ����� ������.");
			break;
		}
	}
	else {
		error;
	}
	wt;
}