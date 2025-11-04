#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define ar array

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> indices(n, vector<int>(m));
	rep(i,k){
		int x, y;cin>>x>>y;
		indices[x-1][y-1] = i+1;
	}

	int u1,v1,u2,v2;cin>>u1>>v1>>u2>>v2;
	--u1;--v1;
	
	int l = 0;
	int r = m+1;
	for(int i = u1; i<u2; i++){
		for(int j = v1; j<v2; j++){
			l = max(indices[i][j],l);
		}
	}
	int best = k+1;
	vector<ar<int,2>> dirs = {{0,-1}, {0,1}, {1,0},{-1, 0}};
	while(l<=r){
		int mid = (l+r)/2;
		vector<vector<bool>> vis(n, vector<bool>(m));
		queue<ar<int,2>> q;
		for(int i = u1; i<u2; i++){
			for(int j = v1; j<v2; j++){
				q.push({i,j});
			}
		}
		int free = 0;
		while(!q.empty()){
			ar<int,2> pos = q.front();
			q.pop();
			if(pos[0]<0||pos[0]>=n||pos[1]<0||pos[1]>=m)
				continue;
			if(vis[pos[0]][pos[1]]||indices[pos[0]][pos[1]]>mid)continue;
			if (indices[pos[0]][pos[1]]==0){
				free++;
			}
			vis[pos[0]][pos[1]] = true;
			for(auto dir: dirs){
				q.push({pos[0]+dir[0], pos[1]+dir[1]});
			}
		}
		if(free>=(u2-u1)*(v2-v1)){
			best = min(best, mid);
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}

	if(best==k+1)
		cout<<-1<<'\n';
	else
		cout<<best<<'\n';
}
