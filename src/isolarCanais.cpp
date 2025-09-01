#include "isolarCanais.hpp"
#include <opencv2/opencv.hpp>

cv::Mat isolarCanalR(const cv::Mat& imagem) {
    std::vector<cv::Mat> canais;
    cv::split(imagem, canais);
    std::vector<cv::Mat> canaisIsolados = {cv::Mat::zeros(imagem.size(), canais[0].type()), cv::Mat::zeros(imagem.size(), canais[1].type()), canais[2]};
    cv::Mat resultado;
    cv::merge(canaisIsolados, resultado);
    return resultado;
}

cv::Mat isolarCanalG(const cv::Mat& imagem) {
    std::vector<cv::Mat> canais;
    cv::split(imagem, canais);
    std::vector<cv::Mat> canaisIsolados = {cv::Mat::zeros(imagem.size(), canais[0].type()), canais[1], cv::Mat::zeros(imagem.size(), canais[2].type())};
    cv::Mat resultado;
    cv::merge(canaisIsolados, resultado);
    return resultado;
}

cv::Mat isolarCanalB(const cv::Mat& imagem) {
    std::vector<cv::Mat> canais;
    cv::split(imagem, canais);
    std::vector<cv::Mat> canaisIsolados = {canais[0], cv::Mat::zeros(imagem.size(), canais[1].type()), cv::Mat::zeros(imagem.size(), canais[2].type())};
    cv::Mat resultado;
    cv::merge(canaisIsolados, resultado);
    return resultado;
}
