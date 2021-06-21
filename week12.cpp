#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 5;
int n, k, m, tot[maxn][10];
vector<int>v[maxn];
int ans = 0;
void dfs(int step)
{
    if(step == n + 1) {ans++; return;}
    for(int i = 1; i <= m; ++i)
    {
        if(!tot[step][i])
        {
            for(int j = 0; j < v[step].size(); ++j) tot[v[step][j]][i]++;        //È¾É«
            dfs(step + 1);
            for(int j = 0; j < v[step].size(); ++j) tot[v[step][j]][i]--;        //»ØËÝ
        }
    }
}
int main() {
  freopen("input.in.txt", " r", stdin);
  freopen("input.out.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 1; i <= k; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
