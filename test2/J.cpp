#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;cin>>n;

    string s = "";
    bool poss = true;
    vector<string> answer;
    rep(i,0, n){
        string bestString = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
        int p;cin>>p;
        bool pos = false;
        rep(i,0, p){
            string part; cin>>part;
            if(part>=s)
                {
                    pos = true;
                    bestString = min(bestString, part);
                }
        }
        answer.push_back(bestString);
        s = bestString;
        poss&=pos;
    }
    if(!poss){
        cout<<"impossible"<<'\n';
        return 0;
    }
    rep(i, 0, sz(answer)){
        cout<<answer[i]<<'\n';
    }

}