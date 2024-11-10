#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first / p1.second) > (p2.first / p2.second);
}

int main(int argc, char const *argv[])
{
    vector<pair<int, int>> arr = {{100, 20}, {60, 10}, {120, 30}}; // p,w
    int finalWeight = 50;

    sort(arr.begin(), arr.end(), compare);

    double ans = 0.0;

    for (auto it : arr)
    {
        if (it.second <= finalWeight)
        {
            finalWeight -= it.second;
            ans += it.first;
        }
        else
        {
            ans += it.first *  ((double)finalWeight / (double)it.second);
            break;
        }
    }

    cout << ans << endl;

    return 0;
}

// Time Complexity: O(N * logN)
// Auxiliary Space: O(N)