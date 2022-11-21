#include <iostream>
using namespace std;

class Vehicle
{
public:
    void virtual Run()
    {
        cout << "vehicle run!" << endl;
    }
    void virtual Stop()
    {
        cout << "vehicle stop!" << endl;
    }
};

class Bicycle : virtual public Vehicle
{
public:
    void virtual Run()
    {
        cout << "bicycle run!" << endl;
    }
    void virtual Stop()
    {
        cout << "bicycle stop!" << endl;
    }
};

class Motorcar : virtual public Vehicle
{
public:
    void Run()
    {
        cout << "motocar run!" << endl;
    }
    void Stop()
    {
        cout << "motocar stop!" << endl;
    }
};

class Motorcycle : public Bicycle, public Motorcar
{
public:
    void Run()
    {
        cout << "motocycle run!" << endl;
    }
    void Stop()
    {
        cout << "motocycle stop!" << endl;
    }
};

int main()
{
    Vehicle v;
    v.Run();
    v.Stop();
    Bicycle b;
    b.Run();
    b.Stop();
    Motorcar m;
    m.Run();
    m.Stop();
    Motorcycle mc;
    mc.Run();
    mc.Stop();
    Vehicle *vp = &v;
    vp->Run();
    vp->Stop();
    vp = &b;
    vp->Run();
    vp->Stop();
    vp = &m;
    vp->Run();
    vp->Stop();
    vp = &mc;
    vp->Run();
    vp->Stop();

    system("pause");
    return 0;
}