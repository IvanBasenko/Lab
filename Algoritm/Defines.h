#pragma once
#include "Windows.h"
#define error _error()
#define say(text) _say(text);
#define pause _pause();

void _say(char *text) {
	printf_s(text);
}

void _error() {
	printf_s("������ �����!");
	rewind(stdin);
}

void _pause() {
	system("pause");
}

#define wt _getch();

#define MULT 2
#define error101 say("������. ��������� ������� ����� ������� � ������� �����!\n"); err = 1; wt;
#define error102 say("������. �� �������� �������� ����� ������� � ����, ��������� �� �� ����� ������ �����!\n"); err = 1; wt;
#define error103 say("������. ���� ������ ��������� � �����, ���� - ������!\n"); err = 1; wt;
#define error104 say("������. ���� �� ������\n"); err = 1; wt;
#define error105 say("������. 0 �������� � �����!\n"); err = 1; wt;
#define error1 say("�������� �������� ������� �����!\n"); err = 1; wt;
#define error2 say("���������� ��������� ��������, ���� �� ������!\n"); err = 1; wt;
#define error5 say("������. ���� ����� ����� 1 �������, � ���������� ������ ��������"); err = 1; wt;

#define error106 say("������. ��������� ������� ����� ������� � ������� ����!\n"); err = 1; wt;
#define error107 say("������. �� �������� �������� ����� ������� � ���, ��������� �� �� ����� ������ �����!\n"); err = 1; wt;
#define error108 say("������. ���� ������ ��������� � ����, ��� - ������!\n"); err = 1; wt;
#define error109 say("������. ��� �� ������\n"); err = 1; wt;
#define error110 say("������. 0 �������� � ����!\n"); err = 1; wt;
#define error3 say("�������� �������� ������� ����!\n"); err = 1; wt;
#define error4 say("���������� ��������� ��������, ��� �� ������!\n"); err = 1; wt;
#define error6 say("������. ��� ����� ����� 1 �������, � ���������� ������ ��������"); err = 1; wt;
#define error7 say("������. �� �� ������ �� ����� ����� �������� � ���� ����, ��������� � ��� �������� ������ ���� ��������"); err = 1; wt;
#define error8 say("������. �� �� ������ �� ����� ����� �������� � ����� ����, ��������� � ��� �������� ������ ���� ��������"); err = 1; wt;