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

const int maxn=10010;

ll gcd(ll a,ll b) {
    return a%b==0?b:gcd(b,a%b);
}

int main() {
    ll a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",a/gcd(a,b)*b);
    return 0;
}
