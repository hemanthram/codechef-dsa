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
#define str string
#define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve(){
    str s;
    cin>>s;
    int cl,cr;
    vec l(26,0ll), r(26,0ll);
    ll n = s.length();
    rep(i,0,n/2){
        cl = int(s[i])-'a';
        cr = int(s[n-i-1])-'a';
        l[cl] += 1; r[cr] += 1; 
    }
    rep(i,0,26){
        // cout<<l[i]<<r[i]<<char(int('a')+i)<<endl;
        if(l[i] != r[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
