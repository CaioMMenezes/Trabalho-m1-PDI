#pragma once
#include <opencv2/opencv.hpp>

// Isola o canal vermelho (R) de uma imagem colorida
cv::Mat isolarCanalR(const cv::Mat& imagem);

// Isola o canal verde (G) de uma imagem colorida
cv::Mat isolarCanalG(const cv::Mat& imagem);

// Isola o canal azul (B) de uma imagem colorida
cv::Mat isolarCanalB(const cv::Mat& imagem);
