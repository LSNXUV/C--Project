
#include "Records.h"


class GoBang
{
    protected:

        int BoardSize;

        int ChessBoard[MaxSize][MaxSize];
        int BoardLocationX;
        int BoardLocationY;

        Records records;

    public:

        void InitWindow();
        void welcome(int delay);
        void menu();
        
        bool Regex(string str);
        void InitChess();
        void EmptyRemind();
        void gotoxy(int x, int y);
        
        void DrawBoard();
        void DrawWinPoint(int x,int y);
        void ClearPoint(int x,int y,int player);
        void DrawPoint(int x,int y,int player);
        void DrawActPoint(int x,int y,int player);
        void DrawActStep(int x,int y,int step);
        //˫�˶�ս
        bool Win(int x,int y,int player);
        void DoublePlay();

        //�鿴��ʷ���
        void History(int delay);
        void Review(int id,int delay);
        void PrintHistory(int delay);
        void RcWelcome(int delay);
        void RcMenu();

        
        void ShowCursor(bool visible);
        void SetTextWhite();
        void SetTextRed();
        void SetTextBlue();
        void SetTextGreen();

        void Mprintf(string str);
        void Cprintf(string str);
        void Slowprintf(string str);

        void DeleteGoAway();
        void SizeGoAway();

        void goodbye();

        GoBang(/* args */);
        ~GoBang();
};


GoBang::GoBang(/* args */)
{
    BoardSize = 15;
    BoardLocationX = 18;
    BoardLocationY = 7;
    // record = *(new Record);
    records = *(new Records);
    InitChess();
}

void GoBang::InitWindow()
{
    //�ر����Ͻ���󻯺͹ر�
	SizeGoAway();
    DeleteGoAway();
	
	system("mode con cols=112 lines=47");
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

void GoBang::EmptyRemind()
{
    cout<<"\n";
    SetTextGreen();
    for(int i = 3;i>=1;i--)
    {
        printf("                                           ��ǰ�޶Ծּ�¼  %d ����Զ��˳�",i);
        Sleep(1000);
        cout<<"\r";
    }
    SetTextWhite();
}

bool GoBang::Regex(string str)
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

void GoBang::welcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("����������������������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("����������������������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  ��������������������������������\n");Sleep(delay);
	printf("��������������������������������  ��            �� �� �� �� �� ��           ��  ��������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  ��������������������������������\n");Sleep(delay);
	printf("��������������������������������              ��������            �������������������������������\n");Sleep(delay);
	printf("��������������������������������              ��������            �������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  �������������������������������\n");Sleep(delay);
	printf("��������������������������������  ��                P.˫����Ϸ              ��  �������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  �������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��              H.�鿴��ʷ�Ծ�            ��  �������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  �������������������������������\n");Sleep(delay);
	printf("��������������������������������  ��                0.�˳���Ϸ              ��  �������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  �������������������������������\n");Sleep(delay);
    printf("����������������������������������������������������������������������������������������������������������������\n");
}

void GoBang::RcWelcome(int delay)
{
    system("cls");
    ShowCursor(false);
    printf("����������������������������������������������������������������������������������������������������������������\n");Sleep(delay);
	printf("����������������������������������������������������������������������������������������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  ��������������������������������\n");Sleep(delay);
	printf("��������������������������������  ��            �� �� �� ʷ �� ��           ��  ��������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  ��������������������������������\n");Sleep(delay);
	printf("��������������������������������              ��������            �������������������������������\n");Sleep(delay);
	printf("��������������������������������              ��������            �������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  �������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��              H.�鿴��ʷ�Ծ�            ��  �������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  �������������������������������\n");Sleep(delay);
	printf("��������������������������������  ��               0.�ص�������             ��  �������������������������������\n");Sleep(delay);
    printf("��������������������������������  ��                                        ��  �������������������������������\n");Sleep(delay);
    printf("����������������������������������������������������������������������������������������������������������������\n");
}

void GoBang::RcMenu()
{
    int choice;

    while(true)
    {
        RcWelcome(20);
        if(records.Count==0){
            EmptyRemind();
            return;
        }
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 72 || choice == 104
            ) break;
        }
        if(choice == 96 || choice == 48) break;

        PrintHistory(20);
    }
}

void GoBang::menu()
{
    InitWindow();
    char Title[200];
    sprintf(Title,"% 134s","�������ս���");
	SetConsoleTitleA(Title);
    int choice;


    while(true)
    {
        welcome(20);
        while(true)
        {
            choice = getch();
            if( choice == 96 || choice == 48 ||
                choice == 80 || choice == 112 ||
                choice == 72 || choice == 104
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
        case 72:
        case 104:
            RcMenu();
        default:
            break;
        }

    }
    goodbye();
    return;
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

    gotoxy(0,BoardLocationY);
    
    for(int i = 0;i<BoardSize;i++)
    {
        if(i==0) printf("                   ��������������������������������������������������������������������������������������������������������������������������������������������������\n                  ");
        else printf("\n                  |��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|��������|������ |\n                  ");
        Sleep(10);
        for(int j = 0;j<BoardSize;j++)
        {
            printf("|    ");Sleep(5);
        
        }
        printf("|");
        Sleep(10);
    }
    printf("\n                   ��������������������������������������������������������������������������������������������������������������������������������������������������\n");

}

void GoBang::DrawWinPoint(int x,int y)
{
    gotoxy(BoardLocationX+2+5*y,BoardLocationY+1+x*2);
    Sleep(50);
    printf("��");
}

void GoBang::DrawPoint(int x,int y,int player)
{
    gotoxy(BoardLocationX+2+5*y,BoardLocationY+1+x*2);
    if(player == 1) {SetTextGreen();printf("��");SetTextWhite();}
    else if(player == 2) {SetTextBlue();printf("��");SetTextWhite();}
    else printf("��");
}

//��ǰִ��
void GoBang::DrawActPoint(int x,int y,int player)
{
    gotoxy(x,y);
    if(player == 1) {SetTextGreen();printf("��");SetTextWhite();}
    else if(player == 2) {SetTextBlue();printf("��");SetTextWhite();}
    else printf("��");
}

void GoBang::DrawActStep(int x,int y,int step)
{
    gotoxy(x,y);
    printf("%d  ",step);
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
    Slowprintf("��ӭ�����������ս��ߣ����������ʼ��Ϸ");
    SetTextWhite();
    getch();

    system("cls");
    
    // system("color F0");
    gotoxy(0,2);
    SetTextGreen();Cprintf("�������ս���");Sleep(20);SetTextWhite();
    gotoxy(0,4);
    
    Cprintf("w a s d (�̷�) / �� �� �� �� (����)    Enter ȷ������    Backspace ����    Esc �˳���Ϸ");Sleep(20);
    
    int choice,ActStep = 0;
    int step = 1;
    Record *record;
    record = new Record;
    Point point;
    int x = 7,y = 7,player = 1;
    ChessBoard[x][y] = player;

    DrawBoard();
    DrawPoint(x,y,player);

    
    DrawActPoint(102,16,player);Sleep(20);DrawActStep(102,20,ActStep);Sleep(20);
    gotoxy(99,14);
    printf("��ǰִ��");Sleep(20);
    gotoxy(99,18);
    printf("��ǰ����");Sleep(20);
    
    while(true)
    {
        
        player = 2-player%2;
        ChessBoard[x][y] = player;
        while(true)
        {
            choice = getch();
            if( choice == 87 || choice == 119 ||    /* W */
                choice == 81 || choice == 113 ||    /* Q */
                choice == 69 || choice == 101 ||    /* E */
                choice == 65 || choice == 97 ||     /* A */
                choice == 90 || choice == 122 ||    /* Z */
                choice == 83 || choice == 115 ||    /* D */
                choice == 88 || choice == 120 ||    /* X */
                choice == 68 || choice == 100 ||    /* S */
                choice == 72 || choice == 80 ||      
                choice == 49 || choice == 51 ||     /* 1 3 */
                choice == 75 || choice == 77 ||
                choice == 55 || choice == 57 ||     /* 7 9 */
                choice == 13 || choice == 8 ||
                choice == 27
            ) break;
        }
        if(choice == 27) break;

        switch (choice)
        {
        case 87:
        case 119:
        case 72:
            /* ���� */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 81:
        case 113:
        case 55:
            /* ���Ϸ��ƶ� */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize-1)%BoardSize;y = (y+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize-1)%BoardSize;y = (y+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 65:
        case 97:
        case 75:
            /* ���� */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            y = (y+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 69:
        case 101:
        case 57:
            /* ���Ϸ��ƶ� */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize-1)%BoardSize;y = (y+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize-1)%BoardSize;y = (y+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 83:
        case 115:
        case 80:
            /* ����  */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 90:
        case 122:
        case 49:
            /* ���·��ƶ� */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize+1)%BoardSize;y = (y+BoardSize-1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize+1)%BoardSize;y = (y+BoardSize-1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 68:
        case 100: 
        case 77:
            /* ���� */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            y = (y+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                y = (y+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 88:
        case 120:
        case 51:
            /* ���·��ƶ� */
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            x = (x+BoardSize+1)%BoardSize;y = (y+BoardSize+1)%BoardSize;
            while(ChessBoard[x][y])
            {
                x = (x+BoardSize+1)%BoardSize;y = (y+BoardSize+1)%BoardSize;
            }
            DrawPoint(x,y,player);
            break;
        case 8:
            if(record->Count == 0) break;
        
            ChessBoard[x][y] = 0;
            ClearPoint(x,y,player);
            point = record->Withdraw();
            x = point.x,y = point.y,player = point.player;
    
            DrawPoint(x,y,player);
            DrawActPoint(102,16,player);
            DrawActStep(102,20,--ActStep);
            break;

        case 13:
            if(Win(x,y,2-player%2)){
                DrawActStep(102,20,++ActStep);
                gotoxy(0,40);
                record->AddRecord(x,y,2-player%2);
                records.AddRecords(record);
                if(player == 1){ SetTextGreen();Cprintf("���һ(�̷�)��ʤ��");SetTextWhite();}
                else {SetTextBlue(); Cprintf("��Ҷ�(����)��ʤ��");SetTextWhite();}
                printf("\n\n");Cprintf("��Esc�˳�");
                while(getch()!=27);
                return;
            }
            record->AddRecord(x,y,player);

            ChessBoard[x][y] = player++;
            player = 2-player%2;

            DrawActPoint(102,16,player);
            DrawActStep(102,20,++ActStep);
            step = 0;

            while(step<BoardSize)
            {
                if(!ChessBoard[(x+BoardSize-step)%BoardSize][y]) {x=(x+BoardSize-step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[(x+BoardSize-step)%BoardSize][(y+BoardSize-step)%BoardSize]) 
                    {x=(x+BoardSize-step)%BoardSize;y=(y+BoardSize-step)%BoardSize;DrawPoint(x,y,player); break;}
                if(!ChessBoard[x][(y+BoardSize-step)%BoardSize]) {y=(y+BoardSize-step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[(x+BoardSize-step)%BoardSize][(y+BoardSize-step)%BoardSize]) 
                    {x=(x+BoardSize+step)%BoardSize;y=(y+BoardSize-step)%BoardSize;DrawPoint(x,y,player); break;}
                if(!ChessBoard[(x+BoardSize+step)%BoardSize][y]) {x=(x+BoardSize+step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[(x+BoardSize-step)%BoardSize][(y+BoardSize-step)%BoardSize]) 
                    {x=(x+BoardSize-step)%BoardSize;y=(y+BoardSize+step)%BoardSize;DrawPoint(x,y,player); break;}
                if(!ChessBoard[x][(y+BoardSize+step)%BoardSize]) {y=(y+BoardSize+step)%BoardSize; DrawPoint(x,y,player); break;}
                if(!ChessBoard[(x+BoardSize-step)%BoardSize][(y+BoardSize-step)%BoardSize]) 
                    {x=(x+BoardSize+step)%BoardSize;y=(y+BoardSize+step)%BoardSize;DrawPoint(x,y,player); break;}
                step++;
            }
            if(step == BoardSize) {
                record->AddRecord(x,y,2-player%2);
                record->AddRecord(x,y,0);
                records.AddRecords(record);
                gotoxy(0,40);Cprintf("����������������Ǳ�(�R?�Q)?");
                printf("\n\n");SetTextGreen();Cprintf("��Esc�˳�");SetTextWhite();
                while(getch()!=27);
                return;
            }
            
            break;
        
        default:
            break;
        }

    }

}

void GoBang::History(int delay)
{
    system("cls");
    printf("\n\n\n");
    Record *head = records.Head->next;
    printf("\n                       ");printf("    ��������������������������������������������������������������������������������������������������������");Sleep(delay);
    printf("\n                      ");printf("    |���\t|   ��ʼʱ��\t|   ����ʱ��\t|������\t|ʤ����\t|");Sleep(delay);
    int i = 1;
    // string winner;
    while(head){
        printf("\n                       ");printf("    ��������������������������������������������������������������������������������������������������������");Sleep(delay);
        printf("\n                      ");

        printf("    |  %d\t|   %02d:%02d:%02d\t|   %02d:%02d:%02d\t|  %d\t|",
        i++,head->StartTime.tm_hour,head->StartTime.tm_min,head->StartTime.tm_sec,
        head->EndTime.tm_hour,head->EndTime.tm_min,head->EndTime.tm_sec,head->Count
        );

        int winner = head->Points[head->Count-1].player;
        if(winner == 1)
        {
            SetTextGreen();
            printf("%s\t|","  ��");
            SetTextWhite();
        }else if(winner == 2)
        {
            SetTextBlue();
            printf("%s\t|","  ��");
            SetTextWhite();
        }else{
            printf("%s\t|"," ����");
        }
        head = head->next;
    }
    printf("\n                       ");printf("    ��������������������������������������������������������������������������������������������������������");Sleep(delay);
}

void GoBang::Review(int id,int delay)
{
    system("cls");
    Record *head = records.Head->next;
    int i = 1;
    while(head && i++ != id){
        head = head->next;
    }
    DrawBoard();
    i = 0;
    while(i<head->Count)
    {
        Sleep(delay);
        DrawPoint(head->Points[i].x, head->Points[i].y, head->Points[i].player);
        i++;
    }
    gotoxy(56,38);
    printf("\n\n");Cprintf("��Esc�˳�");
    while(getch()!=27);

}

void GoBang::PrintHistory(int delay)
{
    
    int id;
    string str;
    while(true)
    {
        History(delay);
        printf("\n\n");
        Cprintf("ѡ0Ϊ�˳��鿴");
        printf("\n\n");
        Cprintf("ѡ����Ų鿴���:");
        cin>>str;
        while(!Regex(str))
        {
            printf("\n\n");
            Cprintf("���ֻ��������:");
            cin>>str;
        }
        id = atoi(str.c_str());
        if(id>records.Count) continue;
        if(id == 0) break;
        Review(id,70);
    }

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
	cout<<setw(56)<<str;
}

void GoBang::Cprintf(string str)
{
	cout<<setw(56+str.length()/2)<<str;
}

void GoBang::Slowprintf(string str)
{
    const char *Str = str.c_str();
    cout<<setw(20+strlen(Str)/2);

    for(int i=0; i<str.length();i++)
    {
        cout<<Str[i];
        Sleep(20);
    }
}


//ȡ����󻯣���С��
void GoBang::SizeGoAway() {
	SetWindowLongPtrA(
		GetConsoleWindow(),
		GWL_STYLE,
		GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
}

//ȡ���ر�  
void GoBang::DeleteGoAway(){
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
		SC_CLOSE, MF_DISABLED);
	DrawMenuBar(GetConsoleWindow());
}

void GoBang::goodbye()
{
	SetTextGreen();
    printf("\n");
	Cprintf("��ӭ�´�����~\n");
	SetTextWhite();

    Sleep(3000);
    // return;
}

GoBang::~GoBang()
{
}
