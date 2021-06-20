#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int m=5,n=4;
    int f[5][6] = {0,0,0,0,0,0,
				   0,11,12,13,14,15,
				   0,0,5,10,15,20,
				   0,2,10,30,32,40,
				   0,20,21,22,23,24
};
    int F[5][6] = {0}; //��5��ԪǮ���䵽ǰ4����Ŀȡ�õ��������
    int x[5][6] = {0}; //�����5����Ŀ��Ͷ���˶�����ԪǮ
    for (int i = 1; i <= 5; i++)
    {
        F[1][i] = f[1][i]; 
        x[1][i] = i;       
    }
    for (int i = 2; i <= 4; i++) //ö�ٷ���
    {
        for (int j = 1; j <= 5; j++) 
        {
            int _max = 0;
            for (int k = 0; k <= j; k++)
            {
                if (f[i][k] + F[i - 1][j - k] > _max)
                {
                    _max = f[i][k] + F[i - 1][j - k]; //���µ�ǰ�������
                    x[i][j] = k;                     
                }
            }
            F[i][j] = _max;
        }
    }
    cout << "������棺" << F[4][5] << "��Ԫ"<< endl;
    int money = 5;
    for (int i = 4; i >= 1; i--) 
    {
        cout << "��" << i << "����ĿͶ��" << x[i][money] << "Ԫ" << endl;
        money -= x[i][money];
    }
    return 0;
}

