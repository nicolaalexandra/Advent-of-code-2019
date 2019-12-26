#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000000];
int n,i,ii,jj,k,j,cif[6],op,semn;
long long val,val2,poz1,poz2,poz3,nr,sol,base;
map <long long,long long> v,w;
map <int,int> f[100000];
deque <int> d;
long long solve (){
    long long sol = -1;
    for (;;){
        if (i > k)
            break;
        cif[1] = cif[2] = cif[3] = cif[4] = cif[5] = 0;
        int poz = 5;
        long long nr = v[i];
        while (nr > 0){
            cif[poz] = nr%10;
            poz--;
            nr /= 10;
        }
        op = cif[4]*10 + cif[5];
        if (op == 99)
            break;
        /// 0  pozitie, 1 valoare, 2 - base
        if (cif[3] == 0)
            poz1 = v[i+1];
        else {
            if (cif[3] == 1)
                poz1 = i+1;
            else poz1 = base + v[i+1];
        }

        if (cif[2] == 0)
            poz2 = v[i+2];
        else {
            if (cif[2] == 1)
                poz2 = i+2;
            else poz2 = base + v[i+2];
        }
        if (cif[1] == 0)
            poz3 = v[i+3];
        else {
            if (cif[1] == 1)
                poz3 = i+3;
            else poz3 = base + v[i+3];
        }

        if (op == 3){
            v[poz1] = d.front();
            d.pop_front();
            i += 2;
            continue;
        }
        if (op == 4){
            sol = v[poz1];
            if (v[poz1] > 127)
                fout<<v[poz1]<<" ";
            i += 2;
            //break;
            continue;
        }

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
        if (op == 9){
            /// mi se schimba baza
            base += v[poz1];
            i += 2;
            continue;
        }
        break;
    }
    if (sol > 127)
        return sol;
}
void add_inputs (string c){
    for (int i=0;i<c.size();i++)
        d.push_back(c[i]);
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
                v[++k] = nr*semn;
                nr = 0;
                semn = 1;
            }
            else {
                nr = nr*10 + s[i] - '0';
            }}}
    v[++k] = nr;
    i = 0, base = 0;

    string c;

    c = "NOT A T\n"; add_inputs(c);
    c = "OR T J\n"; add_inputs(c);
    c = "NOT B T\n"; add_inputs(c);
    c = "OR T J\n"; add_inputs(c);
    c = "NOT C T\n"; add_inputs(c);
    c = "OR T J\n"; add_inputs(c);
    c = "AND D J\n"; add_inputs(c);

    c = "WALK\n"; add_inputs(c);
    solve();




    return 0;
}


