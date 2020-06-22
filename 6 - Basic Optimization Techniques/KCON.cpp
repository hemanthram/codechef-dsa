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
ll a[200005];

long long maxSubSum(ll a[], ll n){
    ll pre_max = LONG_LONG_MIN, max_here = 0; 
    rep(i,0,n){
        max_here = max_here+a[i];
        pre_max = max(pre_max, max_here);
        if(max_here < 0) max_here = 0;
    }
    return pre_max;
}

void solve(){
    ll n,k,s = 0; cin>>n>>k;
    rep(i,0,n) { cin>>a[i]; s+=a[i]; }
    ll sub = maxSubSum(a,n);
    if(k == 1) { cout<<sub<<endl; return; }
    ll ps=LONG_LONG_MIN,ss=LONG_LONG_MIN,ts=0;
    rep(i,0,n) { ts+=a[i]; if(ts>ps) ps=ts; } ts = 0;
    for(ll i = n-1; i>=0; --i) { ts+=a[i]; if(ts>ss) ss=ts; }
    ll ans[4] = {ps+ss, ss+ps+(k-2)*s, sub, k*s};
    cout<<*max_element(ans,ans+4)<<endl;
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