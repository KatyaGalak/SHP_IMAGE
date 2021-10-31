#include<iostream>
#include<cassert>
#include "Pixel.h"
using namespace std;
int main(){
	// для Color
	Color cl;
	assert(cl.R==0);
	assert(cl.G==0);
	assert(cl.B==0);
	assert(cl.A==0);

	cl.R=123; cl.G=143; cl.B=67; cl.A=156;
	assert(cl.R==123); assert(cl.G==143); assert(cl.B==67); assert(cl.A==156);

	Color c2(23, 45, 140, 250);
	assert(c2.R=23); assert(c2.G=45); assert(c2.B=140); assert(c2.A=250);   

	Color c1(c2);
	c1.R=34; c1.G=66; c1.B=90; c1.A=11;
	assert(c1.R!=c2.R); assert(c1.G!=c2.G); assert(c1.B!=c2.B); assert(c1.A!=c2.A);

	
	cout<<"Tests complete!"<<endl; 
}