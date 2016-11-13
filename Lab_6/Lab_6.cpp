#include "stdafx.h"
#include "stdio.h"
#include "locale.h"
#include "Windows.h"
#include <time.h>

#define cls _cls()
#define error _error()
#define say(text) _say(text);

void _say(char *text) {
	printf_s(text);
}

void _cls() {
	system("cls");
}

void _error() {
	printf_s("������ �����!");
	rewind(stdin); 
}

/*��������� �����*/
typedef struct {
	char *str;
	int *lengh;
} Word;

void start();
void again();
void UpPoint();
void GetWord();
Word *chack(Word *arr);

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	start();
	return 0;
}

void UpPoint() {
	int i, /*������� ��� �����*/
		size = 150; /*������ ������*/
	char *src, *estr;
	src = (char*)malloc(sizeof(char) * size);
	say("������� ������ � �������: ");
	estr = fgets(src, size, stdin);
	if (estr != NULL)
	{
		/*�������� � �������� ��������
		��������� ������ ����� �����*/
		for (i = 0; i <= size; i++) {
			if (*(src + i) == '.') {
				*(src + i + 1) = toupper(*(src + i + 1));
			}
		}
		/*������� ����� ������*/
		if (strlen(src) != 0) {
			say("\n�������� ������: ");
			puts(src);
			say("������� ����� �������...");
		}
		else {
			say("�� ����� ������ ������");
		}
	}
}

void GetWord() {
	char seps[] = " "; /*�����������*/
	int size = 151, /*������ ������*/
		h = 0, /*������� ����*/
		i, /*������� �����*/
		cho; /*����� ��������� �����*/
	char *str, /*��������� ������� ������*/
		*token, /*���������� �����*/
		*nun, /*������ ��������� ��� �������*/
		*estr;
	Word *words; /*��������� �� ������ �������� Word*/
	/*�������� ������ ��� �������*/
	words = (Word*)malloc(size / 2 * sizeof(Word)); 
	str = (char*)malloc(size * sizeof(char));
	
	say("������� ������: ");
	estr = fgets(str,size, stdin);
	if (estr != NULL)
	{
		/*�������� �� �������*/
		if (strlen(str) != 0) {
			/*����� ������ ����������� seps*/
			token = strtok_s(str, seps, &nun);
			while (token != NULL)
			{
				(words + h)->str = token;
				(words + h)->lengh = strlen(token);
				token = strtok_s(NULL, seps, &nun);
				h++;
			}

			i = h;
			if (i > 1) { /*�������� �� 1 �����*/
				say("������� ����� �����: ");
				if (scanf_s("%d", &cho)) {
					/*�������� �� ��������� ����*/
					if (cho <= i && i > 0) {
						say("\n���� �����: ");
						*(words + cho - 1) = *chack(words + cho - 1);
						puts((words + cho - 1)->str);
						say("\n������� ����� �������...");
					}
					else { error; }
				}
				else { error; }
			}
			else {
				printf_s("� ����� ����� ���� �����: %s", words->str);
			}
		}
		else {
			say("������. �� ����� ������ ������");
		}
	}
	rewind(stdin);
}

/*�������� ������ ��������*/
Word *chack(Word *arr) {
	char sec[] = { ',','.',';',':','>','<','-','+','(',')','@','#','$','%','^','&','*','!' };
	int i, j;
	char *fe;
	fe = arr->str;
	for (i = 0; i < arr->lengh; i++) {
		for (j = 0; j < strlen(sec); j++) {
			if (*(fe + i) == *(sec + j) && *(fe + i) != '�' && *(fe + i) != '�' && *(fe + i) != '�'){
				*(fe + i) = ' ';
			}
		}
	}
	arr->str = fe;
	return arr;
}

/*����� �������� ����*/
void choose(int mode) {
	char i;
	do {
		i = _getch();
		i = toupper(i);
		switch (i) {
			case '�':
			case 'X':
				cls;
				UpPoint();
				break;
			case '�':
			case 'C':
				cls;
				GetWord();
				break;
			default:
				again();
				break;
		}
	} while (i != 'C' || i != 'X' || i != '�' || i != '�');
}

void start() {
	printf("�������� ������� ����: \nX)������� ����. ������� ����� ����� � ������� ������� \nC)����� ����� �� ������");
	choose(0);
}


void again() {
	cls;
	start();
}