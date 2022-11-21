#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
float applecost(){
    double sum = 0;
    int i = 2;
    int j = 0;
    for(i;i<=100;i*=2)
    {
        sum = sum + i*0.2;
        j++;
    }
    return sum/j;
}
bool isprime(int n){
    if(n==1&&n==2&&n==3)
    {
        return true;
    }
    for(int i = 2;i<sqrt(n);i++)
    {
        if((n % i) == 0){
            cout<<n<<"��������"<<endl;
            return false;
        }
    }
    cout<<n<<"������"<<endl;
    return true;
}
double avrsalary(int rens){
    double salary[20];
    double all = 0;
    for(int i = 0;i < rens;i++)
    {
        cout<<"�������"<<i+1<<"���˵Ĺ���"<<endl;
        cin>>salary[i];
        all = all + salary[i];
        // cout<<all;
    }
    cout<<fixed<<setprecision(2)<<"ƽ������Ϊ:"<<all/rens<<endl;
    return all/rens;
}
typedef struct 
{
    int citynum;
    char name[17];
    double longitude;
    double lagitude;
} city;

city arr[20];
void incities(int cities){
    for(int i = 0;i < cities;i++){
        cout<<"�������"<<i+1<<"�����б��:"<<endl;
        cin>>arr[i].citynum;
        cout<<"�������"<<i+1<<"����������:"<<endl;
        cin>>arr[i].name;
        cout<<"�������"<<i+1<<"�����о���"<<endl;
        cin>>arr[i].longitude;
        cout<<"�������"<<i+1<<"������γ��"<<endl;
        cin>>arr[i].lagitude;
    }
};
void outcities(int cities){
    cout<<"-------------------------------------"<<endl;
    cout<<"|��������|���б��|���о���|����ά��|"<<endl;
    for(int i = 0;i < cities;i++){
        cout<<"|    "<<arr[i].name<<"|\t "<<arr[i].citynum<<"|  "<<arr[i].longitude<<
        "|   "<<arr[i].lagitude<<"|"<<endl;
    }
}
int main(){
    int n;
    int rens;
    int cities;
    double salary[20];
    cout<<"һ.ѭ���ṹ:"<<endl;
    cout<<applecost()<<endl;
    cout<<"��.�����뺯��"<<endl;
    cout<<"2.1:"<<endl;
    cout<<"�������������ж��Ƿ�Ϊ����:";
    cin>>n;
    isprime(n);
    cout<<"2.2:"<<endl;
    cout<<"������ͳ������:";
    cin>>rens;
    avrsalary(rens);
    cout<<"��.�ṹ�塢�����뺯��"<<endl;
    cout<<"3.1:"<<endl;
    cout<<"������Ҫд��ĳ�������:"<<endl;
    cin>>cities;
    incities(cities);
    outcities(cities);
    system("pause");
    return 0;
}