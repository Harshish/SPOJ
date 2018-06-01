#include<bits/stdc++.h>
using namespace std;

/*
1

5

5 5
x...x
.x.x.
..x..
.x.x.
x...x
5 5
xxxxx
x...x
x...x
x...x
xxxxx
6 6
..x...
..x...
xxxxxx
..x...
..x...
......
5 5
.xxx.
x...x
x...x
x...x
.xxx.
5 5
.xxx.
.x.x.
.xxx.
.....
.....
*/

void printMat(char **img,int h,int w)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
            cout << img[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int imgrecog(char **img,int h,int w,int i,int j,string dir)
{
    if(i < 0 || j < 0 || i >= h || j >= w)
        return 0;
    img[i][j] = '~';
    //printMat(img,h,w);
    //U
    if(i-1 >=0 && img[i-1][j]=='x')
    {
        if(dir!="U" && dir!="NA")
            return 1 + imgrecog(img,h,w,i-1,j,"U");
        else
            return imgrecog(img,h,w,i-1,j,"U");
    }

    //D
    if(i+1 < h && img[i+1][j]=='x')
    {
        if(dir!="D" && dir!="NA")
            return 1 + imgrecog(img,h,w,i+1,j,"D");
        else
            return imgrecog(img,h,w,i+1,j,"D");
    }

    //L
    if(j-1 >=0 && img[i][j-1]=='x')
    {
        if(dir!="L" && dir!="NA")
            return 1 + imgrecog(img,h,w,i,j-1,"L");
        else
            return imgrecog(img,h,w,i,j-1,"L");
    }

    //R
    if(j+1 >=0 && img[i][j+1]=='x')
    {
        if(dir!="R" && dir!="NA")
            return 1 + imgrecog(img,h,w,i,j+1,"R");
        else
            return imgrecog(img,h,w,i,j+1,"R");
    }

    //UL
    if(i-1 >=0 && j >=0  && img[i-1][j-1]=='x')
    {
        if(dir!="UL" && dir!="NA")
            return 1 + imgrecog(img,h,w,i-1,j-1,"UL");
        else
            return imgrecog(img,h,w,i-1,j-1,"UL");
    }

    //UR
    if(i-1 >=0 && j+1 < w && img[i-1][j+1]=='x')
    {
        if(dir!="UR" && dir!="NA")
            return 1 + imgrecog(img,h,w,i-1,j+1,"UR");
        else
            return imgrecog(img,h,w,i-1,j+1,"U");
    }

    //DL
    if(i+1 < h && j-1 >= 0 && img[i+1][j-1]=='x')
    {
        if(dir!="DL" && dir!="NA")
            return 1 + imgrecog(img,h,w,i+1,j-1,"DL");
        else
            return imgrecog(img,h,w,i+1,j-1,"DL");
    }

    //DR
    if(i+1 < h && j+1 < w && img[i+1][j+1]=='x')
    {
        if(dir!="DR" && dir!="NA")
            return 1 + imgrecog(img,h,w,i+1,j+1,"DR");
        else
            return imgrecog(img,h,w,i+1,j+1,"DR");
    }
    return 0;
}

int main()
{
    string blank;
    int tc;
    cin >> tc;
    getline(cin,blank);
    getline(cin,blank);
    while(tc--)
    {
        int n;
        cin >> n;
        getline(cin,blank);
        getline(cin,blank);
        string ans_str = "";
        for(int l = 0; l < n; l++)
        {
            int h,w,f_x = -1,f_y = -1;
            cin >> h >> w;

            //IMG
            char **img = new char*[h];
            for(int i = 0; i < h; i++)
            {
                img[i] = new char[w];
                for(int j = 0; j < w; j++)
                {
                    cin >> img[i][j];
                    if(img[i][j]=='x' && f_x==-1)
                    {
                        f_x = i;
                        f_y = j;
                    }
                }
            }
            int ans = imgrecog(img,h,w,f_x,f_y,"NA");
            if(ans==3 || ans==6)
                ans_str += '0';
            else
                ans_str += 'x';
        }
        cout << ans_str << "\n";
    }
}
