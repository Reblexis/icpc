#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


pair<int,int> get_idx(vector<int> state){
    int n = state.size();
    vector<int> GetVal = {1,-1};

    map<int,int> PS_idx;
    PS_idx[0] = 0;
    int best = -1111111;
    pair<int,int> bestIDXs = {0,0};
    int ps = 0;

    for (int i=0;i<n;i++){
        ps += GetVal[state[i]];
        pair<int,int> min_ = *PS_idx.begin();
        if (best<ps-min_.first){
            best = ps-min_.first;
            bestIDXs = {min_.second, i+1};
        }

        PS_idx[ps] = i+1;
    }

    return bestIDXs;

}

int main(){
    int n;
    cin>>n;

    vector<int> state(n,0);

    for (int i=0;i<125;i++){
        auto [l,r] = get_idx(state);
        l++;

        cout<<l<<' '<<r<<'\n';
        cout<<flush;

        for (int j=0;j<n;j++){
            cin>>state[j];
        }

        int val;
        cin>>val;
        if (val>=70){
            break;
        }
    }
}
