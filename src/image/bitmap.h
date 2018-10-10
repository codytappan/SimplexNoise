#ifndef BITMAP_H
#define BITMAP_H

#include <memory>
#include <vector>

class Bitmap {
public:
    Bitmap(int width, int height);
    ~Bitmap() = default;

    std::vector<unsigned char>* GetImageData() { return mImageData.get(); }

private:
    std::unique_ptr<std::vector<unsigned char>> mImageData;
};

#endif