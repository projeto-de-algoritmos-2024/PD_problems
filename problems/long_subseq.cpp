/**
 * Longest Common Subsequence
 *
 * Given two strings s1 and s2, return the length of their longest common subsequence
 * (LCS). If there is no common subsequence, return 0.
 *
 * A subsequence is a sequence that can be derived from the given string by deleting some
 * or no elements without changing the order of the remaining elements. For example,
 * "ABE" is a subsequence of "ABCDE".
 *
 * Difficulty Level: Medium
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int lcs(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> opt(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    opt[i][j] = 1 + opt[i - 1][j - 1];
                else 
                    opt[i][j] = max(opt[i - 1][j], opt[i][j - 1]); 
            }
        }
        return opt[n][m];
    }
};