#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll stops;

ll DFS(ll maxD, ll v, ll par, ll parLen, vector<vector<pair<ll,ll>>> &tree){
    ll maxNum = 0;
    ll maxNum2 = 0;

    for (auto [u,l]:tree[v]){
        if (u!=par){
            ll x = DFS(maxD, u, v, l, tree);
            if (x>=maxNum){
                maxNum2 = maxNum;
                maxNum = x;
            } else if (x>maxNum2){
                maxNum2 = x;
            }
        }
    }

    if (parLen > maxD){
        stops += 1e9;
    }
    if (maxNum+maxNum2 > maxD || maxNum+parLen > maxD){
        stops++;
        maxNum = 0;
    }

    return maxNum + parLen;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    ll n,k;
    cin>>n>>k;

    vector<vector<pair<ll,ll>>> tree(n+1);
    for (int i=1;i<n;i++){
        int a,b,v;
        cin>>a>>b>>v;
        tree[a].push_back({b,v});
        tree[b].push_back({a,v});
    }

    ll l = 0;
    ll r = 1e15;

    while (l<r){
        ll mid = (l+r)/2;

        stops = 0;
        DFS(mid, 1, 0, 0, tree);
        if (stops>k){
            l=mid+1;
        } else {
            r = mid;
        }
    }
    cout<<l<<'\n';
}