
#include "limiarizacao.hpp"
#include <opencv2/opencv.hpp>

limiarizacao::limiarizacao() {}
limiarizacao::~limiarizacao() {}

// Algoritmo de limiarização: pixels acima do limiar viram 255, abaixo viram 0
cv::Mat limiarizacao::aplicarLimiar(const cv::Mat& imagem, uchar limiar) {
	if (imagem.empty()) return cv::Mat();
	cv::Mat resultado(imagem.rows, imagem.cols, CV_8UC1);
	for (int i = 0; i < imagem.rows; ++i) {
		for (int j = 0; j < imagem.cols; ++j) {
			uchar valor = imagem.at<uchar>(i, j);
			resultado.at<uchar>(i, j) = (valor > limiar) ? 255 : 0;
		}
	}
	return resultado;
}

