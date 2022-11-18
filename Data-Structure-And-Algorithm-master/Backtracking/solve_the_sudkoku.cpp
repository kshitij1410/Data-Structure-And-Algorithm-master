//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends
class Solution
{
public:
    // Function to find a solved Sudoku.
    bool isValid(int grid[N][N], int k, int i, int j)
    {
        for (int idx = 0; idx < N; idx++)
        {
            // for rows
            if (grid[i][idx] == k)
                return false;

            // for col
            if (grid[idx][j] == k)
                return false;

            if (grid[3 * (i / 3) + (idx / 3)][3 * (j / 3) + (idx % 3)] == k)
                return false;
        }

        return true;
    }

    bool SolveSudoku(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (isValid(grid, k, i, j) == true)
                        {
                            grid[i][j] = k;
                            bool temp = SolveSudoku(grid);
                            if (temp == false)
                                grid[i][j] = 0;
                            else
                                return temp;
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}
// } Driver Code Ends