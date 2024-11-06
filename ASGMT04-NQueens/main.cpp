/*
Design n-Queens matrix having first Queen placed. Use backtracking to place
remainingQueens to generate the final n-queen
*/

#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<string>> result;

bool isSafe(vector<string> &board, int row, int col)
{
    // Upward Check
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
    }

    // Upward-Left Check
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }

    // Upward-Right Check
    for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }

    return true;
}

void solve(vector<string> &board,int row)
{
    if(row>=N)
    {
        result.push_back(board);
        return;
    }

    for(int col=0;col<N;col++)
    {
        if(isSafe(board,row,col))
        {
            board[row][col]='Q';
            solve(board,row+1);
            board[row][col]='-';
        }
    }

}

void print_boards()
{
    if(result.size()>0)
    {
        for(int i=0;i<result.size();i++)
        {
            cout<<"Board "<<i+1<<":-"<<endl;
            for(int j=0;j<result[i].size();j++)
            {
                cout<<result[i][j]<<endl;
            }
            cout<<endl;
        }

    }
    else
    {
        cout<<"No Boards Possible"<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter number of Queens:- "<<endl;
    cin>>n;

    N=n;

    vector<string> board(N,string(N,'-')); // Character -

    solve(board,0); // Starting from row=0

    print_boards();

    return 0;
}

/*
Output:-
Enter number of Queens:- 
4
Board 1:-
-Q--
---Q
Q---
--Q-

Board 2:-
--Q-
Q---
---Q
-Q--
 */

/*
TC:- O(n!)
Extra Auxillary Space :- O(n^2) board
System Stack Space:- O(n)
 */