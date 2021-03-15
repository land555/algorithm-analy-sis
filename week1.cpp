//primÀ„∑® 
int prim(int e[][maxx],int n)
{
    int ans=0£¨i;
    memset(book,false,sizeof(book));
    book[0]=true;
    for( i=1; i<n; i++)
        dis[i]=e[0][i];
    for( i=1; i<n; i++)
    {
        int minn=inf,u=-1;
        for(int j=0; j<n; j++)
        {
            if(!book[j]&&dis[j]<minn)
            {
                minn=dis[j];
                u=j;
            }
        }
        if(ans==inf)
            return -1;
        ans+=minn;
        book[u]=true;
        for(int v=0; v<n; v++)
            if(!book[v])
                dis[v]=min(dis[v],e[u][v]);
    }
    return ans;
}
//kruskalÀ„∑® 
int Kruskal(int r)
{
	int s = 0,cnt=0;
	sort(E,E+M,cmp);
	init();
	for (int i = 0; i < M; i++)
	{
		int Fu = findFather(E[i].u);
		int Fv = findFather(E[i].v);
		if (Fu != Fv)
		{
			father[Fv] = Fu;
			s += E[i].w;
			cnt++:
			if(cnt==N-1)
				break;
		}
	}
		return s;
}
