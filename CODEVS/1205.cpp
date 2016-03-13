#include "cstdio"
#include "cstdlib"
#include "iostream"
#include "vector"
#include "string"
using namespace std;

vector<string> D;

int main(){
    string tmp;
    while(cin>>tmp){
        D.push_back(tmp);
    }
    for(vector<string>::iterator OP=D.end()-1;OP>=D.begin();OP--)
        cout<<*OP<<' ';
    cout<<endl;
    return 0;
}