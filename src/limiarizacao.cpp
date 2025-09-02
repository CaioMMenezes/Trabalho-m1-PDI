#include "limiarizacao.hpp"
#include <opencv2/opencv.hpp>

/**
 * @class limiarizacao
 * @brief Classe responsável por aplicar limiarização em imagens.
 *
 * Esta classe fornece métodos para aplicar o algoritmo de limiarização em imagens,
 * convertendo pixels acima de um determinado limiar para 255 e abaixo para 0.
 */
limiarizacao::limiarizacao() {}
/**
 * @brief Destrutor da classe limiarizacao.
 *
 * Responsável por liberar recursos, se necessário.
 */
limiarizacao::~limiarizacao() {}

/**
 * @brief Aplica o algoritmo de limiarização em uma imagem.
 *
 * Para cada pixel da imagem de entrada, se o valor do pixel for maior que o limiar,
 * o valor do pixel na imagem de saída será 255; caso contrário, será 0.
 *
 * @param imagem Imagem de entrada em escala de cinza (cv::Mat).
 * @param limiar Valor do limiar (uchar) para segmentação.
 * @return cv::Mat Imagem resultante após a limiarização.
 */
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

