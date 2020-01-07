#include <bits/stdc++.h>

using namespace std;

struct segment{
    int sum,minsum;
}st[65536];

/*
8
(())()((
*/

void printSegmentTree(int n){
    int x = ceil(log2(n));
    int len = pow(2,x+1) - 1;
    printf("Segment TREE: \n");
    for(int i = 0; i < len; i++)
        printf("%d,%d     ",st[i].sum,st[i].minsum);
    printf("\n");
}

int constructSegmentTree(int strt,int end,string s,int pos){
    if(strt==end){
        st[pos].sum = st[pos].minsum = (s[strt] == '(') ? 1 : -1;
        return st[pos].sum;
    }

    int mid = strt + (end-strt)/2;
    st[pos].sum = constructSegmentTree(strt,mid,s,2*pos+1) + constructSegmentTree(mid+1,end,s,2*pos+2);
    st[pos].minsum = min(st[2*pos+1].minsum,st[2*pos+1].sum+st[2*pos+2].minsum);
    return st[pos].sum;
}

void updateTree(int strt,int end,int pos,int index,int diff){
    if(index < strt || index > end )
        return;

    if(strt!=end){
        int mid = strt + (end-strt)/2;
        updateTree(strt,mid,2*pos+1,index,diff);
        updateTree(mid+1,end,2*pos+2,index,diff);
        st[pos].minsum = min(st[2*pos+1].minsum,st[2*pos+1].sum+st[2*pos+2].minsum);
    }

    st[pos].sum += diff;
    if(strt==end)
        st[pos].minsum = st[pos].sum;
}

bool check(){
    if(st[0].sum==0 && st[0].minsum==0)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 10,n,m,k;
    string s;
    for(int t = 1; t <= tc; t++){
        cin >> n;
        cin >> s;
        cin >> m;
        constructSegmentTree(0,n-1,s,0);

        

        printf("Test %d:\n",t);
        for(int i = 0; i < m; i++){
            cin >> k;
            if(k==0){
                if(check())
                    printf("YES\n");
                else
                    printf("NO\n");
            }else if(k > 0){
                if(s[k-1]=='('){
                    s.replace(k-1,1,")");
                    updateTree(0,n-1,0,k-1,-2);
                }
                else{
                    s.replace(k-1,1,"(");
                    updateTree(0,n-1,0,k-1,2);
                }
            }
            //printSegmentTree(n);
        }
    }
    return 0;
}
