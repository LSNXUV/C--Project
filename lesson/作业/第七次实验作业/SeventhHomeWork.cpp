#include <iostream>
#include <stdio.h>

#include <malloc.h>
#include <cstring>

using namespace std;

bool prime(int n){
    return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
}
struct{ 
    int year;
    int month;
    int day;
}date;

void outdays(){
    int days = 0;
    cout<<"������������:";
    cin>>date.year>>date.month>>date.day;
    days+=date.day;
    int year1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<date.month-1;i++){
			days+=year1[i];
	}
    if(prime(date.year&&date.month>=3)){
        days++;
    }
    cout<<date.month<<"/"<<date.day<<" is the "<<days<<"th day in "<<date.year<<"."<<endl;
}

typedef struct inf{
    char name[10];
    char sex[10];
    int born;
}info;

struct inf *pr = (struct inf *)malloc(sizeof(struct inf)*5);

void outinf(){
    int w = 0;
    int r = 0;
    for(int i = 0;i<5;i++){
        cout<<"�������"<<i+1<<"���˵�����:";
        cin>>pr[i].name;
        cout<<"�������"<<i+1<<"���˵��Ա�:";
        cin>>pr[i].sex;
        if(!strcmp(pr[i].sex,"Ů")){
            w+=1;
        }
        // cout<<strcmp(pr[i].sex,"Ů");
        cout<<"�������"<<i+1<<"���˵ĳ�����:";
        cin>>pr[i].born;
        if(pr[i].born>=1990){
            r+=1;
        }
        
    }
    cout<<"Ů:"<<w<<endl;
    cout<<"90��:"<<r<<endl;
}
void infile(){
    int n;
    FILE *fp=fopen("666.txt","w");
	if(fp==NULL){
        cout<<"�ļ�����ʧ��";
        return;
    };
    cout<<"������Ҫ�������ֵĸ���:"<<endl;
    cin>>n;
    for(int i =0;i<n;i++){
        char num[5];
        cout<<"�������"<<i+1<<"������"<<endl;
        cin>>num;
        fprintf(fp,num);
        fprintf(fp," ");
    }
    fclose(fp);
    

}
void outfile(){
    char buff[255];
    FILE *fpr=fopen("666.txt","r");
    if(fpr==NULL){
        cout<<"�ļ���ȡʧ��";
        return;
    };
    fgets(buff,255,(FILE*)fpr);
    cout<<"�ļ�����Ϊ:"<<buff<<endl;
    // printf("%s\n",buff);
    fclose(fpr);
}

void outperfect(){
    int n;
    int arr[10];
    cout<<"������һ����:"<<endl;
	cin>>n;
    int j = 0;
	for(int i=1;i<=n;i++){
		int sum=0; //������������������ӵĺ� 
		for(int j=1;j<i;j++){ //���������� 
			if(i%j==0) sum+=j;
		}
		if(i==sum) arr[j++] = i; //�жϡ���� 
	}
    cout<<"�����ȫ��:"<<arr[j-1];
}

int main(){
    cout<<"һ���ṹ����ָ��"<<endl;
    outdays();
    outinf();
    cout<<"�����ļ�������C�����������"<<endl;
    infile();
    outfile();
    cout<<"��������"<<endl;
    outperfect();
    system("pause");
    return 0;
}