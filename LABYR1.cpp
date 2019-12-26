#include <bits/stdc++.h>

using namespace std;

char mat[1001][1001];
bool v[1001][1001];
int ans = 0,x = 0,y = 0,length = 0;

void findLongestPath(int i,int j,int c,int r){
    
    v[i][j] = true;
    length++;
    
    //LEFT
    if(j-1 >= 0 && mat[i][j-1]=='.' && !v[i][j-1])
        findLongestPath(i,j-1,c,r);
    //RIGHT
    if(j+1 < c && mat[i][j+1]=='.' && !v[i][j+1])
        findLongestPath(i,j+1,c,r);
    //UP
    if(i-1 >= 0 && mat[i-1][j]=='.' && !v[i-1][j])
        findLongestPath(i-1,j,c,r);
    //DOWN
    if(i+1 < r && mat[i+1][j]=='.' && !v[i+1][j])
        findLongestPath(i+1,j,c,r);

    v[i][j] = false;
    length--;
    if(length > ans){
        ans = length;
        x = i;
        y = j;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc,c,r;
    memset(v,0,sizeof(v));

    cin >> tc;
    while(tc--){
        cin >> c >> r;

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> mat[i][j];
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(mat[i][j]=='.'){
                    findLongestPath(i,j,c,r);
                    i = r;
                    break;
                }
            }
        }
        length = ans = 0;

        findLongestPath(x,y,c,r);
        printf("Maximum rope length is %d.\n",ans);
        length = ans = 0;
    }
    return 0;
}
