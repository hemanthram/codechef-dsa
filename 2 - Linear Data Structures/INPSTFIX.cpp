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

ll power(ll x, ll y, ll p){ 
    ll res = 1;
    x = x % p; 
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
}

int preced(char ch) {
   if(ch == '+' || ch == '-') {
      return 1;
   }else if(ch == '*' || ch == '/') {
      return 2;
   }else if(ch == '^') {
      return 3;
   }else {
      return 0;
   }
}

void solve(){
    ll n;
    string s,ans = "";
    stack<char> pf; pf.push('#');
    cin>>n>>s;
    rep(i,0,n){
        if(isalpha(s[i])) ans.pb(s[i]);
        else if(s[i] == '(') pf.push(s[i]);
        else if(s[i] == ')'){
            while(pf.top() != '('){
                char ch = pf.top();
                pf.pop();
                ans.pb(ch);
            }
            pf.pop();
        }
        else {
            while(pf.top() != '#' && preced(s[i]) <= preced(pf.top())){
                char ch = pf.top();
                ans.pb(ch);
                pf.pop();
            }
            pf.push(s[i]);
        }
    }
    while(pf.top() != '#'){
        ans.pb(pf.top());
        pf.pop();
    }
    cout<<ans<<endl;
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
