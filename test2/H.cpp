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

    string a,b,c;
    cin>>a>>b>>c;

    reverse(all(a));
    reverse(all(b));
    reverse(all(c));

    string ans="";

    while (a.size() && b.size() && c.size()){
        char A,B,C;
        A = a.back();
        B = b.back();
        C = c.back();

        if (A==B){
            ans.push_back('3');
            a.pop_back();
            b.pop_back();
        } else if (B==C){
            ans.push_back('1');
            c.pop_back();
            b.pop_back();
        } else {
            ans.push_back('2');
            a.pop_back();
            c.pop_back();
        }
    }

    if (a.size() == 0){
        for (auto x:b){
            ans.push_back('1');
        }
    } else if (b.size()==0){
        for (auto x:a){
            ans.push_back('2');
        }
    } else {
        for (auto x:b){
            ans.push_back('3');
        }
    }

    cout<<ans<<'\n';
}
