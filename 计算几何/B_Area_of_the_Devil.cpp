#include <bits/stdc++.h>
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
using namespace std;
using ull = unsigned long long int;
using ld =long double;
using ll = long long int;
const ld PI = acos(-1.0L);

struct Point{
    ld x;
    ld y;
    Point operator-(const Point &a)const{//向量减法
        return Point{x-a.x,y-a.y};
    }
    Point operator+(const Point &a)const{//向量加法
        return Point{x+a.x,y+a.y};
    }
    Point operator*(const ld &a)const{//向量乘法
        return Point{a*x,a*y};
    }
    ld crs(const Point &a)const{//叉积
        return x*a.y-y*a.x;
    }
};
ld cross(const Point &p,const Point &a,const Point &b){//三个点用叉积求面积
    return (p-a).crs(p-b);
}
Point pt_l_l(const Point &p1, const Point &v1, const Point &p2, const Point &v2){//求出两条线段交点坐标，p1跟p2是两个向量的起点，v1是p1的向量表示，v2是p2的向量表示
	return p1 + v1*(v2.crs(p1-p2)/v1.crs(v2));
}
Point pt_seg_seg(const Point &p1, const Point &p2, const Point &p3, const Point &p4){//p1跟p3是两个向量的起点，求p1->p2向量线段和p3->p4向量线段的交点
	return pt_l_l(p1, p2-p1, p3, p4-p3);	
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin>>_;
    while(_--){
        ld R;
        cin>>R;//圆的半径
        Point O={0L,0L};//原点坐标
        vector<vector<ll>> theat(5,vector<ll>(2)); //五角星的位置角度
        vector<vector<Point>> p(5,vector<Point>(2));//五角星的(x,y)的坐标
        for(int j=0;j<2;j++){
            for(int i=0;i<5;i++){
                cin>>theat[i][j];
                p[i][j]={R*cos(theat[i][j]*PI/180),R*sin(theat[i][j]*PI/180)};//角度转坐标
            }
        }
        ld ANS=0;
        for(int i=0;i<5;i++){
            ld SH;//先算出两个相邻的点的圆弧面积
            if(i==4){
                SH=R*R*(360-theat[i][1]+theat[(i+1)%5][0])*PI/360;//最后一个跟第一个要特殊判断一下
            }
            else{//R^2*theat(转一下弧度)
                SH=R*R*(theat[(i+1)%5][0]-theat[i][1])*PI/360;//两个点位置的角度相减求出弧长对的角度
            }
            ld SOAB=0.5L*cross(O,p[i][1],p[(i+1)%5][0]);//然后用叉积算出圆弧中间的三角形面积
            Point X=pt_seg_seg(p[(i+2)%5][0],p[i][1],p[(i+4)%5][1],p[(i+1)%5][0]);//求出四个点的交点X
            ld SXAB=0.5L*cross(X,p[i][1],p[(i+1)%5][0]);//算出三角形XAB的面积
            ANS+=(SH-SOAB+SXAB);//最后用圆弧的面积减去圆弧中间三角形的面积再加上交点三角形的面积就可以了
        }
        cout<<fixed<<setprecision(9);
        cout<<(PI*R*R)-ANS<<'\n';//整个圆的面积减去算出来的永远不可能出现的面积就是剩下的面积
    }
    return 0;
}