// g++ file.cpp -o file | file
// ram learns c++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define vec vector<ll>
#define pb  push_back
#define pai pair<ll,ll>
#define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
ll M = pow(10,9)+7;
const ll N = 100001;

void solve(){
    ll n,z,t,m=0;
    cin>>n>>z;
    priority_queue< ll, vec, less<ll> > h;
    rep(i,0,n) {cin>>t; h.push(t);}
    while(!h.empty()){
        z -= h.top(); m++;
        if(z <= 0) {break;}
        t = h.top()/2; h.pop();
        if(t != 0) h.push(t);
    }
    if(z <= 0) cout<<m<<endl;
    else cout<<"Evacuate"<<endl;
}   

int main(){
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
