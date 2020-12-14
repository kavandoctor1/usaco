#include <bits/stdc++.h>
using namespace std;
ofstream fout ("promote.out");
ifstream fin ("promote.in");
int main() {
    int bronze,silver,gold,plat,bronze2,silver2,gold2,plat2;
    fin>>bronze>>bronze2>>silver>>silver2>>gold>>gold2>>plat>>plat2;
    int tres = plat2-plat;
    gold2+=tres;
    int dos=gold2-gold;
    silver2+=dos;
    int uno=silver2-silver;
    fout<<uno<<"\n"<<dos<<"\n"<<tres<<"\n";
}