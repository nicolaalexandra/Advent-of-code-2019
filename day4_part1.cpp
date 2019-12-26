#include <bits/stdc++.h>

using namespace std;
ifstream fin ("date.in");
ofstream fout ("date.out");
int i,k,j,ok,ok2,sol,v[12];
int main (){



    for (i=284639;i<=748759;i++){
        int x = i, k = 0;
        while (x){
            v[++k] = x%10;
            x /= 10;
        }
        for (j=1;j<=k/2;j++)
            swap (v[j],v[k-j+1]);
        int ok = 1, ok2 = 0;

        for (j=2;j<=k;j++){
            if (v[j] < v[j-1])
                ok = 0;
        }
        if (!ok)
            continue;

        int ap = 1;
        v[k+1] = 0;
        for (j=2;j<=k+1;j++){
            if (v[j] == v[j-1])
                ap++;
            else {
                if (ap >= 2)
                    ok2 = 1;
                ap = 1;
            }
        }

        if (ok2)
            sol++;
    }
    cout<<sol;


    return 0;
}

