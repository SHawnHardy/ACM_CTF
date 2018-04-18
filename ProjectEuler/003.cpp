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
void primeFactorization(ll x, vector<pll> &ans) {
    ans.clear();
    sieveOfEuler();
    for (int i=0; x>1; i++) {
        if (!(x%prime[i])) {
            int num=0;
            while (!(x%prime[i])) {
                num++;
                x/=prime[i];
            }
            ans.push_back(mp(prime[i], (ll)num));
        }
    }
}


int main() {
    vector<pll> ans;
    primeFactorization(600851475143LL, ans);
    cout<<(*(ans.end()-1)).first;
    return 0;
}
