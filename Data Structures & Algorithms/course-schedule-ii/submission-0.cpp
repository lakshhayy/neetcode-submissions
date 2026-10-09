class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int> indeg(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            cnt++;

            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }

        if(cnt != numCourses){
            return {};
        }
        return ans;
    }
};
