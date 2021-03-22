#include <stdio.h>
int Binary(int a[], int length, int key)
{
	int low = 1;
	int high = length;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;   
		if (key < a[mid])
			high = mid - 1;     
		else if (key > a[mid])
			low = mid + 1;    
			return mid;      
	}
	return -1;
}
int main(){
    int i, num, p;
    int a[5]={1,2,3,4,5};
    scanf("%d",&num);
    p = Binary(a,8,num);
    if(-1 == p)
        printf("j=0\n");
    else
        printf ("j=%d\n",p);
    return 0;
}

