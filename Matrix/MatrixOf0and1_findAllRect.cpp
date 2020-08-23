#include <iostream>
#include <vector>
using namespace std;

void findEnd(vector<vector<int>> &mat, int row, int col, vector<int> &rectCor)
{
    int i = 0, j = 0;
    for (i = row; i < mat.size(); ++i)
    {
        if (mat[i][col] == 1)
            break;
        for (j = col; j < mat[0].size(); ++j)
        {
            if (mat[i][j] == 1)
            {
                break;
            }
            mat[i][j] = 2;
        }
    }
    rectCor.push_back(i - 1);
    rectCor.push_back(j - 1);
}

void findIndex(vector<vector<int>> &mat)
{
    vector<vector<int>> output;
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[0].size(); ++j)
        {
            if (mat[i][j] == 0)
            {
                vector<int> temp = {i, j};
                findEnd(mat, i, j, temp);
                output.push_back(temp);
                temp.clear();
            }
        }
    }
    for (auto &rect : output)
    {
        for (int cord : rect)
        {
            cout << cord << ",";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> mat = {{1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 1, 1, 1, 1},
                               {1, 1, 1, 0, 0, 0, 1},
                               {1, 0, 1, 0, 0, 0, 1},
                               {1, 0, 1, 1, 1, 1, 1},
                               {1, 0, 1, 0, 0, 0, 0},
                               {1, 1, 1, 0, 0, 0, 1},
                               {1, 1, 1, 1, 1, 1, 1}};
    findIndex(mat);
}