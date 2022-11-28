#include "Package.h"

#define MaxSize 70

class GoBang
{
private:

    int BoardSize;

    int ChessBoard[MaxSize][MaxSize];

public:

    void welcome(int delay);
    void menu();

    void DoublePlay();

    void DrawBoard();

    void ShowCursor(bool visible);
    void SetTextWhite();
    void SetTextRed();
    void SetTextGreen();

    void Mprintf(string str);
    void Cprintf(string str);

    void DeleteGoAway();
    void SizeGoAway();

    void goodbye();

    GoBang(/* args */);
    ~GoBang();
};

GoBang::GoBang(/* args */)
{
    BoardSize = 15;
}

void GoBang::welcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������  ��        �� �� �� �� �� ��       ��  ����������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ����������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
	printf("����������������������������          ��������        ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��            P.˫����Ϸ          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
	printf("����������������������������  ��            0.�˳���Ϸ          ��  ���������������������������\n");Sleep(delay);
    printf("����������������������������  ��                                ��  ���������������������������\n");Sleep(delay);
    printf("������������������������������������������������������������������������������������������������\n");
}

void GoBang::menu()
{
    char Title[96];
    SizeGoAway();
    DeleteGoAway();
    sprintf(Title,"% 115s","�������ս���");
	SetConsoleTitleA(Title);
    system("mode con cols=96");


    int choice;
    // welcome(20);

    while(true)
    {
        welcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 80 || choice == 112
            ) break;
        }
        if(choice == 96 || choice == 48) break;

        switch (choice)
        {
        case 80:
        case 112:
            DoublePlay();
            break;
        
        default:
            break;
        }

    }

    goodbye();
    
}

void GoBang::DrawBoard()
{
    char ChessRow[100];
    printf("\n");
    Cprintf("������������������������������������������������������������������������������������������������������������������������������������������������������");
    Cprintf("|?����?��?��");

}

void GoBang::DoublePlay()
{

    DrawBoard();
    getch();
}


void GoBang::ShowCursor(bool visible) { 

    CONSOLE_CURSOR_INFO cursor_info = {20, visible};
    //CONSOLE_CURSOR_INFO�ṹ���������̨�����Ϣ����Ա�ֱ��ʾ���ٷֱȺ�Ⱥ��Ƿ�ɼ�
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
 	//SetConsoleCursorInfo�趨����̨���ڵĹ���С���Ƿ�ɼ�
}

void GoBang::SetTextRed()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void GoBang::SetTextGreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void GoBang::SetTextWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void GoBang::Mprintf(string str)
{
	cout<<setw(48)<<str;
}
void GoBang::Cprintf(string str)
{
	cout<<setw(48+str.length()/2)<<str;
}


//ȡ����󻯣���С��
void GoBang::SizeGoAway() {
	SetWindowLongPtrA(
		GetConsoleWindow(),
		GWL_STYLE,
		GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
}

//ȡ���ر�  ����ʹ�ã�����ר��
void GoBang::DeleteGoAway(){
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
		SC_CLOSE, MF_DISABLED);
	DrawMenuBar(GetConsoleWindow());
}

void GoBang::goodbye()
{
	SetTextGreen();
	printf("\n					   ��ӭ�´�ʹ��~\n");
	SetTextWhite();

    Sleep(3000);
}

GoBang::~GoBang()
{
}
