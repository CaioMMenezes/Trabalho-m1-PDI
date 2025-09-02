/**
 * @file mediaAritmetica.cpp
 * @brief Implementação da classe mediaAritmetica para cálculo da média aritmética dos canais de uma imagem colorida.
 */

#include "mediaAritmetica.hpp"
#include <opencv2/opencv.hpp>

/**
 * @class mediaAritmetica
 * @brief Classe responsável por calcular a média aritmética dos canais de uma imagem colorida.
 *
 * Esta classe fornece métodos para converter uma imagem colorida em uma imagem em escala de cinza,
 * utilizando a média aritmética dos valores dos canais de cor.
 */
 
/**
 * @brief Construtor padrão da classe mediaAritmetica.
 *
 * Inicializa uma nova instância da classe mediaAritmetica.
 */
mediaAritmetica::mediaAritmetica() {}

/**
 * @brief Destrutor da classe mediaAritmetica.
 *
 * Libera os recursos utilizados pela instância da classe.
 */
mediaAritmetica::~mediaAritmetica() {}

/**
 * @brief Calcula a média aritmética dos canais de uma imagem colorida.
 *
 * Este método percorre cada pixel da imagem de entrada, calcula a média dos valores dos canais B, G e R,
 * e gera uma nova imagem em escala de cinza.
 *
 * @param imagem Imagem de entrada no formato cv::Mat (espera-se uma imagem colorida).
 * @return cv::Mat Imagem resultante em escala de cinza. Retorna uma matriz vazia se a imagem de entrada estiver vazia.
 */
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
