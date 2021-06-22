#include<iostream>
#define MAXSIZE 100 
using namespace std;
int n=5,j=2;    //n为任务数，j为机器数 
int best=100;
int besttime[100];//最优调度方案 
int t[5]={1,5,2,10,3};//每个任务完成需要的时间 
int sum[100];//前i个任务需要的时间 
int T[100];//存储搜索树的结点 

//计算搜索到叶子结点可行时完成任务的时间 
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
//回溯法 
void backtrack(int dep) {
	if(dep==n){  
	 int tmp=search(); //叶子节点的可行解 
		 if(tmp<best){
		    best=tmp;
		     for(int i=0;i<n;i++)
            {
                besttime[i]=sum[i];//最优调度方案 
            }
			} 
		 return;
	}
	for(int i=1; i<=j; i++) {
		sum[dep]=i;
		if(search()<best)  // 如果可行解和小于最优解 
			backtrack(dep+1);//递归至下一层 
		sum[dep]=0;//回溯
	}
}
void bestmethods()
{
   cout<<"时间最少的调度方案:"<<endl;
    for(int i=1;i<=j;i++)
    {
        bool hasTask=false;    //判断机器是否分配任务 
        cout<<"机器"<<i<<"分配 ： ";
        for(int k=0;k<n;k++)
        {
            if(i==besttime[k])
            {
             cout<<"任务"<<k+1<<" ";
                hasTask=true;
                  }
        }
        if(hasTask==false)printf("未分配任务！");
          cout<<endl;
    }
}
 int main() {
 	
	for(int i=0; i<j; i++)
	sum[i]=0;
    backtrack(0);
    cout<<"加工时间最少为:"<<endl;
    cout<<best<<endl;
    bestmethods(); 
	return 0;
}

