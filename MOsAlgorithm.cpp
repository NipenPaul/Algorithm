#include <bits/stdc++.h>

using namespace std;

class queries
{
public:
	int left, right, position;
};
int block;
bool comp(queries a, queries b)
{
	if(a.left/block != b.left/block)
		return a.left/block <= b.left/block;
	return a.right <= b.right;
}
int main(int argc, char const *argv[])
{
	int n, q; scanf("%d %d", &n, &q);
	std::vector<int64_t> v(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%ld", &v[i]);
	}
	int l, r;
	std::vector<queries> que;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d %d", &l, &r);
		que.push_back({l-1, r-1, i});
	}
	block = sqrt(n) + 1;
	sort(que.begin(), que.end(), comp);
	std::vector<int64_t> ans(q);
	l = 0, r = 0;
	int64_t sum = v[0];
	for (int i = 0; i < q; ++i)
	{
		while(que[i].right > r)
		{
			sum += v[++r];
		}
		//printf("%ld %d %d\n", sum, l, r);
		while(que[i].left < l)
		{
			sum += v[--l];
		}
		//printf("%ld %d %d\n", sum, l, r);
		while(que[i].right < r)
		{
			sum -= v[r--];
		}
		//printf("%ld %d %d\n", sum, l, r);
		while(que[i].left > l)
		{
			sum -= v[l++];
		}
		//printf("%ld %d %d\n", sum, l, r);
		ans[que[i].position] = sum;
	}
	for(auto &it: ans)
	{
		printf("%ld\n", it);
	}
	return 0;
}