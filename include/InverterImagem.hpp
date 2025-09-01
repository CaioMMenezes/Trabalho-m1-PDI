#include <opencv2/opencv.hpp>

class InverterImagem
{
    public:
        InverterImagem();
        ~InverterImagem();

        static cv::Mat inverter(const cv::Mat& imagem);

    private:
        
};