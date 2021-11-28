#include "Image.h"
typedef unsigned int uint;
#define unsigned char uchar
using namespace std;
class Converter{
public:
	static Image toGray(const Image& im){
		Image im_gr(im.width, im.height);
		for(auto i : im.pixels){
			auto c = i.getColor();
			uchar g = (c.R+uint(c.G)+uint(c.B))/3;
			Color cg(g, g, g, c.A);
			im_gr.setPixel(cg, i.getX(), i.getY());
		}
		return im_gr;
	} 
};