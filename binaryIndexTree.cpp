// Sqrt Root Decompositioon

#include <bits/stdc++.h>

using namespace std;
const int LIM = (int) 2e5 + 5;
typedef long long ll;

ll arr[LIM];
ll arrBIT[LIM], n;

void update(ll pos, ll val)
{
	while(pos <= n)
	{
		arrBIT[pos] += val;
		pos += pos & (-pos);
	}
}

ll sumq(ll pos)
{
    ll s=0;
    while(pos>=1)
    {
        s+=arrBIT[pos];
        pos -= pos&(-pos);
    }
    return s;
}

int main(int argc, char const *argv[])
{
	int q; cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		update(i, arr[i]);
	}
	while(q--)
	{
		int qt; cin >> qt;
		if(qt == 1)
		{
			// update
			ll pos, val; cin >> pos >> val;
			update(pos, val-arr[pos]);
			arr[pos] = val;
		}
		else
		{
			// query
			ll l, r; cin >> l >> r;
			cout << sumq(r) - sumq(l-1) << '\n';
		}
	}
    return 0;
}