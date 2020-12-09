//
// Created by 黄燊 on 2020-12-08.
//

#include "String.h"
void PrintRow(Row *x) {
    String *s = x->head;
    while (s!=NULL) {
        assert(s);
        putchar(s->x);
        s = s->next;
    }
    putchar('\n');
}
void PrintPage(Page *x) {
    Row *r = x->head;
    while (r!=NULL) {
        assert(r);
        PrintRow(r);
        r = r->next;
    }
    putchar('\f');
}

/* ------ Below are features for main.c ------ */
Page *ReadFileContext(FILE *f) {
    Page *p = (Page*)malloc(sizeof(Page));
    Row *r = (Row*)malloc(sizeof(Row));
    p->head = r;
    p->next = NULL;
    Page *q = p;
    String *s = (String*)malloc(sizeof(String));
    r->head = s;
    while (!feof(f)) {
        char ch=(char)fgetc(f);
        if (ch=='\f') {
            Page *tmp = (Page*)malloc(sizeof(Page));
            q->next = tmp;
            q = q->next;
            r = (Row*)malloc(sizeof(Row));
            q->head = r;
            r->head = NULL;
        }
        else if (ch=='\n') {
            Row *tmp = (Row*)malloc(sizeof(Row));
            r->next = tmp;
            r = tmp;
            r->head = NULL;
        }
        else {
            s->x = ch;
            String *t = (String*)malloc(sizeof(String));
            s->next = t;
            s = t;
        }
    }
    return p;
}
void DeleteSpecificLine(Page* first, int page, int row) {
    int cnt_page = 1;
    int cnt_row = 1;
    Page *p = first;
    while (cnt_page!=page && p->next!=NULL) {
        p = p->next;
        cnt_page++;
    }
    Row *r = p->head;
    if (row == 1) {
        p->head = r->next;
        free(r);
    }
    else {
        while (cnt_row != row-1) {
            r = r->next;
            cnt_row++;
        }
        Row *q = r->next;
        if (q == NULL) {
            free(r);
        }
        else {
            r->next = r->next->next;
            free(q);
        }
    }
}
bool Matching(char *a, char *b) {
    int lena = strlen(a), lenb = strlen(b);
    bool f = 0;
    for (int i = 0; i < lena; i++) {
        for (int j = 0; j < lenb; j++) {
            if (a[i + j - 1] == b[j])
                continue;
            else {
                f = 1;
                break;
            }
        }
    }
    return f;
}
void Find(Page *first, char *s) {
    char t[1<<10];
    int cnt = 0;
    int cnt_page = 0, cnt_row = 0;
    while (first!=NULL) {
        Row *r = first->head;
        cnt_page++;
        cnt_row=0;
        while (r!=NULL) {
            String *ch = r->head;
            cnt_row++;
            cnt = 0;
            while (ch!=NULL) {
                t[cnt++] = ch->x;
                ch=ch->next;
            }
            if (Matching(s,t)) {
                printf("Found at Page %d, Row %d.\n",cnt_page, cnt_row);
                return;
            }
            r = r->next;
        }
        first = first->next;
    }
    printf("Not found.\n");
    return;
}
void Insert(Page *first, int page, int row) {
    int cnt_page = 0, cnt_row = 0;
    Page *p = first;
    while (p!=NULL) {
        cnt_page++;
        if (page == cnt_page) break;
        p=p->next;
    }
    Row *r = p->head;
    while (r!=NULL) {
        cnt_row++;
        if (row == cnt_row) break;
        r=r->next;
    }
    Row *tmp = (Row*)malloc(sizeof(Row));
    Row *ne = r->next;
    r->next = tmp;
    tmp->next = ne;
}

void PrintWhole(Page *p) {
    while (p!=NULL) {
        PrintPage(p);
        p = p->next;
    }
}
void saveFile(Page *p) {
    freopen("output.txt","w",stdout);
    while (p != NULL) {
        PrintPage(p);
        p = p->next;
    }
    fclose(stdout);
}