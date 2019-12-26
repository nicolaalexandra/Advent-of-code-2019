#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000000];
int n,i,k,j,nr,cif[6],op,sol,semn,val,val2,poz1,poz2,poz3;
long long v[1000000];
int main (){

    fin>>s;
    n = strlen (s);
    k = -1, semn = 1;
    for (i=0;i<n;i++){
        if (s[i] == '-')
            semn = -1;
        else {
            if (s[i] == ','){
                v[++k] = nr*semn;
                nr = 0;
                semn = 1;
            }
            else {
                nr = nr*10 + s[i] - '0';
            }
        }
    }
    v[++k] = nr;

    int i = 0;
    for (;;){
        if (i > n)
            break;
        cif[1] = cif[2] = cif[3] = cif[4] = cif[5] = 0;
        int nr = v[i], poz = 5;
        while (nr > 0){
            cif[poz] = nr%10;
            poz--;
            nr /= 10;
        }
        op = cif[4]*10 + cif[5];
        if (op == 99)
            break;
        /// 0  pozitie, 1 valoare
        if (op == 3){
            v[v[i+1]] = 5;
            i += 2;
            continue;
        }
        if (op == 4){
            fout<<v[v[i+1]];
            i += 2;
            continue;
        }

        if (cif[3] == 0)
            poz1 = v[i+1];
        else poz1 = i+1;

        if (cif[2] == 0)
            poz2 = v[i+2];
        else poz2 = i+2;

        if (cif[1] == 0)
            poz3 = v[i+3];
        else poz3 = i+3;

        if (op == 1){
            v[poz3] = v[poz1] + v[poz2];
            i += 4;
            continue;
        }
        if (op == 2){
            v[poz3] = v[poz1] * v[poz2];
            i += 4;
            continue;
        }
        if (op == 5){
            if (v[poz1])
                i = v[poz2];
            else i += 3;

            continue;
        }
        if (op == 6){
            if (v[poz1] == 0)
                i = v[poz2];
            else i += 3;

            continue;
        }
        if (op == 7){
            v[poz3] = (v[poz1] < v[poz2]);
            i += 4;
            continue;
        }
        if (op == 8){
            v[poz3] = (v[poz1] == v[poz2]);
            i += 4;
        }
    }


    return 0;
}
