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

const int maxn=100010;

struct Trie {
    struct nd{
        int nxt[26];
        int data;
        void init() {
            memset(nxt,-1,sizeof(nxt));
            data=0;
        }
    };
    
    nd node[maxn*10];
    int top;
    
    void init() {
        node[0].init();
        top=1;
    }
    void insert(char s[]) {
        int p=0;
        node[p].data++;
        int len=strlen(s);
        for (int i=0; i<len; i++) {
            int nt=s[i]-'a';
            if (node[p].nxt[nt]==-1) {
                node[top].init();
                node[p].nxt[nt]=top;
                top++;
            }
            p=node[p].nxt[nt];
            node[p].data++;
        }
    }
    int query(char s[]) {
        int p=0;
        int len=strlen(s);
        for (int i=0; i<len; i++) {
            int nt=s[i]-'a';
            if (node[p].nxt[nt]==-1) {
                return 0;
            }
            p=node[p].nxt[nt];
        }
        return node[p].data;
    }
};

Trie T;

int main() {
    int n;
    scanf("%d",&n);
    T.init();
    for (int i=0; i<n; i++) {
        char t[12];
        scanf("%s",t);
        T.insert(t);
    }
    int m;
    scanf("%d",&m);
    while (m--) {
        char t[12];
        scanf("%s",t);
        printf("%d\n",T.query(t));
    }
    return 0;
}
