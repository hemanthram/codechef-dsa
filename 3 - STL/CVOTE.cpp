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
ll n,m;
string na,co,sc;

void solve() {
    cin>>n>>m;
    unordered_map<string, string> d;
    unordered_map<string, ll> cc,cs;

    rep(i,0,n) {
        cin>>na>>co;
        d[na] = co;
        cc[co] = 0;
        cs[na] = 0;
    }
    string anss = "", ansc = "";
    ll mx = 0;
    rep(i,0,m){
        cin>>sc;
        cc[d[sc]] += 1;
        cs[sc] += 1;
    }
    for(auto itr = cc.begin(); itr != cc.end(); itr++){
        if((*itr).S > mx) { mx = (*itr).S; ansc = (*itr).F; }
        if((*itr).S == mx) if((*itr).F < ansc) ansc = (*itr).F; 
    }
    mx = 0;
    for(auto itr = cs.begin(); itr != cs.end(); itr++){
        if((*itr).S > mx) { mx = (*itr).S; anss = (*itr).F; }
        if((*itr).S == mx) if((*itr).F < anss) anss = (*itr).F; 
    }
    // cout<<mx;
    cout<<ansc<<endl;
    cout<<anss<<endl;
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
