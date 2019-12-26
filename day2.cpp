#include <bits/stdc++.h>

using namespace std;
ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000];
int v[1000],w[1000];
int n,i,j,nr,k;
int main (){

    fin>>s;
    n = strlen (s);
    k = -1;
    for (i=0;i<n;i++){
        if (s[i] == ','){
            v[++k] = nr;
            nr = 0;
        }
        else {
            nr = nr*10 + s[i] - '0';
        }
    }
    v[++k] = nr;

    /// copiez si in w
    for (i=0;i<=k;i++)
        w[i] = v[i];

    /// part 1
    v[1] = 12, v[2] = 2;
    for (i=0;i<=k;i+=4){
        if (v[i] == 1){
            int poza = v[i+1], pozb = v[i+2], poz = v[i+3];
            v[poz] = v[poza] + v[pozb];
        } else {
            if (v[i] == 2){
                int poza = v[i+1], pozb = v[i+2], poz = v[i+3];
                v[poz] = v[poza] * v[pozb];
            } else {
                if (v[i] == 99)
                    break;
            }}}
    fout<<v[0]<<"\n";

    /// part 2
    for (int val=0;val<=99;val++){
        for (int val2=0;val2<=99;val2++){
            for (int i=0;i<=k;i++)
                v[i] = w[i];
            v[1] = val, v[2] = val2;
            for (i=0;i<=k;i+=4){
                if (v[i] == 1){
                    int poza = v[i+1], pozb = v[i+2], poz = v[i+3];
                    v[poz] = v[poza] + v[pozb];
                } else {
                    if (v[i] == 2){
                        int poza = v[i+1], pozb = v[i+2], poz = v[i+3];
                        v[poz] = v[poza] * v[pozb];
                    } else {
                        if (v[i] == 99)
                            break;
                    }}}
            if (v[0] == 19690720){
                fout<<100*val + val2;
                return 0;
            }}}


    return 0;
}
