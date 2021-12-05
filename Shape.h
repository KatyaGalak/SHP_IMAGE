#include"Pixel.h"
#include"Color.h"
#include <bits/stdc++.h>
#include"lodepng.h"
#include <stdexcept>
#include <exception>
typedef unsigned char uchar;
typedef unsigned int uint;
using namespace std;
class Shape{
private:
    vector<Pixel> v;
public:
    Shape(){}
    Shape(const Shape& shp): v(shp.v.begin(), shp.v.end()){}

    Shape& translate(int tx, int ty){    //смещает по x и y на заданное значение
        for (auto& i:v){
            i.setPos(i.getX()+tx, i.getY()+ty);
        }
        Shape shp(v);
        return shp;
    }

    Shape(vector<Pixel> v): v(v.begin(), v.end()){}

    vector<Pixel> getPixels(){return v;}

    Shape& setColor(Color color){
        for(auto &i : v){
            i.setColor(color);
        }
        Shape shp(v);
        return shp;
    }

    static Shape getTriangle(size_t size, Color color){
        vector <Pixel> pixels;
        Pixel pixel(color, Point({0, 0}));

        pixels.push_back(pixel);
        for(int i=1; i <size; ++i){
            pixels.push_back(pixel);
            pixel.setPos(pixel.getX()+1, pixel.getY()+1);
        }

        while(pixel.getY()!=0){
            pixel.setPos(pixel.getX()-1, pixel.getY()-1);
            pixels.push_back(pixel);
            
        }

        while(pixel.getX()!=1){
            pixel.setPos(pixel.getX()-1, pixel.getY());
            pixels.push_back(pixel);
        }

        Shape shp(pixels);
        return shp;
    }
    static Shape getCircle(size_t radius){

    }

    static Shape getRectangle(size_t width, size_t height){

    }

};
