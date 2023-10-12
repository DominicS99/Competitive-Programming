#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(NULL);
    int t,n,l,x;
    cin>>t;
    while(t--){
        cin>>l>>n;
        int a=0,b=0;
        while(n--) {
            cin>>x;
            a=max(a,min(x,l-x));
            b=max(b,max(x,l-x));
        }
        cout<<a<<" "<<b<<endl;
    }
}