#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#include<vector>



void Outrepeat(){
    char repeat[30];
    char ch;
    cout<<"�������ַ�����Ҫ���ҵ��ַ�:"<<endl;
    cin>>repeat>>ch;
    int j = 0;
    for(int i =1;i<strlen(repeat);i++){
        if(repeat[i]==ch){
            cout<<i<<"\t";
            j++;
        }
    }
    if(j==0){
        cout<<"NULL"<<endl;
    }cout<<endl<<j<<endl;
}

void InvertSequence(int num){
    int n = num;
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
    // cout<<result<<endl;
    // cout<<result<<" "<<num;
    if(result==n)
    cout<<result<<endl;
    
}
void outInvertSequence(){
    int a,b;
    cout<<"������������:"<<endl;
    cin>>a>>b;
    
    // cout<<InvertSequence(a);
    for(int i = a;i<=b;i++){
        // cout<<i;
        InvertSequence(i);
    }
}

void BinaryRecursion(int n,vector<int>&ans)
{
    int a;
    a = n%2;
    n = n>>1;
    if (n != 0)
        BinaryRecursion(n,ans);
    cout<<a;
    ans.push_back(a);
}

void quick_Sort(vector<int>& v, int left, int right){
	if(left >= right) return;
	int i = left, j = right, base = v[left];  //ȡ����ߵ���Ϊ����
	while(i < j){
		while(v[j] >= base && i < j){
			j--;
		}
		while(v[i] <= base && i < j){
			i++;
		}
		if(i < j){
			swap(v[i], v[j]);
		}
	} 
	v[left] = v[i];
	v[i] = base;
	quick_Sort(v, left, i - 1);
	quick_Sort(v, i + 1, right);
}
void quickSort(vector<int>& v){
	int n = v.size();
	quick_Sort(v, 0, n - 1);
}

void SelectSort(int n,int a[]){
    int exchange;
    for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[i]>a[j])
            {exchange=a[i];
            a[i]=a[j];
            a[j]=exchange;    
        }     
    }
    }
}
void outMergeArr(){
    // int a=7,b=5;
    int a,b;
    
    vector<int> herr;
    /* if(arr != NULL && brr != NULL)
    {
        cout << "c++������̬����ɹ�" << endl;
    } */
    // int* hrr = (int *)malloc(a+b);
    cout<<"��ֱ�������������ĳ��Ⱥ�����(�ո�ָ�):"<<endl;
    cin>>a;
    int *arr = new int[a];
    for(int i = 0;i<a;i++){
        cin>>arr[i];
    }
    cin>>b;
    int *brr = new int[b];
    for(int i = 0;i<b;i++){
        cin>>brr[i];
    }
    int *hrr = new int[a+b];
    /* for(int i = 0;i<a;i++){
        herr.push_back(arr[i]);
        
    }
    for(int j = a;j<a+b;j++){
        herr.push_back(brr[j-a]);
    } */
    for(int i = 0;i<a;i++){
        hrr[i] = arr[i];
        
    }
    for(int j = a;j<a+b;j++){
        hrr[j] = brr[j-a];
    }
   
    SelectSort(a+b,hrr);
    // cout<<herr[0];
    for(int i = 0;i<a+b;i++){
        cout<<herr[i]<<"#";
    }


}
int main(){
    int a;
    vector<int> ans;
    cout<<"һ�������㷨��˳����ҺͶ��ֲ��ң�"<<endl;
    cout<<"1-1"<<endl;
    // Outrepeat();
    cout<<"���������㷨��ֱ�Ӳ������򡢼�ѡ�������ð������"<<endl<<"2-1"<<endl;
    outMergeArr();
    cout<<endl<<"����ָ���뺯��"<<endl;
    cout<<"3.1"<<endl;
    cout<<"��������Ҫת���ɶ����Ƶ�ʮ������:"<<endl;
    cin>>a;
    BinaryRecursion(a,ans);
    
    cout<<endl<<"3.2"<<endl;
    outInvertSequence();

    system("pause");
    return 0;
}