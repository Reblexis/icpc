#include <bits/stdc++.h>
using namespace std;

using un = long long;
using vuc = vector<un>;
using vol = vector<bool>;

#define REP(i, a, b) for (un i = a; i < b; i++)
#define FEAC(i, a) for (auto& i : a)
#define ALL(x) (x).begin(), (x).end()
#define vec vector

constexpr un INF = INT64_MAX/2;

void solve();

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    un T; cin >> T; while(T--) solve();
}


string input;
un N;

string A;
string B;

un P, Q;

un dijkstra();

void solve() {

    cin >> input;
    N = input.size();

    A = input;
    B = input;
    reverse(ALL(B));

    P = N;
    Q = N;

    un ret = dijkstra() / 2;

    cout << ret << endl;

}


un dijkstra() {

    vec<vuc> ceny = vec(P+1, vuc(Q+1, INF));

    ceny[P][Q] = 0;

    for (un s = P+Q-1; s >= 0; s--){
        for (un p = 0; p <= s; p++) {
            un q = s-p;

            if (p > P) continue;
            if (q > Q) continue;

            if (p < P) ceny[p][q] = min(ceny[p][q], ceny[p+1][q]+1);
            if (q < Q) ceny[p][q] = min(ceny[p][q], ceny[p][q+1]+1);

            if ((p < P) and (q < Q)) {
                if (A[p] == B[q]) ceny[p][q] = min(ceny[p][q], ceny[p+1][q+1]);
                else ceny[p][q] = min(ceny[p][q], ceny[p+1][q+1]+1);
            }
        }
    }

    return ceny[0][0];
}


