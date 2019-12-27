#include <bits/stdc++.h>
#define DIM 1000
#define INF 2000000000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000000];
int n,i,k,j,cif[6],op,semn;
long long val,val2,poz1,poz2,poz3,nr,sol,base,ok;
long long x,y,dirx,diry,dir,cul;
map <long long,long long> v;
long long a[10000][10000];
long long get_next(long long input){
    long long ans = -1;
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
            v[poz1] = input;
            //v[poz1] = 1;
            i += 2;
            continue;
        }
        if (op == 4){
            ans = v[poz1];
            i += 2;
            //return v[poz1];
            //continue;
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
    return ans;
}

void change_dir (){
    /// 0 - stanga, 1 dreapta
    if (dir == 0){ /// stanga..
        if (dirx == -1 && diry == 0)
            dirx = 0, diry = -1;
        else{
            if (dirx == 1 && diry == 0)
                dirx = 0, diry = 1;
            else {
                if (dirx == 0 && diry == -1)
                    dirx = 1, diry = 0;
                else dirx = -1, diry = 0;
            }
        }

    } else { /// dreapta..

        if (dirx == -1 && diry == 0)
            dirx = 0, diry = 1;
        else{
            if (dirx == 1 && diry == 0)
                dirx = 0, diry = -1;
            else {
                if (dirx == 0 && diry == -1)
                    dirx = -1, diry = 0;
                else dirx = 1, diry = 0;
            }
        }
    }
}
int main (){

    fin>>s;
    n = strlen (s);
    k = -1, semn = 1, nr = 0;
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

    base = 0, i = 0;
    /// 0 negru 1 alb
    /// 1 negru 2 alb
    x = 0, y = 0, dirx = -1, diry = 0, ok = 0;
    int sol = 0;
    long long xmin = INF, ymin = INF;
    for (;;){
        long long nr = a[x][y];
        if (nr == 2)
            nr = 1;
        else nr = 0;

        if (!ok){
            /// nr = 0; -> pentru partea 1
            nr = 1; /// pentru partea a doua
            ok = 1;
        }
        cul = get_next(nr);
        dir = get_next(nr);
        if (cul == -1 || dir == -1)
            break;

        if (a[x][y] == 0) /// nu a mai fost vizitat
            sol++;
        /// modific culoarea celui curent
        if (cul == 0)
            a[x][y] = 1;
        else a[x][y] = 2;

        /// ma deplasez
        change_dir ();
        x += dirx, y += diry;
    }
    for (i=0;i<=8;i++){
        for (j=0;j<=50;j++){
            if (a[i][j] == 2)
                fout<<"#";
            else fout<<" "; }
        fout<<"\n";
    }
    fout<<sol;




    return 0;
}


