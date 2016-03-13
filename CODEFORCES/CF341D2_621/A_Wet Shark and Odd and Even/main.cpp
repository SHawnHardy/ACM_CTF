#include "iostream"
using namespace std;
int main(){
    int n;
    cin>>n;
    int flag=0;
    long long int min=1e15;
    long long int ans=0;
    while(n--){
        long long int in=0;
        cin>>in;
        if(in%2){
            flag^=1;
            if(min>in)
                min=in;
        }
        ans+=in;
    }
    if(flag)    ans-=min;
    cout<<ans;
    return 0;
}
