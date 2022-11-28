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
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆        五 子 棋 终 结 者       ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓  ☆                                ☆  〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓★★★★★          ★★★★★★★        ★★★★★〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            P.双人游戏          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
	printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆            0.退出游戏          ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓★  ☆                                ☆  ★〓〓〓〓〓〓〓〓〓〓〓〓〓\n");Sleep(delay);
    printf("〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");
}

void GoBang::menu()
{
    char Title[96];
    SizeGoAway();
    DeleteGoAway();
    sprintf(Title,"% 115s","五子棋终结者");
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
    Cprintf("───────────────────────────────────────────────────────────────────────────");
    Cprintf("|?｜｜?︱?︳");

}

void GoBang::DoublePlay()
{

    DrawBoard();
    getch();
}


void GoBang::ShowCursor(bool visible) { 

    CONSOLE_CURSOR_INFO cursor_info = {20, visible};
    //CONSOLE_CURSOR_INFO结构体包含控制台光标信息，成员分别表示光标百分比厚度和是否可见
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
 	//SetConsoleCursorInfo设定控制台窗口的光标大小和是否可见
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


//取消最大化，最小化
void GoBang::SizeGoAway() {
	SetWindowLongPtrA(
		GetConsoleWindow(),
		GWL_STYLE,
		GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
}

//取消关闭  谨慎使用，坑人专用
void GoBang::DeleteGoAway(){
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
		SC_CLOSE, MF_DISABLED);
	DrawMenuBar(GetConsoleWindow());
}

void GoBang::goodbye()
{
	SetTextGreen();
	printf("\n					   欢迎下次使用~\n");
	SetTextWhite();

    Sleep(3000);
}

GoBang::~GoBang()
{
}
