#include <iostream>
using namespace std;

void newtime(){
    int h,m,s;
    cout<<"��ֱ����� ʱ �� ��(�ո�ֿ�):"<<endl;
    cin>>h>>m>>s;
    switch (s)
    {
    case 59 :
        s = 0;
        m++;
        break;
    default:
        s++;
        break;
    }
    switch (m)
    {
    case 60 :
        m = 0;
        h++;
        break;
    default:
        break;
    }
    switch (h)
    {
    case 24 :
        h = 0;
        break;
    default:
        break;
    }
    cout<<"ʱ��Ϊ:"<<h<<":"<<m<<":"<<s<<endl;
}

int InvertSequence(int num){
    
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
float sum(float a,float b){
    float *c,*d;
    c = &a;
    d = &b;
    return *c+*d;
}
float product(float a,float b){
    float *c,*d;
    c = &a;
    d = &b;
    return *c**d;
}

int main(){
    int num;
    float a,b;
    cout<<"һ.���֧�ṹ"<<endl<<"1.1"<<endl;
    newtime();
    cout<<"��.����"<<endl<<"2.1"<<endl;
    cout<<"������������:"<<endl;
    cin>>num;
    cout<<"������Ϊ:"<<InvertSequence(num)<<endl;
    cout<<"��.ָ��"<<endl<<"3.1"<<endl;
    cout<<"������������:"<<endl;
    cin>>a>>b;
    cout<<"��:"<<sum(a,b)<<endl<<"��:"<<product(a,b);
    system("pause");
    return 0;
}