class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
  		vector<int> res;
  		if (matrix.empty())
  			return res;

  		int row = matrix.size();
  		int col = matrix[0].size();
  		int up = 0, right = col - 1, down = row - 1, left = 0;

  		while (true)
  		{
  			//up
  			for (int c = left; c <= right; ++c)
  				res.push_back(matrix[up][c]);
  			if (++up > down)
  				break;

  			//right
  			for (int r = up; r <= down; ++r)
  				res.push_back(matrix[r][right]);
  			if (--right < left)
  				break;

  			//down
  			for (int c = right; c >= left; --c)
  				res.push_back(matrix[down][c]);
  			if (--down < up)
  				break;

  			//left
  			for (int r = down; r >= up; --r)
  				res.push_back(matrix[r][left]);
  			if (++left > right)
  				break;
  		}

  		return res;
    }
};

