#include <bits/stdc++.h>
#define DIM 20000000
using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000];
vector <pair <int,int> > v[100];
int poz[DIM];
unsigned long long ramas[DIM];
int i,j,n,nr,cod,ok,fuel;
unsigned long long sol,ore,nr_fuel;
void solve (int cod, unsigned long long cantitate){
    /// vreau sa obtin o anumita cantitate dintr o substanta
    int x = poz[cod];
    if (!x){
        sol += cantitate;
        return;
    }
    /// vreau sa vad de cate ori trebuie sa folosesc reactia pt a obtine cat am nevoie
    if (ramas[cod] >= cantitate){
        ramas[cod] -= cantitate;
        return;
    }
    cantitate -= ramas[cod];
    long long nr = cantitate / v[x].back().first;
    if (cantitate % v[x].back().first)
        nr++;
    ramas[cod] = nr*v[x].back().first - cantitate; /// cu atat o sa mai raman
    //if (nr == 0)
      //  return;
    for (int i=0;i<v[x].size()-1;i++){
        int cod2 = v[x][i].second;
        solve (cod2,nr*v[x][i].first);
    }


}
int main (){

    int m = 59;
    for (i=1;i<=m;i++){
        fin.getline(s+1,100);
        n = strlen (s+1);
        nr = 0, cod = 0;
        for (j=1;j<=n;j++){
            if (s[j] == ',' || s[j] == '='){
                v[i].push_back(make_pair(nr,cod));
                nr = 0, cod = 0;
            }
            if (s[j] >= '0' && s[j] <= '9')
                nr = nr*10 + s[j] - '0';
            if (s[j] >= 'A' && s[j] <= 'Z')
                cod = cod*27 + s[j] - 'A' + 1;
        }
        v[i].push_back(make_pair(nr,cod)); /// produsul de reactie
        //fout<<cod<<"\n";
        //if (poz[cod])
          //  ok = 1;
        poz[cod] = i;
    }
    fuel = 133554;
    /// fuel am pe poz 35
    solve (fuel,1);
    fout<<sol<<"\n";
    /// part 2
    ore = 1000000000000;
    nr_fuel = 1;
    unsigned long long st = 1, dr = ore, ans;

    while (st <= dr){
        unsigned long long mid = (st+dr)>>1;
        memset (ramas,0,sizeof ramas);
        sol = 0;
        solve (fuel,mid);
        if (sol <= ore){
            ans = mid;
            st = mid+1;
        } else dr = mid-1;
    }

    fout<<ans;


    return 0;
}
