class Solution {
public:
    bool vis[10][10];
    int vis_count{};
    int m,n;
    
    bool valid(int i, int j, vector<vector<int>>& matrix) {
        if(i >= m || i<0 || j >= n || j<0 || vis[i][j])
            return false;
        
        vis[i][j] = true;
        vis_count++;
        return true;
    }       

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int i{}, j{};

        vector<int> ans;
        while(vis_count < n*m) {
            
            // Moving right
            if(valid(i,j,matrix)) {
                ans.push_back(matrix[i][j]);
                j++;

                while(valid(i,j,matrix))
                    ans.push_back(matrix[i][j]), j++;

                j--;
            }
            i++;


            // Moving down
            if(valid(i,j,matrix)) {
                ans.push_back(matrix[i][j]);
                i++;

                while(valid(i,j,matrix))
                    ans.push_back(matrix[i][j]), i++;

                i--;
            }
            j--;

            // Moving left
            if(valid(i,j,matrix)) {
                ans.push_back(matrix[i][j]);
                j--;

                while(valid(i,j,matrix))
                    ans.push_back(matrix[i][j]), j--;

                j++;
            }
            i--;
                

            // Moving up
            if(valid(i,j,matrix)) {
                ans.push_back(matrix[i][j]);
                i--;

                while(valid(i,j,matrix))
                    ans.push_back(matrix[i][j]), i--;

                i++;
            }
            j++;
        }

        return ans;
    }
};
