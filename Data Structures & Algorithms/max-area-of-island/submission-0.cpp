
class Solution {
public:
    int bfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vis[i][j] = 1;
        q.push({i,j});

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        int cnt = 0;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            cnt++;

            for(int k=0; k<4; k++){
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                grid[nr][nc] == 1 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int area = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    area = max(area,bfs(i,j,vis,grid));
                }
            }
        }
        return area;
    }
};
