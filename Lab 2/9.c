#include <stdio.h>
#include <time.h>
#define MAXSIZE 10
#define SMaxSize 10

#define FEE_per_s 1

typedef struct
{
    int Selem[SMaxSize];
    int top;
    int TIME[SMaxSize];
} SeqStack;

typedef struct
{
    int Qelem[MAXSIZE];
    int front;
    int rear;
} SeqQueue;


void InitStack(SeqStack *S)
{
    S->top = -1;
}
void InitQueue(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
    for (int i = 0; i < MAXSIZE; i++)
    {
        Q->Qelem[i] = NULL;
    }
}


int COUNT_TIME()
{
    time_t tmpcal_ptr;
    struct tm *tmp_ptr = NULL;
    time(&tmpcal_ptr);
    return tmpcal_ptr;
}

int COUNT_FEE(SeqStack S, int gar_NUM)
{
    int fee;
    time_t tmpcal_ptr;
    struct tm *tmp_ptr = NULL;
    time(&tmpcal_ptr);
    fee = (tmpcal_ptr - S.TIME[gar_NUM])*FEE_per_s;
    return fee;
}

int Push(SeqStack *S,int e)
{
    if (S->top == SMaxSize -1 )
        return 0;
    S->Selem[++S->top] = e;
    return 1;
}
int EnQueue(SeqQueue *Q,int e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return 0;
    Q->Qelem[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int Pop(SeqStack *S, int *e)
{
    if (S->top == -1)
        return 0;
    *e = S->Selem[S->top];
    S->top--;
    return 1;
}
int DeQueue(SeqQueue *Q, int *e)
{
    if (Q->front == Q->rear)
        return 0;
    *e = Q->Qelem[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}


int DriveOut(SeqStack *S, int e, SeqStack *St)
{
    int S2S;
    while ( S->Selem[S->top] != e )
    {
        if (Pop(S, &S2S) == 0)
        {
            while (St->top != -1)
            {
                Push(S, St->Selem[St->top]);
                St->top--;
            }
            printf("车库内无此车，驶出失败\n");
            return 0;
        }
        Push(St, S2S);
    }
    if (S->Selem[S->top] == e)
    {
        printf("\n%d车驶出成功\n", S->Selem[S->top]);
        printf("应收停车费为%d\n", COUNT_FEE(*S, S->top));
        for (int i = S->top; i < SMaxSize -1; i++)
        {
            S->TIME[i] = S->TIME[i+1];
        }
        S->top--;
    }
    while (St->top != -1)
    {
        Push(S, St->Selem[St->top]);
        St->top--;
    }
    return 1;
}

int Drive_Qc_S(SeqQueue *Q, SeqStack *S)
{
    int e;
    if (DeQueue(Q, &e) == 0)
        return 0;
    else
    {
        Push(S, e);
        S->TIME[S->top] = COUNT_TIME();
        return 1;
    }
}

void printALL(SeqStack S, SeqQueue Q)
{
    printf("\n");
    printf("当前车库为\n");
    for (int i = S.top; i > -1; i--)
    {
        printf("	| %d |	费用:%d\n",S.Selem[i], COUNT_FEE(S, i));
    }
    printf("当前便道为\n");
    for (int i = Q.front, m = 0; m < MAXSIZE -1; m++)
    {

    }
    int i = Q.front;
    while (1)
    {
        if (i == Q.rear)
            break;
        printf("	| %d |\n", Q.Qelem[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int main()
{
    SeqStack S;
    SeqQueue Qc;
    SeqStack St;
    InitStack(&S);
    InitQueue(&Qc);
    InitStack(&St);
    char con;
    int num;
    int count = 1;
    printf("请输入:\n");
    printf("j:进入车辆\n");
    printf("c:驶出车辆\n");
    printf("e:退出系统\n");
    printf("每秒收费%d元\n", FEE_per_s);
    while (1)
    {
        scanf("%c", &con);
        if (con == 'c')
        {
            printf("请输入驶出的车辆序号\n");
            scanf("%d", &num);
        }

        if (con == 'e')
        {
            return 0;
        }
        if (con == 'j')
        {
            if (Push(&S,count) == 0)
            {
                if(EnQueue(&Qc, count) == 0 )
                    printf("车库便道均已满，进入失败\n");
                else
                {
                    printf("%d进入便道成功\n", count);
                    count++;
                }
            }
            else
            {
                printf("%d进入车库成功\n", count);
                S.TIME[S.top] = COUNT_TIME();
                count++;
            }
        }
        if (con == 'c')
        {
            if (DriveOut(&S, num, &St) == 1)
                Drive_Qc_S(&Qc, &S);
        }
        printALL(S, Qc);
        getchar();
    }
}
