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

void solve() {
    ll n,m; cin>>n>>m;
    vec a(n),b(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];
    ll mna = min_element(all(a)) - a.begin();
    ll mxb = max_element(all(b)) - b.begin();
    rep(i,0,m) cout<<mna<<' '<<i<<endl;
    rep(i,0,n) if(i != mna) cout<<i<<' '<<mxb<<endl;
    // cout<<endl;
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
