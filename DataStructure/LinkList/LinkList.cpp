#include <iostream>

using namespace std;

typedef struct LList
{
    int data;
    struct LList *next;
} LinkList;

/* 
//ͷ�巨��������
LinkList *HeadCreate(int n)
//β�巨��������
LinkList *EndCreate(int n)
//��λԪ��
void Locate(LinkList *p)
//����Ԫ��
void Insert(LinkList *p)
//ɾ��Ԫ��
void Delete(LinkList *p)
//����Ԫ��
void Find(LinkList *p)
//�������
void OutData(LinkList *p)
//��ӡ������
void welcome(int *n) */


LinkList *HeadCreate(int n){
    LinkList *head, *p;
    int i;
    head = NULL;

    cout<<"������"<<n<<"�����ݣ�"<<endl;
    for (i = 0; i < n; i++)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        cin >> p->data;
        p->next = head;
        head = p;
        // p->next = NULL;
    }
    cout << "�����ɹ���" << endl;
    return head;
}

LinkList *EndCreate(int n){
    LinkList *end, *p,*head = NULL;
    int i; 
    cout<<"������"<<n<<"�����ݣ�"<<endl;

    for (i = 0; i < n; i++)
    {
        p = (LinkList *)malloc(sizeof(LinkList));
        cin >> p->data;
        if (i == 0)
        {
            end = p;
            end->next = NULL;
            head = end;
        }
        else
        {
            end->next = p;
            p->next = NULL;
            end = p;
        }
    }
    cout << "�����ɹ���" << endl;
    return head;
}

void OutData(LinkList *p)
{
    if (!p)
    {
        cout << "list is empty!";
    }
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }

}
//��λ
void Locate(LinkList *p)
{
    int n,i;
    LinkList *h;
    h = p;
    cout<<"������Ҫ��λ��Ԫ������:"<<endl;
    cin>>n;
    if(!p)
    {
        cout << "list is empty!";
        return ;
    }
    
    for(i = 0;i<n-1;i++) h = h->next;
    cout<<"��"<<n<<"��Ԫ��Ϊ:"<<endl<<h->data<<endl;
    OutData(p);
}
//����Ԫ��
void Find(LinkList *p)
{
    int n,i = 1;
    LinkList *h;
    h = p;
    cout<<"������Ҫ���ҵ�Ԫ��:"<<endl;
    cin>>n;
    if(!p){
        cout << "list is empty!";
        return;
    }
    while(h->data != n)
    {
        h = h->next;
        i++;
    }
    cout<<"Ԫ���ڵ�"<<i<<"��λ��"<<endl;
    OutData(p);
}

//����Ԫ��
void Insert(LinkList *p)
{
    int m,n,i = 1;
    LinkList *h,*L;

    h = p;

    L = (LinkList *)malloc(sizeof(LinkList));

    cout<<"������Ҫ�����Ԫ�غͲ���λ��:"<<endl;
    cin>>L->data>>n;

    if(!p){
        cout << "list is empty!";
        return;
    }

    while(i != n-1)
    {
        h = h->next;
    }

    L->next = h->next;
    h->next = L;

    cout<<"����������Ϊ:"<<endl;

    OutData(p);
}

//ɾ��Ԫ��
void Delete(LinkList *p)
{
    int n;
    LinkList *p1,*p2;

    cout<<"������Ҫɾ����Ԫ��:"<<endl;
    cin>>n;

    if(!p){
        cout << "list is empty!";
        return;
    }
    if(p->data == n)
    {
        p2=p;
        p=p->next;
        free(p2);
    }
    p1=p;
    p2=p->next;
    while(p2!=NULL)
    {
        if(p2->data == n)
        {
            p1->next=p2->next;
            free(p2);
            p2=p1->next;
        }
        else
        {
            p1=p2;
            p2=p2->next;
        }
    }
    OutData(p);

}

//��ӡ������
void welcome(int *n)
{
    system("cls");

    printf("����������������������������������������������������������������������������\n");
    printf("����������������������������������������������������������������������������\n");
    printf("��������������������  ��     �� �� �� �� ϵ ͳ      ��  ��������������������\n");
    printf("������������������         ��������         �����������������\n");
    printf("������������������         ��������         �����������������\n");
    printf("��������������������  ��          1.��λԪ��        ��  �������������������\n");
    printf("��������������������  ��          2.����Ԫ��        ��  �������������������\n");
    printf("��������������������  ��          3.ɾ��Ԫ��        ��  �������������������\n");
    printf("��������������������  ��          4.����Ԫ��        ��  �������������������\n");
    printf("��������������������  ��          5.���Ԫ��        ��  �������������������\n");
    printf("��������������������  ��          0.�˳�ϵͳ        ��  �������������������\n");
    printf("��������������������  ��                              ��  �����������������\n");
    printf("����������������������������������������������������������������������������\n");

    cout << "��ʼ������ɹ���" << endl;

    cout<<"������Ҫ����Ԫ�صĸ���:"<<endl;

    cin>>*n;

}

    int main()
    {
        LinkList *L1;
        LinkList *L2;
        int n;

        welcome(&n);

        // L1 = HeadCreate(n);

        L2 = HeadCreate(n);

        int op;

        while (true)
        {
            //ָ���û�����
            printf("\n�������Ӧ�Ĺ��ܼ�(����): ");
            cin >> op;
            switch (op)
            {
            case 1:
                Locate(L2);
                break;
            case 2:
                Insert(L2);
                break;
            case 3:
                Delete(L2);
                break;
            case 4:
                Find(L2);
                break;
            case 5:
                cout<<"��ǰ����Ϊ:"<<endl;
                OutData(L2);
                break;
            default:
                break;
            }
        }
        system("pause");
        return 0;
    }