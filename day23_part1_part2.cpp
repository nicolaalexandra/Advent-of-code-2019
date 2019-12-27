#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");

char s[1000000];
int n,i,k,j,cif[6],op,semn,ok;
long long val,val2,poz1,poz2,poz3,nr;
long long poz[60];
long long base[60],idx,x,y,xx,yy,xaux,yaux,ans,ans2;
map <long long,long long> v[60],w;
deque <long long> input[1000],output[1000];

void solve (long long &i, long long &base, map <long long,long long> &v, deque <long long> &input, deque <long long> &output){
   // for (int i=0;i<=k;i++)
       // v[i] = w[i];
    //i = 0, base = 0;
    //sol.clear();
    for (;;){
        //if (i > k)
          //  break;
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
            if (input.empty())
                break;
            v[poz1] = input.front();
            input.pop_front();
            i += 2;
            continue;
        }
        if (op == 4){
            output.push_back(v[poz1]);
            i += 2;
            continue;
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
        //break;
    }
}
int main (){

    fin>>s;
    n = strlen (s);
    k = -1, semn = 1;
    for (i=0;i<n;i++){
        if (s[i] == '-')
            semn = -1;
        else {
            if (s[i] == ','){
                w[++k] = nr*semn;
                nr = 0;
                semn = 1;
            }
            else {
                nr = nr*10 + s[i] - '0';
            }
        }
    }
    w[++k] = nr;

    /*for (val=0;val<=49;val++){
        input[val].push_back(val);
        input[val].push_back(-1);
    }*/
    for (val=0;val<=49;val++){
        for (i=0;i<=k;i++)
            v[val][i] = w[i];
        input[val].clear();
        input[val].push_back(val);
        input[val].push_back(-1);

        solve(poz[val],base[val],v[val],input[val],output[val]); /// trebuie sa retin unde am ramas?

        /*for (auto it:sol){
            output[val].push_back(it);
            fout<<it<<" ";
        }
        fout<<"\n";*/
    }


    for (;;){
        /// rulez din nou incode ul, mereu de unde am ramas
        for (val=0;val<=49;val++)
            solve (poz[val],base[val],v[val],input[val],output[val]);
        /*for (int i=0;i<50;i++){
            for (auto it:output[i])
                fout<<it<<" ";
            fout<<"\n";
        }*/
        for (val=0;val<=49;val++){
            /// parcurg outputul pt fiecare
            for (;;){
                if (output[val].empty())
                    break;
                idx = output[val].front();
                output[val].pop_front();
                if (output[val].empty())
                    break;
                x = output[val].front();
                output[val].pop_front();
                if (output[val].empty())
                    break;
                y = output[val].front();
                output[val].pop_front();

                if (idx == 255){
                    xaux = x, yaux = y;
                    if (!ok){ /// primul cu 255
                        ans = y; /// partea 1
                        ok = 1;
                    }
                } else {
                    /// trb sa adaug la inputul lui idx
                    input[idx].push_back(x);
                    input[idx].push_back(y);
                }

                if (output[val].empty())
                    break;
            }

        }
        int ok2 = 0;
        for (val=0;val<=49;val++){
            if (!input[val].empty())
                ok2 = 1; /// am gasit macar unul
            else input[val].push_back(-1); /// daca n am nmc trb sa pun -1
        }
        if (ok2)
            continue;
        input[0].pop_front();
        if (xx == xaux && yy == yaux){
            ans2 = yy;
            break;
        }
        xx = xaux, yy = yaux;
        input[0].push_back(xx), input[0].push_back(yy);
    }

    fout<<ans<<"\n"<<ans2;


    return 0;
}


