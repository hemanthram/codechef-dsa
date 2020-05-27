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
#define print(x) cout<<x<<endl

ll power(ll x, ll y, ll p){ 
    ll res = 1;
    x = x % p; 
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
}
ll M = 100002;

void solve(){
    string s;
    ll l=0,ind=-1;
    cin>>s;
    rep(i,0,s.length()){
        if(s[i] == '<') l+=1;
        else l-=1;
        if(l < 0) {cout<<i<<endl; return;}
        if(l == 0) ind=i+1;
    }
    if(ind == -1) cout<<0<<endl;
    else cout<<ind<<endl;
}   

int main(){
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
