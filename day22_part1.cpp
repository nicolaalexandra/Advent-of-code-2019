#include <bits/stdc++.h>
#define DIM 100010
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int v[DIM],w[DIM];
char s[100];
int n,t,i,j;
void deal_into_new_stack(){
    int k = -1;
    for (i=n;i>=0;i--)
        w[++k] = v[i];
    for (i=0;i<=n;i++)
        v[i] = w[i];
}
void deal_with_increment (int x){
    int poz = 0;
    for (i=0;i<=n;i++){
        w[poz] = v[i];
        poz += x;
        poz %= (n+1);
    }
    for (i=0;i<=n;i++)
        v[i] = w[i];
}
void cut (int x){
    int k = -1;
    if (x > 0){
        for (i=x;i<=n;i++)
            w[++k] = v[i];
        for (i=0;i<x;i++)
            w[++k] = v[i];
    } else {
        x *= -1;
        for (i=n-x+1;i<=n;i++)
            w[++k] = v[i];
        for (i=0;i<=n-x;i++)
            w[++k] = v[i];
    }
    for (i=0;i<=n;i++)
        v[i] = w[i];
}
int main (){

    t = 100;
    n = 10006;
    //n = 9;
    for (i=0;i<=n;i++)
        v[i] = i;
    for (;t--;){
        fin.getline (s,100);
        if (s[0] == 'd' && s[5] == 'w'){
            int poz = 20, nr = 0;
            while (s[poz] >= '0' && s[poz] <= '9'){
                nr = nr*10 + s[poz] - '0';
                poz++;
            }
            deal_with_increment(nr);
            continue;
        }
        if (s[0] == 'd'){
            deal_into_new_stack();
            continue;
        }
        /// am operatie de cut
        int semn = 1, nr = 0;
        int m = strlen (s);
        for (i=0;i<m;i++){
            if (s[i] == '-')
                semn = -1;
            if (s[i] >= '0' &&  s[i] <= '9')
                nr = nr*10 + s[i] - '0';
        }
        cut (nr*semn);
    }
    for (i=0;i<=n;i++){
        if (v[i] == 2019){
            fout<<i;
            break;
        }
        //fout<<v[i]<<"\n";
    }


    return 0;
}
