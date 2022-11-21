
#include "Student.h"

// #include "StuSys.h"

class StuSys
{

private:
    
public:

    virtual void welcome(int delay);
	virtual void menu();

	void goodbye();
    StuSys(/* args */);
    ~StuSys();
};

class Manager:public StuSys
{
    private:
        Student *Head,*End;

    public:

        int count;
        int countRens();

        // void copy(Student *s1,Student *s);

        bool readFile();
        bool saveFile();

        void EmptyRemind();

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
    Head =  new Student;
    Head->next = NULL;
    End = Head;
    count = 0;
    
}

bool Manager::readFile()
{
    if(!Head->next) 
    {
        FILE *fpw = fopen("Students.txt", "w");
        fclose(fpw); //�ر��ļ�ָ��
    }
    FILE *fpr = fopen("Students.txt", "r");
	Student st;
	// Student *s;

	Student *t = Head;

	if (fpr == NULL)
	{
		return false;
	}
	else
	{

		while (fscanf(fpr, "%d %s %s %d %d %d %d %d %d", 
        &st.id, st.name, st.sex, &st.ma, &st.en, &st.et, &st.pc, &st.avr, &st.sum) != EOF)
		{
            Student *s = new Student;
            *s = st;
			t->next = s;
			t = s;
			t->next = NULL;
            End = t;
            count++;
		}
	}
	fclose(fpr); //�ر��ļ�ָ��
	return true;
}

bool Manager::saveFile()
{
    //����

    FILE *fpw = fopen("Students.txt", "w");

	if (!fpw)
		return false;

	Student *p = Head->next;
    if(!p)
        return true;
	while (p)
	{
		fprintf(fpw, "%d %s %s %d %d %d %d %d %d\n",
        p->id, p->name, p->sex, p->ma, p->en, p->et, p->pc, p->avr, p->sum);
		p = p->next;
	}

	fclose(fpw); //�ر��ļ�ָ��
	return true;
}

void Manager::EmptyRemind()
{
    cout<<"\n";
    SetTextGreen();
    for(int i = 3;i>=1;i--)
    {
        printf("                      ��ǰ��ѧ����Ϣ���������ѧ����Ϣ  %d ����Զ��˳�",i);
        Sleep(1000);
        cout<<"\r";
    }
    SetTextWhite();
}

int Manager::countRens()
{
    if (!Head)
		return 0;
	int n = 0;
    cout<<Head->next<<endl;
	Student *s = Head->next;
    while(s)
    {
        cout<<s->name<<endl;
        n++;
        s = s->next;
    }
	return n;
}


void Manager::welcome(int delay)
{

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
    
    if(readFile())
    {
        printf("������������������������������            �ļ���ʼ���ɹ�            ����������������������������\n");
    }
    else{
        printf("������������������������������            �ļ���ʼ��ʧ��            ����������������������������\n");
    }

}

void Manager::menu()
{

    

    int choice;
    // printf("\n����빦��\n");
    while (true)
    {
        // ShowCursor(true);
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

    Student S,*s = Head->next;
    int choice;
    string str;

    while(true)
    {
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

        printf("������ѧ��:");
        while (1)
        {
            cin >> str;
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                cout << "ѧ��ֻ��������,����������:";
                cin >> str;
            }
            
            S.id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
            if (S.id < 20220000 || S.id > 20229999)
            {
                printf("ѧ�Ÿ�ʽ����,����������:");
            }
            else
            {
                while(s && s->id != S.id)
                {
                    s = s->next;
                }
                if(s)
                {
                    printf("ѧ���Ѵ���!����������:");
                }else{
                    break;
                }
            
            }
            
        }

        printf("����������:");
        scanf("%s", S.name);

        printf("�������Ա�:");
        while (1)
        {
            scanf("%s", S.sex);
            if (strcmp(S.sex, "��") == 0 || strcmp(S.sex, "Ů") == 0)
            {
                break;
            }
            else
            {
                printf("�Ա����,����������:");
            }
        };

        printf("��������ѧ�ɼ�:");
        while (1)
        {

            cin >> str;
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                cout << "����������,����������ѧ:\n";
                cin >> str;
            }
            S.ma = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

            if ((S.ma < 0) || (S.ma > 100))
            {
                printf("��ѧ����100,����������:");
            }
            else
            {
                break;
            }
        }

        printf("������Ӣ��ɼ�:");
        while (1)
        {
            cin >> str;
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                cout << "����������,��������Ӣ��:\n";
                cin >> str;
            }
            S.en = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

            if (S.en < 0 || S.en > 100)
            {
                printf("Ӣ������100,����������:");
            }
            else
            {
                break;
            }
        }

        printf("�����������ɼ�:");
        while (1)
        {
            cin >> str;
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                cout << "����������,������������:\n";
                cin >> str;
            }
            S.et = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

            if (S.et < 0 || S.et > 100)
            {
                printf("��������100,����������:");
            }
            else
            {
                break;
            }
        }

        printf("�����������ɼ�:");
        while (1)
        {

            cin >> str;
            while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
            {
                cout << "����������,������������:\n";
                cin >> str;
            }
            S.pc = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

            if (S.pc < 0 || S.pc > 100)
            {
                printf("���������100,����������:");
            }
            else
            {
                break;
            }
        }

        S.sum = S.en+S.et+S.ma+S.pc;
        S.avr = S.sum/4;
        S.next = NULL;

        AddWelcome(0);
        PrintSingleStu(S);
        printf("\n                                   ȷ����Ϣ?  Y/N");
        while(true)
        { 
            choice = getch();
            if(choice == 89 || choice == 121) 
            {
                AddStu(&S); 
                SetTextGreen();
                cout<<"\n\n                                   ��ӳɹ�!";
                SetTextWhite();
                Sleep(2000);
               break;
            }
            if(choice == 78 || choice == 110)
            {
                break;
            }
        }
        
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
            cout<<"������ѧ��:";
            while (1)
            {
                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    cout << "ѧ������,����������:";
                    cin >> str;
                }
                id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
                if (id < 20220000 || id > 20229999)
                {
                    printf("ѧ������,����������:");
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
                printf("\n                                   ȷ��ɾ��?  Y(��)/N(��)");
            }else{
                printf("\n                                          ѧ�������ڣ�");
                Sleep(2000);
                break;
            }
            while(true)
            {
                choice = getch();
                if(choice == 89 || choice == 121) 
                {
                    DeleteStu(s);
                    cout<<"\n                                        ɾ���ɹ�!";
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
            cout<<"����������:";
            cin>>name;
            DelWelcome(0);
            s = SearchByName(name);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                
                printf("\n                                   ȷ��ɾ��?  Y(��)/N(��)");
            }else{
                printf("\n                                          ѧ�������ڣ�");
                Sleep(2000);
                break;
            }
            while(true)
            {
                choice = getch();
                if(choice == 89 || choice == 121) 
                {
                    DeleteStu(s);
                    cout<<"\n                                   ɾ���ɹ�!";
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
                    SetTextRed();
                    PrintSingleStu(S);
                    SetTextWhite();
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n                                          ����ѧ�ҿ�ѧ��");
                Sleep(2500);
                break;
            }
            printf("\n                                          �����������");
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
                    SetTextRed();
                    PrintSingleStu(S);
                    SetTextWhite();
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n                                          ��Ӣ��ҿ�ѧ��");
                Sleep(2500);
                break;
            }
            printf("\n                                          �����������");
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
                    SetTextRed();
                    PrintSingleStu(S);
                    SetTextWhite();
                    
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n                                          �������ҿ�ѧ��");
                Sleep(2500);
                break;
            }
            printf("\n                                          �����������");
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
                    SetTextRed();
                    PrintSingleStu(S);
                    SetTextWhite();
                }
                s = s->next;
            }
            if(!countRens)
            {
                printf("\n                                          �޼�����ҿ�ѧ��");
                Sleep(2500);
                break;
            }
            printf("\n                                              �����������");
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
            cout<<"������ѧ��:";
            while (1)
            {
                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    cout << "ѧ������,����������:";
                    cin >> str;
                }
                id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
                if (id < 20220000 || id > 20229999)
                {
                    printf("ѧ������,����������:");
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
                printf("\n                                      �����������");
            }else{
                printf("\n                                          ѧ�������ڣ�");
                Sleep(2000);
                break;
            }
            getch();
            break;
        case 78:
        case 110:

            ShowCursor(true);
            cout<<"����������:";
            cin>>name;
            SearchWelcome(0);
            s = SearchByName(name);
            if(s->next)
            {
                S = *s->next;
                PrintSingleStu(S);
                printf("\n                                         �����������");
            }else{
                printf("\n                                          ѧ�������ڣ�");
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
    Student S,*s;
    if(stu->next)
    {
        UpWelcome(20);
        S = *stu->next;
        PrintSingleStu(S);
        
    }else{
        printf("\n                                          ѧ�������ڣ�");
        Sleep(2000);
        return;
    }

    //�޸���Ϣ
    s = stu->next;
    while(true)
    {

        UpdateChoice = getch();
        if(UpdateChoice == 96 || UpdateChoice == 48) break;
    
        switch (UpdateChoice)
        {
        case 49:
        case 97:
            cout<<endl;
            printf("������ѧ��:");
            while (1)
            {
                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    cout << "ѧ��ֻ��������,����������:";
                    cin >> str;
                }
                s->id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
                if (s->id < 20220000 || s->id > 20229999)
                {
                    printf("ѧ�Ų��Ϸ�,����������:");
                }
                else
                {
                    break;
                }
            }
            printf("                                            �޸ĳɹ���");
            Sleep(2000);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 50:
        case 98:
            cout<<endl;
            printf("����������:");
            scanf("%s", s->name);
            printf("                                            �޸ĳɹ���");
            Sleep(2000);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 51:
        case 99:
            cout<<endl;
            printf("�������Ա�:");
            while (1)
            {
                scanf("%s", s->sex);
                if (strcmp(s->sex, "��") == 0 || strcmp(s->sex, "Ů") == 0)
                {
                    break;
                }
                else
                {
                    printf("�Ա����,����������:");
                }
            };
            printf("                                            �޸ĳɹ���");
            Sleep(2000);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 52:
        case 100:
            cout<<endl;
            printf("��������ѧ�ɼ�:");
            while (1)
            {

                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    cout << "����������,����������ѧ:\n";
                    cin >> str;
                }
                s->ma = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

                if ((s->ma < 0) || (s->ma > 100))
                {
                    printf("��ѧ����100,����������:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("                                            �޸ĳɹ���");
            Sleep(2000);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 53:
        case 101:
            cout<<endl;
            printf("������Ӣ��ɼ�:");
            while (1)
            {
                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    cout << "����������,��������Ӣ��:\n";
                    cin >> str;
                }
                s->en = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

                if (s->en < 0 || s->en > 100)
                {
                    printf("Ӣ������100,����������:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("                                            �޸ĳɹ���");
            Sleep(2000);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 54:
        case 102:
            cout<<endl;
            printf("�����������ɼ�:");
            while (1)
            {
                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    cout << "����������,������������:\n";
                    cin >> str;
                }
                s->et = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

                if (s->et < 0 || s->et > 100)
                {
                    printf("��������100,����������:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("                                            �޸ĳɹ���");
            Sleep(2000);
            UpWelcome(10);

            PrintSingleStu(*s);
            break;
        case 55:
        case 103:
            cout<<endl;
            printf("�����������ɼ�:");
            while (1)
            {

                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    cout << "����������,������������:\n";
                    cin >> str;
                }
                s->pc = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����

                if (s->pc < 0 || s->pc > 100)
                {
                    printf("���������100,����������:");
                }
                else
                {
                    break;
                }
            }
            s->sum = s->en+s->et+s->ma+s->pc;
            s->avr = s->sum/4;
            printf("                                            �޸ĳɹ���");
            Sleep(2000);
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
            cout<<"������ѧ��:";
            while (1)
            {
                cin >> str;
                while (!IsRegexInput(str)) // �ж�����������Ƿ�Ϊ����
                {
                    cout << "ѧ������,����������:";
                    cin >> str;
                }
                id = atoi(str.c_str()); //����û�����⣬�����ַ���ת��Ϊ����
                if (id < 20220000 || id > 20229999)
                {
                    printf("ѧ������,����������:");
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
            printf("����������:");
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

