#include "isolarCanais.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Isola o canal vermelho (R) de uma imagem colorida.
 * 
 * Esta função recebe uma imagem colorida no formato BGR e retorna uma nova imagem
 * onde apenas o canal vermelho é mantido, enquanto os canais azul e verde são zerados.
 * 
 * @param imagem Imagem de entrada do tipo cv::Mat (espera-se uma imagem colorida BGR).
 * @return cv::Mat Imagem resultante contendo apenas o canal vermelho.
 */
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

/**
 * @brief Isola o canal verde (G) de uma imagem colorida.
 * 
 * Esta função recebe uma imagem colorida no formato BGR e retorna uma nova imagem
 * onde apenas o canal verde é mantido, enquanto os canais azul e vermelho são zerados.
 * 
 * @param imagem Imagem de entrada do tipo cv::Mat (espera-se uma imagem colorida BGR).
 * @return cv::Mat Imagem resultante contendo apenas o canal verde.
 */
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

/**
 * @brief Isola o canal azul (B) de uma imagem colorida.
 * 
 * Esta função recebe uma imagem colorida no formato BGR e retorna uma nova imagem
 * onde apenas o canal azul é mantido, enquanto os canais verde e vermelho são zerados.
 * 
 * @param imagem Imagem de entrada do tipo cv::Mat (espera-se uma imagem colorida BGR).
 * @return cv::Mat Imagem resultante contendo apenas o canal azul.
 */
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
