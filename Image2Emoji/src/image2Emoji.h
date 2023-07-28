#ifndef IMAGE_2_EMOJI_
#define IMAGE_2_EMOJI_

#include <opencv2/opencv.hpp>
#include <string>

class Image2Emoji {
public:
    Image2Emoji(const std::string& inImg, const std::string& emImage, const std::string& s, unsigned int argCount);
    ~Image2Emoji() noexcept;
    void process();

private:
    void is_empty(const cv::Mat&);
    void is_valid_argc(unsigned int);
    int getEmojiSize(const std::string&);

private:
    std::string inputImage;
    std::string emojiImage;
    std::string size;
    unsigned int argc;
};


#endif  //IMAGE_2_EMOJI_