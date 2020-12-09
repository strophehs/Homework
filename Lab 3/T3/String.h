//
// Created by 黄燊 on 2020-12-08.
//

#ifndef LAB_STRING_H
#define LAB_STRING_H

#endif //LAB_STRING_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct String {
    char x;
    struct String *next;
} String;

typedef struct Row {
    struct String *head;
    struct Row *next;
} Row;

typedef struct Page {
    struct Row *head;
    struct Page *next;
} Page;

void PrintRow(Row *x);
void PrintPage(Page *x);
Page *ReadFileContext(FILE *f);
void DeleteSpecificLine(Page *first, int page, int row);
void Find(Page *first, char *s);
void Insert(Page *first, int page, int row);

void PrintWhole(Page *p);
void saveFile(Page *p);