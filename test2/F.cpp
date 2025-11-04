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

un N, M;

vec<vuc> adj;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    cin >> N >> M;

    if ((N % 2 == 1) or (N > 3*1000)) {
        cout << "impossible" << endl;
        return 0;
    }

    adj = vec<vuc>(N, vuc(N, 0));

    REP(i, 0, M) {
        un a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    REP(i, 0, N) adj[i][i] = 1;


    vol prirazeny(N, 0);

    pair<vec<vuc>, vec<vuc>> vel;

    REP(now, 0, N) {

        if (prirazeny[now] > 0) continue;

        vel.first.push_back(vuc());
        vel.second.push_back(vuc());

        stack<un> zasoba;
        zasoba.push(now);
        prirazeny[now] = 1;
        vel.first.back().push_back(now);

        while (not zasoba.empty())
        {
            un i = zasoba.top(); zasoba.pop();

            REP(j, 0, N) {
                if ((adj[i][j] == 0) and (prirazeny[j] == 0)) {
                    prirazeny[j] = 3 - prirazeny[i];
                    if (prirazeny[j] == 1){
                        vel.first.back().push_back(j);

                        FEAC(k, vel.first[i]) {
                            if (adj[j][k] == 0) {
                                cout << "impossible";
                                return 0;
                            }
                        }

                    } 
                    if (prirazeny[j] == 2){
                        vel.second.back().push_back(j);

                        FEAC(k, vel.second[i]) {
                            if (adj[j][k] == 0) {
                                cout << "impossible";
                                return 0;
                            }
                        }

                    } 

                    zasoba.push(j);
                }
            }
        }
    }


    vol now(N/2 + 1, false);
    vol last(N/2 + 1, false);
    last[0] = true;

    vec<vuc> constrNow(N/2 + 1);
    vuc constrLast(N/2 + 1);



    REP(i, 0, N) {
        now = vol(N, false);
                
        REP(j, 0, N/2+1) {
            if (last[j] and (j + (un)vel.first[i].size() <= N/2)) now[j + (un)vel.first[i].size()] = true;
            if (last[j] and (j + (un)vel.second[i].size() <= N/2)) now[j + (un)vel.second[i].size()] = true;
        }
    }


    if (now[N/2]) {

    }
    else {
        cout << "impossible" << endl;
    }

}