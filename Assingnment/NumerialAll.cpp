#include<bits/stdc++.h>

using namespace std;

double a[50][50];
double x[50];
int n;

void Pivot_gauss()
{
	for(int k = 1; k < n; k++)
	{
        int mxI = k;
        double mxV = fabs(a[k][k]);
        for(int i = k + 1; i <= n; i++)
        {
            if(fabs(a[i][k]) > mxV)
            {
                mxV = fabs(a[i][k]);
                mxI = i;
            }
        }

        if(k != mxI)
        {
            for(int i = 1; i <= n+1; i++)
            {
                swap(a[k][i], a[mxI][i]);
            }
        }

        if(a[k][k] == 0.0)continue;

		for(int i = k + 1; i <= n; i++)
		{
			for(int j = k+1; j <= n + 1; j++)
			{
				a[i][j] = a[i][j] -  a[i][k] / a[k][k] * a[k][j];
			}
			a[i][k] = 0.0;
		}
	}

	 x[n] = a[n][n+1] / a[n][n];
    for(int i = n - 1; i >= 1; i--)
    {
        double sum = 0;
        for(int j = i + 1; j <= n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n+1] - sum) / a[i][i];
    }

    cout << "\nShow the Result Pivot: \n";
    for(int i = 1; i <= n; i++)
    {
        cout << "X" << i << " = " << x[i] << endl;
    }
    cout << endl;
}

void Jordan()
{
    for(int k = 1; k <= n; k++)
	{
	    if(a[k][k] == 0.0)
        {
            int mxI = k;
            double mxV = fabs(a[k][k]);
            for(int i = k + 1; i <= n; i++)
            {
                if(fabs(a[i][k]) > mxV)
                {
                    mxV = fabs(a[i][k]);
                    mxI = i;
                }
            }

            if(k != mxI)
            {
                for(int i = 1; i <= n+1; i++)
                {
                    swap(a[k][i], a[mxI][i]);
                }
            }
        }
        double pivot = a[k][k];
        for(int i = 1; i <= n+1; i++)
        {
            a[k][i] = (a[k][i] / pivot);
        }
        a[k][k] = 1;


		for(int i = 1; i <= n; i++)
		{
		    if(i == k)continue;
		    pivot = a[i][k];
			for(int j = 1; j <= n + 1; j++)
			{
				a[i][j] = a[i][j] -  (pivot * a[k][j]);
			}
			a[i][k] = 0.0;
		}
	}

    cout << "\nShow the Result of Jordan: \n";
    for(int i = 1; i <= n; i++)
    {
        cout << "X" << i << " = " << a[i][n+1] << endl;
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n + 1; j++)
		{
			cin >> a[i][j];
		}
	}
	Pivot_gauss();
	Jordan();
    return 0;
}
/**
check input:

4
6 -2.0 2 4 16
12 -8 6 10 26
3 -13 9 3 -19
-6 4 1 -18 -34

3
3.0 -0.1 -0.2 7.85
0.1 7.0 -0.3 -19.3
0.3 -0.2 10.0 71.4

4
0 2 0 1 0
2 2 3 2 -2
4 -3 0 1 -7
6 1 -6 -5 6

*/



