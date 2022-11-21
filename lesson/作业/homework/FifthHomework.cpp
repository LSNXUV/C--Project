#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool IsPrime(int n)
{
	if(n <= 1){
		// cout<<n<<"��������"<<endl; 
		return false;
	}
    for (int i = 2; i <sqrt(n); i++)
    {
        if ((n % i) == 0){
            // cout<<n<<"��������"<<endl;
            return false;
        }
    }
    cout<<n<<"������"<<endl;
    return true;
} 
void Outprime(int m,int n){
    for(int i = m;i<n;i++){
        IsPrime(i);
    }
}
void Outrepeat(char repeat[30],char ch){
    int j = 0;
    for(int i =1;i<strlen(repeat);i++){
        if(repeat[i]==ch){
            cout<<i<<"\t";
            j++;
        }
    }
    if(j==0){
        cout<<"NULL"<<endl;
    }
}
void Outdiagonal(){
    int arr[4][4];
    int sum = 0;
    cout<<endl<<"������16������:"<<endl;
    for(int i = 0;i < 4;i++){
        int j = 0;
        while(j < 4){
            // cout<<"�������"<<i+j-1<<"������:";
            cin>>arr[i][j];
            // cout<<i<<"\t"<<j<<endl;
            j++;
        }
    }
    sum = arr[1][1] + arr[2][2] + arr[3][3] + arr[0][0];
    cout<<"�Խ��ߺ�Ϊ:"<<sum<<endl;
}

typedef struct {
    int stunum;
    char name[10];
    int score[3];
}student;

student info[100];

void Outinf(int n){
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    for(int i = 0;i < n;i++){
        cout<<"�������"<<i+1<<"��ѧ����Ϣ(ѧ�� ���� Ӣ�� ��ѧ �����):"<<endl;
        cin>>info[i].stunum>>info[i].name>>info[i].score[1]>>info[i].score[2]>>info[i].score[3];
        
        sum1+=info[i].score[1];
        // cout<<sum1;
        if(max1<info[i].score[1]){
            max1 = info[i].score[1];
        }
       
        sum2+=info[i].score[2];
        if(max2<info[i].score[2]){
            max2 = info[i].score[2];
        }
        sum3+=info[i].score[3];
        if(max3<info[i].score[3]){
            max3 = info[i].score[3];
        }
    }
    cout<<"Ӣ��ƽ���ɼ�Ϊ:"<<sum1/n<<"��߷�Ϊ:"<<max1<<endl;
    cout<<"��ѧƽ���ɼ�Ϊ:"<<sum2/n<<"��߷�Ϊ:"<<max2<<endl;
    cout<<"�����ƽ���ɼ�Ϊ:"<<sum3/n<<"��߷�Ϊ:"<<max3<<endl;
}

int Fibonacci(int n) 
{
	if(n==0) 
		return 0;
	else if(n==1)
		return 1;
	else
		return Fibonacci(n-1)+Fibonacci(n-2);
}
int main(){
    int m,n,arr[4][4],students;
    int fib;
    char repeat[30],ch;
    cout<<"һ������Ƕ�׺�ѭ���ж�"<<endl;
    cout<<"������m��n(2<=m<n):";
    cin>>m>>n;
    Outprime(m,n);
    cout<<"�����ַ�����"<<endl;
    cout<<"������һ���ַ��͵����ַ����ո�ֿ���:";
    cin>>repeat>>ch;
    Outrepeat(repeat,ch);
    cout<<"����ָ����һά����"<<endl;
    cout<<"������һ���ַ��͵����ַ����ո�ֿ���:";
    cin>>repeat>>ch;
    Outrepeat(repeat,ch);
    cout<<"�ġ���ά����"<<endl;
    Outdiagonal();
    cout<<"�塢�ṹ���ָ��������"<<endl;
    cout<<"������Ҫ¼��ѧ����Ϣ��:";
    cin>>students;
    Outinf(students);
    cout<<"���������ĵݹ��Ƕ��"<<endl;
	cout<<"������һ������"<<endl;
	cin>>fib;
	cout<<Fibonacci(fib)<<endl;

    system("pause");
    return 0;
}