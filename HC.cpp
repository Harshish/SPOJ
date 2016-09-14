#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	int val;
	struct node *link;
}NODE;

typedef NODE* NODEPTR;

NODEPTR addNode(NODEPTR list,int v)
{
	NODEPTR newnd = new NODE();
	newnd->val = v;
	newnd->link = NULL;
	NODEPTR curr = list;
	if (!curr)
		return newnd;
	while(curr->link!=NULL)
		curr = curr->link;
	curr->link = newnd;
	return list;
}

NODEPTR deleteNode(NODEPTR list,NODEPTR del)
{
	if(list==del)
		return list->link;
	NODEPTR curr = list;
	NODEPTR prev = NULL;
	while(curr && curr!=del)
	{
		prev = curr;
		curr = curr->link;
	}
	prev->link = curr->link;
	return list;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		string str;
		int n;
		scanf("%d",&n);
		NODEPTR list = NULL;
		for (int i = 0; i < n; ++i)
		{
			cin >> str;
			if(str=="lxh")
				list = addNode(list,1);
			else if(str=="hhb")
				list = addNode(list,0);
		}
		int i = 1;
		bool flag = true;
		while(flag)
		{
			NODEPTR curr = list;
			NODEPTR next = list;
			next = next->link;
			if(!next)
			{
				flag = false;
				continue;
			}
			if(i%2)
			{		
				while(next && curr->val==next->val)
				{
					curr = next;
					next = next->link;
				}
				if(next && curr->val==0)
					list = deleteNode(list,curr);
				else if(next && next->val==0)
					list = deleteNode(list,next);
			}
			else
			{
				while(next && curr->val!=next->val)
				{
					curr = next;
					next = next->link;
				}
				if(next)
				{
					curr->val = 0;
					list = deleteNode(list,next);
				}
			}
			i++;
		}
		if(list->val)
			printf("%s\n","lxh");
		else
			printf("%s\n","hhb");
	}
	return 0;
}