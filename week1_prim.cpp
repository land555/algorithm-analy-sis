#include<iostream>
#include<fstream>
#define maxx 100
#define MAXCOST 0x7fffffff

using  namespace std; 
int  e[maxx][maxx];
 
int prim(int  e[][maxx], int n)
{
	int lowcost[maxx];
	int mst[maxx];
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= n; i++)
	{
		lowcost[i] =  e[1][i];
		mst[i] = 1;
	}
	mst[1] = 0;
	for (i = 2; i <= n; i++)
	{
		min = MAXCOST;
		minid = 0;
		for (j = 2; j <= n; j++)
		{
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;
		sum += min;
		lowcost[minid] = 0;
		for (j = 2; j <= n; j++)
		{
			if ( e[minid][j] < lowcost[j])
			{
				lowcost[j] =  e[minid][j];
				mst[j] = minid;
			}
		}
	}
	return sum;
}
 
int main()
{
	int i, j, k, m, n;
	int x, y, cost;
	ifstream in("input.txt");
	in >> m >> n;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			 e[i][j] = MAXCOST;
		}
	}
	for (k = 1; k <= n; k++)
	{
		in >> i >> j >> cost;
		 e[i][j] = cost;
		 e[j][i] = cost;
	}
	cost = prim( e, m);
	cout << "最小权值和=" << cost << endl;
	system("pause");
	return 0;
}
