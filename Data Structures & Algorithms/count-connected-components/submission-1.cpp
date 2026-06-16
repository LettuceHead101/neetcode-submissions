// disjoint set union
struct DSU{
    vector<int> parent;// who is the parent of node i (where i is the index) at index i
    vector<int> group_count;
    int groups;
    DSU(int n ): group_count(n,1), groups(n){
        parent.resize(n);
        for(int i = 0; i < n; ++i){
            parent[i] = i;
        }
    }

    int find_parent(int u){
        if(parent[u] != u){
            parent[u] = find_parent(parent[u]);
        }
        return parent[u];
    }

    bool union_helper(int u , int v){
        int up = find_parent(u);
        int vp = find_parent(v);

        if(up == vp)return false;

        if(group_count[vp] > group_count[up]){
            swap(up,vp);
        }
        group_count[up] += group_count[vp];
        parent[vp] = up;
        groups--;
        return true;
    }

    int count(){
        return groups;
    }
        

};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            dsu.union_helper(u,v);

        }
        return dsu.count();
    }
};
