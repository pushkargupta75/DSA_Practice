class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int n=routes.size();
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            for(auto& stop:routes[i]){
                mp[stop].push_back(i);
            }
        }
        queue<int> q;
        for(auto& bus: mp[source]){
            q.push(bus);
            visited[bus]=true;
        }
        int count=1;
        while(!q.empty()){
            int size=q.size();  
            while(size--){
                int n_s=q.front();
                q.pop();
                for(auto& stop:routes[n_s]){
                    if(stop==target) return count;
                    for(auto&next:mp[stop]){
                        if(visited[next]==false){
                            visited[next]=true;
                            q.push(next);
                        }
                    }
                }
            }
            count++;

        }
        return -1;
    }
};