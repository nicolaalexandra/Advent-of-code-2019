#include <bits/stdc++.h>
#define DIM 10000000
#define INF 2000000000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
vector <int> L[DIM];
deque <int> c;
int sp[DIM],viz[DIM],g[DIM],d[DIM];
char s[100];
int i,x,y,n,maxi,val,start,fi,sol;
void dfs (int nod, int niv){
    sol += niv;
    viz[nod] = sp[nod] = 1;
    for (int i=0;i<L[nod].size();i++){
        int vecin = L[nod][i];
        if (!viz[vecin]){
            dfs (vecin,niv+1);
        }
        sp[nod] += sp[vecin];
    }
}
int main (){

    while (fin>>s+1){
        n = strlen (s+1);
        int ok = 0;
        x = y = 0;
        for (i=1;i<=n;i++){
            if (s[i] == ')'){
                ok = 1;
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
                val = s[i]-'0' + 27;
            else val = s[i] - 'A' + 1;
            if (!ok)
                y = y*40 + val;
            else x = x*40 + val;
        }
        if (s[1] == 'C' && s[2] == 'O' && s[3] == 'M')
            s[1] = 'C';
        g[y]++;
        L[y].push_back(x);
        L[x].push_back(y);
        maxi = max (maxi,x);
        maxi = max (maxi,y);
    }

    /// COM are codul 5413
    dfs (5413,0);

    fout<<sol<<endl;


    /// part 2

    for (i=0;i<=maxi;i++)
        d[i] = INF;

    /// YOU are codul 40621 si SAN are 30454
    start = 40621, fi = 30454;
    c.push_back(start);
    d[start] = 0;
    while (!c.empty()){
        int nod = c.front();
        c.pop_front();
        for (auto vecin:L[nod]){
            if (d[vecin] == INF){
                d[vecin] = 1 + d[nod];
                if (vecin == fi){
                    fout<<d[vecin]-2;
                    return 0;
                }
                c.push_back(vecin);
            }
        }
    }

    return 0;
}
