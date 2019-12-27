#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int a[6][6],aux[6][6];
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
int n,i,j,pas,ok;
char ch;
map <long long, long long> b;
int inmat (int i, int j){
    if (i && j && i <= n && j <= n)
        return 1;
    return 0;
}
int main (){

    n = 5;
    int idx = 0;
    long long mask = 0;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++){
            fin>>ch;
            if (ch == '.')
                a[i][j] = 0;
            else a[i][j] = 1;
            mask += (1LL<<idx);
            idx++;
        }
    b[mask] = 1;
    for (pas=2;;pas++){
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++){
                int nr0 = 0, nr1 = 0;
                for (int dir=0;dir<=3;dir++){
                    int iv = i + di[dir];
                    int jv = j + dj[dir];
                    if (inmat (iv,jv)){
                        if (a[iv][jv] == 0)
                            nr0++;
                        else nr1++;
                    }
                }
                if (a[i][j]){
                    if (nr1 != 1)
                        aux[i][j] = 0;
                    else aux[i][j] = 1;
                } else {
                    if (nr1 >= 1 && nr1 <= 2)
                        aux[i][j] = 1;
                    else aux[i][j] = 0;
                }

            }
        long long mask = 0;
        int idx = 0;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++){
                a[i][j] = aux[i][j];
                if (a[i][j])
                    mask += (1LL<<idx);

                idx++;
            }
        if (b[mask]){
            for (i=1;i<=n;i++,fout<<"\n")
                for (j=1;j<=n;j++)
                    fout<<a[i][j]<<" ";
            fout<<mask;
            break;
        } else b[mask] = 1;
        cout<<pas<<endl;

    }


    return 0;
}

