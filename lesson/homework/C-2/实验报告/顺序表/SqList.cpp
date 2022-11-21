#include <iostream>
#define MAX 100
using namespace std;


typedef struct
{
    int a[MAX];
    int length;
} SqList;


/* //��λԪ��
void Locate(SqList *sq)
//����Ԫ��
void Insert(SqList *sq)
//ɾ��Ԫ��
void Delete(SqList *sq)
//����Ԫ��
void Find(SqList *sq)
//���ԭʼ����
void OutData(SqList *sq)
//�������֮�������
void OutList(SqList *sq)
//��ӡ������
void welcome(SqList *sq) */

//
void OutData(SqList *sq)
{
    int i;
    for (i = 0; i < sq->length; i++)
    {
        cout << sq->a[i] << "  ";
    }
    cout << endl;
}
void OutList(SqList *sq)
{
    int i;
    for (i = 0; i < sq->length; i++)
    {
        cout << sq->a[i] << " ";
    }
    cout << endl;
}

//��λ
void Locate(SqList *sq)
{
    int index;
    cout << "������index:" << endl;
    cin >> index;
    if (index < 1 || index > sq->length)
    {
        cout << "�����ڵ�" << index << "��Ԫ��" << endl;
    }
    else
    {
        cout << "��" << index << "��Ԫ��:" << sq->a[index - 1] << endl;
    }
}
//����Ԫ��
void Find(SqList *sq)
{
    int i = 0, item;
    cout << "������Ҫ���ҵ�Ԫ��:" << endl;
    cin >> item;
    while (i < sq->length && sq->a[i] != item)
        i++;
    if (i >= sq->length)
        cout << "������Ԫ��" << item << "�����ڣ�" << endl;
    else
        cout << "���ң�Ԫ��" << item << "�ǵ�" << i + 1 << "��Ԫ��" << endl;
}

//����Ԫ��
void Insert(SqList *sq)
{
    int j, l, k;
    cout << "������Ҫ�����λ�ú�Ԫ��:" << endl;
    cin >> l >> k;
    if (l < 1 || l > sq->length)
    {
        cout << "����λ�÷Ƿ���" << endl;
    }
    else
    {
        l--;
        for (j = sq->length; j > l; j--)
            sq->a[j] = sq->a[j - 1];
        sq->a[l] = k;
        sq->length++;
        cout << "������˳���ΪL: ";
        OutList(sq);
    }
}

//ɾ��Ԫ��
void Delete(SqList *sq)
{
    int j, dl;
    cout << "������Ҫɾ����Ԫ��λ��:" << endl;
    cin >> dl;
    if (dl < 1 || dl > sq->length)
    {
        cout << "ɾ����" << dl << "��Ԫ�ز����ڣ�" << endl;
    }
    else
    {
        dl--;
        for (j = dl; j < sq->length - 1; j++)
            sq->a[j] = sq->a[j + 1];
        sq->length--;
        cout << "ɾ�����˳���ΪL: ";
        OutList(sq);
    }
}
//��ӡ������
void welcome(SqList *sq)
{
    system("cls");

    printf("����������������������������������������������������������������������������\n");
    printf("����������������������������������������������������������������������������\n");
    printf("��������������������  ��   ˳ �� �� �� �� ϵ ͳ     ��  ��������������������\n");
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

    int n = 0;
    int op;

    cout << "������Ԫ�ظ���:" << endl;
    cin >> sq->length;

    cout << "������" << sq->length << "��Ԫ��:" << endl;

    while (cin >> sq->a[n++])
    {
        if (cin.get() == '\n')
            break;
    }
    sq->length = n;
    cout << "�����ɹ���" << endl;
}

int main()
{
    SqList *sq;
    sq = (SqList *)malloc(sizeof(SqList));
    int op;
    //��ӡ������
    welcome(sq);
    while (true)
    {
        //ָ���û�����
        printf("\n�������Ӧ�Ĺ��ܼ�(����): ");
        cin >> op;
        switch (op)
        {
        case 1:
            Locate(sq);
            break;
        case 2:
            Insert(sq);
            break;
        case 3:
            Delete(sq);
            break;
        case 4:
            Find(sq);
            break;
        case 5:
            cout<<"��ǰ����Ϊ:"<<endl;
            OutList(sq);
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}