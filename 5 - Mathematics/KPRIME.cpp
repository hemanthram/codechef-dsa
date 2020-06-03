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
const ll N = 100001,M=1000000007;
ll n,a,b,k;

vector <ll> prime;
ll nopf[N] = {0}, ans[6][N];
void primes() {
	ll all[N];
	rep(i,0,N) all[i] = 0;
	rep(i,2,N) {
		if(!all[i] ) { prime.push_back(i); nopf[i]+=1; }
        else continue; 
		ll j = 2*i;
		while(j <= N) {
            nopf[j] += 1;
			all[j] = 1;
			j += i;
		}
	}
    rep(i,1,6) ans[i][1] = 0;
    rep(i,2,N) {
        rep(j,1,6) {
            if(nopf[i] == j){
                ans[j][i] = ans[j][i-1] + 1;
            }
            else{
                ans[j][i] = ans[j][i-1];
            }
        }
    }
} 

void solve(){
    cin>>a>>b>>k;
    cout<<ans[k][b]-ans[k][a-1]<<endl;
}   

int main(){
    fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	#endif
	primes();
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
