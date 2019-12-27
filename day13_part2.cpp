#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000000];
int n,i,k,j,cif[6],op,semn;
long long val,val2,poz1,poz2,poz3,nr,sol,base,y,x,p,b;
//long long v[1000000];
map <long long,long long> v;
deque <long long> input,output;
int get_next (){
    int sol = -1;
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
            if (input.empty())
                return 0;
            v[poz1] = input.front();
            input.pop_front();
            i += 2;
            continue;
        }
        if (op == 4){
            output.push_back(v[poz1]);
            //sol = v[poz1];
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
        return 0;
    }
    return 1; /// e ok
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
            }
        }
    }
    v[++k] = nr;
    base = 0;
    i = 0;
    int ans = 0;

    for (;;){
        int ok = 1;
        do{
            ok = get_next();
        } while (ok);

        while (!output.empty()){
            x = output.front(), output.pop_front();
            y = output.front(), output.pop_front();
            val = output.front(), output.pop_front();

            if (val == 3) /// paddle
                p = x;
            else {
                if (val == 4) /// ball
                    b = x;
            }
            if (x == -1 && y == 0)
                cout<<val<<endl;
        }
        if (p == b)
            input.push_back(0);
        else {
            if (p < b)
                input.push_back(1);
            else input.push_back(-1);
        }
    }


    return 0;
}


