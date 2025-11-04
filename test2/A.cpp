#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


using un = long long;
using vuc = vector<un>;
using vol = vector<bool>;

#define REP(i, a, b) for (un i = (un)a; i < (un)b; i++)
#define FEAC(i, a) for (auto&& i : a)
#define ALL(x) (x).begin(), (x).end()
#define vec vector

constexpr un WRONG = 10000;

un N, L, H;
vuc A;

pair<un, un> get_range(un a) {
    un dole, hore;
    
    for (un i = -10; i <= 10; i++){
        if ((L <= a + i*12) and (a + i*12 <= H)) {
            dole = i;
            break;
        }
    }

    for (un i = 10; i >= -10; i--){
        if ((L <= a + i*12) and (a + i*12 <= H)){
            hore = i;
            break;
        }
    }

    return {dole, hore};
}

pair<un, un> merge_range(pair<un, un> a, pair<un, un> b) {
    un dole, hore;

    dole = max(a.first, b.first);
    hore = min(a.second, b.second);

    if (dole > hore) return {WRONG, WRONG};
    return {dole, hore};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);


    cin >> N >> L >> H;

    A = vuc(N);
    FEAC(a, A) cin >> a;

    vec<pair<un, un>> ranges(N);

    REP(i, 0, N)  ranges[i] = get_range(A[i]);


    vuc DP(N+1, 0);
    DP[0] = 10000;

    REP(nowPos, 0, N){
        un delka = 0;
        pair<un, un> now = ranges[nowPos + delka];

        while((now.first != WRONG) and (nowPos + delka <= N)) {
            DP[nowPos + delka] = max(DP[nowPos + delka], min(delka, DP[nowPos]));

            if (nowPos + delka == N) break;

            now = merge_range(now, ranges[nowPos+delka]);
            delka++;
        }
    }

    cout << DP[N] << endl;
}