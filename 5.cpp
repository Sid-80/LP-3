#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(int row, int col, vector<vector<string>> board, int n)
{

    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == "X")
            return false;
    }

    int r = row - 1, c = col - 1;
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == "X")
            return false;
        r -= 1;
        c -= 1;
    }

    r = row - 1;
    c = col + 1;
    while (r >= 0 && c < n)
    {
        if (board[r][c] == "X")
            return false;
        r -= 1;
        c += 1;
    }

    return true;
}

void solve(int row, vector<vector<string>> &board, vector<vector<vector<string>>> &ans, int n)
{
    if (row == n)
    {
        cout << ans.size() << endl;
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isValid(row, col, board, n))
        {
            board[row][col] = "X";
            solve(row + 1, board, ans, n);
            board[row][col] = ".";
        }
    }

    return;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<string>> board(n, vector<string>(n, "."));

    vector<vector<vector<string>>> ans;

    solve(0, board, ans, n);

    for (int k = 0; k < ans.size(); k++)
    {
        cout << "Solution " << k + 1 << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[k][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}