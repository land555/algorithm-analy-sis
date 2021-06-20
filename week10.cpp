#include <iostream>
#define N 4//物品种数
#define B 10//背包大小 
int v[N] = {3, 4, 5, 6};//物品单价
int w[N] = {2, 3, 4, 5};//物品重量 
int F[N + 1][B + 1];
int S[N + 1][B + 1];
using namespace std;
void Knapsack(int n, int y);
void Track(int n, int y, int *a);

int main(){
	    Knapsack(N, B);
    cout<<"最大物品价值："<<F[N][B]<<endl;
    
    int a[N];
    for (int i = 0; i < N; ++i) 
        a[i] = 0; 
    
    Track(N, B, a);
    
    for (int i = 0; i < N; ++i) 
        cout<<"第"<<i<<"种物品放入："<<a[i]<<endl; 
    return 0;
}
void Knapsack(int n, int y){
    int i, j, t0, t1, t3;
    for (i = 1; i <= n; ++i) {
        t3 = w[i - 1];
        for (j = 1; j <= y; ++j) {
            t0 = F[i - 1][j];
            if (j - t3 < 0) {
                F[i][j] = t0;
                S[i][j] = S[i - 1][j];
            } else {
                t1 = F[i][j - t3] + v[i - 1];
                if (t0 > t1) {
                    F[i][j] = t0;
                    S[i][j] = S[i - 1][j];
                } else {
                    F[i][j] = t1;
                    S[i][j] = i;
                }
            }
        }
    }
}
void Track(int n, int y, int *a){
    if (y <= 0) return;
    int t = S[n][y];
    if (t == 0) return;
    ++a[t - 1];
    Track(t, y - w[t - 1], a);
}

