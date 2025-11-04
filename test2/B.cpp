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
    
    ll d, a, o, Da, Do;
    cin>>d>>a>>o>>Da>>Do;

    ll Va = max(0LL, a-d*Da);
    ll Vo = max(0LL, o-d*Do);

    cout<<setprecision(16);
    cout<<(double)Va/(Va+Vo)*100<<'\n';
}
