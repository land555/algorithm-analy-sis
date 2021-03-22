//À≥–Ú≤È’“
 #include <stdio.h>
int Sequential(int *a,int n,int key)
{
	int i;
	for (i=0;i<n;i++)
	{
		if (a[i]==key)
		return i;
	}
	return 0;
}
int main()
{
	int a[5]={1,2,3,4,5},m;
	int x;
	scanf("%d",&x);
	m=Sequential(a,5,x);  
	if (m)
	   printf("j=%d",m);
	else
	   printf("j=0");
	return 0;
	} 

