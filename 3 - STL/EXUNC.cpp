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
ll n,q,o,i,x;

void solve() {
   cin>>n>>q;
   vec a(n,0);
   rep(i,0,n) cin>>a[i];
   set<ll> s; ll j=0; 
   rep(i,0,n-1){
       if(a[i+1] % a[i] == 0) continue;
       else {s.insert(j); j=i+1;} 
   } s.insert(j);   
   rep(k,0,q){
        cin>>o>>i;
        if(o == 2){
            auto itr = s.upper_bound(i-1);
            cout<<(*(--itr))+1<<endl;
            continue;
        }
        cin>>x; 
        i -= 1; a[i] = x;
        if(i > 0) s.insert(i);
        if(i < n) s.insert(i+1);
        if(i > 0 and x%a[i-1] == 0) s.erase(i);
        if(i < n and a[i+1]%x == 0) s.erase(i+1);
   }
}   

int main(){
    fastio;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}
