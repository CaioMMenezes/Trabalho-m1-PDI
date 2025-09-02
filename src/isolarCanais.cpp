#include "isolarCanais.hpp"
#include <opencv2/opencv.hpp>


cv::Mat isolarCanalR(const cv::Mat& imagem) {
    cv::Mat resultado = cv::Mat::zeros(imagem.size(), imagem.type());
    for (int y = 0; y < imagem.rows; y++) {
        for (int x = 0; x < imagem.cols; x++) {
            resultado.at<cv::Vec3b>(y, x)[0] = 0;
            resultado.at<cv::Vec3b>(y, x)[1] = 0;
            resultado.at<cv::Vec3b>(y, x)[2] = imagem.at<cv::Vec3b>(y, x)[2];
        }
    }
    return resultado;
}

cv::Mat isolarCanalG(const cv::Mat& imagem) {
    cv::Mat resultado = cv::Mat::zeros(imagem.size(), imagem.type());
    for (int y = 0; y < imagem.rows; y++) {
        for (int x = 0; x < imagem.cols; x++) {
            resultado.at<cv::Vec3b>(y, x)[0] = 0;
            resultado.at<cv::Vec3b>(y, x)[1] = imagem.at<cv::Vec3b>(y, x)[1];
            resultado.at<cv::Vec3b>(y, x)[2] = 0;
        }
    }
    return resultado;
}

cv::Mat isolarCanalB(const cv::Mat& imagem) {
    cv::Mat resultado = cv::Mat::zeros(imagem.size(), imagem.type());
    for (int y = 0; y < imagem.rows; y++) {
        for (int x = 0; x < imagem.cols; x++) {
            resultado.at<cv::Vec3b>(y, x)[0] = imagem.at<cv::Vec3b>(y, x)[0];
            resultado.at<cv::Vec3b>(y, x)[1] = 0;
            resultado.at<cv::Vec3b>(y, x)[2] = 0;
        }
    }
    return resultado;
}
