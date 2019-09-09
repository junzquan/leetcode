// DFS

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), int col = row ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < row; i++)
        {
        	for (int j = 0; j < col; j++)
        	{
        		if (grid[i][j] == '1')
        		{
        			islands++;
        			eraseIslands(grid, i, j);
        		}
        	}
        }
    }

private:
	void eraseIslands(vector<vector<char>>& grid, int i, int j)
	{
		int row = grid.size(), col = grid[0].size();
		if (i < 0 || i == row || j < 0 || j == col || grid[i][j] == '0')
			return;
		grid[i][j] = '0';
		eraseIslands(grid, i - 1, j);
		eraseIslands(grid, i + 1, j);
		eraseIslands(grid, i, j - 1);
		eraseIslands(grid, i, j + 1);
	}
};