#include <iostream>
#include <cmath>
#include <algorithm>
#include <assert.h>

using namespace std;

typedef double T;

struct points
{
   T x,y;
   points operator+(points p){return{x+p.x, y+p.y};} 
   points operator-(points p){return{x-p.x, y-p.y};}
   points operator*(T d){return{x*d,y*d};}
   points operator/(T d){return{x/d, y/d};}//for floting points;
      
   
};

T sq(points p){return p.x*p.x + p.y*p.y;}
double abs(points p){return sqrt(sq(p));}

bool operator==(points a,points b){return a.x == b.x && a.y == b.y; }
bool operator!=(points a, points b){return !(a==b);}

ostream& operator<<(ostream& os, points p)
{ 
    return os<< "(" <<p.x<<","<<p.y<<")";
}

//dot product 
T dot(points v, points w){return v.x*w.x+v.y*w.y;}

//proverka dali dva vektora sa perpendiculairni
bool isPerpen(points v, points w){return dot(v,w)==0;}

//namirane na agal mezdu dva vektora
double angele(points v, points w)
{
    double cosTheta = dot(v,w)/abs(v)/abs(w);
    return acos(max(-1.0,min(1.0,cosTheta)));
}
//cross product v1Xv2 how perpendiculare are
T cross(points v, points w){return v.x*w.y-v.y*w.x;}

//orientation pionts and other objects
T orient(points a, points b, points c){return cross(b-a,c-a);}

//if the point is in the angle
bool inAngle(points a, points b, points c, points p)
{
    assert(orient(a,b,c)!=0);
    if(orient(a,b,c)<0) swap(b,c);
    return orient(a,b,p)>=0&&orient(a,c,p)<=0;    
}
//amplitude of oriented angle
double orientedAngle(points a, points b, points c){
    if(orient(a,b,c)>=0)
    {
        return angele(b-a,c-a);
    }
    else
    {
        return 2*M_PI - angele(b-a,c-a);
    }
    
}
points perp(points p){return{-p.y,p.x};}

///////////////////////////////////////////////////////////////////////////////////////////////
//LINES
struct line
{
    points v; T c;
    //from direction vector v and offcet c
    line(points v, T c):v(v), c(c){}
    //from equation ax+by=c;
    line(T a, T b, T c):v({b,-a}),c(c){}
    //from point P to Q
    line(points p, points q):v(q-p),c(cross(v,p)){}

    //ax+by-c
    int side(points p){return cross(v,p)-c;}
   
    //distance
    double dist(points p){return abs(side(p))/abs(v);}
    double sqDist(points p){return (side(p)*side(p))/(double)sq(v);}

    //perpendiculiarni two line are perp only if their direct vect are perpen
    line perpThrough(points p){return {p, p+perp(v)};}
    
    //comparator
    bool cmpProj(points p, points q){return dot(v,p)<dot(v,q);}
    //translating the line 
    line translete(points t){return{v,c+cross(v,t)};}
    line shiftLeft(double dist){return{v,c+dist*abs(v)};}
    //line itersection presi4ane
    bool iner(line l1, line l2, points &out){
        double d = cross(l1.v,l2.v);
        if(d==0)return false;
        out = (l2.v*l1.c - l1.v*l2.c)/d;

        return true;
    }
    //projection
    points proj(points p){return p-perp(v)*side(p)/sq(v);}
    //reflection
    points refl(points p){return p-perp(v)*2*side(p)/sq(v);}
};





int main()
{
    points a{1,-5};
    points b{3,7};
    
    line l{a,b};

    cout<<l.dist(b)<<endl;
    
    double x = dot(a,b);
    cout<<x<<endl;
    cout<<a+b<<" "<<a-b<<endl;
    cout<<a*-1<<" "<<b/2<<endl;    
    return 0;
}