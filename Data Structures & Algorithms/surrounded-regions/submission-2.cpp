class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis){
        vis[i][j] = 1;

        int n = board.size();
        int m = board[0].size();

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int k=0; k<4; k++){
            int nr = i + drow[k];
            int nc = j + dcol[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && !vis[nr][nc]){
                vis[nr][nc] = 1;
                dfs(nr,nc,board,vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i,0,board,vis);
            }
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis);
            }
        }

        for(int j=0; j<m; j++){
            if(board[0][j] == 'O' && vis[0][j] == 0){
                dfs(0,j,board,vis);
            }
            if(board[n-1][j] == 'O' && vis[n-1][j] == 0){
                dfs(n-1,j,board,vis);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
