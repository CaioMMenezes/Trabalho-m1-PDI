#include <opencv2/opencv.hpp>

class mediaPonderada
{
    public:
        mediaPonderada();
        ~mediaPonderada();

    static cv::Mat calcularMedia(const cv::Mat& imagem, float b, float g, float r);

    private:
        
};