class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        int width = n / 2;
        int height = n / 2;
        if (n % 2 != 0)
            width += 1;
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                int xx = x;
                int yy = y;
                int temp = matrix[xx][yy];
                for (int i = 0; i < 3; i++)
                {
                    matrix[xx][yy] = matrix[n - yy - 1][xx];
                    int tempxx = n - yy - 1;
                    int tempyy = xx;
                    xx = tempxx;
                    yy = tempyy;
                }
                matrix[xx][yy] = temp;
            }
        }
    }
};
