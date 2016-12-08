#include "stdafx.h"

typedef struct {
	char *str;
	int lengh;
} Word;

typedef struct {
	char *binds;
} Binds;

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	int width;
	int height;
} Size;

/*��������� ������� ����*/
typedef struct {
	Point coords;
	Size size;
	Binds dbreak;
	int height;
	int prioritet;
	char *header;
} Properties;

/*��������� ����*/
typedef struct {
	Word *text;
	Binds *binds;
	Properties properties;
	int *pointers;
	unsigned int slots;
} Menu;

/*������� �����*/
typedef struct {
	int number; /*��������*/
	int *previus; /*���������� �������*/
} StekItem;

/*���������� �����*/
typedef struct {
	StekItem *first; /*������ �������*/
	int count; /*������*/
} StekDescr;

/*������� ����*/
typedef struct {
	int number; /*��������*/
	int *previus; /*��������� �������*/
	int *after; /*���������� �������*/
} DekItem;

/*���������� ����*/
typedef struct {
	DekItem *first; /*������ �������*/
	DekItem *last; /*��������� �������*/
	int count; /*������*/
} DekDescr;

typedef struct {
	int number;
	int *previus;
} SpisItem;

typedef struct {
	int count;
	SpisItem *first;
} SpisDescr;
