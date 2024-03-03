short di[4] {0,0,1,-1};
short dj[4] {1,-1,0,0};
int n,m,c, target;

bool valid(int i, int j) {
    return i<n && i>=0 and j<m && j>=0;
}

void dfs(vector<vector<int>> &image, vector<vector<bool>> &vis, int i, int j) {
    vis[i][j] = true;
    image[i][j] = c;

    for(int k{}; k<4; k++) {
        int i2 = i+di[k];
        int j2 = j+dj[k];
        
        if(valid(i2, j2) && !vis[i2][j2] && image[i2][j2] == target)
            dfs(image, vis, i2, j2);
    }
    
}


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size(); 
        vector<vector<bool>> vis(n,vector<bool>(m));
        c = color;
        target = image[sr][sc];
        
        
        dfs(image, vis, sr, sc);
        return image;
    }
};
