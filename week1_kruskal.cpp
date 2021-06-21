#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int c, n, m;
struct node
{
	int s, e, w;
	bool operator<(const node a)const {
		return w < a.w;
	}
}edge[10010];
int fa[110];
int find(int x) {
	return fa[x] == x ? x : find(fa[x]);
}
void merge(int x, int y) {
	fa[find(x)] = find(y);
}
int Kruskal() {
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < m; i++) fa[i] = i;
	sort(edge + 1, edge + n + 1);
	for (int i = 1; i <= n; i++) {
		int s = edge[i].s, e = edge[i].e;
		if (find(s) != find(e)) {
			merge(s, e);
			++cnt;
			sum += edge[i].w;
			if (cnt >= n - 1) break;
		}
	}
	return sum;
}
int main() {
	while (cin >> c >> n >> m) {
		for (int i = 1; i <= n; i++) {
			cin >> edge[i].s >> edge[i].e >> edge[i].w;
		}
		if (Kruskal() > c) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}

