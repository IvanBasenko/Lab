#include "stdafx.h"
#include "Structures.cpp"

void StekGeneration(int count) {
	int i;
	for (i = 0; i < count; i++) {
		StekCreateItem(rand() % count + 1, SDes);
	}
}

void StekGenerations() {
	int num;
	if (SDes == NULL) {
		SDes = StekCreateDescr();
	}
	say("������� ��������� �������������: ");
	if (scanf_s("%d", &num)) {
		if (num < 25000000 && num > 0) {
			StekGeneration(num);
			say("���� ������������ �������.\n");
			StekShow();
			_getch();
		} if (num < 1) {
			say("������� ���� ���������!");
			_getch();
		} if (num > 25000000) {
			say("������� ����� ���������!");
			_getch();
		}
	}
	else {
		error;
	}
}

StekDescr* StekCreateDescr() {
	StekDescr *des;
	des = (StekDescr*)malloc(sizeof(StekDescr));
	des->first = NULL;
	des->count = 0;
	return des;
}

StekDescr* StekCreateItem(int number, StekDescr *des) {
	if (des == NULL) {
		des = StekCreateDescr();
	}
	StekItem* item = (StekItem*)malloc(sizeof(StekItem));
	item->previus = (int*)des->first;
	item->number = number;

	des->first = item;
	des->count++;
	return des;
}

StekDescr* StekDeletItem(StekDescr *des) {
	if (des->count > 1) {
		StekItem *last;
		last = des->first;
		des->first = (StekItem*)des->first->previus;
		free(last);
		des->count--;
	}
	else {
		free(des);
		des = NULL;
	}
	return des;
}

int SetkError(StekDescr *des) {
	if (des != NULL) {
		if ((void*)des->count != NULL) {
			if (des->count < 1) {
				say("������. � ����� 0 ���������, ������ �� ��������!");
				_getch();
				return 0;
			}
			else { return 1; }
		}
		else {
			say("������. ���� ������!");
			_getch();
			return 0;
		}
	}
	else {
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
	}
	else {
		error;
	}
	_getch();
}

void StekPop() {
	if (SetkError(SDes)) {
		SDes = StekDeletItem(SDes);
		if (SDes != NULL) {
			printf_s("������� ������� �����, ������ ����� ������� �������: %d\n", SDes->first->number);
			StekShow();
		}
		else {
			printf_s("���� ��� ��������� �������.");
		}
		_getch();
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
	}
	else if (SDes->count < 2000000) {
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
	else {
		say("������� ����� ��������� ���� ��� ������ � ����, ��� ��� �� �� ������� ��� :) ");
	}
}

void StekCount() {
	if (SetkError(SDes)) {
		printf_s("� �����: %d ���������.\n", SDes->count);
		StekShow();
		_getch();
	}
}