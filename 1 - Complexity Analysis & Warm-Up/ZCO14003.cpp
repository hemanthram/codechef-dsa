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

vec p(500001,0);

void solve(){
    ll n,ans = 0;
    cin>>n;
    rep(i,0,n) cin>>p[i];
    sort(p.begin(),p.begin()+n);
    rep(i,0,n){
        if(p[i]*(n-i) > ans)
        ans = p[i]*(n-i);
    }
    cout<<ans<<endl;
}

int main(){
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;
    t = 1;
    while(t--)
    solve();
    return 0;
}
