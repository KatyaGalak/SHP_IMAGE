#include "lodepng.h"
#include <bits/stdc++.h>
using namespace std;

// создать функцию, принимающую x, y, поворот

//double rad (double ugl){
  //  return 180.0 / M_PI * ugl;
//}



int main(int argc, char* argv[]){
    const char* filein = argc > 1 ? argv[1] : "now.png";
    const char* fileout = argc > 2 ? argv[2] : "test_out_2.png";

    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height, error;

    //decode
    error = lodepng::decode(image, width, height, filein);

    //if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    //MODIFY image

    //std::reverse(image.begin(), image.end());   // поворот только изображения, цвета остаются на своих местах

    std::vector<unsigned char> new_image (width + height);

    cout<<width / 2<<" "<<height;
    cout<<image[0];
    for (unsigned x = 0; x < width; ++x)
        for (unsigned y = 0; y < height / 2; ++y)
            for (unsigned z = 0; z < 4; ++z){
                //swap(image[])
                //cout<<height - x - 1 + y<<endl;
                //swap(image[height - x - 1 + y], image[x + y]);

                swap(image[(x + y * width) * 4 + z], image[(x + (height - 1 - y) * width) * 4 + z]);
            }
        
    


    //encode
    error = lodepng::encode(fileout, image, width, height);

    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}