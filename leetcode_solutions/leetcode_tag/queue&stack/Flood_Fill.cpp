class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        floodFill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    
private:
    void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor) return;
        image[sr][sc] = newColor;
        floodFill(image, sr - 1, sc, newColor, oldColor);
        floodFill(image, sr + 1, sc, newColor, oldColor);
        floodFill(image, sr, sc - 1, newColor, oldColor);
        floodFill(image, sr, sc + 1, newColor, oldColor);
    }
};
