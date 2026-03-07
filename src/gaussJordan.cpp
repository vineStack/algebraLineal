#include <vector>
using namespace std;

vector<vector<double>> multiplicacion(const vector<vector<double>> &A, const vector<vector<double>> &B, int n, int m, int p)
{
    vector<vector<double>> C(n, vector<double>(p,0.0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < m; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    return C;
}