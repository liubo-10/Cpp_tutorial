/*****************************************************************************
 * | @file    : main.c
 * | @author  : liubo
 * | @version : V1.0.0
 * | @date    : 2025-03-24
 * --------------
 * | @brief   : 120. 三角形最小路径和
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int size = 0;
        int result = 0;

        size = triangle.size();

        vector<vector<int>> f(size, vector<int>(size,0));

        f[0][0] = triangle[0][0];
        
        for (int i = 1; i < size; i++)
        {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; j++)
            {

                f[i][j] = std::min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
            }

            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }

        result = f[size - 1][0];
        for (int i = 1; i < size; i++)
        {

            if (result > f[size - 1][i])
            {

                result = f[size - 1][i];
            }
        }

        return result;
    }
};

/*****************************************************************************
 * end of file
 ******************************************************************************/

 




