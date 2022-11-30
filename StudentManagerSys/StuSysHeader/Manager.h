
#include "Student.h"


class StuSys
{
    private:

    protected:
        Student *Head,*End;
        int count;
    public:

        bool readFile();
        bool saveFile();

        virtual void welcome(int delay);
        virtual void menu();

        void Cprintf(string str);
        void Mprintf(string str);
        void SetTextWhite();
        void SetTextGreen();
        void SetTextRed();
        void ShowCursor(bool visible);
        bool IsRegexInput(string str);
        void gotoxy(int x,int y);
        void SizeGoAway();
        void DeleteGoAway();
        void EmptyRemind();


        void goodbye();
        void Free(Student *Head);
        StuSys(/* args */);
        ~StuSys();

};

class Manager:public StuSys
{
    private:

    public:

        void welcome(int delay);
        void menu();

        void AddWelcome(int delay);
        void PrintAddStu();
        void AddStu(Student *S);

        void DeleteStu(Student *S);
        void DelWelcome(int delay);
        void PrintDeleteStu();

        void UpdateWelcome(int delay);
        // ��ӡ�޸���Ϣ��ʾҳ��
        void UpWelcome(int delay);
        void PrintUpdateStu();
        void UpdateStu(Student *stu);

        //����
        void SearchWelcome(int delay);
        void PrintSingleStu(Student S);
        void PrintSearchStu();
        void PrintSearchFail();
        void SearchFailWelcome(int delay);

        Student * SearchByName(char name[]);
        Student * SearchById(int id);


        Manager(/* args */);
        ~Manager();
};


Manager::Manager(/* args */)
{
    
}


void Manager::welcome(int delay)
{
    readFile();
    system("cls");
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��     ѧ �� �� �� �� �� ϵ ͳ    ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          A.����ѧ����Ϣ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          D.ɾ��ѧ����Ϣ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          U.�޸�ѧ����Ϣ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          S.��ѯѧ����Ϣ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�˳�����ϵͳ        ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");
    printf("������������������������������            �ļ���ʼ���ɹ�            ����������������������������\n");
    

}

void Manager::menu()
{
    
    int choice;

    while (true)
    {
        
        welcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 65 || choice == 97 || choice == 68 || choice == 100 || 
                choice == 85 || choice == 117 || choice == 83 || choice == 115 ||
                choice == 96||choice == 48 )
            {
                break;
            }
        }
        if(choice == 96||choice == 48)
        {
            break;
        }
        switch (choice)
        {
        case 65:
        case 97:
            PrintAddStu();
            break;
        case 68:
        case 100:
            PrintDeleteStu();
            break;
        case 85:
        case 117:
            PrintUpdateStu();
            break;
        case 83:
        case 115:
            PrintSearchStu();
            break;
        default:
            break;
        }
    }
}


void Manager::AddStu(Student *S)
{

    End->next = S;
    End = S;
    End->next = NULL;

    // PrintSingleStu(*End);
    saveFile();
}

void Manager::AddWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��     ѧ �� �� Ϣ �� �� ϵ ͳ    ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          A.����ѧ����Ϣ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�ص�����ϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");
}

void Manager::PrintAddStu()
{

    Student *s;
    int choice;
    string str;

    while(true)
    {
        Student *Stu = new Student;

        AddWelcome(20);

        while(true)
        {
            choice = getch();
            if(choice == 97 || choice == 65 || choice == 96 || choice == 48)
            {
                break;
            }
        }
        
        if(choice == 96 || choice == 48)
        {
            return;
        }
        
        //���ѧ����Ϣ

        ShowCursor(true);
        printf("\n");
        Mprintf("������ѧ��:");
        
        while (1)
        {
            SetTextGreen();
            cin >> str;
            SetTextWhite();
            printf("\n");
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                SetTextGreen();Cprintf("ѧ��ֻ��������\n");SetTextWhite();
                Mprintf("����������:");
                SetTextGreen();cin >> str;SetTextWhite();
                printf("\n");
            }
            
            Stu->id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
            if (Stu->id < 20220000 || Stu->id > 20229999)
            {
                SetTextGreen();
                Cprintf("ѧ�Ÿ�ʽ����\n");
                SetTextWhite();
                Mprintf("����������:");
            }
            else
            {
                s = Head->next;
                while(s && s->id != Stu->id)
                {
                    // cout<<s->id<<" -- "<<S.id<<endl;
                    s = s->next;
                }
                if(s)
                {
                    // cout<<s->id<<" -- "<<S.id<<endl;
                    SetTextGreen();Cprintf("ѧ���Ѵ���\n");SetTextWhite();
                    Mprintf("����������:");
                }else{
                    break;
                }
            }
        }

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("����������:");
        SetTextGreen();
        scanf("%s", Stu->name);
        printf("\n");
        while(strlen(Stu->name) > 6)
        {
            SetTextGreen();
            printf("\n");Cprintf("�������Ȳ��ܳ���3");printf("\n");SetTextWhite();
            Mprintf("����������:");
            SetTextGreen();
            scanf("%s", Stu->name);
        }
        SetTextWhite();

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("�������Ա�:");
        while (1)
        {
            SetTextGreen();scanf("%s", Stu->sex);SetTextWhite();printf("\n\n");
            if (strcmp(Stu->sex, "��") == 0 || strcmp(Stu->sex, "Ů") == 0)
            {
                break;
            }
            else
            {
                SetTextGreen();Cprintf("�ǵ����˲��������ϢŶ\n");SetTextWhite();
                Mprintf("����������:");
            }
        };

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("��������ѧ�ɼ�:");
        while (1)
        {

            SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                SetTextGreen();Cprintf("������������\n");SetTextWhite();
                Mprintf("����������:");
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            }
            Stu->ma = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

            if ((Stu->ma < 0) || (Stu->ma > 100))
            {
                SetTextGreen();Cprintf("��ѧ����100\n");SetTextWhite();
                Mprintf("����������:");
            }
            else
            {
                break;
            }
        }

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("������Ӣ��ɼ�:");
        while (1)
        {
            SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                SetTextGreen();Cprintf("������������\n");SetTextWhite();
                Mprintf("����������:");
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            }
            Stu->en = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

            if (Stu->en < 0 || Stu->en > 100)
            {
                SetTextGreen();Cprintf("Ӣ������100\n");SetTextWhite();
                Mprintf("����������:");
            }
            else
            {
                break;
            }
        }

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("�����������ɼ�:");
        while (1)
        {
            SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                SetTextGreen();Cprintf("������������\n");SetTextWhite();
                Mprintf("����������:");
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            }
            Stu->et = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

            if (Stu->et < 0 || Stu->et > 100)
            {
                SetTextGreen();Cprintf("��������100\n");SetTextWhite();
                Mprintf("����������:");
            }
            else
            {
                break;
            }
        }

        AddWelcome(10);ShowCursor(true);
        printf("\n");
        Mprintf("�����������ɼ�:");
        while (1)
        {

            SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                SetTextGreen();Cprintf("������������\n");SetTextWhite();
                Mprintf("����������:");
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
            }
            Stu->pc = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

            if (Stu->pc < 0 || Stu->pc > 100)
            {
                SetTextGreen();Cprintf("���������100\n");SetTextWhite();
                Mprintf("����������:");
            }
            else
            {
                break;
            }
        }

        Stu->sum = Stu->en+Stu->et+Stu->ma+Stu->pc;
        Stu->avr = Stu->sum/4;
        Stu->next = NULL;

        AddWelcome(10);
        PrintSingleStu(*Stu);
        printf("\n\n");
        SetTextGreen();
        Cprintf("ȷ����Ϣ?  Y/N");
        while(true)
        { 
            choice = getch();
            if(choice == 89 || choice == 121) 
            {
                AddStu(Stu); 
                printf("\n\n");
                Cprintf("��ӳɹ�!");
                
                Sleep(2000);
               break;
            }
            if(choice == 78 || choice == 110)
            {
                break;
            }
        }
        SetTextWhite();
        
    }
    
}

Student * Manager::SearchById(int id)
{
    Student *S = Head;
    while(S->next && S->next->id !=  id)
    {
        S = S->next;
    }
    return S;
}

Student * Manager::SearchByName(char name[])
{
    Student *S = Head;
    while(S->next && strcmp(S->next->name,name) != 0)
    {
        S = S->next;
    }
    return S;
}

void Manager::DeleteStu(Student *S)
{
    Student *s = S->next;
    S->next = s->next;
    free(s);

    saveFile();
}

void Manager::DelWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��     ѧ �� �� Ϣ ɾ �� ϵ ͳ    ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          I.ͨ��ѧ�Ų���        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          N.ͨ�����ֲ���        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�ص�����ϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");

}

void Manager::PrintDeleteStu()
{
    
    int choice;
    int id;
    char name[50];
    Student S,*s;
    string str;
    while(true)
    {
        DelWelcome(20);
        //�ж�ѧ����Ϣ�Ƿ�Ϊ��
        if(count == 0)
        {
            EmptyRemind();
            break;
        }
        while(true)
        {
            choice = getch();
            if( choice == 73 || choice == 105 ||
                choice == 78 || choice == 110 || 
                choice == 96 || choice == 48 
            )
            {
                break;
            }
        }
        
        switch (choice)
        {
        case 73:
        case 105:

            ShowCursor(true);
            printf("\n\n");Mprintf("������ѧ��:");
            while (1)
            {
                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    Mprintf("ѧ������,����������:");
                    cin >> str;
                }
                id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
                if (id < 20220000 || id > 20229999)
                {
                    Mprintf("ѧ������,����������:");
                }
                else
                {
                    break;
                }
            }
            DelWelcome(0);
            s = SearchById(id);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                printf("\n\n");
                SetTextRed();
                Cprintf("ȷ��ɾ��?  Y(��)/N(��)");
                SetTextWhite();
            }else{
                printf("\n\n");
                SetTextGreen();
                Cprintf("ѧ��������!");
                SetTextWhite();
                printf("\n\n");
                Cprintf("��������˳�");
                Sleep(2000);
                getch();
                break;
            }
            while(true)
            {
                choice = getch();
                if(choice == 89 || choice == 121) 
                {
                    DeleteStu(s);
                    printf("\n\n");
                    SetTextGreen();
                    Cprintf("ɾ���ɹ�!");
                    SetTextWhite();
                    Sleep(2000);
                    break;
                }
                if(choice == 78 || choice == 110)
                {
                    break;
                }
            }
            break;
        case 78:
        case 110:

            ShowCursor(true);
            Mprintf("����������:");
            cin>>name;
            DelWelcome(0);
            s = SearchByName(name);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                printf("\n\n");
                SetTextRed();
                Cprintf("ȷ��ɾ��?  Y(��)/N(��)");
                SetTextWhite();
            }else{
                printf("\n\n");
                SetTextGreen();
                Cprintf("ѧ��������!");
                SetTextWhite();
                printf("\n\n");
                Cprintf("��������˳�");
                Sleep(2000);
                getch();
                break;
            }
            while(true)
            {
                choice = getch();
                if(choice == 89 || choice == 121) 
                {
                    DeleteStu(s);
                    printf("\n\n");
                    SetTextGreen();
                    Cprintf("ɾ���ɹ�!");
                    SetTextWhite();
                    Sleep(2000);
                    break;
                }
                if(choice == 78 || choice == 110)
                {
                    break;
                }
            }
            break;
        default:
            break;
        }

        if(choice==96||choice==48)
		{
			break;
		}
    }
}

void Manager::SearchWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��     ѧ �� �� Ϣ �� ѯ ϵ ͳ    ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          I.ͨ��ѧ�Ų���        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          N.ͨ�����ֲ���        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          F.���ҹҿ�ѧ��        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�ص�����ϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");
}

void Manager::SearchFailWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��     ѧ �� �� �� �� ѯ ϵ ͳ    ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��            1.��ѧ�ҿ�          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            2.Ӣ��ҿ�          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            3.�����ҿ�          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��           4.������ҿ�         ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�ص���ѯϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");

}

void Manager::PrintSearchFail()
{
    int choice;
    Student *s,S;
    while(true)
    {
        int countRens = 0;
        SearchFailWelcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 97 || choice == 49 ||
                choice == 98 || choice == 50 ||
                choice == 99 || choice == 51 ||
                choice == 100 || choice == 52 
            ) break; 
        }

        if(choice == 96 || choice == 48) break;

        switch (choice)
        {
        case 97:
        case 49:
            s = Head->next;
            while(s)
            {
                if(s->ma < 60)
                {
                    countRens++;
                    S = *s;
                    SetTextGreen();
                    PrintSingleStu(S);Sleep(30);
                    SetTextWhite();
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n\n");
                SetTextGreen();Cprintf("����ѧ�ҿ�ѧ��");SetTextWhite();
                Sleep(2500);
                break;
            }
            printf("\n\n");
            Cprintf("�����������");
            getch();
            break;
        case 98:
        case 50:
            s = Head->next;
            while(s)
            {
                if(s->en < 60)
                {
                    countRens++;
                    S = *s;
                    SetTextGreen();
                    PrintSingleStu(S);Sleep(30);
                    SetTextWhite();
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n\n");
                SetTextGreen();Cprintf("��Ӣ��ҿ�ѧ��");SetTextWhite();
                Sleep(2500);
                break;
            }
            printf("\n\n");
            Cprintf("�����������");
            getch();
            break;
            break;
        case 99:
        case 51:
            s = Head->next;
            while(s)
            {
                if(s->et < 60)
                {
                    countRens++;
                    S = *s;
                    SetTextGreen();
                    PrintSingleStu(S);Sleep(30);
                    SetTextWhite();
                    
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n\n");
                SetTextGreen();Cprintf("�������ҿ�ѧ��");SetTextWhite();
                Sleep(2500);
                break;
            }
            printf("\n\n");
            Cprintf("�����������");
            getch();
            break;
        case 100:
        case 52:
            s = Head->next;
            while(s)
            {
                if(s->pc < 60)
                {
                    countRens++;
                    S = *s;
                    SetTextGreen();
                    PrintSingleStu(S);Sleep(30);
                    SetTextWhite();
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n\n");
                SetTextGreen();Cprintf("�޼�����ҿ�ѧ��");SetTextWhite();
                Sleep(2500);
                break;
            }
            printf("\n\n");
            Cprintf("�����������");
            getch();
            break;
        default:
            break;
        }
    }
}

void Manager::PrintSingleStu(Student S)
{
    cout<<"\n           ";
    printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������");
    cout<<"\n           ";
    printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|");
    cout<<"\n           ";
    printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������");
    cout<<"\n           ";
    printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|", S.id, S.name, S.sex, S.ma, S.en, S.et, S.pc, S.avr, S.sum);
    cout<<"\n           ";
    printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������");
}

void Manager::PrintSearchStu()
{
    int choice;
    int id;
    char name[50];
    Student S,*s;
    string str;
    while(true)
    {
        SearchWelcome(20);
        //�ж�ѧ����Ϣ�Ƿ�Ϊ��
        if(count == 0)
        {
            EmptyRemind();
            break;
        }
        while(true)
        {
            choice = getch();
            if( choice == 78 || choice == 73 || 
                choice == 110 || choice == 105 || 
                choice == 96 || choice == 48 ||
                choice == 70 || choice == 102
            )
            {
                break;
            }
        }
        
        switch (choice)
        {
        case 73:
        case 105:

            ShowCursor(true);
            printf("\n\n");Mprintf("������ѧ��:");
            
            while (1)
            {
                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    Mprintf("ѧ��ֻ����������,����������:");
                    cin >> str;
                }
                id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
                if (id < 20220000 || id > 20229999)
                {
                    Mprintf("ѧ������,����������:");
                }
                else
                {
                    break;
                }
            }
            SearchWelcome(0);
            
            s = SearchById(id);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                printf("\n\n");
                Cprintf("�����������");
            }else{
                printf("\n\n");
                Cprintf("ѧ�������ڣ�");
                Sleep(2000);
                break;
            }
            getch();
            break;
        case 78:
        case 110:

            ShowCursor(true);
            Mprintf("����������:");
            cin>>name;
            SearchWelcome(0);
            s = SearchByName(name);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                printf("\n\n");
                Cprintf("�����������");
            }else{
                printf("\n\n");
                Cprintf("ѧ�������ڣ�");
                Sleep(2000);
                break;
            }
            getch();
            break;
        case 70:
        case 102:
            PrintSearchFail();
            break;
        default:
            break;
        }
        if(choice==96||choice==48)
		{
			break;
		}
    }
}

void Manager::UpdateWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��     ѧ �� �� Ϣ �� �� ϵ ͳ    ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          I.ͨ��ѧ�Ų���        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          N.ͨ�����ֲ���        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�ص�����ϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");

}

void Manager::UpWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��     ѧ �� �� Ϣ �� �� ϵ ͳ    ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��            1.�޸�ѧ��          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            2.�޸�����          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            3.�޸��Ա�          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          4.�޸���ѧ�ɼ�        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          5.�޸�Ӣ��ɼ�        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          6.�޸������ɼ�        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��         7.�޸ļ�����ɼ�       ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�ص���ѯϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");
}

void Manager::UpdateStu(Student *stu)
{
    string str;
    int UpdateChoice;
    Student S,*s,*st = Head->next;
    int id;
    if(stu->next)
    {
        UpWelcome(20);
        S = *stu->next;
        PrintSingleStu(S);
        
    }else{
        printf("\n\n");
        Cprintf("ѧ�������ڣ�");
        Sleep(2000);
        return;
    }

    //�޸���Ϣ
    s = stu->next;
    while(true)
    {

        UpdateChoice = getch();
        if(UpdateChoice == 96 || UpdateChoice == 48) 
        {
            ShowCursor(false);
            break;
        }
        ShowCursor(true);
        switch (UpdateChoice)
        {
        case 49:
        case 97:
    
            printf("\n\n");Mprintf("������ѧ��:");
            while (1)
            {
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    SetTextGreen();Cprintf("ѧ��ֻ��������\n");SetTextWhite();
                    Mprintf("����������:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
            
                id = atoi(str.c_str());//����û�����⣬�����ַ���ת��Ϊ����
                if (id < 20220000 || id > 20229999)
                {
                    SetTextGreen();Cprintf("ѧ�Ÿ�ʽ����\n");SetTextWhite();
                    Mprintf("����������:");
                }
                else
                {
                    if(id == s->id) break;
                    while(st && st->id != id)
                    {
                        st = st->next;
                    }
                    if(st)
                    {
                        SetTextGreen();Cprintf("ѧ���Ѵ���\n");SetTextWhite();
                        Mprintf("����������:");
                        st = Head->next;
                    }else{
                        break;
                    }
                }
            }
            printf("\n");
            ShowCursor(false);Cprintf("�޸ĳɹ���");
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 50:
        case 98:
            printf("\n\n");Mprintf("����������:");
            SetTextGreen();scanf("%s", s->name);
            while(strlen(s->name)>=6)
            {
                SetTextGreen();
                printf("\n");Cprintf("�������Ȳ��ܳ���3");printf("\n");SetTextWhite();
                Mprintf("����������:");
                SetTextGreen();
                scanf("%s", s->name);
            }
            SetTextWhite();
            printf("\n");
            Cprintf("�޸ĳɹ���");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 51:
        case 99:
            cout<<endl;
            printf("\n\n");Mprintf("�������Ա�:");
            while (1)
            {
                scanf("%s", s->sex);
                if (strcmp(s->sex, "��") == 0 || strcmp(s->sex, "Ů") == 0)
                {
                    break;
                }
                else
                {
                    SetTextGreen(); Cprintf("�ǵ����˲��������ϢŶ\n");SetTextWhite();
                    Mprintf("����������:");
                }
            };
            printf("\n");
            Cprintf("�޸ĳɹ���");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 52:
        case 100:

            printf("\n\n");Mprintf("��������ѧ�ɼ�:");
            while (1)
            {

                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    SetTextGreen();Cprintf("������������\n");SetTextWhite();
                    Mprintf("����������:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
                s->ma = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

                if ((s->ma < 0) || (s->ma > 100))
                {
                    SetTextGreen();Cprintf("��ѧ����100\n");SetTextWhite();
                    Mprintf("����������:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("\n");
            Cprintf("�޸ĳɹ���");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 53:
        case 101:
            cout<<endl;
            printf("\n\n");Mprintf("������Ӣ��ɼ�:");
            while (1)
            {
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    SetTextGreen();Cprintf("������������\n");SetTextWhite();
                    Mprintf("����������:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
                s->en = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

                if (s->en < 0 || s->en > 100)
                {
                    SetTextGreen();Cprintf("Ӣ������100\n");SetTextWhite();
                    Mprintf("����������:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("\n");
            Cprintf("�޸ĳɹ���");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 54:
        case 102:
            cout<<endl;
            printf("\n\n");Mprintf("�����������ɼ�:");
            while (1)
            {
                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    SetTextGreen();Cprintf("������������\n");SetTextWhite();
                    Mprintf("����������:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
                s->et = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

                if (s->et < 0 || s->et > 100)
                {
                    SetTextGreen();Cprintf("��������100\n");SetTextWhite();
                    Mprintf("����������:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("\n");
            Cprintf("�޸ĳɹ���");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 55:
        case 103:
            cout<<endl;
            printf("\n\n");Mprintf("�����������ɼ�:");
            while (1)
            {

                SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    SetTextGreen();Cprintf("������������\n");SetTextWhite();
                    Mprintf("����������:");
                    SetTextGreen();cin >> str;SetTextWhite();printf("\n");
                }
                s->pc = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

                if (s->pc < 0 || s->pc > 100)
                {
                    SetTextGreen();Cprintf("���������100\n");SetTextWhite();
                    Mprintf("����������:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("\n");
            Cprintf("�޸ĳɹ���");ShowCursor(false);
            Sleep(1500);
            UpWelcome(10);
            PrintSingleStu(*s);
            break;
        default:
            break;
        }
    }

    saveFile();
}

void Manager::PrintUpdateStu()
{
    int choice,UpdateChoice,id;
    char name[50];
    string str;
    Student S,*s,*stu;
    s = new Student();

    while(true)
    {
        UpdateWelcome(20);

        //�ж�ѧ����Ϣ�Ƿ�Ϊ��
        if(count == 0)
        {
            EmptyRemind();
            break;
        }
        while(true)
        {
            choice = getch();
            if( choice == 78 || choice == 73 || 
                choice == 110 || choice == 105 || 
                choice == 96 || choice == 48
            )
            {
                break;
            }
        }

        switch (choice)
        {
        case 73:
        case 105:

            ShowCursor(true);
            printf("\n\n");Mprintf("������ѧ��:");
            while (1)
            {
                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    Mprintf("ѧ������,����������:");
                    cin >> str;
                }
                id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
                if (id < 20220000 || id > 20229999)
                {
                    Mprintf("ѧ������,����������:");
                }
                else
                {
                    break;
                }
            }
    
            stu = SearchById(id);
            
            UpdateStu(stu);
            
            break;
        case 78:
        case 110:
            ShowCursor(true);
            printf("\n\n");Mprintf("����������:");
            scanf("%s", name);

            stu = SearchByName(name);

            UpdateStu(stu);
            break;
        default:
            break;
        }
        
        if(choice == 96 || choice == 48)
        {
            break;
        }
    }
}


Manager::~Manager()
{

}

