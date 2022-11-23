
#include <iostream>

#define MaxSize 200

using namespace std;

typedef struct Queue
{
    int data[MaxSize];
    int front, rear;
} SqQueue;

typedef struct Stack
{
    int data[MaxSize];
    int top;
} SqStack;

void InitQueue(SqQueue *&q){
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;

}
bool InQueue(SqQueue *&q,int e){
    if((q->rear+1) % MaxSize == q->front)
        return false;
    q->rear = (q->rear+1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}

void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}


bool Push(SqStack *&s, int e)
{

    if(s->top == MaxSize-1) 
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;

}

//��ʼ������
void InitQ(SqQueue *Q){
    int k;
    cout<<"������Ҫ���Ե�����(����):"<<endl;
    while(cin>>k)
    {
        InQueue(Q,k);
        if(cin.get() == '\n') break;
    }
    cout<<endl<<"��ʼ�����гɹ���"<<endl;
}
//��ʼ��ջ
void InitS(SqStack *S){
    int k;
    cout<<"������Ҫ���Ե�����(ջ):"<<endl;
    while(cin>>k)
    {
        Push(S,k);
        if(cin.get() == '\n') break;
    }
    cout<<endl<<"��ʼ��ջ�ɹ���"<<endl;
}
//����
void InQ(SqQueue *&q)
{
    int n;
    cout<<"������Ҫ��ӵ�Ԫ��:";
    cin>>n;
    if((q->rear+1) % MaxSize == q->front)
    {
        cout<<"error"<<endl;
        return;
    }
    q->rear = (q->rear+1) % MaxSize;
    q->data[q->rear] = n;

}
//��ջ
void InS(SqStack *&s)
{
    int n;
    cout<<"������Ҫ��ջ��Ԫ��:";
    cin>>n;
    if(s->top == MaxSize-1) 
    {
        cout<<"error"<<endl;
        return;
    }
    s->top++;
    s->data[s->top] = n;

}
//����
void OutQ(SqQueue *&q)
{
    if(q->front == q->rear){
        cout<<"error"<<endl;
        return;
    }

    q->front = (q->front+1) % MaxSize;
    cout<<"��ǰ����Ԫ��Ϊ��"<<q->data[q->front]<<endl;

}
//��ջ
void OutS(SqStack *&s)
{
    if(s->top == -1){
        cout<<"error"<<endl;
        return;
    }
    cout<<"��ǰ��ջԪ��Ϊ��"<<s->data[s->top--]<<endl;

}

void Gettop(SqStack *&s){

    cout<<"��ǰջ��Ԫ��Ϊ��"<<s->data[s->top]<<endl;

}

//���������
void welcome(SqQueue *&Q,SqStack *&S)
{

    system("cls");

    printf("����������������������������������������������������������������������������\n");
    printf("����������������������������������������������������������������������������\n");
    printf("��������������������  ��      ջ�Ͷ��в���ϵͳ      ��  ��������������������\n");
    printf("������������������         ��������         �����������������\n");
    printf("������������������         ��������         �����������������\n");
    printf("��������������������  ��            1.����          ��  �������������������\n");
    printf("��������������������  ��            2.��ջ          ��  �������������������\n");
    printf("��������������������  ��            3.���          ��  �������������������\n");
    printf("��������������������  ��            4.��ջ          ��  �������������������\n");
    printf("��������������������  ��            5.ջ��          ��  �������������������\n");
    printf("��������������������  ��          0.�˳�ϵͳ        ��  �������������������\n");
    printf("��������������������  ��                            ��  �������������������\n");
    printf("����������������������������������������������������������������������������\n");

    InitQ(Q);
    InitS(S);

}


int main()
{

    SqQueue *Q;
    SqStack *S;
    int choice;
    InitStack(S);
    InitQueue(Q);

    welcome(Q,S);
    while (1)
    {
        cout<<"��������������:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            OutQ(Q);
            continue;
        case 2:
            OutS(S);
            continue;
        case 3:
            InQ(Q);
            continue;
        case 4:
            InS(S);
            continue;
        case 5:
            Gettop(S);
            continue;
        case 0:
            break;
        default:
            continue;
        }

    }
    
    system("pause");
    return 0;
}
