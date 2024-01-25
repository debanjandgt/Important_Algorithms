#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
	vector<int> rank, parent, size;
public:
	DisjointSet(int n)
	{
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
	}
	int findPar(int node)
	{
		if (node == parent[node])
			return node;
		return parent[node] = findPar(parent[node]);
	}
	void unionByRank(int u, int v)
	{
		int ulp_u = findPar(u);
		int ulp_v = findPar(v);
		//If they belong to same component ,I need not to do anything
		if (ulp_v == ulp_u)
			return;
		else
		{
			if (rank[ulp_u] < rank[ulp_v])
			{
				parent[ulp_u] = ulp_v;
			}
			else if (rank[ulp_v] <  rank[ulp_u] )
			{
				parent[ulp_v] = ulp_u;
			}
			else
			{
				//They are Same
				parent[ulp_u] = ulp_v;
				rank[ulp_v] += 1;
			}
		}
	}
	void unionBySize(int u, int v)
	{
		int ulp_u = findPar(u);
		int ulp_v = findPar(v);
		//If they belong to same component ,I need not to do anything
		if (ulp_v == ulp_u)
			return;
		if (size[ulp_u] < size[ulp_v])
		{
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
		else
		{
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//Creating object of this class
	DisjointSet ds(7);
	ds.unionByRank(1, 2);
	ds.unionByRank(2, 3);
	ds.unionByRank(4, 5);
	ds.unionByRank(6, 7);
	ds.unionByRank(5, 6);
	if (ds.findPar(3) == ds.findPar(7))
	{
		cout << "SAME" << endl;
	}
	else
		cout << "NOT SAME" << endl;
	ds.unionByRank(3, 7);
	if (ds.findPar(3) == ds.findPar(7))
	{
		cout << "SAME" << endl;
	}
	else
		cout << "NOT SAME" << endl;
}
