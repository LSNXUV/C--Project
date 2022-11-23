#include <iostream>
using namespace std;
#define MaxSize 200

typedef struct
{
    char str[MaxSize];
    int length;
} SqString;


//�󳤶Ȳ���¼
void StrLength(SqString *S)
{
    S->length = 0;
    while (S->str[S->length++] != '\0')
        ;
    S->length--;
}

//BF�㷨1
int index2(SqString str, SqString substr)
{
    int i, j, k;
    for (i = 0; i < str.length; i++)
    {
        for (j = i, k = 0; str.str[j] == substr.str[k]; 
            j++, k++);

        // cout<<i<<" "<<k<<endl;
        if (k == substr.length+1)
            //ע��jÿ�δ�i��ʼ,�л���
            
            return  i+1;
    }
    return -1;
}

//BF�㷨2
int index(SqString S, SqString T) 
{
    int i = 0, j = 0;
    while (i < S.length && j < T.length)
    {
        if (S.str[i] == T.str[j]) //����ƥ����һ���ַ�
        {
            i++;
            j++;
        }
        else //�������Ӵ�ָ��������¿�ʼ��һ��ƥ��
        {
            i = i - j + 1; //��������һ��λ�ÿ�ʼƥ��
            j = 0;         //�Ӵ���ͷ��ʼƥ��
        }
    }
    if (j >= T.length)
    {
        return (i - T.length+1); //����ƥ��ĵ�һ���ַ����±�
    }
    else //ģʽƥ�䲻�ɹ�
    {
        return (-1);
    }
}


void GetNextval(SqString t, int nextval[])
{
    int j = 0, k = -1;
    nextval[0] = -1;
    while (j < t.length)
    {
        if (k == -1 || t.str[j] == t.str[k])
        {
            j++;
            k++;
            if (t.str[j] != t.str[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
}

//KMP�㷨
int KMPIndex(SqString s, SqString t)
{
    int nextval[MaxSize], i = 0, j = 0;
    GetNextval(t, nextval);
    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.str[i] == t.str[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
    }
    if (j >= t.length)
        return (i - t.length+1);
    else
        return (-1);
}


//������
void welcome()
{

    system("cls");

    printf("����������������������������������������������������������������������������\n");
    printf("����������������������������������������������������������������������������\n");
    printf("��������������������  ��      ˳�򴮵�ģʽƥ��      ��  ��������������������\n");
    printf("������������������         ��������         �����������������\n");
    printf("������������������         ��������         �����������������\n");
    printf("��������������������  ��          1.BF�㷨          ��  �������������������\n");
    printf("��������������������  ��          2.BF�㷨2         ��  �������������������\n");
    printf("��������������������  ��          3.KMF�㷨         ��  �������������������\n");
    printf("��������������������  ��          0.�˳�ϵͳ        ��  �������������������\n");
    printf("��������������������  ��                              ��  �����������������\n");
    printf("����������������������������������������������������������������������������\n");

    cout << "��ʼ���ɹ���" << endl;
}

//BF����1
void BF()
{
    cout << "������Ҫ���Ե�ԭ�ַ�����ģ���ַ���:" << endl;
    SqString S, T;
    cin >> S.str >> T.str;
    StrLength(&S);
    StrLength(&T);

    if (index(S, T) != -1)
    {
        cout << "ƥ��ɹ���" << endl;
        cout << "��Ӧ�±�Ϊ:" << index(S, T)<<endl;
        return;
    }
    cout << "ƥ��ʧ�ܣ�" << endl;
    return;
}
//BF����2
void BF2()
{
    cout << "������Ҫ���Ե�ԭ�ַ�����ģ���ַ���:" << endl;
    SqString S, T;
    cin >> S.str >> T.str;
    StrLength(&S);
    StrLength(&T);

    if (index2(S, T) != -1)
    {
        cout << "ƥ��ɹ���" << endl;
        cout << "��Ӧ�±�Ϊ:" << index2(S, T)<<endl;
        return;
    }
    cout << "ƥ��ʧ�ܣ�" << endl;
    return;
}
//KMP����1
void KMP(){
    cout << "������Ҫ���Ե�ԭ�ַ�����ģ���ַ���:" << endl;
    SqString S, T;
    cin >> S.str >> T.str;
    StrLength(&S);
    StrLength(&T);

    if (KMPIndex(S, T) != -1)
    {
        cout << "ƥ��ɹ���" << endl;
        cout << "��Ӧ�±�Ϊ:" << KMPIndex(S, T)<<endl;
        return;
    }
    cout << "ƥ��ʧ�ܣ�" << endl;
    return;
}

int main()
{
    welcome();
    while (1)
    {
        int choice;
        cout << "��������Ҫʵ�ֵĹ������:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            BF();
            continue;
        case 2:
            BF2();
            continue;
        case 3:
            KMP();
            continue;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}