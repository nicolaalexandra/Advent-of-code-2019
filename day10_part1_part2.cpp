#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int a[50][50];
int n,i,maxi,j,soli,solj,ox,oy,k;
pair <int,int> v[1000000];
char ch;
inline int gcd (int a, int b){
    int r = 0;
    while (b){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int modul (int n){
    if (n < 0)
        return -n;
    return n;
}
int verif (int x, int y, int x2, int y2){
    if (x < x2){
        swap (x,x2);
        swap (y,y2);
    } else {
        if (x == x2 && y < y2)
            swap (y,y2);
    }
    int difx = modul(x-x2);
    int dify = modul(y-y2);
    int val = modul(gcd (difx, dify));
    difx /= val, dify /= val;
    int semn;
    if (y > y2)
        semn = 1;
    else semn = -1;
    //while (x >= 1 && y >= 1 && x <= n && y <= n)
    int ok = 1;
    while (1){
        x -= difx, y -= dify*semn;
        if (x == x2 && y == y2)
            break;
        if (a[x][y] == 1){
            ok = 0;
            break;
        }

    }
    return ok;

}
int cadran (pair<int,int> p){
    if (p.x <= ox && p.y >= oy)
        return 4;
    if (p.x <= ox && p.y < oy)
        return 1;
    if (p.x > ox && p.y < oy)
        return 2;
    return 3;
}

int aria (pair <int,int> a, pair <int,int> b){
    return a.x * b.y - b.x * a.y;
}

int distantaOrigine (pair<int,int> a){
    return (a.x - ox) * (a.x - ox) + (a.y - oy) * (a.y - oy);
}

int det(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
    return (X2-X1)*(Y3-Y1) - (Y2-Y1)*(X3-X1);
}

int cmp (pair <int,int> a,pair <int,int> b){
    int c1 = cadran (a);
    int c2 = cadran (b);
    if (c1 != c2)
        return c1 < c2;

    int aria1 = det (ox,oy,a.x,a.y,b.x,b.y);
    if (aria1 != 0)
        return aria1 > 0;

    return distantaOrigine(a) > distantaOrigine(b); /// dist mai maree

}
int main (){

    n = 20;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++){
            fin>>ch;
            if (ch == '#')
                a[i][j] = 1;
            else a[i][j] = 0;
        }

    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++){
            if (!a[i][j])
                continue;
            //if (i == 5 && j == 4)
              //  i = 5;
            int sol = 0;
            for (int lin=1;lin<=n;lin++)
                for (int col=1;col<=n;col++){
                    if (lin == i && col == j)
                        continue;
                    if (a[lin][col])
                        sol += verif (i,j,lin,col);
                }
            if (sol > maxi){
                maxi = sol;
                soli = i;
                solj = j;
            }
            //maxi = max (maxi,sol);
        }

    fout<<maxi<<" "<<soli<<" "<<solj<<"\n";

    /// part 2

    ox = soli, oy = solj;
    pair <int,int> ans = make_pair(-1,-1);
    int nr = 0;
    for (;;){
        k = 0;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++){
                if (i == ox && j == oy)
                    continue;
                if (a[i][j])
                    v[++k] = make_pair(i,j);
            }
        if (!k)
            break;
        sort (v+1,v+k+1,cmp);
        for (i=k;i;i--){
            if (i == 1 || det (ox,oy,v[i].first,v[i].second,v[i-1].first,v[i-1].second) != 0){
                nr++;
                a[v[i].first][v[i].second] = 0;
                if (nr == 200){
                    ans = v[i];
                    break;
                }}}
        if (ans.first != -1)
            break;

    }
    fout<<(ans.second-1)*100 + ans.first-1;

    return 0;
}
