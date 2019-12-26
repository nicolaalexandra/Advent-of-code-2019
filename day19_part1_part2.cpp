#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000000];
int n,i,ii,jj,k,j,cif[6],op,semn,a[20000][20000];
long long val,val2,poz1,poz2,poz3,nr,sol;
map <long long,long long> v,w;
map <int,int> f[100000];
deque <int> d;
int solve (){
    for (int i=0;i<=k;i++)
        v[i] = w[i];
    int i = 0, base = 0;
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
            if (!d.empty()){
                //break;
                v[poz1] = d.back();
                d.pop_back();
            }
            i += 2;
            continue;
        }
        if (op == 4){
            sol = v[poz1];
            i += 2;
            break;
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
    return sol;
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
    int ans = 0;
    for (i=0;i<=49;i++)
        for (j=0;j<=49;j++){
            d.clear();
            d.push_back(i);
            d.push_back(j);
            ans += solve();
        }
    fout<<ans<<"\n";
    /// part 2
    /*for (i=0;i<=100;i++)
        for (j=0;j<=100;j++){
            d.clear();
            d.push_back(i);
            d.push_back(j);
            a[i][j] = solve();
        }

    for (i=0;i<=100;i++,fout<<"\n")
        for (j=0;j<=100;j++)
            if (a[i][j])
                fout<<"#";
            else fout<<".";*/

    for (i=700;i<25000;i++){ /// intuitia nu tradeaza niciodata
        int ok = 0;
        for (j=100;j<25000;j++){
            d.clear(), d.push_back(i),d.push_back(j);
            val = solve();
            cout<<i<<" "<<j<<" "<<val<<"\n";
            if (val == 0 && ok)
                break;
            if (val == 1){
                ok = 1;
                d.clear(), d.push_back(i-100+1),d.push_back(j-100+1);
                int val2 = solve();
                if (val2 == 0)
                    continue;
                d.clear(), d.push_back(i-100+1),d.push_back(j);
                int val3 = solve();
                if (val3 == 0)
                    continue;
                d.clear(), d.push_back(i),d.push_back(j-100+1);
                int val4 = solve();
                if (val4 == 0)
                    continue;
                /// am gasit zona
                fout<<i<<" "<<j<<" "<<(j-99)*10000+i-99;
                return 0;
            }
        }
    }


    return 0;
}
