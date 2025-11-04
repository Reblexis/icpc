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
    
    string s;
    cin>>s;
    vector<int> counts(26,0);

    for (char c:s){
        counts[c-'a']++;
    }

    int noOdd = 0;
    for (int i=0;i<26;i++){
        noOdd += counts[i]%2;
    }

    if (noOdd>1){
        cout<<"no\n";
    } else {
        cout<<"yes\n";
    }
}
