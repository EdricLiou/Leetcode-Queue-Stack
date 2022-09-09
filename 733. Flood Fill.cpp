//DFS

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        helper(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    void helper(vector<vector<int>>& image, int i, int j, int color, int newColor) {
        int m = image.size(), n = image[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || image[i][j] != color) return;
        image[i][j] = newColor;
        helper(image, i + 1, j, color, newColor);
        helper(image, i, j + 1, color, newColor);
        helper(image, i - 1, j, color, newColor);
        helper(image, i, j - 1, color, newColor);
    }
};

//https://www.cnblogs.com/grandyang/p/7990046.html

//BFS

class Solution {
public:
    queue<pair<int, int>> q;
    vector<pair<int, int>> visited;
    
    bool isVisited(int r, int c){
        return find(visited.begin(), visited.end(), make_pair(r, c))!=visited.end();
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        q.push(make_pair(sr, sc));
        
        //BFS a graph
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            sr = p.first;
            sc = p.second;
            // cout << sr << " " << sc << endl;
            
            image[sr][sc] = newColor;
            visited.push_back(make_pair(sr, sc));
            
            if(sr > 0 && !isVisited(sr-1, sc) && image[sr-1][sc]==oldColor){
                q.push(make_pair(sr-1, sc));
            }
            if(sc > 0 && !isVisited(sr, sc-1) && image[sr][sc-1]==oldColor){
                q.push(make_pair(sr, sc-1));
            }
            if(sr < image.size()-1 && !isVisited(sr+1, sc) && image[sr+1][sc]==oldColor){
                q.push(make_pair(sr+1, sc));
            }
            if(sc < image[0].size()-1 && !isVisited(sr, sc+1) && image[sr][sc+1]==oldColor){
                q.push(make_pair(sr, sc+1));
            }
        }
        
        return image;
    }
};
