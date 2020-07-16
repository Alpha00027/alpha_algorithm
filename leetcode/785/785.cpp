class Solution {
private:
    bool valid;  // 目前的二分图是否有效
    vector<int> set;    // 元素所在集合编号，0：待定，1：集合1，2：集合2.

public:
    bool isBipartite(vector<vector<int>>& graph) {
        valid = true;   // 初值认为是有效的
        set.assign(graph.size(),0); // 认为目前的所有元素都待定
        // 可能是非连通图，需要全部遍历一次，不同的子图需要全部为二分图
        for(int node = 0;node < graph.size() && valid;node++) 
        {
            // 如果该节点是图内第一个被选中的元素，假定该节点属于集合1，（剩余节点应该都会在dfs函数中处理）
            if(set[node] == 0)
                dfs(node,1,graph);
        }
        return valid;
    }

    //
    // node:节点编号
    // set_id:集合编号
    // graph:图
    void dfs(int node,int set_id,const vector<vector<int>>& graph)
    {
        set[node] = set_id; // 设定当前节点的所属集合
        int node_neibor_set_id = (set_id == 1?2:1);  // 判断邻居所属的集合

        for(int node_neibor : graph[node]){ // 遍历该节点的所有邻居
            if(set[node_neibor] == 0){   // 如果邻居的集合待定
                dfs(node_neibor,node_neibor_set_id,graph);  // 遍历该邻居节点
            }
            // 该邻居本身所在的集合和计算出的结果不一致，说明非二分图
            else if(set[node_neibor] != node_neibor_set_id){
                valid = false;  // 设置该二分图非法
            }
            if(!valid) return;  // 如果非二分图，则退出
        }
    }
};