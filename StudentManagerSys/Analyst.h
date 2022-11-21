
#include "Student.h"

// #include "StuSys.h"



class Analyst:public StuSys
{

private:
    int count;
    Student *Head,*End;

public:


    bool readFile();
    bool saveFile();
    void welcome(int delay);
    void menu();

    void SortById();
    void SortBySum();
    void SortByMa();
    void SortByEn();
    void SortByEt();
    void SortByPc();
    void SortByName();

    void PtWelcome(int delay);
    void PrintStu();
    void PrintStuInfo(bool IsRank,bool IsSingle);

    void AtWelcome(int delay);
    void PrintAnalyst();
    void PrintAnalyse();
    void PrintAnalysis();

    void CreatXls();

    void CtWelcome(int delay);
    void PrintCreatHtml();
    void CreatTd(FILE *f,int data);
    void CreatAnalystHtml();
    void CreatHtml(bool IsRank,bool IsSingle,string FileName);

    Analyst(/* args */);
    ~Analyst();
};

Analyst::Analyst(/* args */)
{
    Head =  new Student;
    Head->next = new Student;
    End = Head->next;
    count = 0;
}

void Analyst::welcome(int delay)
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
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          P.���ѧ����Ϣ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          A.ѧ���ɼ�����        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          H.������Ϣ��ҳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��         E.����EXCEL�ļ�        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�˳�����ϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");

    if(readFile())
    {
        printf("������������������������������            �ļ���ʼ���ɹ�            ����������������������������\n");
    }
    else{
        printf("�������������������������������������������ļ���ʼ��ʧ�ܣ�����������������������������������������\n");
    }
    // cout<<Head->next->name<<" "<<End->name;
}

void Analyst::menu()
{
    
    int choice;
    
    while (true)
    {

        welcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 65 || choice == 97 ||
                choice == 72 || choice == 104 ||
                choice == 80 || choice == 112 ||
                choice == 69 || choice == 101
                )
            {
                break;
            }
        }

        if(choice == 96 || choice == 48)
        {
            break;
        }
     
        switch (choice)
        {
        case 80:
        case 112:
            PrintStu();
            break;
        case 65:
        case 97:
            PrintAnalyst();
            break;
        case 72:
        case 104:
            PrintCreatHtml();
            break;
        case 69:
        case 101:
            CreatXls();
            break;
        default:
            break;
        }
    }
}

bool Analyst::readFile()
{
    FILE *fpr = fopen("studentInfo.txt", "r");
	Student st;
	// Student *s;
    count = 0;
	Student *t = Head;

	if (fpr == NULL)
	{
		return false;
	}
	else
	{

		while (fscanf(fpr, "%d %s %s %d %d %d %d %d %d", &st.id, st.name, st.sex, &st.ma, &st.en, &st.et, &st.pc, &st.avr, &st.sum) != EOF)
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
	fclose(fpr); 
	return true;
}

bool Analyst::saveFile()
{

    //��ʼ���ļ�ָ��
    FILE *fpw = fopen("studentInfo.txt", "w");
    count = 0;
	if (!fpw)
		return false;
	Student *p = Head->next;

	while (p)
	{
		fprintf(fpw, "%d %s %s %d %d %d %d %d %d\n", p->id, p->name, p->sex, p->ma, p->en, p->et, p->pc, p->avr, p->sum);
        count++;
		p = p->next;
	}

	fclose(fpw); //�ر��ļ�ָ��
	return true;
}


void Analyst::SortById()
{
    Student *pre, *cur, *next, *end; // preǰһ�� cur��ǰ�� next��һ�� end����ѭ������(�Ż�ð��)
	end = NULL;
	while (Head->next != end)
	{
		//��ʼ������ָ�� ; �ж��Ƿ񵽴����λ�� ; ����ָ�뼯�����
		for (pre = Head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (/* !(next->age) && */ cur->id > next->id) //��С����
			{
				pre->next = next;
				cur->next = next->next;
				next->next = cur;

				//��ʱnext��ǰһ�cur���һ��  ����next cur
				Student *temp = cur;
				cur = next;
				next = temp;
			}
		}
		//һ��ѭ������ ���һ���Ѿ��ź� end��ǰһ�� (ð��ԭ��)
		end = cur;
	}
}

void Analyst::SortBySum()
{
    Student *p, *pre, *q;
	p = Head->next->next;	  //�ȱ�����L�ĵڶ���Ԫ�أ���Ϊ��һ��Ҫ��L���ֻ��һ��Ԫ�ص������
	Head->next->next = NULL; // ��L���ֻ��һ��Ԫ�ص������
	// ��L�ĵڶ���Ԫ�ؿ�ʼ��������Lֱ����β
	while (p != NULL)
	{
		q = p->next;
		pre = Head;										   // ����pre������L��
		while (pre->next != NULL && pre->next->sum > p->sum) // ����pre��ָ��������L��ֱ���ҵ���p��Ľڵ�
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

void Analyst::SortByMa()
{
    Student *pos, *p, *pre, *max, *premax; // posʼ��ָ��δ���������һ���ڵ�
	pos = Head->next;
	Head->next = NULL; //��ͷ�ڵ�����ÿ�

	while (pos != NULL) //���ѭ��
	{
		premax = pre = NULL;
		p = max = pos; // pָ���δ����������ɨ��

		while (p != NULL)
		{
			if (p->ma < max->ma) //�ҵ��ϴ�ֵ
			{
				max = p;
				premax = pre;
			}
			pre = p; // pָ������ƶ�
			p = p->next;
		}
		if (premax == NULL)
		{ 
            //��ʾ���ֵ����δ�����еĵ�һ���ڵ�
			pos = max->next;
		}
		else
		{ 
            //��δ���������Ƴ����ڵ�
			premax->next = max->next;
		}
		//��δ���������ڵ�ͷ�巨����Lָ�������������
		max->next = Head->next;
		Head->next = max;
	}
}

void Analyst::SortByEn()
{
    Student *pre, *cur, *next, *end; 
	end = NULL;
	while (Head->next != end)
	{
		for (pre = Head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			if (cur->en < next->en)
			{
				pre->next = next;
				cur->next = next->next;
				next->next = cur;

				Student *temp = cur;
				cur = next;
				next = temp;
			}
		}
		end = cur;
	}
}

void Analyst::SortByEt()
{
    Student *pos, *p, *pre, *max, *premax; 
	pos = Head->next;
	Head->next = NULL; 

	while (pos != NULL) 
	{
		premax = pre = NULL;
		p = max = pos; 

		while (p != NULL)
		{
			if (p->et < max->et) 
			{
				max = p;
				premax = pre;
			}
			pre = p; 
			p = p->next;
		}
		if (premax == NULL)
		{ 
			pos = max->next;
		}
		else
		{ 
			premax->next = max->next;
		}
		
		max->next = Head->next;
		Head->next = max;
	}
}

void Analyst::SortByPc()
{
    Student *p, *pre, *q;
	p = Head->next->next;	 
	Head->next->next = NULL; 
	while (p != NULL)
	{
		q = p->next;
		pre = Head;										   
		while (pre->next != NULL && pre->next->pc > p->pc) 
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

void Analyst::SortByName()
{
    Student *p, *pre, *q;
	p = Head->next->next;	 
	Head->next->next = NULL; 
	while (p != NULL)
	{
		q = p->next;
		pre = Head;										   
		while (pre->next != NULL && strcmp(pre->next->name,p->name) == -1 ) 
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

void Analyst::PtWelcome(int delay)
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
	printf("����������������������������  ��            1.ѧ������          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            2.�ܷ�����          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            3.��ѧ����          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            4.Ӣ������          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            5.��������          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            6.���������        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            7.��������          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��           0.�ص�����ϵͳ       ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");

}

void Analyst::PrintStuInfo(bool IsRank,bool IsSingle)
{
    system("cls");
    Student S,*s;
    s = Head->next;
    int rank = 1;
    if(IsRank)
    {
        cout<<"\n    ";
        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������");
        cout<<"\n    ";
        if(IsSingle)
        {
            printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|��������\t|");
        }else{
            printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|����\t|");
        }
        
        cout<<"\n    ";
        printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������");
        while(s)
        {
            Sleep(20);
            S = *s;
            cout<<"\n    ";
            printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|", S.id, S.name, S.sex, S.ma, S.en, S.et, S.pc, S.avr, S.sum,rank++);
            cout<<"\n    ";
            printf(" ��������������������������������������������������������������������������������������������������������������������������������������������������������������������");
            s = s->next;
        }
    }else{

        cout<<"\n           ";
        printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������");
        cout<<"\n           ";
        printf("|ѧ��\t|����\t|�Ա�\t|��ѧ\t|Ӣ��\t|����\t|�����\t|ƽ����\t|�ܷ�\t|");
        cout<<"\n           ";
        printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������");

        while(s)
        {
            Sleep(20);
            S = *s;
            cout<<"\n           ";
            printf("|%d\t|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|", S.id, S.name, S.sex, S.ma, S.en, S.et, S.pc, S.avr, S.sum);
            cout<<"\n           ";
            printf(" ������������������������������������������������������������������������������������������������������������������������������������������������������");
            s = s->next;
        }
    }
    
    printf("                                                       ��������˳�");
    getch();
}

void Analyst::PrintStu()
{
    int choice;
    string str;

    while(true)
    {

        PtWelcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 97 || choice == 49 ||
                choice == 98 || choice == 50 ||
                choice == 99 || choice == 51 ||
                choice == 100 || choice == 52 ||
                choice == 101 || choice == 53 ||
                choice == 102 || choice == 54 ||
                choice == 103 || choice == 55
            )
            {
                break;
            }
        }

        if(choice == 96 || choice == 48)
        {
            break;
        }

        switch (choice)
        {
        case 97:
        case 49:
            SortById();
            PrintStuInfo(false,false);
            break;
        case 98:
        case 50:
            SortBySum();
            PrintStuInfo(true,false);
            break;
        case 99:
        case 51:
            SortByMa();
            PrintStuInfo(true,true);
            break;
        case 100:
        case 52:
            SortByEn();
            PrintStuInfo(true,true);
            break;
        case 101:
        case 53:
            SortByEt();
            PrintStuInfo(true,true);
            break;
        case 102:
        case 54:
            SortByPc();
            PrintStuInfo(true,true);
            break;
        case 103:
        case 55:
            SortByName();
            PrintStuInfo(false,false);
            break;
        default:
            break;
        }

    }
}

void Analyst::AtWelcome(int delay)
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
	printf("����������������������������  ��        1.�鿴���ƾ������      ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��         2.�鿴���ֶ�����       ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��          0.�ص�����ϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");
}

void Analyst::PrintAnalyse()
{
    Student *head;
    int max,min,avr,sum = 0,passRens = 0;
    int passRate;

    SortByMa();
    head = Head->next;
    max = head->ma;
    while(head)
    {
        min = head->ma;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                ";
    printf("|��ѧ \t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                ";
    printf(" ������������������������������������������������������������������������������������������������������������");Sleep(20);


    SortByEn();
    head = Head->next;
    max = head->en;
    sum = 0;
    passRens = 0;
    while(head)
    {
        min = head->en;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                ";
    printf("|Ӣ�� \t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                ";
    printf(" ������������������������������������������������������������������������������������������������������������");Sleep(20);

    SortByEt();
    head = Head->next;
    max = head->et;
    sum = 0;
    passRens = 0;
    while(head)
    {
        min = head->et;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                ";
    printf("|���� \t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                ";
    printf(" ������������������������������������������������������������������������������������������������������������");Sleep(20);

    SortByPc();
    head = Head->next;
    max = head->pc;
    sum = 0;
    passRens = 0;
    while(head)
    {
        min = head->pc;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                ";
    printf("|�����\t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                ";
    printf(" ������������������������������������������������������������������������������������������������������������");Sleep(20);
    
    SortBySum();
    head = Head->next;
    max = head->sum;
    sum = 0;
    passRens = 0;
    while(head)
    {
        min = head->sum;
        sum += min;
        if(min>=240) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    cout<<"\n                ";
    printf("|�ܷ� \t|%d\t|%d\t|%d\t|%d/%d\t\t|%d %%\t|",max,min,avr,passRens,count,passRate);Sleep(20);
    cout<<"\n                ";
    printf(" ������������������������������������������������������������������������������������������������������������");Sleep(20);
}

void Analyst::PrintAnalysis()
{
    if(count == 0)
    {
        printf("                                     ��ǰ��ѧ����Ϣ,������ѧ���� ��������˳�");
        getch();
        return;
    }
    
    cout<<"\n                ";
    printf(" ������������������������������������������������������������������������������������������������������������");Sleep(20);
    cout<<"\n                ";
    printf("|������\t|��߷�\t|��ͷ�\t|ƽ����\t|������/������\t|������\t|");Sleep(20);
    cout<<"\n                ";
    printf(" ������������������������������������������������������������������������������������������������������������");Sleep(20);


    PrintAnalyse();


    printf("                                                       ��������˳�");
    getch();
}

void Analyst::PrintAnalyst()
{
    int choice;

    while(true)
    {
        AtWelcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 97 || choice == 49 ||
                choice == 98 || choice == 50 
            )
            {
                break;
            }
        }
        if(choice ==96 ||choice ==48) break;
        
        switch (choice)
        {
        case 97:
        case 49:
            PrintAnalysis();

            break;
        case 98:
        case 50:
            
            break;
        default:
            break;
        }

    }

}


void Analyst::CreatXls()
{
    ofstream oFile;
	oFile.open("Xls/Students.csv",ios::out|ios::trunc);
	oFile<<"ѧ��"<<","<<"����"<<","<<"�Ա�"<<","<<"��ѧ"<<","<<"Ӣ��"<<","<<"����"<<","<<"�����"<<","<<"ƽ����"<<","<<"�ܷ�"<<endl;
    SortBySum();
    Student *S = Head->next;
    while(S)
    {
        oFile<<S->id<<","<<S->name<<","<<S->sex<<","<<S->ma<<","<<S->en<<","<<S->et<<","<<S->pc<<","<<S->avr<<","<<S->sum<<endl;
        S = S->next;
    }
	oFile.close();
    system("start Xls/Students.csv");
}

void Analyst::CtWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��     �� Ϣ �� ҳ �� �� ϵ ͳ    ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��            1.����ѧ��          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            2.��������          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��            3.�����ܷ�          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            4.������ѧ          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            5.����Ӣ��          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��            6.��������          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��           7.���ݼ����         ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          8.�����������        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��          0.���ط���ϵͳ        ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");
}

void Analyst::CreatTd(FILE *f,int data)
{
    char str[50];
    fprintf(f,"<td class=\"text-center\">");
    itoa(data,str,10);fprintf(f,str);
    fprintf(f,"</td>\n");
}

void Analyst::CreatHtml(bool IsRank,bool IsSingle,string FileName)
{
    FILE *f;
    int i = 1;
    f=fopen(("HTML/"+FileName).c_str(),"w+");

    fprintf(f,"<html lang=\"en\">\n");
    fprintf(f,"<head>\n");
    fprintf(f," <meta charset=\"gb2312\" />\n");
    fprintf(f," <title>ѧ����Ϣ����</title>\n");
    fprintf(f,"	<meta name=\"viewport\" content=\"initial-scale=1.0; maximum-scale=1.0; width=device-width;\">\n");
    fprintf(f," <link rel=\"stylesheet\" href=\"table.css\">\n");
    fprintf(f,"</head>\n");
    fprintf(f,"<body>\n");

    fprintf(f,"<div class=\"table-title\">\n");


    fprintf(f," <h3>ѧ���ɼ���Ϣ</h3>\n");


    fprintf(f,"</div>\n");

    fprintf(f,"<table class=\"table-fill\">\n");
    fprintf(f,"<thead>\n");
    fprintf(f," <tr>\n");
    fprintf(f,"   <th class=\"text-center\">ѧ��</th>\n");
    fprintf(f,"   <th class=\"text-center\">����</th>\n");
    fprintf(f,"   <th class=\"text-center\">�Ա�</th>\n");
    fprintf(f,"   <th class=\"text-center\">��ѧ</th>\n");
    fprintf(f,"   <th class=\"text-center\">Ӣ��</th>\n");
    fprintf(f,"   <th class=\"text-center\">����</th>\n");
    fprintf(f,"   <th class=\"text-center\">�����</th>\n");
    fprintf(f,"   <th class=\"text-center\">ƽ����</th>\n");
    fprintf(f,"   <th class=\"text-center\">�ܷ�</th>\n");

    if(IsRank){
        if(IsSingle)
            fprintf(f,"   <th class=\"text-center\">��������</th>\n");
        else
            fprintf(f,"   <th class=\"text-center\">����</th>\n");
    }
        
    fprintf(f,"  </tr>\n");
    fprintf(f,"</thead>\n");
    fprintf(f,"<tbody class=\"table-hover\">\n");
    
    for(Student *S = Head->next;S;S = S->next)
    {
        char str[50];
        fprintf(f," <tr>\n");

        CreatTd(f,S->id);

        fprintf(f,"<td class=\"text-center\">");
        fprintf(f,S->name);
        fprintf(f,"</td>\n");

        fprintf(f,"<td class=\"text-center\">");
        fprintf(f,S->sex);
        fprintf(f,"</td>\n");

        CreatTd(f,S->ma);

        CreatTd(f,S->en);

        CreatTd(f,S->et);

        CreatTd(f,S->pc);

        CreatTd(f,S->avr);

        CreatTd(f,S->sum);

        if(IsRank)
        {
            CreatTd(f,i++);
        }
        
        fprintf(f,"  </tr>\n");
    }
    
    fprintf(f,"</tbody>\n");
    fprintf(f,"</table>\n");
    fprintf(f,"</body>\n");
    fclose(f);
    
    system(("start HTML/"+FileName).c_str());
}


void Analyst::CreatAnalystHtml()
{
    FILE *f;
    f = fopen("HTML/Analysis.html","w+");

    fprintf(f,"<html lang=\"en\">\n");
    fprintf(f,"<head>\n");
    fprintf(f," <meta charset=\"gb2312\" />\n");
    fprintf(f," <title>ѧ����Ϣ����</title>\n");
    fprintf(f,"	<meta name=\"viewport\" content=\"initial-scale=1.0; maximum-scale=1.0; width=device-width;\">\n");
    fprintf(f," <link rel=\"stylesheet\" href=\"table.css\">\n");
    fprintf(f,"</head>\n");
    fprintf(f,"<body>\n");

    fprintf(f,"<div class=\"table-title\">\n");

    fprintf(f," <h3>ѧ���ɼ�����</h3>\n");

    fprintf(f,"</div>\n");

    fprintf(f,"<table class=\"table-fill\">\n");
    fprintf(f,"<thead>\n");
    fprintf(f," <tr>\n");
    fprintf(f,"   <th class=\"text-center\">������</th>\n");
    fprintf(f,"   <th class=\"text-center\">��߷�</th>\n");
    fprintf(f,"   <th class=\"text-center\">��ͷ�</th>\n");
    fprintf(f,"   <th class=\"text-center\">ƽ����</th>\n");
    fprintf(f,"   <th class=\"text-center\">��������</th>\n");
    fprintf(f,"   <th class=\"text-center\">������</th>\n");
    fprintf(f,"   <th class=\"text-center\">������</th>\n");
    
    fprintf(f,"  </tr>\n");
    fprintf(f,"</thead>\n");

    fprintf(f,"<tbody class=\"table-hover\">\n");

    char str[50];
    Student *head;
    int max,min,avr,sum = 0,passRens = 0,passRate;

    SortByMa();
    head = Head->next;
    max = head->ma;
    while(head)
    {
        min = head->ma;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">��ѧ</td>\n");
        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    SortByEn();
    head = Head->next;
    max = head->en;
    sum = 0,passRens = 0;
    while(head)
    {
        min = head->en;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">Ӣ��</td>\n");

        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    SortByEt();
    head = Head->next;
    max = head->et;
    sum = 0,passRens = 0;
    while(head)
    {
        min = head->et;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">����</td>\n");

        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    SortByPc();
    head = Head->next;
    max = head->pc;
    sum = 0,passRens = 0;
    while(head)
    {
        min = head->pc;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">�����</td>\n");

        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    SortBySum();
    head = Head->next;
    max = head->sum;
    sum = 0,passRens = 0;
    while(head)
    {
        min = head->sum;
        sum += min;
        if(min>=60) passRens++;
        head = head->next;
    }
    avr = sum/count;
    passRate = 100 * passRens / count ;
    fprintf(f," <tr>\n");
        fprintf(f,"<td class=\"text-center\">�ܷ�</td>\n");

        CreatTd(f,max);
        CreatTd(f,min);
        CreatTd(f,avr);
        CreatTd(f,passRens);
        CreatTd(f,count);
        fprintf(f,"<td class=\"text-center\">");
        itoa(passRate,str,10);fprintf(f,str);
        fprintf(f,"%%</td>\n");
    fprintf(f,"  </tr>\n");

    fprintf(f,"</tbody>\n");
    fprintf(f,"</table>\n");
    fprintf(f,"</body>\n");
    fclose(f);
    
    system("start HTML/Analysis.html");

}

void Analyst::PrintCreatHtml()
{

    int choice;

    while(true)
    {
        CtWelcome(20);
        while(true)
        {
            choice = getch();
            if(
                choice == 96 || choice == 48 ||
                choice == 97 || choice == 49 ||
                choice == 98 || choice == 50 ||
                choice == 99 || choice == 51 ||
                choice == 100 || choice == 52 ||
                choice == 101 || choice == 53 ||
                choice == 102 || choice == 54 ||
                choice == 103 || choice == 55 ||
                choice == 104 || choice == 56
            ) break;
        }
        if(choice == 96 || choice == 48) break;

        switch (choice)
        {
        case 97:
        case 49:
            SortById();
            CreatHtml(false,false,"Students-Id.html");
            break;
        case 98:
        case 50:
            SortByName();
            CreatHtml(false,false,"Students-Name.html");
            break;
        case 99:
        case 51:
            SortBySum();
            CreatHtml(true,false,"Students-Total.html");
            break;
        case 100:
        case 52:
            SortByMa();
            CreatHtml(true,true,"Students-Math.html");
            break;
        case 101:
        case 53:
            SortByEn();
            CreatHtml(true,true,"Students-English.html");
            break;

        case 102:
        case 54:
            SortByEt();
            CreatHtml(true,true,"Students-ET.html");
            break;

        case 103:
        case 55:
            SortByPc();
            CreatHtml(true,true,"Students-Computer.html");
            break;
        case 104:
        case 56:
            CreatAnalystHtml();
            break;
        default:
            break;
        }
    }
}

Analyst::~Analyst()
{
}
