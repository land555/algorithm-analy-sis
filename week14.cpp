#include<iostream>
#define MAXSIZE 100 
using namespace std;
int n=5,j=2;    //nΪ��������jΪ������ 
int best=100;
int besttime[100];//���ŵ��ȷ��� 
int t[5]={1,5,2,10,3};//ÿ�����������Ҫ��ʱ�� 
int sum[100];//ǰi��������Ҫ��ʱ�� 
int T[100];//�洢�������Ľ�� 

//����������Ҷ�ӽ�����ʱ��������ʱ�� 
int search(){
	int J[MAXSIZE]={0};
	  for(int i=0;i<n;i++)
    {
       J[sum[i]]+=t[i];
    }
 	 int max=J[1];
      for(int i=1; i<=j;i++) 
	  {
        if(J[i]>max) max=J[i];
      }
      return max;
}
//���ݷ� 
void backtrack(int dep) {
	if(dep==n){  
	 int tmp=search(); //Ҷ�ӽڵ�Ŀ��н� 
		 if(tmp<best){
		    best=tmp;
		     for(int i=0;i<n;i++)
            {
                besttime[i]=sum[i];//���ŵ��ȷ��� 
            }
			} 
		 return;
	}
	for(int i=1; i<=j; i++) {
		sum[dep]=i;
		if(search()<best)  // ������н��С�����Ž� 
			backtrack(dep+1);//�ݹ�����һ�� 
		sum[dep]=0;//����
	}
}
void bestmethods()
{
   cout<<"ʱ�����ٵĵ��ȷ���:"<<endl;
    for(int i=1;i<=j;i++)
    {
        bool hasTask=false;    //�жϻ����Ƿ�������� 
        cout<<"����"<<i<<"���� �� ";
        for(int k=0;k<n;k++)
        {
            if(i==besttime[k])
            {
             cout<<"����"<<k+1<<" ";
                hasTask=true;
                  }
        }
        if(hasTask==false)printf("δ��������");
          cout<<endl;
    }
}
 int main() {
 	
	for(int i=0; i<j; i++)
	sum[i]=0;
    backtrack(0);
    cout<<"�ӹ�ʱ������Ϊ:"<<endl;
    cout<<best<<endl;
    bestmethods(); 
	return 0;
}

