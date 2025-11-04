#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i< (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f){
    int low = val[j] = ++Time, x; z.push_back(j);
    for(auto e: g[j])if(comp[e]<0)
        low = min(low, val[e] ?: dfs(e,g,f));
    if(low==val[j]){
        do{
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        }while(x!=j);
        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low;
}

template<class G, class F> void scc(G& g, F f){
    int n = sz(g);
    val.assign(n, 0); comp.assign(n,-1);
    Time = ncomps = 0;
    rep(i,0,n)if(comp[i]<0)dfs(i,g,f);
}

vector<bool> vis;

void dfs(int v, vector<vector<int>> &G){
    if(vis[v])
        return;
    vis[v] = true;
    for(auto e: G[v]){
        dfs(e, G);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;cin>>n;
    int lastID = 0;
    map<string, int> ids;
    vector<vector<int>> graph;
    
    rep(i,0,n){
        string A; cin>>A;
        A.pop_back();
        string son;cin>>son; string of;cin>>of;
        string B; cin>>B;
        if(ids.count(A)==0){
            graph.push_back({});
            ids[A] = lastID++;
        }
        if(ids.count(B)==0){
            graph.push_back({});
            ids[B] = lastID++;
        }
        graph[ids[B]].push_back(ids[A]);
    }
    
    scc(graph, [&](vi& v){});
    
    vis.assign(n, false);
    int maxm = 0;
    int maxID = 0;
    rep(i,0,n){
        if(comp[i]>maxm)
            {
            maxID = i;
            maxm = comp[i];
            }

    }
    dfs(maxID, graph);
    bool pos = true;
    rep(i,0,n){
        pos&=vis[i];
    }
    if(pos){
        cout<<"possible"<<'\n';
    }
    else
        cout<<"impossible"<<'\n';
}
            graph.push_back({});