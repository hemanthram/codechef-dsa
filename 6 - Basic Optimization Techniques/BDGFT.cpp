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

void solve(){
    string s; cin>>s;
    vec pre={0}; ll c=0,c1=1,b=0,n=s.length();
    rep(i,0,n) {if(s[i] == '1') c+=1; pre.pb(c);}
    while(c1+c1*c1 <= n){
        rep(i,0,n-(c1+c1*c1)+1)
        if((pre[i+c1+c1*c1]-pre[i]) == c1) b+=1;
        c1 += 1;
    }
    cout<<b<<endl;
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