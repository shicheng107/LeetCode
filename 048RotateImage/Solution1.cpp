class Solution

{

public:

    void rotate(vector<vector<int> > &matrix)

    {

        int n = matrix.size();

        vector<int> row(n, 0);

        vector<vector<int> > output(n, row);

        for (int x = 0; x < n; x++)

            for (int y = 0; y < n; y++)

                output[x][y] = matrix[n - y - 1][x];

        matrix = output;

    }

};

