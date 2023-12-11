//前言
//我们可以将本题抽象成如下的一个图论模型：

//我们将地图中的每一个格子看成图中的一个节点；

//我们将两个相邻（左右相邻或者上下相邻）的两个格子对应的节点之间连接一条无向边，边的权值为这两个格子的高度差的绝对值；

//我们需要找到一条从左上角到右下角的最短路径，其中一条路径的长度定义为其经过的所有边权的最大值。

//方法一：二分查找
//我们可以将这个问题转化成一个「判定性」问题，即：

//是否存在一条从左上角到右下角的路径，其经过的所有边权的最大值不超过x？

//这个判定性问题解决起来并不复杂，我们只要从左上角开始进行深度优先搜索或者广度优先搜索，在搜索的过程中只允许经过边权不超过 x 的边，搜索结束后判断是否能到达右下角即可。

//随着 x 的增大，原先可以经过的边仍然会被保留，因此如果当 x=x0 时，我们可以从左上角到达右下角，那么当 x>x0 时同样也可以可行的。因此我们可以使用二分查找的方法，找出满足要求的最小的那个 x 值，记为 xans
//那么：
//当 x<xans ，我们无法从左上角到达右下角；
//当 x≥xans ，我们可以从左上角到达右下角。

//由于格子的高度范围为 [1,10^6]，因此我们可以在 [0,10^6−1] 的范围内对 xxx 进行二分查找。在每一步查找的过程中，我们使用进行深度优先搜索或者广度优先搜索判断是否可以从左上角到达右下角，并根据判定结果更新二分查找的左边界或右边界即可。

class Solution{
private:
    static constexpr int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

public:
    int minimumEffortPath(vector<vector<int>>& heights){
        int m = heights.size();
        int n = heights[0].size();
        int left = 0,right = 999999,ans = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            queue<pair<int ,int>> q;
            q.emplace(0,0);
            vector<int>seen(m * n);
            seen[0] = 1;
            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();
                for (int i = 0;i < 4; ++i){
                    int nx = x + dirs[i][0];
                    int ny = y + dirs[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx * n + ny] && abs(heights[x][y] - heights[nx][ny]) <= mid){
                        q.emplace(nx,ny);
                        seen[nx * n + ny] = 1;
                    }
                }
            }
            if (seen[m * n - 1]){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }        
};