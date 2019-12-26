#include <bits/stdc++.h>
#define DIM 200
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char a[DIM][DIM];
vector <pair<int,int> > b[DIM][DIM];
deque <pair<int,int> > c;
int dp[DIM][DIM],dp2[DIM][DIM][DIM];
pair <int,int> poz[DIM][DIM];
int n,i,j,x,y,x2,y2,xstart,ystart,xfin,yfin;
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
struct idk{
    int x,y,level;
};
deque <idk> d;
inline int inmat (int i, int j){
    if (i >= 1 && i <= n && j >= 1 && j <= n)
        return 1;
    return 0;
}
int get_tip (int i, int j){
    if (i <= 2 || i >= 130)
        return -1;
    if (j <= 2 || j >= 130)
        return -1;
    return 1;
}
int main (){

    n = 131;
    for (i=1;i<=n;i++)
        fin.getline(a[i]+1,DIM);

    /// gasesc portalele
    for (j=1;j<=n;j++){
        if (a[1][j] >= 'A' && a[1][j] <= 'Z'){
            char ch1 = a[1][j], ch2 = a[2][j];
            if (ch1 > ch2) swap (ch1,ch2);
            b[ch1][ch2].push_back(make_pair(3,j));
        }
        if (a[n][j] >= 'A' && a[n][j] <= 'Z'){
            char ch1 = a[n][j], ch2 = a[n-1][j];
            if (ch1 > ch2) swap (ch1,ch2);
            b[ch1][ch2].push_back(make_pair(n-2,j));
        }
    }
    for (i=1;i<=n;i++){
        if (a[i][1] >= 'A' && a[i][1] <= 'Z'){
            char ch1 = a[i][1], ch2 = a[i][2];
            if (ch1 > ch2) swap (ch1,ch2);
            b[ch1][ch2].push_back(make_pair(i,3));
        }
        if (a[i][n] >= 'A' && a[i][n] <= 'Z'){
            char ch1 = a[i][n], ch2 = a[i][n-1];
            if (ch1 > ch2) swap (ch1,ch2);
            b[ch1][ch2].push_back(make_pair(i,n-2));
        }
    }

    for (j=1;j<=n;j++){
        i = 38;
        if (a[i][j] >= 'A' && a[i][j] <= 'Z'){
            char ch1 = a[i][j], ch2 = a[i+1][j];
            if (ch1 > ch2) swap (ch1,ch2);
            b[ch1][ch2].push_back(make_pair(i-1,j));
        }
        i = 94;
        if (a[i][j] >= 'A' && a[i][j] <= 'Z'){
            char ch1 = a[i][j], ch2 = a[i-1][j];
            if (ch1 > ch2) swap (ch1,ch2);
            b[ch1][ch2].push_back(make_pair(i+1,j));
        }
    }

    for (i=1;i<=n;i++){
        j = 38;
        if (a[i][j] >= 'A' && a[i][j] <= 'Z'){
            char ch1 = a[i][j], ch2 = a[i][j+1];
            if (ch1 > ch2) swap (ch1,ch2);
            b[ch1][ch2].push_back(make_pair(i,j-1));
        }
        j = 94;
        if (a[i][j] >= 'A' && a[i][j] <= 'Z'){
            char ch1 = a[i][j], ch2 = a[i][j-1];
            if (ch1 > ch2) swap (ch1,ch2);
            b[ch1][ch2].push_back(make_pair(i,j+1));
        }
    }

    for (i=65;i<=90;i++){
        for (j=i+1;j<=90;j++){
            if (b[i][j].empty())
                continue;
            if (i == 69 && j == 84)
                i = 69;
            x = b[i][j][0].first, y = b[i][j][0].second;
            x2 = b[i][j][1].first, y2 = b[i][j][1].second;
            poz[x][y] = make_pair(x2,y2);
            poz[x2][y2] = make_pair(x,y);
        }
    }

    xstart = 46, ystart = 129;
    xfin = 129, yfin = 82;

    c.push_back(make_pair(xstart,ystart));
    dp[xstart][ystart] = 1;
    while (!c.empty()){
        int ic = c.front().first;
        int jc = c.front().second;
        c.pop_front();
        /// mai intai ma deplasez normal
        for (int dir=0;dir<=3;dir++){
            int iv = ic + di[dir];
            int jv = jc + dj[dir];
            if (!inmat(iv,jv) || a[iv][jv] == '#')
                continue;
            if (a[iv][jv] == '.'){
                if (!dp[iv][jv]){
                    dp[iv][jv] = 1 + dp[ic][jc];
                    c.push_back(make_pair(iv,jv));
                }
            } else {
                if (a[iv][jv] >= 'A' && a[iv][jv] <= 'Z'){
                    /// ma aflu langa un portal
                    int ii = poz[ic][jc].first, jj = poz[ic][jc].second;
                    if (inmat(ii,jj) && !dp[ii][jj]){
                        dp[ii][jj] = 1 + dp[ic][jc];
                        c.push_back(make_pair(ii,jj));
                    }}}}}

    fout<<dp[xfin][yfin]-1<<"\n"; /// part 1

    /// portalele de pe margine imi scad nivelul cu 1, iar cele din interior il cresc
    d.push_back({xstart,ystart,0});
    dp2[xstart][ystart][0] = 1;
    while (!d.empty()){
        int ic = d.front().x;
        int jc = d.front().y;
        int level = d.front().level;
        d.pop_front();
        for (int dir=0;dir<=3;dir++){
            int iv = ic + di[dir];
            int jv = jc + dj[dir];
            if (!inmat(iv,jv) || a[iv][jv] == '#')
                continue;
            if (a[iv][jv] == '.'){
                if (!dp2[iv][jv][level]){
                    dp2[iv][jv][level] = 1 + dp2[ic][jc][level];
                    d.push_back({iv,jv,level});
                }
            } else {
                if (a[iv][jv] >= 'A' && a[iv][jv] <= 'Z'){
                    /// ma aflu langa un portal
                    int ii = poz[ic][jc].first, jj = poz[ic][jc].second;
                    if (!inmat(ii,jj))
                        continue;
                    int tip = get_tip (iv,jv); /// vreau sa aflu daca imi creste sau imi scade nivelul
                    if (tip == 1){
                        /// creste
                        if (!dp2[ii][jj][level+1]){
                            dp2[ii][jj][level+1] = 1 + dp2[ic][jc][level];
                            d.push_back({ii,jj,level+1});
                        }
                    } else {
                        if (level && !dp2[ii][jj][level-1]){
                            dp2[ii][jj][level-1] = 1 + dp2[ic][jc][level];
                            d.push_back({ii,jj,level-1});
                        }}}}}}

    fout<<dp2[xfin][yfin][0]-1;

    return 0;
}
