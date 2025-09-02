#pragma once
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

/**
 * @file histograma.hpp
 * @brief Funções utilitárias para cálculo e visualização de histogramas de imagens.
 */

/**
 * @brief Calcula o histograma de uma imagem em tons de cinza.
 * 
 * Esta função percorre todos os pixels da imagem fornecida e conta a frequência de cada valor de intensidade (0-255).
 * 
 * @param imagem Imagem de entrada em tons de cinza (cv::Mat).
 * @return std::vector<int> Vetor contendo a contagem de pixels para cada intensidade (256 posições).
 */
std::vector<int> calcularHistogramaGrayscale(const cv::Mat& imagem);

/**
 * @brief Calcula o histograma de uma imagem colorida (RGB).
 * 
 * Esta função calcula separadamente o histograma de cada canal de cor (R, G, B) da imagem fornecida.
 * 
 * @param imagem Imagem de entrada colorida (cv::Mat).
 * @return std::vector<std::vector<int>> Vetor de três vetores, cada um contendo o histograma de um canal (R, G, B).
 */
std::vector<std::vector<int>> calcularHistogramaColorido(const cv::Mat& imagem);

/**
 * @brief Gera uma imagem de visualização do histograma em tons de cinza.
 * 
 * Cria uma imagem que representa graficamente o histograma fornecido, facilitando a análise visual da distribuição de intensidades.
 * 
 * @param histograma Vetor contendo o histograma de uma imagem em tons de cinza.
 * @return cv::Mat Imagem representando o histograma.
 */
cv::Mat visualizarHistogramaGrayscale(const std::vector<int>& histograma);

/**
 * @brief Gera uma imagem de visualização do histograma colorido.
 * 
 * Cria uma imagem que representa graficamente os histogramas dos canais R, G e B, sobrepostos para facilitar a análise visual.
 * 
 * @param histograma Vetor de três vetores, cada um contendo o histograma de um canal de cor.
 * @return cv::Mat Imagem representando o histograma colorido.
 */
cv::Mat visualizarHistogramaColorido(const std::vector<std::vector<int>>& histograma);
