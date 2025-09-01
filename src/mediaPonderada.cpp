#include "mediaPonderada.hpp"
#include <opencv2/opencv.hpp>

mediaPonderada::mediaPonderada() {}
mediaPonderada::~mediaPonderada() {}

// Calcula a média ponderada dos canais de uma imagem colorida e retorna uma imagem em escala de cinza
cv::Mat mediaPonderada::calcularMedia(const cv::Mat& imagem, float b, float g, float r) {
    if (imagem.empty()) return cv::Mat();
    cv::Mat imagem_resultado(imagem.rows, imagem.cols, CV_8UC1);
    for (int i = 0; i < imagem.rows; ++i) {
        for (int j = 0; j < imagem.cols; ++j) {
            cv::Vec3b pixel = imagem.at<cv::Vec3b>(i, j);
            float valor = pixel[0] * b + pixel[1] * g + pixel[2] * r;
            imagem_resultado.at<uchar>(i, j) = static_cast<uchar>(std::min(std::max(valor, 0.0f), 255.0f));
        }
    }
    return imagem_resultado;
}
