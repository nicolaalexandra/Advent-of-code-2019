#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000000000];
int n,i,j,idx,k,mini,sol,b[30][30],a[1000][30][30];
int main (){

    fin>>s+1;
    n = strlen (s+1);
    idx = 1;
    mini = 2000000000;
    for (;s[idx] != NULL;){
        int nr0 = 0, nr1 = 0, nr2 = 0;
        k++;
        for (i=1;i<=6;i++)
            for (j=1;j<=25;j++){
                a[k][i][j] = s[idx] - '0';
                if (s[idx] == '0')
                    nr0++;
                if (s[idx] == '1')
                    nr1++;
                if (s[idx] == '2')
                    nr2++;
                idx++;
            }
        if (nr0 < mini){
            mini = nr0;
            sol = nr1*nr2;
        }
        if (idx > n)
            break;
    }
    fout<<sol<<endl;


    for (i=1;i<=6;i++)
        for (j=1;j<=25;j++){
            /// vreau sa determin pixelul de la i,j
            int last = 0;
            for (int x=k;x;x--){
                if (a[x][i][j] != 2)
                    last = a[x][i][j];
            }

            b[i][j] = last;
        }

    for (i=1;i<=6;i++,fout<<endl)
        for (j=1;j<=25;j++)
            fout<<b[i][j]<<" ";




    return 0;
}
