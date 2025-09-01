#pragma once
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

// Calcula o histograma de uma imagem em tons de cinza
std::vector<int> calcularHistogramaGrayscale(const cv::Mat& imagem);

// Calcula o histograma de uma imagem colorida (RGB)
std::vector<std::vector<int>> calcularHistogramaColorido(const cv::Mat& imagem);

// Gera uma imagem de visualização do histograma em tons de cinza
cv::Mat visualizarHistogramaGrayscale(const std::vector<int>& histograma);

// Gera uma imagem de visualização do histograma colorido
cv::Mat visualizarHistogramaColorido(const std::vector<std::vector<int>>& histograma);
