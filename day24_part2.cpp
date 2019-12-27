#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int a[300][6][6],aux[6][6];
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
int n,i,j,pas,ok,Left,Right,nr;
char ch;
map <long long, long long> b;
int inmat (int i, int j){
    if (i >= 1 && j >= 1 && i <= n && j <= n)
        return 1;
    return 0;
}
int get_value (int x){
    if (x == 1 || x == -1)
        return 1;
    return 0;
}
int solve (int i, int j, int level){
    if (i == 3 && j == 3) /// e ala din mijloc pe care nu trb sa l iau in calcul
        return 0;
    int ap = 0;
    for (int dir=0;dir<=3;dir++){
        int iv = i + di[dir], jv = j + dj[dir];
        if (inmat(iv,jv) && get_value(a[level][iv][jv]))
            ap++;
        else {
            if (!inmat(iv,jv)) /// scade nivelul
                ap += get_value(a[level-1][3+di[dir]][3+dj[dir]]);
            else {
                if (iv == 3 && jv == 3){
                    /// acum creste, ma aflu in mijloc
                    /// iau fiecare directie in parte
                    if (dir == 0){
                        for (int idx=1;idx<=n;idx++)
                            ap += get_value (a[level+1][n][idx]);

                        continue;
                    }
                    if (dir == 1){
                        for (int idx=1;idx<=n;idx++)
                            ap += get_value (a[level+1][1][idx]);

                        continue;
                    }
                    if (dir == 2){
                        for (int idx=1;idx<=n;idx++)
                            ap += get_value (a[level+1][idx][n]);
                        continue;
                    }
                    /// dir 3
                    for (int idx=1;idx<=n;idx++)
                        ap += get_value (a[level+1][idx][1]);

                }}}}
    return ap;
}
int main (){

    n = 5;
    int idx = 0;
    //long long mask = 0;
    /// pornesc de pe nivelul 100
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++){
            fin>>ch;
            if (ch == '.')
                a[100][i][j] = 0;
            else a[100][i][j] = 1;
            //mask += (1LL<<idx);
            idx++;
        }

    Left = 100, Right = 100;
    for (pas=1;pas<=200;pas++){
        for (int level=Left-1;level<=Right+1;level++){
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++){
                    if (a[level][i][j])
                        continue;
                    nr = solve (i,j,level);
                    if (nr == 1 || nr == 2)
                        a[level][i][j] = 2;
                }

        }
        for (int level=Left-1;level<=Right+1;level++){
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++){
                    if (a[level][i][j] != 1)
                        continue;
                    nr = solve (i,j,level);
                    if (nr != 1)
                        a[level][i][j] = -1;
                }

        }
        /// schimb
        for (int level=Left-1;level<=Right+1;level++){
            for (i=1;i<=n;i++)
                for (j=1;j<=n;j++){
                    if (a[level][i][j] == 2)
                        a[level][i][j] = 1;
                    else {
                        if (a[level][i][j] == -1)
                            a[level][i][j] = 0;
                    }
                }

            /*
            for (i=1;i<=n;i++){
                for (j=1;j<=n;j++)
                    fout<<a[i][j]<<" ";
                fout<<"\n";
            } */

        }

        /// trb sa vad daca extind intervalul Left Right
        long long sum_Left = 0, sum_Right = 0;
        for (i=1;i<=n;i++){
            for (j=1;j<=n;j++){
                sum_Left += a[Left-1][i][j];
                sum_Right += a[Right+1][i][j];
            }}
        if (sum_Left)
            Left--;
        if (sum_Right)
            Right++;
    }
    long long sol = 0;
    for (int level=Left+1;level<=Right;level++){
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                sol += a[level][i][j];
    }
    fout<<sol;

    /*
    part 1
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


    */
    return 0;
}
