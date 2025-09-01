#include "mediaAritmetica.hpp"
#include <opencv2/opencv.hpp>

mediaAritmetica::mediaAritmetica() {}
mediaAritmetica::~mediaAritmetica() {}

// Calcula a média aritmética dos canais de uma imagem colorida e retorna uma imagem em escala de cinza
cv::Mat mediaAritmetica::calcularMedia(const cv::Mat& imagem) {
	if (imagem.empty()) return cv::Mat();
	cv::Mat imagem_resultado(imagem.rows, imagem.cols, CV_8UC1);
	for (int i = 0; i < imagem.rows; ++i) {
		for (int j = 0; j < imagem.cols; ++j) {
			cv::Vec3b pixel = imagem.at<cv::Vec3b>(i, j);
			imagem_resultado.at<uchar>(i, j) = (pixel[0] + pixel[1] + pixel[2]) / 3;
		}
	}
	return imagem_resultado;
}
