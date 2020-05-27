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
ll M = pow(10,9)+7;

void solve(){
    ll n,k,ans = 1; 
    cin>>n>>k;
    vec a(n), m(n,-1);
    rep(i,0,n) cin>>a[i];
    stack<ll> s; 
    rep(i,0,n){
        while(!s.empty() && a[s.top()] > a[i]) {
            m[s.top()] = i; s.pop(); 
        }
        s.push(i);
    }
    rep(i,0,n) if(m[i] != -1) ans = (ans*(m[i]-i+1))%M;
    cout<<ans<<endl;
}   

int main(){
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}
