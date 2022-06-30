#include<bits/stdc++.h>
#define mx 100001
#define ll long long int
using namespace std;

int arr[mx];
struct info {
    ll prop, sum;
} tree[mx * 4]; //sum and extra update value added prop
void update(int node, int b, int e, int i, int j, ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) //Full range interset
    {
        tree[node].sum += ((e - b + 1) * x); //all down node e-b+1, so,  (e-b+1) * x added.
        tree[node].prop += x; //all down node sum with x
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
    //up all node added with prop value
    // left and right node sum + extra summation
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1); //sum + extra value
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop); //prop value + carray
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].sum = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    init(1, 1, n);
    update(1, 1, n, 1, 7, 2);
    update(1, 1, n, 1, 4, 3);
    cout << query(1, 1, n, 1, 7) << endl;
    cout << query(1, 1, n, 1, 4) << endl;
    return 0;
}

/* data set
7
4 -9 3 7 1 0 2

*/