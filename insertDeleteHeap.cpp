#include <bits/stdc++.h>

using namespace std;

const int N = 1e4;

int heapTree[N];

void swap(int &a, int &b)
{
	int tem = a;
	a = b;
	b = tem;
}

int insertHeap(int value, int heapSize)
{
	heapTree[++heapSize] = value;
	int i = heapSize, j = heapSize / 2;
	while(i > 1 && heapTree[j] < heapTree[i])
	{
		swap(heapTree[j], heapTree[i]);
		i = j;
		j = i / 2;
	}
	return heapSize;
}

int deleteHeap(int heapSize)
{
	if(heapSize < 1) return 0;
	swap(heapTree[1], heapTree[heapSize]);
	heapSize--;
	int i = 1, left, right;
	while(i <= heapSize)
	{
		left = i*2;
		right = i*2+1;
		if(left <= heapSize && right <= heapSize)
		{
			if(heapTree[left] > heapTree[i] || heapTree[right] > heapTree[i])
			{
				if(heapTree[left] > heapTree[right])
				{
					swap(heapTree[left], heapTree[i]);
					i = left;
				}
				else
				{
					swap(heapTree[right], heapTree[i]);
					i = right;
				}
			}
			else break;
		}
		else if(left <= heapSize)
		{
			if(heapTree[left] > heapTree[i])
			{
				swap(heapTree[left], heapTree[i]);
				i = left;
			}else break;
		}
		else if(right <= heapSize)
		{
			if(heapTree[right] > heapTree[i])
			{
				swap(heapTree[right], heapTree[i]);
				i = right;
			}else break;
		}
		else break;
	}
		
	return heapSize;
}

void showHeap(int n)
{
	for(int i = 1; i <= n; i++)
	{
		cout << heapTree[i] << " ";
	}
	cout << '\n';
}

int main(int argc, char const *argv[])
{
	int heapSize = 0;
	heapSize = insertHeap(10, heapSize);
	heapSize = insertHeap(8, heapSize);
	heapSize = insertHeap(12, heapSize);
	heapSize = insertHeap(4, heapSize);
	heapSize = insertHeap(16, heapSize);
	heapSize = insertHeap(12, heapSize);
	heapSize = insertHeap(16, heapSize);
	showHeap(heapSize);
	heapSize = deleteHeap(heapSize);
	heapSize = deleteHeap(heapSize);
	heapSize = deleteHeap(heapSize);
	heapSize = deleteHeap(heapSize);
	heapSize = deleteHeap(heapSize);
	heapSize = deleteHeap(heapSize);
	heapSize = deleteHeap(heapSize);
	showHeap(7);
	return 0;
}