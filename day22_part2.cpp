#include <bits/stdc++.h>
#define DIM 100010
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int A[100],B[100],C[100],v[100];
char s[100];
int t,i,j;
long long n,idx,m,a,b,a_nxt,b_nxt;
vector <pair<int,long long> > op;
map <long long, long long> mp;


void get_cifr (long long nr, int A[]){
    A[0] = 0;
    while (nr){
        A[++A[0]] = nr%10;
        nr /= 10;
    }
}
void inmultire_nr_mari (int A[], int B[], int C[]){
    int i,j,t;
    C[0] = A[0] + B[0] - 1;
    for (i=1;i<=A[0]+B[0];)
        C[i++]=0;
    for (i=1;i<=A[0];i++)
        for (j=1;j<=B[0];j++)
            C[i+j-1] += A[i]*B[j];
    t = 0;
    for (i=1;i<=C[0];i++){
        C[i] += t;
        t = C[i]/10;
        C[i]%=10;
    }
    while (t){
        C[++C[0]] = t;
        t /= 10;
    }
}
long long get_rest (int A[], long long n){
    long long rest = 0;
    for (int i=A[0];i;i--)
        rest = (rest*10+A[i])%n;

    return rest;
}
long long inmultire (long long x, long long y){
    get_cifr (x,A);
    get_cifr (y,B);
    /// acum trb sa facem inmultire de numere mari
    inmultire_nr_mari (A,B,C);
    /// acum trebuie sa aflam restul impartirii la n
    return get_rest (C,n);
}
long long lg_put (long long baza, long long exp){
    long long ans = 1;
    while (exp){
        if (exp%2)
            ans = inmultire(ans,baza);
        baza = inmultire(baza,baza);
        exp >>= 1;
    }
    return ans;
}
void deal_into_new_stack (long long &x){
    x = n-x-1;
}
void deal_with_increment (long long &x, long long &val){
    x = (x*val)%n;
}
void cut (long long &x, long long &val){
    if (val <= 0){ /// de la sfarsit
        val *= -1;
        if (n-x <= val)
            x = (val - n + x)%n;
        else x = (x+val)%n;

    } else { /// de la inceput
        if (x < val)
            x = (n-val+x)%n;
        else x = (x-val)%n;
    }
}

long long solve (long long x){

    for (int i=0;i<op.size();i++){
        long long tip = op[i].first, val = op[i].second;
        if (tip == 1){ /// deal with increment
            deal_with_increment(x,val);
        } else {
            if (tip == 2){
                deal_into_new_stack(x);
            } else { /// cut
                cut (x,val);
            }}}
    return x;
}

int main (){

    t = 100;
    n = 119315717514047;
    m = 101741582076661;
    for (;t--;){
        fin.getline (s,100);
        if (s[0] == 'd' && s[5] == 'w'){
            int poz = 20;
            long long nr = 0;
            while (s[poz] >= '0' && s[poz] <= '9'){
                nr = nr*10 + s[poz] - '0';
                poz++;
            }
            op.push_back(make_pair(1,nr));
            //deal_with_increment(nr);
            continue;
        }
        if (s[0] == 'd'){
            //deal_into_new_stack();
            op.push_back(make_pair(2,0));
            continue;
        }
        /// am operatie de cut
        int semn = 1;
        long long nr = 0;
        int m = strlen (s);
        for (i=0;i<m;i++){
            if (s[i] == '-')
                semn = -1;
            if (s[i] >= '0' &&  s[i] <= '9')
                nr = nr*10 + s[i] - '0';
        }
        //cut (nr*semn);
        op.push_back(make_pair(3,nr*semn));
    }

    /// inversul modular al lui x la n, unde n e prim este: x^(n-2)

    /// f(x) = a*x + b;
    /// trb sa aflu a si b
    b = solve (0LL);
    a = solve (1LL);
    a = ((a-b)%n + n)%n;

    /// avem de calculat f(f(f(...x))) de m ori
    /*
    a * x + b
    a^2 * x + a * b + b
    a^3 * x + a^2 * b + a * b + b
    a^4 * x + a^3 * b + a^2 * b + a * b + b
    .
    .
    .
    a^N * x + (a^(N-1) + a^(N-2) + ... + 1) * b -> progresie geometrica
    (a^n - 1) / (a - 1)
    */
    /// trebuie sa fac operatii pe numere mari, pt ca depaseste long long:(
    a_nxt = lg_put (a,m);
    b_nxt = inmultire ( inmultire (a_nxt-1,lg_put(a-1,n-2)), b);
    long long sol = inmultire ( ((2020-b_nxt)%n + n)%n, lg_put(a_nxt,n-2) );
    fout<<sol;


    return 0;
}
