/*
 ID: shawn_w1
 PROG: friday
 LANG: C++
 */
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "fstream"
using namespace std;

int main(){
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int N;
    int DOM[12]={31,31,28,31,30,31,30,31,31,30,31,30};
    int ans[10]={0};
    fin>>N;
    int lmt=3;
    for (int i=1900; i<1900+N; i++) {
        for (int j=1; j<=12; j++) {
            lmt+=DOM[j-1];
            if (j==3) {
                if (!(i%4)) {
                    if (i%100||(!(i%400))) {
                        lmt++;
                    }
                }
            }
            
            lmt%=7;
            ans[lmt]++;
        }
    }
    fout<<ans[6];
    for (int i=0; i<6; i++) {
        fout<<' '<<ans[i];
    }
    fout<<endl;
    return 0;
}