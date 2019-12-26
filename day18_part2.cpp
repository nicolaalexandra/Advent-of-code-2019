/// observatie drumurile din matrice sunt aproape unice:)
/// observatie 2: pt partea a doua am 4 cadrane independente, deci rezolv separat:)
#include <bits/stdc++.h>
#define DIM 1000
#define INF 2000000000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[DIM];
int a[DIM][DIM],mrk[DIM][DIM];
priority_queue <pair<pair<int,int>,pair<int,int> >, vector<pair<pair<int,int>,pair<int,int> > >, greater<pair<pair<int,int>,pair<int,int> > > > H;
pair <int,int> t[DIM][DIM];
int n,m,i,j,xstart,ystart,sol,dist,x,y,imin,jmin,imax,jmax;
pair <int,int> poz[DIM];
map <int,int> viz[100][100],dp[100][100];
deque <pair<int,int> > d;
int di[] = {-1,1,0,0};
int dj[] = {0,0,-1,1};
struct stare{
    int x,y,mask;
};
deque <stare> c;

inline int inmat (int i, int j){
    if (i >= 1 && j >= 1 && i <= n && j <= n)
        return 1;
    return 0;
}

int verif (int x, int y, int ch, int mask, int imin, int jmin, int imax, int jmax, int mask_final){
    d.clear();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            mrk[i][j]  = 0;

    d.push_back (make_pair(x,y));
    mrk[x][y] = 1;
    int ok = 0, sol = 0;
    while (!d.empty()){
        int ic = d.front().first;
        int jc = d.front().second;
        d.pop_front();
        for (int dir=0;dir<=3;dir++){
            int iv = ic + di[dir];
            int jv = jc + dj[dir];
            if (!(iv >= imin && iv <= imax && jv >= jmin && jv <= jmax))
                continue;
            if (!mrk[iv][jv] && a[iv][jv] != -1){
                if (a[iv][jv] == ch){ /// am ajuns la cheia pe care o voiam
                    sol = mrk[ic][jc];
                    ok = 1;
                    break;
                }

                if (a[iv][jv] >= 65 && a[iv][jv] <= 90){ /// usa
                    int bit = a[iv][jv] - 65;
                    /// mai intai testez daca face parte din masca aia mare
                    if (mask_final&(1<<bit)){
                        if (!(mask&(1<<bit))) /// nu mi apare in masca deci nu am voie sa continui
                            continue;
                    }}
                if (a[iv][jv] >= 97 && a[iv][jv] <= 122){ /// cheie, trb sa ma asigur sa o am in matrice
                    int bit = a[iv][jv] - 97;
                    if (!(mask&(1<<bit)))
                        continue;
                }
                mrk[iv][jv] = 1 + mrk[ic][jc];

                d.push_back(make_pair(iv,jv));
            }}
        if (ok)
            break;
    }
    if (!ok)
        return -1;

    return sol;
}
int main (){

    n = 81;
    for (i=1;i<=n;i++){
        fin>>s+1;
        for (j=1;j<=n;j++){
            if (s[j] == '@')
                xstart = i, ystart = j;
            else {
                if (s[j] == '#')
                    a[i][j] = -1; /// mereu e blocat
                else {
                    if (s[j] == '.')
                        a[i][j] = 0;
                    else { /// litera
                        a[i][j] = s[j];
                        poz[s[j]] = make_pair(i,j);
                    }}}}}

    /// obs: robotii parcurg zone independente!!!! (am 4 cadrane)

    a[xstart-1][ystart] = a[xstart+1][ystart] = a[xstart][ystart-1] = a[xstart][ystart+1] = -1;
    /// bellman ford de 4 ori ieeei:)
    int sum = 0;
    for (int pas=1;pas<=4;pas++){
        if (pas == 1){
            x = xstart-1, y = ystart-1, imin = 1, jmin = 1, imax = x, jmax = y;
        } else {
            if (pas == 2){
                x = xstart-1, y = ystart+1, imin = 1, jmin = y, imax = x, jmax = n;
            } else {
                if (pas == 3)
                    x = xstart+1, y = ystart-1, imin = x, jmin = 1, imax = n, jmax = y;
                else x = xstart+1, y = ystart+1, imin = x, jmin = y, imax = n, jmax = n;
            }
        }

        /// calculez masca finala pe care trebuie sa o obtin pt cadranul asta
        int mask_final = 0;
        for (i=imin;i<=imax;i++)
            for (j=jmin;j<=jmax;j++)
                if (a[i][j] >= 97 && a[i][j] <= 122)
                    mask_final += (1<<(a[i][j]-97));

        c.clear();
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                viz[i][j].clear(); dp[i][j].clear();
        c.push_back({x,y,0});
        dp[x][y][0] = 1; /// cel mai mic nr de pasi pt a ajunge intr o stare
        viz[x][y][0] = 1;
        int sol = INF;
        while (!c.empty()){
            int ic = c.front().x;
            int jc = c.front().y;
            int mask = c.front().mask;
            c.pop_front();
            viz[ic][jc][mask] = 0;
            if (mask == mask_final){
                sol = min (sol,dp[ic][jc][mask]);
            }
            /// vad ce caracter pot sa adaug la masca curenta
            for (int i=97;i<=122;i++){
                int bit = i-97;
                /// daca nu face parte din masca finala nu pot sa continui
                if (!(mask_final&(1<<bit)))
                    continue;
                if (!(mask&(1<<bit))){
                    /// vad daca pot sa ajung din ic,jc la litera i
                    dist = verif (ic,jc,i,mask,imin,jmin,imax,jmax,mask_final);
                    if (dist == -1)
                        continue;
                    int new_mask = mask+(1<<bit);
                    int iv = poz[i].first, jv = poz[i].second;
                    if (dp[iv][jv][new_mask] == 0){
                        /// inseamna ca e prima oara cand ajung in masca asta
                        dp[iv][jv][new_mask] = dp[ic][jc][mask] + dist;
                        if (!viz[iv][jv][new_mask]){
                            viz[iv][jv][new_mask] = 1;
                            c.push_back({iv,jv,new_mask});
                        }
                    } else { /// acum vad daca imi actualizeaza solutia
                        if (dp[ic][jc][mask] + dist < dp[iv][jv][new_mask]){
                            dp[iv][jv][new_mask] = dp[ic][jc][mask] + dist;
                            if (!viz[iv][jv][new_mask]){
                                viz[iv][jv][new_mask] = 1;
                                c.push_back({poz[i].first,poz[i].second,new_mask});
                            }}}}}}
        sum += sol-1;
    }
    fout<<sum;

    return 0;
}

