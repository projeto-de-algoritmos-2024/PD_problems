/**
 * 0-1 Knapsack Problem
 *
 * You are given the weights and values of items, and you need to put these items in a knapsack of capacity capacity to achieve the maximum total value in
 * the knapsack. Each item is available in only one quantity.
 *
 * In other words, you are given two integer arrays val[] and wt[], which represent the values and weights associated with items, respectively. You are
 * also given an integer capacity, which represents the knapsack capacity. Your task is to find the maximum sum of values of a subset of val[] such that
 * the sum of the weights of the corresponding subset is less than or equal to capacity. You cannot break an item; you must either pick the entire item or
 * leave it (0-1 property).
 *
 * Difficulty Level: Medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int knapsack(int capacity, vector<int> &val, vector<int> &wt)
    {
        vector<vector<int>> opt(val.size() + 1, vector<int>(capacity + 1, 0));

        for (int row = 1; row <= (int)val.size(); row++)
        {
            for (int col = 1; col <= capacity; col++)
            {
                if (wt[row - 1] <= col)
                    opt[row][col] = max(val[row - 1] + opt[row - 1][col - wt[row - 1]], opt[row - 1][col]);
                else
                    opt[row][col] = opt[row - 1][col];
            }
        }

        return opt[val.size()][capacity];
    }
};

int main ()
{
    Solution s;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    cout << s.knapsack(capacity, val, wt) << endl;

    return 0;
}