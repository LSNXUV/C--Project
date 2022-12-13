

class Attack
{
private:
    /* data */
public:
    int die1,die2,die3,die4;  //
    int alive1,alive2,alive3,alive4;
    Attack(/* args */);
    ~Attack();
};

Attack::Attack(/* args */)
{
    die1 = 0,die2 = 0,die3 = 0,die4 = 0;
    alive1 = 0,alive2 = 0,alive3 = 0,alive4 = 0;
}

Attack::~Attack()
{
}


class Weight
{
private:
    /* data */
public:
    
    Attack AtWeight;
    
    int weight;

    void Sum();

    Weight(/* args */);
    ~Weight();
};

Weight::Weight(/* args */)
{

    weight = 0;
}

void Weight::Sum()
{


}

Weight::~Weight()
{
}


class AI
{
private:
    /* data */
public:

    Weight ChessWeight[15][15];

    void InitWeight();

    void CalcuWeight(int ChessBoard[][15]);

    AI(/* args */);
    ~AI();
};

AI::AI(/* args */)
{
}

void AI::InitWeight()
{
    for(int i = 0;i<15;i++)
    {
        for(int j = 0;j<15;j++)
        {
            
        }
    }
}

AI::~AI()
{
}


void AI::CalcuWeight(int ChessBoard[][15])
{

}
