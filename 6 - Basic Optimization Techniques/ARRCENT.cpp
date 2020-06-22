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
const ll M = 1000000007;

void solve(){
    ll n,t; cin>>n;
    vec a(n), prs(n), sus(n); 
    rep(i,0,n) {cin>>a[i]; prs[i] = sus[i] = a[i]; }
    rep(i,0,4) {
        rep(i,1,n-1){
            prs[i] = (prs[i]+prs[i-1])%M;
            sus[n-i-1] = (sus[n-i-1]+sus[n-i])%M;
        }
    }
    rep(i,0,n) {
        t = 0;
        if(i>0) t = (t+prs[i-1])%M;
        if(i<n-1) t = (t+sus[i+1])%M;
        cout<<t<<' '; 
    }
    cout<<endl;
}

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return(0);
}