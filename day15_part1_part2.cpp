#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000000];
int n,i,k,j,cif[6],op,semn,cnt,ans,isol,jsol,maxi;
int d[2000][2000],viz[2000][2000],a[2000][2000];
deque <pair<int,int> > c;
long long val,val2,poz1,poz2,poz3,nr,sol,base,w[1000000];
map <long long,long long> v;
int di[] = {0,-1,1,0,0};
int dj[] = {0,0,0,-1,1};
int get_next (int input, int &i){
    //i = 0, base = 0;
    //for (i=0;i<=k;i++)
      //  v[i] = w[i];
    long long sol = -1, cnt = 0;
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
        if (i == 249)
            i = 249;
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
            cnt++;
            if (cnt > 1)
                return -1;
            v[poz1] = input;
            //cnt++;
            i += 2;
            continue;
        }
        if (op == 4){
            sol = v[poz1];
            i += 2;
            break;
            //continue;
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
void dfs (int ic, int jc, map<long long,long long> w, int poz){
    //if (ans) de data asta trebuie sa umplu toata matricea
       // return;
    for (int dir=1;dir<=4;dir++){
        int iv = ic + di[dir];
        int jv = jc + dj[dir];
        if (viz[iv][jv])
            continue;

        for (j=0;j<=k;j++)
            v[j] = w[j];
        int val = get_next (dir,poz);

        if (val == 0)
            viz[iv][jv] = 1;
        if (val == 1){
            viz[iv][jv] = 1;
            d[iv][jv] = 1+d[ic][jc];
            dfs (iv,jv,v,poz);
        }
        if (val == 2){
            viz[iv][jv] = 1;
            d[iv][jv] = 1+d[ic][jc];
            if (!ans){
                ans = d[iv][jv];
                isol = iv, jsol = jv;
            }
            //return;
        }
    }
}
void bfs (int istart, int jstart){
    c.clear();
    c.push_back(make_pair(istart,jstart));
    a[istart][jstart] = 1;
    while (!c.empty()){
        int ic = c.front().first;
        int jc = c.front().second;
        c.pop_front();
        for (int dir=1;dir<=4;dir++){
            int iv = ic + di[dir];
            int jv = jc + dj[dir];
            if (d[iv][jv] == 0)
                continue;
            if (a[iv][jv] == 0){
                a[iv][jv] = 1+a[ic][jc];
                maxi = max (maxi,a[iv][jv]);
                c.push_back(make_pair(iv,jv));
            }}}}
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
    i = base = 0;
    d[30][30] = 1;
    dfs (30,30,v,0);
    fout<<ans-1<<"\n";
    bfs (isol,jsol);
    /*for (i=1;i<=50;i++){
        for (j=1;j<=50;j++)
            fout<<a[i][j]<<"   ";
        fout<<"\n";
    }*/
    fout<<maxi-1;

    return 0;
}

