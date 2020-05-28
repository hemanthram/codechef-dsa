// g++ file.cpp -o file | file
// ram learns c++

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
// #define ll long long
// #define F first
// #define S second
// #define vec vector<ll>
// #define pb  push_back
// #define pai pair<ll,ll>
// #define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(int i=a;i<b;i++)
// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
// ll M = pow(10,9)+7;
int c[2001];
int a[2001];

int n,k,b = 0,m,x,bx,f; 
ordered_set bst;

int32_t main(){
    // fastio;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        b = 0;
        scanf("%d %d",&n,&k);
        rep(i,0,n) scanf("%d", &a[i]);
        rep(i,0,n){
            bst.clear();
            memset(c, 0, sizeof(c));
            rep(j,i,n){
                m = (k+j-i)/(j-i+1);
                x = (k+m-1)/m;
                c[a[j]] += 1;
                bst.insert({a[j],j});
                bx = bst.find_by_order(x-1)->first;
                f = c[bx];
                if(c[f]) b += 1;
            }
        }
        printf("%d\n",b);
    }
    return 0;
}
