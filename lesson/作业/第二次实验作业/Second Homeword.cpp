#include <iostream>
#include <string>
#include <cstring>
using namespace std;

double max(double a,double b){

    return a > b ? a : b;
}
int reverseint(int num){
    int result = 0;
	// ����������
	for (int i = num; i ; )
	{
		// ȥ����λ�ϵ���
		i = i/10*10;
		// ��result��һλ�������ϵ�ǰ��λ�ϵ�����num-i��
		result = result * 10 + num - i;
 
		i = i /10;
		num = num/10;
	}
    return result;
}
char* dopoem(){
    static char poem[88];
    strcpy(poem,"ҹ��ı�\n�ơ�������\n���ʹ���δ���ڣ�\n��ɽҹ������ء�\n�ε�����������\nȴ����ɽҹ��ʱ��");
    return poem;
}
char* Isleap(int year){
    static char isleap[70];
    static char isnotleap[70];
    strcpy(isleap,"Yes");
    strcpy(isnotleap," No");
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ){
	    return isleap;
    } return isnotleap;
}
float* min(float arr[],int n){
    float min = arr[0];
    float index = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
            index = i;
        }
    }
    static float arr1[2];
    arr1[0] = min;
    
    arr1[1] = index;
    return arr1;
}

int main(){
    double a,b,c,d;
    int i,year,n;
    float farr[10];
    cout<<"һ.ѡ��ṹ"<<endl;
    cout<<"�������ĸ�˫���ȸ������ԱȽϴ�С:";
    cin>>a>>b>>c>>d;
    cout<<"�����Ϊ"<<max(max(max(a,b),c),d)<<endl;
    cout<<"��.ѭ���ṹ"<<endl;
    
    cout<<"������Ҫ��ת��������:"; 
    cin>>i;
    while (i<0)
    {
        cout<<"������������:";
        cin>>i;
    }
    cout<<"result="<<reverseint(i)<<endl;
    cout<<"��.����"<<endl;
    cout<<"1.ʫ"<<endl;
    cout<<dopoem();
    cout<<endl<<"2.����"<<endl;
    cout<<"���������:";
    cin>>year;
    cout<<Isleap(year)<<endl;
    cout<<"��.����"<<endl;
    for(int i = 0;i<10;i++){
        cin>>farr[i];
    }
    cout<<"���飺";
    for(int i = 0;i<10;i++){
       cout<<farr[i]<<" ";
    }
    cout<<"����n��";
    cin>>n;
    cout<<"����ǰ"<<n<<"λ��СֵΪ"<<min(farr,n)[0]<<"�±�Ϊ"<<min(farr,n)[1];
    system("pause");
    return 0;
}