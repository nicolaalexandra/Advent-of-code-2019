#include <bits/stdc++.h>
#define DIM 1000000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[DIM];
int n,i,k,j,nr,op,sol,semn,val,val2,poz1,poz2,poz3,maxi,op4;
int x[11],f[11],d[11],OK[11],cif[7];
int v[DIM],w[DIM];
void solve(int val, int input, int idx){

    i = 0;
    for (;;){
        if (i > k)
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
            if (!OK[idx]){
                v[v[i+1]] = val;
                OK[idx] = 1;
            } else v[v[i+1]] = input;
            i += 2;
            continue;
        }
        if (op == 4){
            sol = v[v[i+1]];
            op4 = 1;
            i += 2;
            break;
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
            continue;
        }
        break; /// upcode pe care nu il stiu
    }
   // return sol;

}

void back (int pas){
    if (pas == 6){
        /// am o permutare
        /// inputul pt A e 0 DOAR PRIMA DATA
        for (int i=0;i<=k;i++)
            v[i] = w[i];
        int input,output;
        input = 0;
        int lastE;

        OK[1] = OK[2] = OK[3] = OK[4] = OK[5] = 0; /// sa stiu daca trb prima sau a dpua instructiune folosita


        for (int idx=1;idx<=5;idx++){
            sol = 0;

            solve (x[idx],input,idx);

            output = sol;
            input = output;
        }

        maxi = max (maxi,output);
        return;
    }
    for (int i=0;i<=4;i++){
        if (f[i] == 0){
            f[i] = 1;
            x[pas] = i;
            back (pas+1);
            f[i] = 0;
        }
    }
}
int main (){

    fin>>s;
    n = strlen (s);
    k = -1, semn = 1;
    for (i=0;i<n;i++){
        if (s[i] == '-')
            semn = -1;
        else {
            if (s[i] == ','){
                w[++k] = nr*semn;
                nr = 0;
                semn = 1;
            }
            else {
                nr = nr*10 + s[i] - '0';
            }
        }
    }
    w[++k] = nr;
    maxi = 0;
    back(1);
    fout<<maxi;



    return 0;
}


