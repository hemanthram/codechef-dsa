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
ll n,m,k,r,c;

void solve() {
   cin>>n>>m>>k;
   unordered_map<ll, unordered_map<ll,bool>> d;
   ll cc = 0;
   rep(i,0,k) {
       cin>>r>>c;
       if(d.find(r) != d.end()){
           if(d[r].find(c+1) != d[r].end())
           cc += 1;
           if(d[r].find(c-1) != d[r].end())
           cc += 1;
       }
       if(d.find(r+1) != d.end())
       if(d[r+1].find(c) != d[r+1].end())
       cc += 1;
       if(d.find(r-1) != d.end())
       if(d[r-1].find(c) != d[r+1].end())
       cc += 1;
    d[r][c] = true;
   }
   cout<<(4*k-2*cc)<<endl;
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
