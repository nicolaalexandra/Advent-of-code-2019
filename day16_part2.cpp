#include <bits/stdc++.h>

#define DIM 7000000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int d[] = {0,1,0,-1};
int v[DIM],w[DIM];
char s[DIM];
long long sp[DIM];
int n,i,j,pas,sol,k;
int main (){

    fin>>s+1;
    n = strlen (s+1);
    int nr = 0;
    for (i=1;i<=n;++i){
        v[i] = s[i] - '0';
        if (i <= 7)
            nr = nr*10 + v[i];
    }
    k = n;
    for (i=1;i<=10000;++i){
        for (j=1;j<=n;++j)
            v[++k] = v[j];
    }
    n = k;


    for (pas=1;pas<=100;++pas){
        for (i=1;i<=n;i++)
            sp[i] = sp[i-1] + v[i];
        for (i=1;i<=n;i++){
            int poz = 0;
            long long sum = 0;
            for (j=i;j<=n;j+=i){
                poz++;
                if (poz == 4)
                    poz = 0;
                sum += 1LL*(sp[min(j+i-1,n)] - sp[j-1])*d[poz];
            }
            if (sum < 0)
                sum *= -1;
            v[i] = sum%10;
        }
        cout<<pas<<"\n";
    }

    for (i=nr+1;i<=nr+8;i++)
        fout<<v[i];



    return 0;
}
