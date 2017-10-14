#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "ctime"
#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"

using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,string> pis;

const int MAXN=1000000;

template<class T>
struct Fenwick : vector<T> {
    typedef vector<T> S;
    int N;
    inline int lb(int x) {
        return x&(-x);
    }
    
    Fenwick(int _N=0): S(_N),N(_N) {}
    void add(int pos, T x) {
    	for (; pos<N; pos+=lb(pos))
            S::operator[](pos)+=x;
    }
    T sum(int pos) {
	    T re=0;
	    for (; pos; pos-=lb(pos)) 
            re+=S::operator[](pos);
    	return re;
    }
    T sum(int l, int r) {
	    return sum(r) - sum(l-1);
    }
};


Fenwick<int> f(MAXN);
bool big=false;

bool sol(int x) {
    if (f.sum(1,1))
        return false;
    if (x>=MAXN) {
        big=true;
        return true;
    }
    if (f.sum(1,x)<(x-1)) {
        int i;
        for (i=x; f.sum(i,i); i--)
            f.add(i,-1);
        f.add(i,1);
        return true;
    }
    else {
        if (big||f.sum(x+1,MAXN))
            return false;
        else {
            f.add(1,1);
            return true;
        }
    }    
}

int main() {
    int n;
    scanf("%d",&n);
    while (n--) {
        int t;
        scanf("%d",&t);
        puts(sol(t+1)?"Yes":"No");
    }
    return 0;
}
