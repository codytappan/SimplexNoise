#include "bitmap.h"
#include "../noise/simplexnoise1234.h"

using namespace std;

Bitmap::Bitmap(int width, int height) {
    mImageData.reset(new vector<unsigned char>);

    float scale = .007;
    int i, j;
    for(i = 0; i < height; i++) {
       for(j = 0; j < width; j++) {
           mImageData->push_back(
                static_cast<unsigned char>((SimplexNoise1234::noise(j * scale, i * scale) + 1) / 2.0 * 255.0 )
           );
       }
    }
}