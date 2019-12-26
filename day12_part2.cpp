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
inline unsigned long long modul (unsigned long long n){
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

    for (int pas=1;;pas++){

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

        if (v[1].x == w[1].x && v[2].x == w[2].x && v[3].x == w[3].x && v[4].x == v[4].x && v[1].v1 == w[1].v1 && v[2].v1 == w[2].v1 && v[3].v1 == w[3].v1 && v[4].v1 == v[4].v1){
            if (!pasx)
                pasx = pas;
        }

        if (v[1].y == w[1].y && v[2].y == w[2].y && v[3].y == w[3].y && v[4].y == v[4].y && v[1].v2 == w[1].v2 && v[2].v2 == w[2].v2 && v[3].v2 == w[3].v2 && v[4].v2 == v[4].v2){
            if (!pasy)
                pasy = pas;
        }
        if (v[1].z == w[1].z && v[2].z == w[2].z && v[3].z == w[3].z && v[4].z == v[4].z && v[1].v3 == w[1].v3 && v[2].v3 == w[2].v3 && v[3].v3 == w[3].v3 && v[4].v3 == v[4].v3){
            if (!pasz)
                pasz = pas;
        }


        if (pasx && pasy && pasz)
            break;

    }

    long long sol;
    /*long long x = gcd (pasx,pasy);
    x = gcd (x,pasz);
    x = gcd (x,pasv1);
    x = gcd (x,pasv2);
    x = gcd (x,pasv3);
    sol = pasx*pasy*pasz*pasv1*pasv2*pasv3 / x;*/
    sol = cmmmc (pasx,pasy);
    sol = cmmmc (sol,pasz);

    fout<<sol;





    return 0;
}
