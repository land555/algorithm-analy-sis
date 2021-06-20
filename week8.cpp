#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int tmp = 0,s,k;
	cout << "请输入矩阵数目：";
	cin >> s;
	int* Matrixchain = new int[ s + 1];
    
	cout << "请输入矩阵链:" << endl;
	for (int i = 0; i < s + 1; i++){
		cin >> Matrixchain[i];
	}


	int** Min = new int*[s + 1];
	for (int i = 0; i < s + 1; i++){
		Min[i] = new int[s+1];
	}
	for (int i = 0; i < s + 1; i++){
		Min[i][i] = 0;
	}

	int** Break = new int*[s + 1];
	for (int i = 0; i < s + 1; i++){
		Break[i] = new int[s + 1];
	}

	for (int Len = 2; Len < s + 1; Len++){
		for (int i = 1; i < s-Len+2; i++){
			int j = i + Len - 1;
			Min[i][j] = Min[i][j - 1] + Matrixchain[i - 1] * Matrixchain[j - 1] * Matrixchain[j];
		for (int k = i; k < j; k++){
				tmp = Min[i][k] + Min[k + 1][j] + Matrixchain[i - 1] * Matrixchain[k] * Matrixchain[j];
				if (tmp < Min[i][j]){
					Min[i][j] = tmp;
					Break[i][j] = k;
				}
			}
		}
	}

	cout << "最小计算值=" << Min[1][s] << endl;

	delete[] Matrixchain;
	for (int i = 0; i < s+1; i++){
		delete[] Min[i];
		delete[] Break[i];
	}
	delete[] Min;
	delete[] Break;

	cin.get();
	cin.get();
	return 0;
}



