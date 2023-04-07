#include <iostream>
using namespace std;
class Time{
	public:
	int hours ;
	int minutes ;
	Time(){
		hours=0;minutes=0;
	};
	Time(int h,int m){
		hours=h;minutes=m;
	}
	Time operator +(const Time &t);
	void show() {
		cout<<hours<<" "<<minutes;
	}
};
Time Time::operator+(const Time &t){
//	int h0;int m0;
	Time sum;
	sum.hours=t.hours+hours;
	if(t.minutes+minutes>59){
		sum.hours++;
		sum.minutes=t.minutes+minutes-60;
	}
	else
		sum.minutes=t.minutes+minutes;
	return sum;
};
int main(){
	int h,m;
	cin>>h>>m;
Time t1(2,20);
Time t2(h,m);
Time sum;
sum=t1+t2;
sum.show();
return 0;
}



