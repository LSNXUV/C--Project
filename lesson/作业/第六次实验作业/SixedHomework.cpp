#include <iostream>
#include<iomanip>
#include<cmath>
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
char* del(char word[20],int m,int n){
    strcpy(word+m-1,word+m+n-1);
    return word;
}

void out(){
    const int n = 8;
	int a[n][n];
	int i,j;
	for( i=0;i<=n-1;i++)
	{
		for( j=0;j<=i;j++)
		{
			if(j==0||j==i)
			{
				a[i][j]=1;
			}
			else 
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

int Fibonacci(int n)
{
    if (n <= 0)    //�������
        return 0;
    else if (n == 1) // �������
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(){
    char word[20];

    int m,n,rens,a,b,fib;

    
    cout<<"һ������Ƕ��"<<endl;
    cout<<"������m��n(2<=m<n):";
    cin>>m>>n;
    Outprime(m,n);
    cout<<"����ָ����һά����"<<endl;
    cout<<"������ͳ������:";
    cin>>rens;
    avrsalary(rens);
    cout<<"����ָ�����ַ�����"<<endl;
    cout<<"������Ҫ�������ַ���:";
    cin>>word;
    cout<<"������ɾ���ĳ�ʶλ�úͽ���λ�õ����:";
    cin>>a>>b;
    cout<<"���Ϊ:"<<del(word,a,b)<<endl;
    cout<<"�ġ���ά����"<<endl;
    cout<<"�������:"<<endl;
    out();
    cout<<"�塢�����ĵݹ�"<<endl;
    cout<<"������Ǹ���:"<<endl;
    cin>>fib;
    cout<<Fibonacci(fib);



    system("pause");
    return 0;
}