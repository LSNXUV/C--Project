

#include "Manager.h"
#include "Analyst.h"


StuSys::StuSys(/* args */)
{
	Head =  new Student;
    Head->next = NULL;
    End = Head;
    count = 0;
}

bool StuSys::readFile()
{
    ifstream f("Students.txt");
    if(!f.good())
    {
        FILE *fpw = fopen("Students.txt", "w");
        fclose(fpw); //�ر��ļ�ָ��
        return true;
    }
    FILE *fpr = fopen("Students.txt", "r");
    Student st;
    // Student *s;

    Student *t = Head;
	count = 0;
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

bool StuSys::saveFile()
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

void StuSys::welcome(int delay)
{

	system("cls");
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��      ѧ���ɼ����������ϵͳ    ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������                                ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          ��������        ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          S.�ɼ�����ϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          F.�ɼ�����ϵͳ        ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          H.�鿴ʹ���ֲ�        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�� ��  ϵ ͳ        ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");


}

void StuSys::menu()
{

	SetConsoleTitleA("ѧ����Ϣ����ͷ���ϵͳ");
    system("mode con cols=96");

    welcome(20);
	int choice;
	Manager StuM;
	Analyst StuA;
	string username = "root";
	string password = "admin777";
	string user,pw;
	
	/* cout<<"���������Ա�˺�����\n";
	while(true)
	{
		cout<<"username:";
		cin>>user;
		cout<<"password:";
		cin>>pw;
		if(user == "root" && pw == "admin777")
		{
			cout<<"��¼�ɹ�!\n";
			break;
		}
		cout<<"�˺Ż��������!\n";
	} */

	// printf("����빦��\n");
	
	while(true)
	{
		//���ع��
		ShowCursor(false);

		welcome(0);

		choice = getch();
		switch (choice)
		{
		case 83:
		case 115:
			StuM.menu();
			welcome(20);
			break;
		case 70:
		case 102:
			StuA.menu();
			welcome(20);
			break;
		default:
			break;
		}
		if(choice==96||choice==48)
		{
			break;
		}
	}
	goodbye();

}

void StuSys::EmptyRemind()
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

bool StuSys::IsRegexInput(string str) 
{
	bool flag;
	flag = true;
	regex r("\\d{1,8}");
	while (!(flag = regex_match(str, r)))
	{
		return flag;
	}
	return flag;

}

//��ʾ�����ع��
void StuSys::ShowCursor(bool visible) { 

    CONSOLE_CURSOR_INFO cursor_info = {20, visible};
    //CONSOLE_CURSOR_INFO�ṹ���������̨�����Ϣ����Ա�ֱ��ʾ���ٷֱȺ�Ⱥ��Ƿ�ɼ�
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
 	//SetConsoleCursorInfo�趨����̨���ڵĹ���С���Ƿ�ɼ�
}


void StuSys::SetTextRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void StuSys::SetTextGreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void StuSys::SetTextWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


void StuSys::gotoxy(int x,int y){  
    COORD pos;  
    pos.X=x;  
    pos.Y=y;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos); 
}

void StuSys::Mprintf(string str)
{
	cout<<setw(48)<<str;
}
void StuSys::Cprintf(string str)
{
	cout<<setw(48+str.length()/2)<<str;
}

void StuSys::goodbye()
{
	SetTextGreen();
	printf("\n					   ��ӭ�´�ʹ��~\n");
	SetTextWhite();

    Sleep(3000);
}

void StuSys::Free(Student *Head)
{
	if(Head)
	{
		Free(Head->next);
		free(Head);
	}
}

StuSys::~StuSys()
{

}
