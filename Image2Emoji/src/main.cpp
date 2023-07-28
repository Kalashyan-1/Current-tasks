#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#include "image2Emoji.h"

int main(int argc, char** argv) {
    Image2Emoji app(argv[1], argv[2], argv[3], argc);
    app.process();
}
