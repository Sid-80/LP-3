#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void tabularApproach(vector<int> profit, vector<int> weight, int finalW)
{
    int n = profit.size();

    vector<vector<int>> dp(n + 1, vector<int>(finalW + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= finalW; j++)
        {
            if (j >= weight[i-1])
            {
                dp[i][j] = max(
                    profit[i-1] + dp[i - 1][j - weight[i-1]],
                    dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    
    cout << "Maximum Profit (Tabular): " << dp[n][finalW] << endl;

    return;
}

int solve(int i, vector<int> &profit, vector<int> &weight, int finalW, vector<vector<int>> &dp)
{
    if (i < 0)
    {
        return 0;
    }

    if (dp[i][finalW] != -1)
    {
        return dp[i][finalW];
    }

    int pick = 0;
    if (finalW >= weight[i])
    {
        pick = profit[i] + solve(i - 1, profit, weight, finalW - weight[i], dp);
    }

    int npick = solve(i - 1, profit, weight, finalW, dp);

    dp[i][finalW] = max(pick, npick);
    return dp[i][finalW];
}

void memoizedApproach(vector<int> profit, vector<int> weight, int finalW)
{
    int n = profit.size();
    vector<vector<int>> dp(n, vector<int>(finalW + 1, -1));
    cout << "Maximum Profit (Memoized): " << solve(n - 1, profit, weight, finalW, dp) << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> profit = {100, 60, 120};
    vector<int> weight = {20, 10, 30};
    int finalWeight = 50;

    tabularApproach(profit, weight, finalWeight);

    return 0;
}

// Time Complexity: O(N * logN)
// Auxiliary Space: O(N)