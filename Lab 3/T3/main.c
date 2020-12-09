#include "String.h"

int main() {
    printf("Limited by the C language, we'll only read from input.txt.\n");
    printf("Please make sure the text you need to edit is in this file.\n");
    printf("Press any key to continue...");
    getchar();
    FILE *fp = fopen("E:\\Desktop\\input.txt","r");
    if (fp == NULL) {
        printf("The file doesn't exist, please try it later.\n");
        exit(0);
    }
    Page *firstPage = ReadFileContext(fp);
    fclose(fp);
    char op;
    int page, row;
    char s[1<<10];
    while (true) {
        printf("Please input your operator D(delete)/F(find)/I(insert)/P(print)/E(exit)...");
        scanf("%c", &op);
        switch (op) {
            case 'D':
                scanf("%d%d",&page,&row);
                DeleteSpecificLine(firstPage, page, row);
                break;
            case 'F':
                scanf("%s",s);
                Find(firstPage,s);
                break;
            case 'I':
                scanf("%d%d",&page,&row);
                Insert(firstPage,page,row);
                break;
            case 'P':
                PrintWhole(firstPage);
                break;
            case 'E':
                saveFile(firstPage);
                free(firstPage);
                exit(0);
            default:
                printf("Error!");
                break;
        }
    }
    return 0;
}
