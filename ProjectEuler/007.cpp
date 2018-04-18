#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "string"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "map"
#include "iostream"
#include "complex"

#define pb push_back
#define fi first
#define se second
#define dbg(...) cerr<< "[" << #__VA_ARGS__ ":" << (__VA_ARGS__) << "]" <<endl;
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=800000+10;

vector<ll> prime;
bool isprime[MAXN];

void sieveOfEuler() {
    prime.clear();
    memset(isprime,-1,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for (int i=2; i<MAXN; i++) {
        if (isprime[i])
            prime.push_back(i);
        for (int j=0; j<(int)prime.size() && i*prime[j]<MAXN; j++) {
            isprime[i*prime[j]]=false;
            if (!(i%prime[j]))
                break;
        }
    }
}

int main() {
    sieveOfEuler();
    printf("%lld\n",prime[10000]);
    return 0;
}

