//#include"Pixel.h"
#include"Color.h"
#include <bits/stdc++.h>
#include"lodepng.h"
#include <stdexcept>
#include <exception>
typedef unsigned char uchar;
typedef unsigned int uint;
using namespace std;
class Image{
public:
    uint width, height;
    vector <Pixel> pixels;
    Image():width(0), height(0){}
    Image(int width, int heigth){
        throw std::exception();
        //throw std::exception("not implemented!");
        //throw std::current_exception("not implemented!");
    }
    Image(int width, int height, vector <Pixel> pixel): width(width), height(height), pixels(pixel){}
    Image(const Image& image): width(image.width), height(image.height), pixels(image.pixels){}

    Image(string filename){
		const char* filein = filename.c_str();
		vector <uchar> image;
		unsigned width, height, w=0, h=0;
		lodepng::decode(image, width, height, filein);

		for(unsigned long long i=0; i<width*height*4; i+=4, w++){
			Color color(image[i], image[i+1], image[i+2], image[i+3]);
			Point point(w/width, w%width+1);
			Pixel pixel(color, point);
			pixels.push_back(pixel);
		}
	}

    void setPixel(Pixel pixel, unsigned x){
		pixels[x]=pixel;
	}
	
	void setPixel(Color c, unsigned x, unsigned y){
		pixels[y*width+x].setColor(c);
	}
	
	void setPixel(Pixel pixel){
		pixels[pixel.getY()*width+pixel.getX()]=pixel;
	}

	
	Pixel getPixel(unsigned x){
		return pixels[x];
	}

	Pixel getPixel(unsigned x, unsigned y){
		return pixels[y*width+x];
	}

	vector <Pixel> getPixel(){
		return pixels;
	}

    void setPixel(Color color, unsigned x, unsigned y){
		Point point(x, y);
		Pixel pixel(color, point);
		pixels[y*width+x]=pixel;
	}

    void outputImage(string filename){
		vector <uchar> image;
		unsigned width = pixels[pixels.size()-1].getY(), height=pixels[pixels.size()-1].getX();
		for(unsigned long long i=0; i<pixels.size(); i++){
			image.push_back(pixels[i].getColor().R);
			image.push_back(pixels[i].getColor().G);
			image.push_back(pixels[i].getColor().B);
			image.push_back(pixels[i].getColor().A);
		}
		lodepng::encode(filename.c_str(), image, width, height);
	}


    void new_Color(){

        for (int x=0; x<width; ++x){
            for (int y=0; y<height; ++y){
                Pixel p=getPixel(x, y);
                uchar value=p.getColor().R + p.getColor().G + p.getColor().B;
                value /= 3;
                Color newColor;
                newColor.setColor(value, value, value);
                p.setColor(newColor);
            }
        }
    }
    
};