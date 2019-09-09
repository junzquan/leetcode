class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return matrix;
        int cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int> > q;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        
        int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = curr.first + dir[i][0], y = curr.second + dir[i][1];
                if (x >= 0 && x < rows && y >= 0 && y < cols 
                    && dist[x][y] > dist[curr.first][curr.second] + 1)
                {
                    dist[x][y] = dist[curr.first][curr.second] + 1;
                    q.push(make_pair(x, y));
                }
            }
        }

        return dist;
    }
};