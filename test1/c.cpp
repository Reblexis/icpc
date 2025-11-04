#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    while (t--){
        int n,m;
        cin>>n>>m;
        vector<ll> arr(n+1,0);

        for (int i=0;i<m;i++){
            int a,b,v;
            cin>>a>>b>>v;

            ll newVa = arr[b]+v;
            ll newVb = arr[a]+v;
            arr[a] = newVa;
            arr[b] = newVb;
        }

        cout<<*max_element(arr.begin(), arr.end())<<'\n';
    }
}