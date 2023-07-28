#include "image2Emoji.h"

Image2Emoji::Image2Emoji(const std::string& inImg, const std::string& emImage, const std::string& s, unsigned int argCount) 
    : inputImage{inImg}, emojiImage{emImage}, size{s}, argc{argCount} {} 

Image2Emoji::~Image2Emoji() noexcept {}

void Image2Emoji::process() {
    is_valid_argc(argc);
    int size = 7;
    cv::Mat image = cv::imread(inputImage);
    cv::resize(image, image, cv::Size(550, 500));
    is_empty(image);
    cv::Mat emoji = cv::imread(emojiImage, cv::IMREAD_UNCHANGED);
    cv::resize(emoji, emoji, cv::Size(550, 500));
    is_empty(emoji);
    if (argc > 3) {
        size = getEmojiSize(this->size);
    }
    cv::Size emojiSize(size, size);
    cv::resize(emoji, emoji, emojiSize);
    cv::Mat outputImage = image.clone();
    cv::resize(outputImage, outputImage, cv::Size(550, 500));

    for (int y = 0; y < image.rows; y += emojiSize.height) {
        for (int x = 0; x < image.cols; x += emojiSize.width) {
            cv::Rect roi(cv::Point(x, y), emoji.size());
            if (roi.x >= 0 && roi.y >= 0 && roi.x + roi.width <= outputImage.cols && roi.y + roi.height <= outputImage.rows) {
                cv::Vec3b color = image.at<cv::Vec3b>(y, x);
                cv::Mat shadedEmoji = emoji.clone();
                for (int i = 0; i < emoji.rows; i++) {
                    for (int j = 0; j < emoji.cols; j++) {
                        cv::Vec4b& pixel = shadedEmoji.at<cv::Vec4b>(i, j);
                        if (pixel[3] > 0) { 
                            pixel[0] = cv::saturate_cast<uchar>(pixel[0] + color[0]);
                            pixel[1] = cv::saturate_cast<uchar>(pixel[1] + color[1]);
                            pixel[2] = cv::saturate_cast<uchar>(pixel[2] + color[2]);
                        }
                    }
                }
                cv::Mat overlay = outputImage(roi);
                cv::Mat mask;
                cv::extractChannel(shadedEmoji, mask, 3);
                cv::Mat emoji3Channels;
                cv::cvtColor(shadedEmoji, emoji3Channels, cv::COLOR_BGRA2BGR);
                emoji3Channels.copyTo(overlay, mask);
            }
        }
    }
    std::string output = "output.png";
    std::cout << output << " image generated succesfuly.\n " << std::endl;
    cv::imwrite(output, outputImage);
}
void Image2Emoji::is_empty(const cv::Mat& image) {
    if (image.empty()) {
        std::cerr << "Error: Unable to read the image file." << std::endl;
        exit(-1);
    }
} 

void Image2Emoji::is_valid_argc(unsigned int count) {
    if (count < 3) {
        std::cerr << "Error: too few arguments. " << std::endl;
        std::cout << "Usage: ./EmojiArt <image> <emoji> [emoji size] [background color]" << std::endl;
        exit(-1);
    }
    if (count > 5) {
        std::cerr << "Error: too many arguments. " << std::endl;
        std::cout << "Usage: ./EmojiArt <image> <emoji> [emoji size] [background color]" << std::endl;
        exit(-1);
    }
} 

int Image2Emoji::getEmojiSize(const std::string& size) {
    int tmp_size;
    try {
        tmp_size = std::stoi(size);
    } catch(...) {
        throw std::invalid_argument("Invalid size value.\n");
    }
    if (tmp_size <= 0) {
        throw std::invalid_argument("Invalid size value.\n");    
    }
    return tmp_size;
}
