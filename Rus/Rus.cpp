// Rus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Windows.h"
#include "locale.h"
#include "RusLanguage.h"

������� local();
����� �������()
{
	����� ��� = 0;
	��������������;
	�����("�� - ��� ������� ���!)\n");
	�������(�����);
	����(����� � = 0; � < 5; �++) {
		�����("������� �����: %d\n",���);
	}
	�������(�����);
	���������� 0;
}

������� local() {
	����(LC_ALL, "RUS");
}

