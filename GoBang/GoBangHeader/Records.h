
typedef struct Point
{

    int x,y;
    int player;
    
} Point;

class Records
{

public:
    Point Points[225];
    int Count;

    void AddRecord(int x,int y,int player);
    Point Withdraw();
    Records(/* args */);
    ~Records();

};

Records::Records(/* args */)
{
    Count = 0;
}

void Records::AddRecord(int x,int y,int player)
{
    Points[Count].x = x;
    Points[Count].y = y;
    Points[Count++].player = player;
}

Point Records::Withdraw()
{
    Point point;
    point.x = Points[Count-1].x;
    point.y = Points[Count-1].y;
    point.player = Points[Count---1].player;

    return point;
}

Records::~Records()
{
}


