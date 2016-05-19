/*
 ID: shawn_w1
 PROG: gift1
 LANG: C++
 */
#include "cstdio"
#include "string"
#include "fstream"
#include "map"
#include "cmath"
#define psi pair<string,int>
#define M 15
using namespace std;
string nam[M];
map<string,int> d;
int chg[M]={0};

int main(){
    int n;
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    fin>>n;
    for (int i=0; i<n; i++) {
        string in;
        fin>>in;
        nam[i]=in;
        d.insert((psi){in,i});
    }
    for (int i=0; i<n; i++) {
        string na;
        fin>>na;
        int num=d[na];
        int mny,frd;
        fin>>mny>>frd;
        if (!frd) {
            chg[num]-=mny;
            continue;
        }
        int gft=mny/frd;
        chg[num]-=mny;
        chg[num]+=(mny%frd);
        for (int i=0; i<frd; i++) {
            string fna;
            fin>>fna;
            int fnum=d[fna];
            chg[fnum]+=gft;
        }
    }
    for (int i=0; i<n; i++) {
        fout<<nam[i]<<' '<<chg[i]<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}