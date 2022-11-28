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

    void InitChess();

    void gotoxy(int x, int y);
    void DoublePlay();
    bool Win(int x,int y,int player);
    void DrawBoard();
    void DrawPoint(int x,int y,int player);
    void Preview(int x,int y,int player);

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
    InitChess();
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
            InitChess();
            DoublePlay();
            break;
        
        default:
            break;
        }

    }
    goodbye();
}

void GoBang::gotoxy(int x, int y) {					//�ƶ����
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
    //ˮƽ����
    for(int i = MinX;i <= MaxX-4;i++)
    {
        sum = 0;
        for(int j = i;j<i+5;j++)
        {
            if(ChessBoard[j][y] == player) sum++;
            else  break;
        }
        if(sum == 5) {
            
            return true;
        }
    }
   
    //��ֱ����
    for(int i = MinY;i <= MaxY-4;i++)
    {
        sum = 0;
        for(int j = i;j<i+5;j++)
        {
            if(ChessBoard[x][j] == player) sum++;
            else break;
        }
        if(sum == 5) {
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
            return true;
        }
    }
    
    return false;
}

void GoBang::DrawBoard()
{
    system("cls");
    char ChessRow[100];
    for(int i = 0;i<BoardSize;i++)
    {
        if(i!=0) printf("\n          |��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|������ |\n          ");
        else printf("\n           ��������������������������������������������������������������������������������������������������������������������������������������������������\n          ");
        // printf("\n          ������������������������������������������������������������������������������������������������������������������������������������������������������\n          ");
        for(int j = 0;j<BoardSize;j++)
        {
            printf("| ");
            if(ChessBoard[i][j] == 0)
            {
                printf("  ");
            }
            else if(ChessBoard[i][j] == 1)
            {
                SetTextGreen();
                printf("��");
                SetTextWhite();
            }
            else
            {
                SetTextBlue();
                printf("��");
                SetTextWhite();
            }
            printf(" ");
        }
        printf("|");
    }
    printf("\n           ��������������������������������������������������������������������������������������������������������������������������������������������������\n");

}

void GoBang::DrawPoint(int x,int y,int player)
{
    gotoxy(12+5*y,2+x*2);
    if(player == 1) {SetTextGreen();printf("��");SetTextWhite();}
    else {SetTextBlue();printf("��");SetTextWhite();}
}

void GoBang::DoublePlay()
{

    printf("\n\n");
    Cprintf("��ӭ�����������ս��ߣ����������ʼ��Ϸ");
    getch();
    system("cls");
    printf("\n\n\n\n");
    int choice;
    int step = 1;
    int preX = 7,preY = 7;
    int x = 7,y = 7,player = 1;
    ChessBoard[x][y] = player;
    DrawBoard();
    while(true)
    {
        
        player = 2-player%2;
        ChessBoard[x][y] = player;
        // DrawBoard();

        while(true)
        {
            choice = getch();
            if( choice == 87 || choice == 119 ||
                choice == 65 || choice == 97 ||
                choice == 83 || choice == 115 ||
                choice == 68 || choice == 100 ||
                choice == 13 || choice == 8 ||
                choice == 27
            ) break;
        }
        if(choice == 27) break;

        switch (choice)
        {
        case 87:
        case 119:
            preX = x;
            ChessBoard[x][y] = 0;
            gotoxy(12+5*y,2+x*2);
            printf("  ");
            x = (x+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 65:
        case 97:
            preY = y;
            ChessBoard[x][y] = 0;
            gotoxy(12+5*y,2+x*2);
            printf("  ");
            y = (y+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 83:
        case 115:
            preX = x;
            ChessBoard[x][y] = 0;
            gotoxy(12+5*y,2+x*2);
            printf("  ");
            x = (x+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 68:
        case 100:
            preY = y;
            ChessBoard[x][y] = 0;
            gotoxy(12+5*y,2+x*2);
            printf("  ");
            y = (y+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 13:

            if(Win(x,y,2-player%2)){
                gotoxy(30,37);
                if(player == 1) Cprintf("���һ(�̷�)��ʤ��");
                else Cprintf("��Ҷ�(����)��ʤ��");
                Sleep(5000);
                return;
            }
            ChessBoard[x][y] = player++;
            player = 2-player%2;
            preX = x,preY = y;
            step = 0;
            while(true)
            {
                if(!ChessBoard[(x+BoardSize-step)%BoardSize][y]) {x=(x+BoardSize-step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[(x+BoardSize+step)%BoardSize][y]) {x=(x+BoardSize+step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[x][(y+BoardSize-step)%BoardSize]) {y=(y+BoardSize-step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[x][(y+BoardSize+step)%BoardSize]) {y=(y+BoardSize+step)%BoardSize; DrawPoint(x,y,player); break;}
                step++;
            }
            
            break;
        case 8:

            ChessBoard[x][y] = 0;
            ChessBoard[preX][preY] = 0;
            player++;
            x = preX,y = preY;
            break;

        default:
            break;
        }

    }
    // DrawBoard();

    // getch();
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
    // return;
}

GoBang::~GoBang()
{
}
