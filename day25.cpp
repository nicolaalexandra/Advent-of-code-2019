#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
char s[1000000];
int n,i,k,j,cif[6],op,semn;
long long val,val2,poz1,poz2,poz3,nr,sol,base;
//long long v[1000000];
map <long long,long long> v,w;
deque <long long> input,output,c[1000];
char ch[10];
int get_next(int &i, long long &base){
    long long sol = -1;
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
            if (!input.empty()){
                v[poz1] = input.front();
                input.pop_front();
            } else break;
            //v[poz1] = 1;
            i += 2;
            continue;
        }
        if (op == 4){
            //sol = v[poz1];
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
        break;
    }
    return sol;
}
void solve (map<long long, long long> v, int &i, long long &base, deque <long long> input){

    output.clear();
    get_next(i,base);
    for (auto it:output)
        fout<<(char)(it);
    /// vad ce mutari sunt disponibile
    k = 0;
    for (int j=0;j<output.size();j++){
        if ((char)(output[j]) == '-'){
            k++;
        }
        if (k && output[j] >= 97 && output[j] <= 122)
            c[k].push_back(output[j]);
    }

    for (int j=1;j<=k;j++){
        input.clear();
        for (auto it:c[k])
            input.push_back(it);
        solve (v,i,base,input);
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
                v[++k] = nr*semn;
                nr = 0;
                semn = 1;
            }
            else {
                nr = nr*10 + s[i] - '0';
            }
        }
    }
    v[++k] = nr;

    /// am aflat obiectele manual, acum vr sa vad ce numar imi returneaza
    string c = "east\neast\ntake spool of cat6\nnorth\nsouth\ntakefixed point\neast\nwest\ntake shell\neast\ntake candy cane";
    for (i=0;i<c.size();i++)
        input.push_back(c[i]);
    i = 0, base = 0;
    get_next(i,base);

    /*for (i=0;i<=k;i++)
        w[i] = v[i];
    i = 0, base = 0;
    for (;;){

        output.clear();
        get_next(i,base);
        for (auto it:output)
            cout<<(char)(it);
        input.clear();
        cin.getline(ch,10);
        int dim = strlen (ch);
        for (int idx=0;idx<dim;idx++)
            input.push_back(ch[i]);


    }*/

/*    string c = "north\n";
    for (int i=0;i<c.size();i++)
        input.push_back(c[i]);

    c = "take wreath\n";
    for (auto it:c)
        input.push_back(it);

    c = "south\n";
    for (auto it:c)
        input.push_back(it);
    c = "north\n";
    for (auto it:c)
        input.push_back(it);
    c = "south\n";
    for (auto it:c)
        input.push_back(it);
    c = "north\n";
    for (auto it:c)
        input.push_back(it);
    c = "north\n";
    for (auto it:c)
        input.push_back(it);
    c = "east\n";
    for (auto it:c)
        input.push_back(it);
    c = "south\n";
    for (auto it:c)
        input.push_back(it);
    c = "west\n";
    for (auto it:c)
        input.push_back(it);


    get_next(i,base);
    for (auto it:output)
        cout<<(char)(it);
*/
    /// weather machine - nu o iau, wreath - drop
    /// loom , photons

    /// spool of cat6, fixed point, shell, candy cane

    return 0;
}
