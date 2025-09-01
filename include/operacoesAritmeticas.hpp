#pragma once
#include <opencv2/opencv.hpp>

// Operações entre duas imagens
cv::Mat somaImagens(const cv::Mat& img1, const cv::Mat& img2);
cv::Mat subtraiImagens(const cv::Mat& img1, const cv::Mat& img2);
cv::Mat multiplicaImagens(const cv::Mat& img1, const cv::Mat& img2);
cv::Mat divideImagens(const cv::Mat& img1, const cv::Mat& img2);

// Operações entre imagem e escalar
cv::Mat somaEscalar(const cv::Mat& img, double valor);
cv::Mat subtraiEscalar(const cv::Mat& img, double valor);
cv::Mat multiplicaEscalar(const cv::Mat& img, double valor);
cv::Mat divideEscalar(const cv::Mat& img, double valor);
