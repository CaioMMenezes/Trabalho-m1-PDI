/**
 * @file InverterImagem.cpp
 * @brief Implementação da classe InverterImagem para inverter imagens usando OpenCV.
 */

#include "InverterImagem.hpp"
#include <opencv2/opencv.hpp>

/**
 * @class InverterImagem
 * @brief Classe responsável por inverter imagens em escala de cinza ou coloridas.
 *
 * Esta classe fornece um método para inverter os valores dos pixels de uma imagem,
 * seja ela em escala de cinza ou colorida (BGR), utilizando a biblioteca OpenCV.
 */
 
/**
 * @brief Construtor padrão da classe InverterImagem.
 *
 * Inicializa uma nova instância da classe InverterImagem.
 */
InverterImagem::InverterImagem() {}

/**
 * @brief Destrutor da classe InverterImagem.
 *
 * Libera os recursos utilizados pela instância da classe InverterImagem.
 */
InverterImagem::~InverterImagem() {}

/**
 * @brief Inverte os valores dos pixels de uma imagem.
 *
 * Este método recebe uma imagem (cv::Mat) e retorna uma nova imagem com os valores dos pixels invertidos.
 * Para imagens em escala de cinza, cada pixel é invertido em relação a 255.
 * Para imagens coloridas, cada canal (B, G, R) é invertido individualmente.
 *
 * @param imagem Imagem de entrada a ser invertida (cv::Mat).
 * @return cv::Mat Imagem resultante com os pixels invertidos. Retorna uma matriz vazia se a imagem de entrada estiver vazia.
 */
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

