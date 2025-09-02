#pragma once
#include <opencv2/opencv.hpp>

/**
 * @file operacoesAritmeticas.hpp
 * @brief Declaração de funções para operações aritméticas entre imagens e entre imagem e escalar usando OpenCV.
 *
 * Este arquivo contém as assinaturas das funções que realizam operações aritméticas básicas (soma, subtração, multiplicação e divisão)
 * entre duas imagens ou entre uma imagem e um valor escalar.
 */

/**
 * @brief Soma duas imagens pixel a pixel.
 * @param img1 Primeira imagem de entrada.
 * @param img2 Segunda imagem de entrada.
 * @return Imagem resultante da soma.
 */
cv::Mat somaImagens(const cv::Mat& img1, const cv::Mat& img2);

/**
 * @brief Subtrai a segunda imagem da primeira pixel a pixel.
 * @param img1 Primeira imagem de entrada.
 * @param img2 Segunda imagem de entrada.
 * @return Imagem resultante da subtração.
 */
cv::Mat subtraiImagens(const cv::Mat& img1, const cv::Mat& img2);

/**
 * @brief Multiplica duas imagens pixel a pixel.
 * @param img1 Primeira imagem de entrada.
 * @param img2 Segunda imagem de entrada.
 * @return Imagem resultante da multiplicação.
 */
cv::Mat multiplicaImagens(const cv::Mat& img1, const cv::Mat& img2);

/**
 * @brief Divide a primeira imagem pela segunda pixel a pixel.
 * @param img1 Primeira imagem de entrada.
 * @param img2 Segunda imagem de entrada.
 * @return Imagem resultante da divisão.
 */
cv::Mat divideImagens(const cv::Mat& img1, const cv::Mat& img2);

/**
 * @brief Soma um valor escalar a todos os pixels da imagem.
 * @param img Imagem de entrada.
 * @param valor Valor escalar a ser somado.
 * @return Imagem resultante da soma.
 */
cv::Mat somaEscalar(const cv::Mat& img, double valor);

/**
 * @brief Subtrai um valor escalar de todos os pixels da imagem.
 * @param img Imagem de entrada.
 * @param valor Valor escalar a ser subtraído.
 * @return Imagem resultante da subtração.
 */
cv::Mat subtraiEscalar(const cv::Mat& img, double valor);

/**
 * @brief Multiplica todos os pixels da imagem por um valor escalar.
 * @param img Imagem de entrada.
 * @param valor Valor escalar multiplicador.
 * @return Imagem resultante da multiplicação.
 */
cv::Mat multiplicaEscalar(const cv::Mat& img, double valor);

/**
 * @brief Divide todos os pixels da imagem por um valor escalar.
 * @param img Imagem de entrada.
 * @param valor Valor escalar divisor.
 * @return Imagem resultante da divisão.
 */
cv::Mat divideEscalar(const cv::Mat& img, double valor);
