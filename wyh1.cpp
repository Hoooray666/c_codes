#include <iostream>
#include <math.h>
using namespace std;
class point
{
 double a,b;
 public:
  point(double x,double y)
  {
   a=x;b=y;
  }
     friend double distance(point &,point &);  
};
        double distance(point &c,point &d)
  {
   double dx=c.a-d.a;
   double dy=c.b-d.b;
   return sqrt(dx*dx+dy*dy);
  }
int main()
{
 point p1(1,1),p2(0,1);
 cout<<distance(p1,p2);
}
