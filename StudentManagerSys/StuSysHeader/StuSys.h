

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
	
	system("md Students 2>nul");
    FILE *fpr = fopen("Students/Students.txt", "r");
    Student st;
    Student *t = Head;
	count = 0;
	
    if (!fpr)
    {
        FILE *fpw = fopen("Students/Students.txt", "w");
        fclose(fpw); //�ر��ļ�ָ��
        return true;
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
	system("md Students 2>nul");
    FILE *fpw = fopen("Students/Students.txt", "w");

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
	
	SizeGoAway();
    DeleteGoAway();
	SetConsoleTitleA("                                                                                               ѧ����Ϣ����ͷ���ϵͳ");
    system("mode con cols=96");

    welcome(20);

	string username;
	char ch;
	
	printf("\n\n");
	Cprintf("���������Ա�˺�����\n");
	while(true)
	{
		int i = 0;
		char password[50];
		string pw;

		printf("\n");
		Mprintf("username:");
		cin>>username;

		printf("\n");
		Mprintf("password:");
		while((ch=getch())!='\r')
		{
			if(ch!=8)//���ǻس���¼��
			{
				password[i++]=ch;
				putchar('*');//�������*��
			}
			else
			{
				if(i == 0) continue;
				putchar('\b');//������ɾ��һ��������ͨ������س��� /b���س�һ��
				putchar(' ');//����ʾ�ո���Ѹղŵ�*����ס��
				putchar('\b');//Ȼ���� �س�һ��ȴ�¼�롣
				i--;
			}
		}

		password[i]='\0';
		pw = password;
		if(username == "root" && pw == "admin777")
		{
			SetTextGreen();
			printf("\n\n");
			Cprintf("��¼�ɹ�!\n");
			SetTextWhite();
			ShowCursor(false);
			Sleep(1000);
			break;
		}

		welcome(0);
		printf("\n\n");
		Cprintf("�˺Ż��������!\n\n");
		
	}


	int choice;
	Manager StuM;
	Analyst StuA;
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

//ȡ����󻯣���С��
void StuSys::SizeGoAway() {
	SetWindowLongPtrA(
		GetConsoleWindow(),
		GWL_STYLE,
		GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
}

//ȡ���ر�  ����ʹ�ã�����ר��
void StuSys::DeleteGoAway(){
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
		SC_CLOSE, MF_DISABLED);
	DrawMenuBar(GetConsoleWindow());
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
