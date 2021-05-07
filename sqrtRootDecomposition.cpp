// Sqrt Root Decompositioon

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	int n, q; cin >> n >> q;
	int arr[n+1];
	int sq = sqrt(n);
	ll sqrtSum[sq+5] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sqrtSum[i/sq] += arr[i];
	}
	while(q--)
	{
		int qt; cin >> qt;
		if(qt == 1)
		{
			// update
			int pos, val; cin >> pos >> val;
			pos--;
			sqrtSum[pos/sq] -= arr[pos];
			arr[pos] = val;
			sqrtSum[pos/sq] += val;
		}
		else
		{
			// query
			int l, r; cin >> l >> r;
			l--; r--;
			int sql = l/sq;
			int sqr = r/sq;
			ll sum = 0;
			if(sql == sqr)
			{
				// same block
				for(l; l <= r; l++)
				{
					sum += arr[l];
				}
			}
			else
			{
				// left side
				int len = (sql+1)*sq-1;
				for(int i = l; i <= len; i++)
					sum += arr[i];
				// right side
				len = sq*sqr;
				for(int i = r; i >= len; i--)
					sum += arr[i];
				// block sqrtsum
				for(int i = sql+1; i < sqr; i++)
					sum += sqrtSum[i];

			}
			cout << sum << '\n';
		}
	}
    return 0;
}