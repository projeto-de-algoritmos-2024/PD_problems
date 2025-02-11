/**
 * Knapsack with Duplicate Items
 *
 * Given a set of items, each with a weight and a value, represented by the array wt and
 * val respectively. Also, a knapsack with a weight limit capacity.
 *
 * The task is to fill the knapsack in such a way that we can get the maximum profit.
 * Return the maximum profit.
 *
 * Note: Each item can be taken any number of times.
 * 
 * Difficulty Level: Medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int knapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        vector<vector<int>> opt(val.size() + 1, vector<int>(capacity + 1, 0));

        for (int row = 1; row <= (int)val.size(); row++)
        {
            for (int col = 1; col <= capacity; col++)
            {
                if (wt[row - 1] <= col)
                    opt[row][col] = max(val[row - 1] + opt[row][col - wt[row - 1]], opt[row - 1][col]);
                else
                    opt[row][col] = opt[row - 1][col];
            }
        }
        return opt[val.size()][capacity];
    }
};