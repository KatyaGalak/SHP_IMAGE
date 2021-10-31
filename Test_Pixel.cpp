#include<iostream>
#include<cassert>
#include "Pixel.h"
using namespace std;
int main(){

	// для Pixel
    Point p;
    assert(p.x==0); assert(p.y==0);

    p.x=12; p.y=16;
    assert(p.x==12); assert(p.y==16);

    Point p1(15, 34);
    assert(p1.x==15); assert(p1.y==34);

    Point p2(p1);
    assert(p2.x==p1.x); assert(p2.y==p1.x);

    p2.x=5; p2.y=31;
    assert(p1.x!=p2.x); assert(p1.y!=p2.y);
	
	cout<<"Tests complete!"<<endl; 
}