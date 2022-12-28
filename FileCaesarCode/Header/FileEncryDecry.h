
#include "System.h"

//���˵�����
void System::welcome()
{
    system("cls");
    printf("\n\n");

    Cprintf("��ӭ~");
    printf("\n\n");

    Cprintf("�ļ��ӽ���ϵͳ");
    printf("\n\n");

    Cprintf("1.д���ļ�");
    printf("\n\n");

    Cprintf("2.�鿴�ı�");
    printf("\n\n");

    Cprintf("3.������Կ");
    printf("\n\n");

    Cprintf("4.�����ļ�");
    printf("\n\n");

    Cprintf("5.�����ļ�");
    printf("\n\n");

    Cprintf("0.�˳�ϵͳ");
    printf("\n\n\n");

}

//���˵�
void System::menu()
{
    welcome();
    int choice;
    while(1)
    {
        Cprintf("�����빦�����:");
        cin>>choice;
        if(choice == 0) break;
        
        printf("\n\n");

        switch(choice)
        {
            case 1:

                write();
                welcome();
                break;
            case 2:

                view();
                welcome();

                break;
            case 3:

                setkey();
                welcome();

                break;
            case 4:

                encrypt();
                welcome();

                break;
            case 5:

                decrypt();
                welcome();

                break;
        }
    }
    
}

void System::Cprintf(string str)
{
	cout<<setw(56+str.length()/2)<<str;
}

//д���ļ�
void System::write()
{
    
    printf("\n\n");
    cout<<"������Ҫ���ܵ��ı��ַ���:";

    cin>>content;

    printf("\n\n");
    Cprintf("д��ɹ�!");

    printf("\n\n");
    Cprintf("�Ƿ���Ҫ���浽\"content.txt\"�ļ�?  (y(��)/n(��)):");
    

    string str;
    cin>>str;
    if(str == "y" ||str == "Y")
    {
        SaveFile();
        printf("\n\n");
        Cprintf("����ɹ���");
    }
    else
    {

        Cprintf("����ʧ�ܣ�");

    }

    printf("\n\n");
    Cprintf("��Enter������");
    while(getch() != 13);
}

//�鿴�ı�
void System::view()
{
    printf("\n\n");

    Cprintf("��ǰ�ı��ַ�������Ϊ:( ��ʼ��  ������)");

    printf("\n");

    cout<<"��\n\n";

    cout<<content;

    cout<<"\n\n ��\n";

    Cprintf("��Enter������");

    while(getch() != 13);
}

//������Կ
void System::setkey()
{

    printf("\n\n");
    cout<<"��������ܵ���Կ:";
    cin>>key;
    while(true)
    {
        if(!cin.good())
        {
            cout<<"��Կֻ����С�ڵ���26��������:";
            cin>>key;
        } else
        {
            break;
        }
    }
    

    Cprintf("��Enter������");
    while(getch() != 13);
}

//��ȡ�ļ� 
void System::ReadFile()
{
    ifstream in;

    system("md Content 2>nul");

    in.open("Content/content.txt");

    if (!in.is_open()){
        Cprintf("�ļ������ڣ�");
        return;
    }
    
    in>>content;

    in.close();

}

void System::SaveFile()
{
    ofstream out;
    system("md Content 2>nul");

	out.open("Content/content.txt");

    out<<content;

    out.close();

}

//����
void System::encrypt()
{
    Cprintf("��ǰδ�����ı��ַ�������Ϊ:( ��ʼ��  ������)");
    printf("\n");

    cout<<"��\n\n";
    cout<<content<<"\n\n ��\n";

    Cprintf("�Ƿ�Ҫ���ܵ�\"content.txt\"?  y(��)/n(��):");
    
    string str;
    cin>>str;

    printf("\n");
    if(str == "y" || str == "Y"){

        encrypted(content);
        SaveFile();

        Cprintf("�Ѽ�����ɲ����浽\"content.txt\"");
        printf("\n\n");

        Cprintf("��Enter������");
        while(getch() != 13);

        return;
    }

}

char * System::encrypted(char cont[1000])
{
    int i;
    //��λ
    int num;

    //��λ���ascii��ֵ
    int ascii;

    //��ʱ������ܺ���ַ���
    static char temp[1000];

    for(i=0; cont[i]!='\0'; i++)
    {

        if (cont[i] >= 'A' && cont[i] <= 'Z')
		{
            num = cont[i] - 'A' + key;
            ascii = num % 26;

			temp[i] = ascii + 'A';
		}
		else if (cont[i] >= 'a' && cont[i] <= 'z')
		{
			num = cont[i] - 'a' + key;
            ascii = num % 26;

			temp[i] = ascii + 'a';

		}

    }

    cont[i] = '\0';

    
    //��ֵ��content
    for(int j=0; j<i; j++)
    {
        content[j] = temp[j];
    }


    return temp;
}

//����
void System::decrypt()
{
    Cprintf("��ǰδ�����ı��ַ�������Ϊ:( ��ʼ��  ������)");
    printf("\n");

    cout<<"��\n\n";
    cout<<content<<"\n\n ��\n";

    Cprintf("�Ƿ�Ҫ���ܵ�\"content.txt\"?  y(��)/n(��):");
    

    string str;
    cin>>str;

    printf("\n");
    if(str == "y" || str == "Y"){

        decrypted(content);
        SaveFile();

        printf("\n");

        Cprintf("�ѽ�����ɲ����浽\"content.txt\"");
        printf("\n\n");

        Cprintf("��Enter������");
        while(getch() != 13);
        return;

    }
}

char *  System::decrypted(char cont[1000])
{
    int i;
    //��λ
    int NUM,num;

    //��λ���ascii��ֵ
    int ASCII,ascii;

    //����key
    int Decrykey = 26-key;

    //��ʱ������ܺ���ַ���
    static char temp[1000];

    for(i=0; cont[i]!='\0'; i++)
    {
        
        if (cont[i] >= 'A' && cont[i] <= 'Z')
		{
            num = cont[i] - 'A' + Decrykey;
            ascii = num % 26;

			temp[i] = ascii + 'A';
		}
		else if (cont[i] >= 'a' && cont[i] <= 'z')
		{
			num = cont[i] - 'a' + Decrykey;
            ascii = num % 26;

			temp[i] = ascii + 'a';

		}

    }

    cont[i] = '\0';


    //��ֵ��content
    for(int j=0; j<i; j++)
    {
        content[j] = temp[j];
    }

    return temp;

}