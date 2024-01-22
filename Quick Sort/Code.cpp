#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& vec, int low, int hi)
{
	int pivotIndex = low;
	int pivot = vec[pivotIndex];
	for (int j = low + 1; j <= hi; j++)
	{
		if (vec[j] <= pivot)
		{
			low++;
			swap(vec[low], vec[j]);
		}
	}
	swap(vec[pivotIndex], vec[low]);
	return low;
}
void quicksort(vector<int>& vec, int i, int j)
{
	if (i <= j) {
		int mid = partition(vec, i, j);
		quicksort(vec, i, mid - 1);
		quicksort(vec, mid + 1, j);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int size;
	cin >> size;
	vector<int> vec;
	for (int i = 0; i < size; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	quicksort(vec, 0, size - 1);
	cout << "After Quick Sort" << endl;
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}
