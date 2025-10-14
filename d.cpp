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

    un ret = INF;

    // even
    for(un i = 0; i <= N; i++) {
        A = input.substr(0, i);
        B = input.substr(i, N-i);
        reverse(ALL(B));

        P = A.size();
        Q = B.size();

        ret = min(ret, dijkstra());
    }


    // odd
    for(un i = 0; i < N; i++){
        A = input.substr(0, i);
        B = input.substr(i+1, N-i-1);
        reverse(ALL(B));

        P = A.size();
        Q = B.size();

        ret = min(ret, dijkstra());
    } 

    cout << ret << endl;

}


un dijkstra() {

    priority_queue<tuple<un, un, un>, vector<tuple<un, un, un>>, greater<tuple<un, un, un>>> kjuu;


    kjuu.push({0, P, Q});

    map<pair<un, un>, un> ceny;


    while (not kjuu.empty())
    {
        auto [w, p, q] = kjuu.top(); kjuu.pop();

        if (ceny.find({p, q}) != ceny.end()) continue;

        ceny[{p, q}] = w;

        if ((p == 0) and (q==0)) continue;

        if (p == 0) kjuu.push({w+q, 0, 0});
        else if (q == 0) kjuu.push({w+p, 0, 0});
        else {

            if (A[p-1] == B[q-1]) {
                kjuu.push({w, p-1, q-1});
            }
            else {
                kjuu.push({w+1, p-1, q-1});
                kjuu.push({w+1, p-1, q});
                kjuu.push({w+1, p, q-1});
            }
        }
    }
    
    return ceny[{0, 0}];
}


