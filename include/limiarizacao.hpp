#include <opencv2/opencv.hpp>

class limiarizacao
{
    public:
        limiarizacao();
        ~limiarizacao();

    static cv::Mat aplicarLimiar(const cv::Mat& imagem, uchar limiar);

    private:
        
};