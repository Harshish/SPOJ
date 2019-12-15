#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x,y,n;
};

Point p0;

void swap(Point *u,Point *v){
    Point temp = *u;
    *u = *v;
    *v = temp;
}

int orientation(Point u,Point v,Point w){
    Point a,b;
    a.x = v.x - u.x;
    a.y = v.y - u.y;
    b.x = w.x - u.x;
    b.y = w.y - u.y;

    int val = (a.x * b.y) - (a.y * b.x);

    if(val > 0) 
        return 1;
    else if(val == 0) 
        return 0;
    else 
        return -1;
}

int distSq(Point a,Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool compare(Point u,Point v){

    int val = orientation(p0,u,v);

    int dv,du;
    if(val == 0){
        dv = distSq(p0,v);
        du = distSq(p0,u);
    }

    if(val == -1)
        return false;
    else if(val == 1)
        return true;
    else if(val == 0 && dv > du)
        return true;
    else if(val == 0 && dv == du && v.n < u.n)
        return true;
    else
        return false;

}

void printStack(stack<Point> s){
    vector<int> v;
    p0 = s.top();s.pop();
    Point p2 = p0;
    v.push_back(p0.n);
    double p = 0.0;
    while(!s.empty()){
        Point p1 = s.top();s.pop();
        p += (double) sqrt(distSq(p2,p1));
        p2 = p1;
        v.push_back(p1.n);
    }
    p += (double) sqrt(distSq(p2,p0));
    printf("%0.2f\n",p);

    for(int i = v.size() - 1; i >=0; i--)
        printf("%d ",v[i]);
    printf("\n\n");
}

Point nextToTop(stack<Point> &s){
    Point temp = s.top();
    s.pop();
    Point res = s.top();
    s.push(temp);
    return res;
}

bool checkConditions(Point pts[],int n){
    if(n==1){
        printf("0.00\n1\n\n");
        return false;
    }else if(n==2){
        if(pts[1].x==pts[0].x && pts[1].y==pts[0].y){
            printf("0.00\n1\n\n");
            return false;
        }
        double p  = (double) (2*sqrt(distSq(pts[0],pts[1])));
        if(pts[1].y < pts[0].y || (pts[1].y==pts[0].y && pts[1].x < pts[0].x))
            printf("%0.2f\n%d %d\n\n",p,pts[1].n,pts[0].n);
        else
            printf("%0.2f\n%d %d\n\n",p,pts[0].n,pts[1].n);
        return false;
    }else
        return true;
}

void convexHull(Point pts[],int n){
    int minval = 0;
    for(int i = 1; i < n; i++)
        if((pts[i].y < pts[minval].y) || (pts[i].y == pts[minval].y && pts[i].x < pts[minval].x))
            minval = i;

    swap(&pts[0],&pts[minval]);
    p0 = pts[0];

    sort(&pts[1],pts+n,compare);

    int m = 1;
    for(int i = 1; i < n; i++){
        while(i < n-1 && (orientation(p0,pts[i],pts[i+1])==0))
            i++;
        pts[m] = pts[i];
        m++;
    }

    if(!checkConditions(pts,m))
        return;

    stack<Point> s;
    s.push(pts[0]);
    s.push(pts[1]);
    s.push(pts[2]);

    for(int i = 3; i < m; i++){
        while(orientation(nextToTop(s),s.top(),pts[i])!=1)
            s.pop();
        s.push(pts[i]);
    }
    
    printStack(s);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        Point pts[n];
        for(int i = 0; i < n; i++){
            scanf("%d%d",&pts[i].x,&pts[i].y);
            pts[i].n = i+1;
        }
        
        if(checkConditions(pts,n))
            convexHull(pts,n);

    }
    return 0;
}
