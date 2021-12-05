#include"Pixel.h"
//#include"Color.h"
//#include<Image.h>
#include<Shape.h>
#include <bits/stdc++.h>
#include"lodepng.h"
#include <stdexcept>
#include <exception>
typedef unsigned char uchar;
typedef unsigned int uint;
using namespace std;

typedef unsigned int uint;
#define unsigned char uchar
using namespace std;
class Drawer{
public:
    static void drawShape(Image im, Shape shp){
        for(auto i:shp.getPixels()){
            im.setPixel(i);
        }
    }
};