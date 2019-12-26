#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
struct idk{
    long long x,y,z,v1,v2,v3;
};
idk v[10],w[10];
unsigned long long pasx,pasy,pasz,pasv1,pasv2,pasv3;
int n,i,j;
inline long long modul (long long n){
    if (n < 0)
        return -n;
    return n;
}
unsigned long long gcd (unsigned long long a, unsigned long long b){
    unsigned long long r = 0;
    while (b){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
unsigned long long cmmmc (unsigned long long a, unsigned long long b){
    return a*b / gcd (a,b);
}
int main (){

    n = 4;
    for (i=1;i<=n;i++){
        fin>>v[i].x>>v[i].y>>v[i].z;
        w[i] = v[i];
    }

    for (int pas=1;pas<=1000;pas++){

        for (i=1;i<n;i++){
            for (j=i+1;j<=n;j++){
                if (v[i].x != v[j].x){
                    if (v[i].x < v[j].x)
                        v[i].v1++, v[j].v1--;
                    else v[i].v1--, v[j].v1++;
                }
                if (v[i].y != v[j].y){
                    if (v[i].y < v[j].y)
                        v[i].v2++, v[j].v2--;
                    else v[i].v2--, v[j].v2++;
                }
                if (v[i].z != v[j].z){
                    if (v[i].z < v[j].z)
                        v[i].v3++, v[j].v3--;
                    else v[i].v3--, v[j].v3++;
                }
            }}
        for (i=1;i<=n;i++){
            v[i].x += v[i].v1;
            v[i].y += v[i].v2;
            v[i].z += v[i].v3;
        }
    }
    unsigned long long energ_pot = 0, energ_cin = 0, sol = 0;
    for (i=1;i<=n;i++){
        energ_pot = modul (v[i].x) + modul (v[i].y) + modul (v[i].z);
        energ_cin = modul (v[i].v1) + modul (v[i].v2) + modul (v[i].v3);
        sol += energ_pot * energ_cin;
    }
    fout<<sol;


    return 0;
}

