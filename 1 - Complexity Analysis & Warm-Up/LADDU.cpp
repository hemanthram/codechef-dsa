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

void solve(){
    ll a,r,s,mn,l=0;
    string str;
    cin>>a>>str;
    mn = (str == "INDIAN") ? 200 : 400;
    while(a--){
        cin>>str;
        if(str == "CONTEST_WON") {
            cin>>r;
            l += 300+(max(0ll,20-r));
        }
        if(str == "TOP_CONTRIBUTOR"){
            l += 300;
        }
        if(str == "BUG_FOUND"){
            cin>>s;
            l += s;
        }
        if(str == "CONTEST_HOSTED"){
            l += 50;
        }
    }
    cout<<l/mn<<endl;
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
