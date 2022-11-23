
#include <iostream>
#include <cstring>
using namespace std;
#define Max 100

typedef struct tree
{
    char data;
    struct tree *lchild,*rchild;
} DBTree;


//������������ͺ����������������
DBTree* CreateDBTreeByAft(char *instr, char *afterstr, int length)
{
    if (length == 0)//���������
    {
        return NULL;
    }
    char c = afterstr[length - 1];//���ĸ�Ϊ����������һ���ַ�
    int i = 0;
    while ((instr[i] != c) && i < length)//�ҵ���������иø���λ��
    {
        i = i + 1;
    }
    int leftlength = i;//ȷ���������н�����Ŀ
    int rightlength = length - i - 1;//ȷ���������н�����Ŀ
    DBTree *T;
    T = (DBTree*)malloc(sizeof(DBTree));
    T->data = c;//�����½�㣬ÿ�ζ�ʹ�����ÿ��С�����ĸ����
    // printf("%c",c);//����
    T->lchild = NULL;
    T->rchild = NULL;
    T->lchild = CreateDBTreeByAft(&instr[0], &afterstr[0], leftlength);//����������
    T->rchild = CreateDBTreeByAft(&instr[i + 1], &afterstr[i], rightlength);//����������
    
    return T;

}
//����ǰ������������������������
DBTree* CreateDBTreeByPre(char *instr, char *prestr, int length)
{
    if (length == 0)//���������
    {
        return NULL;
    }
    char c = prestr[0];//���ĸ�Ϊǰ�������һһ���ַ�
    int i = 0;
    while ((instr[i] != c) && i < length)//�ҵ���������иø���λ��
    {
        i = i + 1;
    }
    int leftlength = i;//ȷ���������н�����Ŀ
    int rightlength = length - i - 1;//ȷ���������н�����Ŀ
    DBTree *T;
    T = (DBTree*)malloc(sizeof(DBTree));
    T->data = c;//�����½�㣬ÿ�ζ�ʹ�����ÿ��С�����ĸ����
    // printf("%c",c);//����
    T->lchild = NULL;
    T->rchild = NULL;
    T->lchild = CreateDBTreeByPre(&instr[0], &prestr[1], leftlength);//����������
    T->rchild = CreateDBTreeByPre(&instr[i + 1], &prestr[i+1], rightlength);//����������

    return T;
}

//�ڵ����
int NodeCount(DBTree *bt)
{
    int num1,num2;
    if(bt==NULL)
    {
        return 0;
    }
    else
    {
        num1 = NodeCount(bt->lchild);
        num2 = NodeCount(bt->rchild);
        return num1 + num2 + 1 ;
    }
}

//�������
void PreOrder(DBTree *bt)
{
    if(bt)
    {
        cout<<bt->data;
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

//�������
void InOrder(DBTree *bt)
{
    if(bt)
    {
        InOrder(bt->lchild);
        cout<<bt->data;
        InOrder(bt->rchild);
    }
}

//�������
void PostOrder(DBTree * bt)
{
    if(bt)
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout<<bt->data;
    }
}

//��α���
void LevelOrder(DBTree *DT)
{
    DBTree *p;
    DBTree * qu[Max];
    int front,rear;
    front = rear = 0;
    rear++;qu[rear]=DT;
    while(front!=rear)
    {
        front = (front+1)%Max;
        p = qu[front];
        cout<<p->data;
        if(p->lchild)
        {
            rear = (rear+1)%Max;
            qu[rear]=p->lchild;
        }
        if(p->rchild)
        {
            rear = (rear+1)%Max;
            qu[rear]=p->rchild;
        }

    }

}

//��ӡ������
void welcome()
{
    system("cls");
    cout<<endl;
    printf("����������������������������������������������������������������������������\n");
    printf("����������������������������������������������������������������������������\n");
    printf("������������������  ��      �� �� �� �� �� �� ��      ��  ������������������\n");
    printf("������������������         ��������         �����������������\n");
    printf("������������������         ��������         �����������������\n");
    printf("��������������������  ��          1.�������        ��  �������������������\n");
    printf("��������������������  ��          2.�������        ��  �������������������\n");
    printf("��������������������  ��          3.�������        ��  �������������������\n");
    printf("��������������������  ��          4.��α���        ��  �������������������\n");
    printf("��������������������  ��          0.�˳�ϵͳ        ��  �������������������\n");
    printf("��������������������  ��                            ��  �������������������\n");
    printf("����������������������������������������������������������������������������\n");


}

int main(){
    int choice,len;
    DBTree * DT;
    char prestr[Max],instr[Max],aftstr[Max];
    welcome();
    cout<<"1.��������������������������������"<<endl;
    cout<<"2.���ݺ���������������������������"<<endl;
    cout<<"��������Ҫ�����������ķ�ʽ��"<<endl;
    cin>>choice;
    if(choice==1){
        cout<<"��ֱ���������������������(�ո�ָ�):"<<endl;
        cin>>prestr>>instr;
        len = strlen(instr);
        DT = CreateDBTreeByPre(instr,prestr,len);
    }else{
        cout<<"��ֱ��������������������(�ո�ָ�):"<<endl;
        cin>>aftstr>>instr;
        len = strlen(instr);
        DT = CreateDBTreeByAft(instr,aftstr,len);
    }
    cout<<"�����ɹ���"<<endl;
    while(1){
        cout<<"�����빦����ţ�"<<endl;
        cin>>choice;
        switch (choice)
        {
        
        case 1:
            cout<<"�������Ϊ:";
            PreOrder(DT);
            cout<<endl;
            continue;
        case 2:
            cout<<"�������Ϊ:";
            InOrder(DT);
            cout<<endl;
            continue;
        case 3:
            cout<<"�������Ϊ:";
            PostOrder(DT);
            cout<<endl;
            continue;
        case 4:
            cout<<"��α���Ϊ:";
            LevelOrder(DT);
            cout<<endl;
            continue;
        case 0:
            break;
        default:
            cout<<"�������Ϊ:";
            PreOrder(DT);
            cout<<endl;
            continue;
        }
    }
    
    system("pause");
    return 0;
}