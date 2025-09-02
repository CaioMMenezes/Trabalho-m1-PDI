#pragma once
#include <opencv2/opencv.hpp>

/**
 * @file isolarCanais.hpp
 * @brief Funções para isolar canais de cor em imagens coloridas usando OpenCV.
 *
 * Este arquivo contém declarações de funções para isolar os canais vermelho (R), verde (G) e azul (B)
 * de uma imagem colorida representada por um objeto cv::Mat.
 */

/**
 * @brief Isola o canal vermelho (R) de uma imagem colorida.
 *
 * Esta função recebe uma imagem colorida no formato BGR e retorna uma nova imagem
 * onde apenas o canal vermelho é mantido, enquanto os canais azul e verde são zerados.
 *
 * @param imagem Imagem de entrada no formato cv::Mat (BGR).
 * @return cv::Mat Imagem resultante contendo apenas o canal vermelho.
 */
cv::Mat isolarCanalR(const cv::Mat& imagem);

/**
 * @brief Isola o canal verde (G) de uma imagem colorida.
 *
 * Esta função recebe uma imagem colorida no formato BGR e retorna uma nova imagem
 * onde apenas o canal verde é mantido, enquanto os canais azul e vermelho são zerados.
 *
 * @param imagem Imagem de entrada no formato cv::Mat (BGR).
 * @return cv::Mat Imagem resultante contendo apenas o canal verde.
 */
cv::Mat isolarCanalG(const cv::Mat& imagem);

/**
 * @brief Isola o canal azul (B) de uma imagem colorida.
 *
 * Esta função recebe uma imagem colorida no formato BGR e retorna uma nova imagem
 * onde apenas o canal azul é mantido, enquanto os canais verde e vermelho são zerados.
 *
 * @param imagem Imagem de entrada no formato cv::Mat (BGR).
 * @return cv::Mat Imagem resultante contendo apenas o canal azul.
 */
cv::Mat isolarCanalB(const cv::Mat& imagem);
