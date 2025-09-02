/**
 * @file mediaPonderada.cpp
 * @brief Implementação da classe mediaPonderada para cálculo de média ponderada de imagens coloridas.
 */

#include "mediaPonderada.hpp"
#include <opencv2/opencv.hpp>

/**
 * @class mediaPonderada
 * @brief Classe responsável por calcular a média ponderada dos canais de uma imagem colorida.
 *
 * Esta classe fornece métodos para converter uma imagem colorida em escala de cinza,
 * utilizando pesos personalizados para cada canal (B, G, R).
 */
mediaPonderada::mediaPonderada() {}
/**
 * @brief Destrutor da classe mediaPonderada.
 *
 * Libera recursos utilizados pela classe, se necessário.
 */
mediaPonderada::~mediaPonderada() {}

/**
 * @brief Calcula a média ponderada dos canais de uma imagem colorida.
 *
 * Converte uma imagem colorida (BGR) em escala de cinza, aplicando pesos específicos
 * para cada canal (b, g, r).
 *
 * @param imagem Imagem de entrada no formato cv::Mat (BGR).
 * @param b Peso para o canal azul (Blue).
 * @param g Peso para o canal verde (Green).
 * @param r Peso para o canal vermelho (Red).
 * @return cv::Mat Imagem resultante em escala de cinza.
 */
cv::Mat mediaPonderada::calcularMedia(const cv::Mat& imagem, float b, float g, float r) {
    if (imagem.empty()) return cv::Mat();
    cv::Mat imagem_resultado(imagem.rows, imagem.cols, CV_8UC1);
    for (int i = 0; i < imagem.rows; ++i) {
        for (int j = 0; j < imagem.cols; ++j) {
            cv::Vec3b pixel = imagem.at<cv::Vec3b>(i, j);
            float valor = pixel[0] * b + pixel[1] * g + pixel[2] * r;
            imagem_resultado.at<uchar>(i, j) = static_cast<uchar>(std::min(std::max(valor, 0.0f), 255.0f));
        }
    }
    return imagem_resultado;
}
