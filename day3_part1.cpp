#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
//char a[40000][40000];
map <int,int> a[40000];
char s[1000000];
int n,ic,jc,x,y,i,j,diri,dirj,sol,nr,idx;
int modul (int n){
    if (n < 0)
        return -n;
    return n;
}
int main (){

    fin>>s+1;
    n = strlen (s+1);
    x = 20000, y = 20000;
    int minix = INF, miniy = INF, maxix = -INF, maxiy = -INF;
    ic = x, jc = y, nr = 0, idx = 1;
    for (i=1;i<=n;i++){
        if (s[i] >= '0' && s[i] <= '9'){
            nr = nr*10 + s[i] - '0';
            continue;
        }
        if (s[i] == ','){
            /// s a terminat o comanda
            for (int pas=1;pas<=nr;pas++){
                a[ic][jc] = idx;
                ic += diri, jc += dirj;
                idx++;
                minix = min (minix, ic);
                miniy = min (miniy,jc);
                maxix = max (maxix, ic);
                maxiy = max (maxiy,jc);
            }
            nr = 0;
            continue;
        }
        if (s[i] == 'R')
            diri = 0, dirj = 1;
        else {
            if (s[i] == 'L')
                diri = 0, dirj = -1;
            else {
                if (s[i] == 'D')
                    diri = 1, dirj = 0;
                else diri = -1, dirj = 0;
            }
        }
    }
    /// mai fac pt ultimul inca odata
    for (int pas=1;pas<=nr+1;pas++){
        a[ic][jc] = idx;
        idx++;
        ic += diri, jc += dirj;
    }

    fin>>s+1;
    n = strlen (s+1);
    ic = x, jc = y, nr = 0;
    idx = 1;
    sol = INF;
    for (i=1;i<=n;i++){
        if (s[i] >= '0' && s[i] <= '9'){
            nr = nr*10 + s[i] - '0';
            continue;
        }
        if (s[i] == ','){
            /// s a terminat o comanda
            for (int pas=1;pas<=nr;pas++){
                if (a[ic][jc] && (!(ic == x && jc == y))){
                    int dist = modul (ic-x) + modul (jc-y);
                    sol = min (sol,dist);
                }
                minix = min (minix, ic);
                miniy = min (miniy,jc);
                maxix = max (maxix, ic);
                maxiy = max (maxiy,jc);

                ic += diri, jc += dirj;
                idx ++;
            }
            nr = 0;
            continue;
        }
        if (s[i] == 'R')
            diri = 0, dirj = 1;
        else {
            if (s[i] == 'L')
                diri = 0, dirj = -1;
            else {
                if (s[i] == 'D')
                    diri = 1, dirj = 0;
                else diri = -1, dirj = 0;
            }
        }
    }

    for (int pas=1;pas<=nr+1;pas++){
        if (a[ic][jc] && (!(ic == x && jc == y))){
            int dist = modul (ic-x) + modul (jc-y);
            sol = min (sol,dist);
        }
        ic += diri, jc += dirj;
        idx++;
    }
    cout<<minix<<" "<<miniy<<" "<<maxix<<" "<<maxiy;

    fout<<sol;

    return 0;
}

