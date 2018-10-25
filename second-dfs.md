/*
 * 利用深度优先搜索遍历每个节点
 * 如果节点为0，将当前节点所属岛屿面积加一
 * 如果当前节点为0且周围任意一个节点超过边界，那么当前节点所在地不是一个岛屿，之前的面积作废 返回 -1
 * 如果当前节点为1 跳过该节点
 * 最终用两个变量记录最大值与次大值 如果次大值为0 输出最大值
 * 时间复杂度 O(n*n)
 */

	#include <bits/stdc++.h>
	using namespace std;
	const int MAX = 1000 + 5;
	bool mp[MAX][MAX];
	bool vis[MAX][MAX];
	int n;
	int dir[4][2] = {
	    {-1,0},{1,0},{0,-1},{0,1} //上，下，左，右
	};
	int dfs(int x, int y) {
	    int xx,yy;
	    int res = 1;
	    mp[x][y] = 1;
	    for(int i = 0; i < 4; i++) {
	        xx = x + dir[i][0];
	        yy = y + dir[i][1];
	
	        if( !(xx >= 1 && xx <= n && yy >= 1 && yy <= n)) return -1; // 越过边	界 返回-1
	        if(mp[xx][yy] == 0) {                                       //移动到与	当前节点相连岛屿 
	            int num = dfs(xx, yy);
	            if(num == -1) return -1;
	            res += num;
	        }
	    }
	    return res;
	}
	int main() {
	    cin >> n;
	    for(int i = 1; i <= n; i++) {
	        for(int j = 1; j <= n; j++)
	            cin >> mp[i][j];
	    }
	    int max_f = 0, max_s = 0; //first max and second max
	    for(int i = 1; i <= n; i++)             //遍历每个节点 记录最大值与次大值
	        for(int j = 1; j <= n; j++) {
	            if(mp[i][j]) continue;
	            else {
	                int size = dfs(i,j);
	                if(size > max_f) {
	                    max_s = max_f, max_f = size;
	                } else if(size > max_s) {
	                    max_s = size;
	                }
	            }
	        }
	    if(max_s > 0) cout << max_s << endl;
	    else cout << max_f << endl;
	    return 0;
	}