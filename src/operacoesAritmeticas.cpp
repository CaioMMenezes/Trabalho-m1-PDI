#include "operacoesAritmeticas.hpp"
#include <opencv2/opencv.hpp>

cv::Mat somaImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado;
    cv::add(img1, img2, resultado);
    return resultado;
}

cv::Mat subtraiImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado;
    cv::subtract(img1, img2, resultado);
    return resultado;
}

cv::Mat multiplicaImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado;
    cv::multiply(img1, img2, resultado);
    return resultado;
}

cv::Mat divideImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado;
    cv::divide(img1, img2, resultado);
    return resultado;
}

cv::Mat somaEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado;
    cv::add(img, valor, resultado);
    return resultado;
}

cv::Mat subtraiEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado;
    cv::subtract(img, valor, resultado);
    return resultado;
}

cv::Mat multiplicaEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado;
    cv::multiply(img, valor, resultado);
    return resultado;
}

cv::Mat divideEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado;
    cv::divide(img, valor, resultado);
    return resultado;
}
