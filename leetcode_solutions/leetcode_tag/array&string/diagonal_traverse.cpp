class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
        	return res;
    
	    int row = matrix.size() - 1;
	    int col = matrix[0].size() - 1;
	    bool flag = true;    //true for up, false for down
	    
	    for (int i = 0; i <= (row + col); i++)
	    {
	        if (flag)
	        {
	            int r = 0, c = 0;
	            if (i <= row)
	            {
	                r = i;
	                c = 0;
	            }
	            else
	            {
	                r = row;
	                c = i - row;
	            }
	            while (r >= 0 && c <= col)
	            {
	                res.push_back(matrix[r][c]);
	                r--;
	                c++;
	            }
	            flag = false;
	        }
	        else
	        {
	            int r = 0, c = 0;
	            if (i <= col)
	            {
	                c = i;
	                r = 0;
	            }
	            else
	            {
	                c = col;
	                r = i - col;
	            }
	            while (r <= row && c >= 0)
	            {
	                res.push_back(matrix[r][c]);
	                r++;
	                c--;
	            }
	            flag = true;
	        }
	    }

    	return res;
    }
};

/*
0 0
0 1, 1 0
2 0, 1 1, 0 2
1 2, 2 1
2 2


*/