#include <bits/stdc++.h>

using namespace std;

/*
1
13
3 2 3 4
0
3 5 6 7
0
0
2 8 9
2 10 11
0
0
2 12 13
0
0
0
1
9 12
*/

typedef struct tree
{
	int val,nlinks;
	struct tree **link;
	struct tree *parent;
}TREE;

typedef TREE* TREEPTR;

TREEPTR createNode(int val)
{
	TREEPTR newnd = new TREE();
	newnd->val = val;
	newnd->link = NULL;
	newnd->parent = NULL;
	return newnd;
}

TREEPTR createLinks(TREEPTR newnd,int links)
{
	newnd->nlinks = links;
	if(links==0)
		return newnd;
	newnd->link = new TREEPTR[links];
	return newnd;
}

/*void displayTree(TREEPTR root)
{
	printf("NODE = %d LINKS = %d\n",root->val,root->nlinks);
	for (int i = 0; i < root->nlinks; ++i)
		displayTree(root->link[i]);
}*/

int lowestCommonAncestor(TREEPTR x,TREEPTR y)
{
	while(x->val!=y->val)
	{
		if(x->val > y->val)
			x = x->parent;
		else
			y = y->parent;
	}
	return x->val;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int k = 0; k < n; ++k)
	{
		int numNodes;
		scanf("%d",&numNodes);
		TREEPTR arr[numNodes];
		for (int i = 1; i <= numNodes; ++i)
			arr[i-1] = createNode(i);
		int m,nd;
		for (int i = 0; i < numNodes; ++i)
		{
			scanf("%d",&m);
		 	arr[i] = createLinks(arr[i],m);
		 	for (int j = 0; j < m; ++j)
		 	{
		 		scanf("%d",&nd);
		 		arr[i]->link[j] = arr[nd-1];
		 		arr[nd-1]->parent = arr[i]; 	
		 	}
		} 
		//displayTree(root);
		int q;
		scanf("%d",&q);
		printf("Case %d:\n",k+1);
		int v,w;
		for (int i = 0; i < q; ++i)
		{
			scanf("%d %d",&v,&w);
			printf("%d\n",lowestCommonAncestor(arr[v-1],arr[w-1]));
		}
	}
	return 0;
}
