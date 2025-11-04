#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define ar array
#define all(x) x.begin(),x.end()

bool dfs(int a, int L, vector<vector<int>>& g, vector<int>& btoa, vector<int> &A, vector<int> &B){
	if (A[a]!=L) return 0;
	A[a] = -1;
	for(int b: g[a]) if(B[b]==L+1){
		B[b] = 0;
		if(btoa[b]==-1 || dfs(btoa[b], L+1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vector<int>> &g, vector<int>& btoa){
	int res = 0; 
	vector<int> A(g.size()), B(btoa.size()), cur, next;
	for(;;){
		fill(all(A), 0);
		fill(all(B), 0);
		cur.clear();
		for(int a: btoa) if(a!=-1) A[a]=-1;
		rep(a, g.size()) if(A[a]==0) cur.push_back(a);
		for(int lay=1;; lay++){
			bool islast=0;
			next.clear();
			for(int a:cur)for (int b:g[a]){
				if(btoa[b]==-1){
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] !=a && !B[b]){
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if(islast)break;
			if(next.empty())return res;
			for(int a: next) A[a]=lay;
			cur.swap(next);
		}
		rep(a, g.size())
			res+=dfs(a, 0, g, btoa, A, B);
	}
}

int main(){
	int n;cin>>n;
	vector<vector<int>> arr(n, vector<int>(n));
	vector<vector<int>> arr0(n, vector<int>(n,-1));
	int zeros = 0;
	rep(i,n){
		rep(j,n){
			cin>>arr[i][j];
			if (arr[i][j]==0){
				arr0[i][j] = zeros;
				zeros++;
			}
		}
	}

	vector<int> btoa(zeros, -1);
	vector<vector<int>> g;

	int stonesGT1 = 0;
	rep(i,n){
		rep(j,n){
			if (arr[i][j]>1){
				rep(stone, arr[i][j]-1){
					g.push_back({});
					rep(k,n){
						if (k!=i && arr0[k][j]!=-1){
							g.back().push_back(arr0[k][j]);
						}
						if (k!=j && arr0[i][k]!=-1){
							g.back().push_back(arr0[i][k]);
							
						}
					}
				}
				stonesGT1 += arr[i][j]-1;
			}
		}
	}

	int ones = hopcroftKarp(g, btoa);

	cout<<ones+2*(stonesGT1-ones)<<'\n';

}
