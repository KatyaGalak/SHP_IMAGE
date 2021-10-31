#include"Pixel.h"
#include <bits/stdc++.h>
#include"lodepng.h"
typedef unsigned char uchar;
typedef unsigned int uint;
using namespace std;
class Image{
public:
    uint width, height;
    vector <Pixel> pixel;
    Image():width(0), height(0){}
    Image(int width, int height, vector <Pixel> pixel): width(width), height(height), pixel(pixel){}
    Image(const Image& image): width(image.width), height(image.height), pixel(image.pixel){}

    vector <Pixel> getImage(){
        return pixel;
    }
    Pixel getPixel(uint x, uint y){
        return pixel[x * y];
    }
    /*void setPixel(Pixel new_pixel, uint x, uint y){
        pixel[x * y] = new_pixel;
    }*/

    void returnImage(string fileName){
        uint sizeIm = pixel.size();
        vector <uchar> image;

        for (uint i = 0; i < sizeIm; ++i){
            image.push_back(pixel[i].getColor().R);
            image.push_back(pixel[i].getColor().G);
            image.push_back(pixel[i].getColor().B);
            image.push_back(pixel[i].getColor().A);
        }

        uint height = pixel[sizeIm - 1].getX();
        uint width = pixel[sizeIm - 1].getY(); 
        lodepng::encode((fileName + ".png").c_str(), image, width, height);
    }
    
};