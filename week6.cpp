#include<stdio.h>
int Select( int a[], int s, int e, int k )
{
	int i=s,j=e,tmp;
if(s < e)

{
tmp = a[s];

while(i != j)

{
while(j > i && a[j] >= tmp)

j--;

a[i] = a[j];

while(i < j && a[i] <= tmp)

i++;

a[j] = a[i];

}

a[i] = tmp;

if(k-1 == i)

return a[i];

else if(k-1 < i)

return Select(a, s, i-1, k);

else

return Select(a, i+1, e, k);

}

else if(s == e && s == k-1)

return a[k-1];

}


int main()
{
	int n=10;
    int arr[10] = {5,-6,8,-3,2,6,1,3,-1,7};
	int k,t;
	
	printf("寻找一个数组第k小的元素，请输入k(k!=0)：" );
	while(1){
		scanf("%d",&k);
		if(k == 0){
			printf("END\n");
			break;
		}
		int t= Select( arr, 0, n-1, n-k+1);
		printf("第%d小的数是: %d\n",k,t);
	}
}

