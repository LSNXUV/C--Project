#include "Package.h"
#include "Records.h"

#define MaxSize 70

class GoBang
{
    private:

        int BoardSize;

        int ChessBoard[MaxSize][MaxSize];
        int BoardLocationX;
        int BoardLocationY;
        Records records;

    public:

        void InitWindow();
        void welcome(int delay);
        void menu();

        void InitChess();

        void gotoxy(int x, int y);
        void DoublePlay();
        bool Win(int x,int y,int player);
        void DrawBoard();
        void DrawWinPoint(int x,int y);
        void ClearPoint(int x,int y,int player);
        void DrawPoint(int x,int y,int player);

        void ShowCursor(bool visible);
        void SetTextWhite();
        void SetTextRed();
        void SetTextBlue();
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
    BoardLocationX = 10;
    BoardLocationY = 7;
    InitChess();
}

void GoBang::InitWindow()
{
    //关闭右上角最大化和关闭
	SizeGoAway();
    DeleteGoAway();
	//设置管理权限图标
	HWND hwnd = GetConsoleWindow();
    SendMessage(hwnd, WM_SETICON, 0, (LPARAM)
    LoadIcon((HINSTANCE) GetWindowLongPtr(hwnd, GWLP_HINSTANCE),MAKEINTRESOURCE(32518)));
	
	system("mode con cols=96 lines=47");
}

void GoBang::InitChess()
{
    for(int i = 0;i<BoardSize;i++)
    {
        for(int j = 0;j<BoardSize;j++)
        {
            ChessBoard[i][j] = 0;
        }
    }
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
    InitWindow();
    char Title[96];
    sprintf(Title,"% 114s","五子棋终结者");
	SetConsoleTitleA(Title);
    
    int choice;

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
            InitChess();
            DoublePlay();
            break;
        
        default:
            break;
        }

    }
    goodbye();
    return;
}

void GoBang::gotoxy(int x, int y) {					//移动光标
	COORD pos;
    pos.X = x,pos.Y = y;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

bool GoBang::Win(int x,int y,int player)
{
    
    int MinX = max( 0 , x - 4 );
    int MaxX = min( x + 4 , BoardSize - 1 );
    int MinY = max( 0 , y - 4 );
    int MaxY = min( y + 4 , BoardSize - 1 );

    int sum;
    //水平方向
    for(int i = MinX;i <= MaxX-4;i++)
    {
        sum = 0;
        for(int j = i;j<i+5;j++)
        {
            if(ChessBoard[j][y] == player) sum++;
            else  break;
        }
        if(sum == 5) {
            for(int k = 0;k<3;k++){
                for(int j = i;j<i+5;j++)
                {
                    DrawWinPoint(j,y);
                    Sleep(50);
                    DrawPoint(j,y,player);
                }
            }
            for(int j = i;j<i+5;j++)
            {
                DrawWinPoint(j,y);
            }
            return true;
        }
    }
   
    //垂直方向
    for(int i = MinY;i <= MaxY-4;i++)
    {
        sum = 0;
        for(int j = i;j<i+5;j++)
        {
            if(ChessBoard[x][j] == player) sum++;
            else break;
        }
        if(sum == 5) {
            for(int k = 0;k<3;k++){
                for(int j = i;j<i+5;j++)
                {
                    DrawWinPoint(x,j);
                    Sleep(50);
                    DrawPoint(x,j,player);
                }
            }
            for(int j = i;j<i+5;j++)
            {
                DrawWinPoint(x,j);
            }
            return true;
        }
    }
    
    int i,j;

    for(i = x,j = y;i > MinX && j > MinY; i--,j--);
    for(;i <= MaxX-4 && j <= MaxY-4; i++,j++)
    {
        sum = 0;
        for(int p = i,q = j;p < i+5;p++,q++)
        {
            if(ChessBoard[p][q] == player) sum++;
            else break;
        }
        if(sum == 5) {
            for(int k = 0;k<3;k++){
                for(int p = i,q = j;p < i+5;p++,q++)
                {
                    DrawWinPoint(p,q);Sleep(50);DrawPoint(p,q,player);
                }
            }
            for(int p = i,q = j;p < i+5;p++,q++)
            {
                DrawWinPoint(p,q);
            }
            return true;
        }
    }
    
    for(i = x,j = y;i > MinX && j < MaxY; i--,j++);
    for(;i <= MaxX-4 && j >= MinY+4; i++,j--)
    {
        sum = 0;
        for(int p = i,q = j;p < i+5;p++,q--)
        {
            if(ChessBoard[p][q] == player) sum++;
            else break;
        }
        if(sum == 5) {
            for(int k = 0;k<3;k++){
                for(int p = i,q = j;p < i+5;p++,q--)
                {
                    DrawWinPoint(p,q);Sleep(50);DrawPoint(p,q,player);
                }
            }
            for(int p = i,q = j;p < i+5;p++,q--)
            {
                DrawWinPoint(p,q);
            }
            return true;
        }
    }
    
    return false;
}

void GoBang::DrawBoard()
{

    char ChessRow[100];
    gotoxy(0,BoardLocationY);
    for(int i = 0;i<BoardSize;i++)
    {
        if(i!=0) printf("\n          |────|────|────|────|────|────|────|────|────|────|────|────|────|────|─── |\n          ");
        else printf("           ─────────────────────────────────────────────────────────────────────────\n          ");
        // printf("\n          ─────────────────────────────────────────────────────────────────────────\n          ");
        Sleep(10);
        for(int j = 0;j<BoardSize;j++)
        {
            printf("|    ");Sleep(5);
        
        }
        printf("|");
        Sleep(10);
    }
    printf("\n           ─────────────────────────────────────────────────────────────────────────\n");

}

void GoBang::DrawWinPoint(int x,int y)
{
    gotoxy(BoardLocationX+2+5*y,BoardLocationY+1+x*2);
    Sleep(50);
    printf("●");
}

void GoBang::DrawPoint(int x,int y,int player)
{
    gotoxy(BoardLocationX+2+5*y,BoardLocationY+1+x*2);
    if(player == 1) {SetTextGreen();printf("●");SetTextWhite();}
    else {SetTextBlue();printf("●");SetTextWhite();}
}

void GoBang::ClearPoint(int x,int y,int player)
{
    gotoxy(BoardLocationX+2+5*y,BoardLocationY+1+x*2);
    printf("  ");
}


void GoBang::DoublePlay()
{

    printf("\n\n");
    SetTextGreen();
    Cprintf("欢迎来到五子棋终结者，按任意键开始游戏");
    SetTextWhite();
    getch();

    system("cls");
    
    // system("color F0");
    gotoxy(0,2);
    SetTextGreen();Cprintf("五子棋终结者");Sleep(20);SetTextWhite();
    gotoxy(0,4);
    
    Cprintf("w a s d (绿方) / ↑ ← ↓ → (蓝方)    Enter 确认落子    Backspace 悔棋    Esc 退出游戏");Sleep(20);
    
    
    int choice;
    int step = 1;
    Records records;
    Point point;
    int x = 7,y = 7,player = 1;
    ChessBoard[x][y] = player;

    DrawBoard();
    DrawPoint(x,y,player);
    while(true)
    {
        
        player = 2-player%2;
        ChessBoard[x][y] = player;
        while(true)
        {
            choice = getch();
            if( choice == 87 || choice == 119 ||
                choice == 65 || choice == 97 ||
                choice == 83 || choice == 115 ||
                choice == 68 || choice == 100 ||
                choice == 72 || choice == 80 ||
                choice == 75 || choice == 77 ||
                choice == 13 || choice == 8 ||
                choice == 27
            ) break;
        }
        if(choice == 27) break;

        switch (choice)
        {
        case 87:
        case 119:
            if(player != 1) break;
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 72:
            if(player != 2) break;
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 65:
        case 97:
            if(player != 1) break;
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            y = (y+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 75:
            if(player != 2) break;
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            y = (y+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 83:
        case 115:
            if(player != 1) break;
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 80:
            if(player != 2) break;
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 68:
        case 100:
            if(player != 1) break;
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            y = (y+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 77:
            if(player != 2) break;
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            y = (y+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;

        case 8:
            if(records.Count == 0) break;
        
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            point = records.Withdraw();
            x = point.x,y = point.y,player = point.player;
    
            DrawPoint(x,y,player);
            break;

        case 13:
            if(Win(x,y,2-player%2)){
                gotoxy(0,40);

                if(player == 1){ SetTextGreen();Cprintf("玩家一(绿方)获胜！");SetTextWhite();}
                else {SetTextBlue(); Cprintf("玩家二(蓝方)获胜！");SetTextWhite();}
                printf("\n\n");Cprintf("按Esc退出");
                while(getch()!=27);
                return;
            }
            
            records.AddRecord(x,y,player);

            ChessBoard[x][y] = player++;
            player = 2-player%2;
            step = 0;

            while(step<BoardSize)
            {
                if(!ChessBoard[(x+BoardSize-step)%BoardSize][y]) {x=(x+BoardSize-step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[x][(y+BoardSize-step)%BoardSize]) {y=(y+BoardSize-step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[(x+BoardSize+step)%BoardSize][y]) {x=(x+BoardSize+step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[x][(y+BoardSize+step)%BoardSize]) {y=(y+BoardSize+step)%BoardSize; DrawPoint(x,y,player); break;}
                step++;
            }
            if(step == BoardSize) {
                gotoxy(0,40);Cprintf("你故意和棋的样子真狼狈(≧?≦)?");
                printf("\n\n");SetTextGreen();Cprintf("按Esc退出");SetTextWhite();
                while(getch()!=27);
                return;
            }
            
            break;
        
        default:
            break;
        }

    }

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

void GoBang::SetTextBlue()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE | FOREGROUND_INTENSITY);
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

//取消关闭  
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
    // return;
}

GoBang::~GoBang()
{
}
