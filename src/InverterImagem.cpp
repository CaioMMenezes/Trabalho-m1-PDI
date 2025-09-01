#include "InverterImagem.hpp"
#include <opencv2/opencv.hpp>

InverterImagem::InverterImagem() {}
InverterImagem::~InverterImagem() {}

cv::Mat InverterImagem::inverter(const cv::Mat& imagem) {
	if (imagem.empty()) return cv::Mat();
	cv::Mat resultado = imagem.clone();
	if (imagem.channels() == 1) {
		// Imagem em escala de cinza
		for (int i = 0; i < imagem.rows; ++i) {
			for (int j = 0; j < imagem.cols; ++j) {
				resultado.at<uchar>(i, j) = 255 - imagem.at<uchar>(i, j);
			}
		}
	} else if (imagem.channels() == 3) {
		// Imagem colorida
		for (int i = 0; i < imagem.rows; ++i) {
			for (int j = 0; j < imagem.cols; ++j) {
				cv::Vec3b pixel = imagem.at<cv::Vec3b>(i, j);
				resultado.at<cv::Vec3b>(i, j)[0] = 255 - pixel[0]; // B
				resultado.at<cv::Vec3b>(i, j)[1] = 255 - pixel[1]; // G
				resultado.at<cv::Vec3b>(i, j)[2] = 255 - pixel[2]; // R
			}
		}
	}
	return resultado;
}

