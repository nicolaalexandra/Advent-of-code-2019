#include <bits/stdc++.h>

using namespace std;

ifstream fin ("date.in");
ofstream fout ("date.out");
int x;
int main (){

    /// part 1
    long long sum = 0;
    while (fin>>x){
        sum += x/3 - 2;
    }
    fout<<sum<<" ";

    /// part 2
    sum = 0;
    while (fin>>x){
        while (x > 0){
            int nr = x/3 - 2;
            if (nr <= 0)
                break;
            sum += nr;
            x = nr;
        }
    }
    fout<<sum;

    return 0;
}
