#include<bits/stdc++.h>
using namespace std;

string printMat(int mat[][9])
{
    string s = "";
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            s += mat[i][j] + '0';
    return s;
}

bool notInBox(int mat[][9],int num,int row,int col)
{
    int s_row = (row / 3) * 3;
    int s_col = (col / 3) * 3;
    for(int i = s_row; i < s_row + 3; i++)
        for(int j = s_col; j < s_col + 3; j++)
            if(mat[i][j]==num)
                return false;
    return true;
}

bool isSafe(int mat[][9],int *row,int *col,int n,int num)
{
    return (!(col[n%9] & 1<<num)) &  (!(row[n/9] & 1<<num))  & notInBox(mat,num,n/9,n%9);
}

bool solve(int mat[][9],int *row,int *col,int n)
{
    if(n==81)
        return true;
    if(mat[n/9][n%9]!=0)
        return solve(mat,row,col,n+1);
    for(int i = 1; i <= 9; i++)
    {
        if(isSafe(mat,row,col,n,i))
        {
            row[n/9] |= 1<<i;
            col[n%9] |= 1<<i;
            mat[n/9][n%9] = i;
            if(solve(mat,row,col,n+1))
                return true;
            mat[n/9][n%9] = 0;
            int x = 1<<i;
            int y = ~x;
            row[n/9] &= y;
            col[n%9] &= y;
        }
    }  
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    int mat[9][9] = {0,0};
    string ip;
    cin >> tc;
    while(tc--)
    {
        cin >> ip;
        int *row = new int[9]();
        int *col = new int[9]();
        for(int i = 0; i < ip.length(); i++)
        {
            if(ip[i]!='.')
            {
                mat[i/9][i%9] = ip[i] - '0';
                row[i/9] |= 1<<mat[i/9][i%9];
                col[i%9] |= 1<<mat[i/9][i%9];
            }
            else
                mat[i/9][i%9] = 0;
        }
        //printMat(mat);
        cout << "Y\n";
        solve(mat,row,col,0);
        cout << printMat(mat) << "\n";
    }
    return 0;
}
