#include "histograma.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

/**
 * @brief Calcula o histograma de uma imagem em tons de cinza.
 * 
 * Esta função percorre todos os pixels da imagem fornecida e conta a frequência de cada valor de intensidade (0-255).
 * 
 * @param imagem Imagem de entrada no formato cv::Mat, em tons de cinza (CV_8UC1).
 * @return std::vector<int> Vetor de 256 posições contendo a contagem de cada intensidade.
 */
std::vector<int> calcularHistogramaGrayscale(const cv::Mat& imagem) {
    std::vector<int> histograma(256, 0);
    for (int y = 0; y < imagem.rows; y++) {
        for (int x = 0; x < imagem.cols; x++) {
            int valor = imagem.at<uchar>(y, x);
            histograma[valor]++;
        }
    }
    return histograma;
}

/**
 * @brief Calcula o histograma de uma imagem colorida (BGR).
 * 
 * Esta função percorre todos os pixels da imagem colorida e conta a frequência de cada valor de intensidade (0-255) para cada canal (B, G, R).
 * 
 * @param imagem Imagem de entrada no formato cv::Mat, colorida (CV_8UC3).
 * @return std::vector<std::vector<int>> Vetor de 3 vetores (um para cada canal), cada um com 256 posições.
 */
std::vector<std::vector<int>> calcularHistogramaColorido(const cv::Mat& imagem) {
    std::vector<std::vector<int>> histograma(3, std::vector<int>(256, 0));
    for (int y = 0; y < imagem.rows; y++) {
        for (int x = 0; x < imagem.cols; x++) {
            cv::Vec3b pixel = imagem.at<cv::Vec3b>(y, x);
            for (int c = 0; c < 3; c++) {
                histograma[c][pixel[c]]++;
            }
        }
    }
    return histograma;
}

/**
 * @brief Gera uma imagem de visualização do histograma em tons de cinza.
 * 
 * Esta função normaliza o histograma e desenha as barras correspondentes em uma imagem, facilitando a visualização.
 * 
 * @param histograma Vetor de 256 posições contendo a contagem de cada intensidade.
 * @return cv::Mat Imagem do histograma (512x400 pixels, fundo branco, barras pretas).
 */
cv::Mat visualizarHistogramaGrayscale(const std::vector<int>& histograma) {
    int hist_w = 512, hist_h = 400;
    int bin_w = hist_w / 256;
    cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(255,255,255));
    int max = 1;
    for (int i = 0; i < 256; i++) {
        if (histograma[i] > max) max = histograma[i];
    }
    std::vector<int> norm_hist(256);
    for (int i = 0; i < 256; i++) {
        norm_hist[i] = (int)(((double)histograma[i] / max) * hist_h);
    }
    // Desenhar barras manualmente
    for (int i = 0; i < 256; i++) {
        for (int y = hist_h - 1; y >= hist_h - norm_hist[i]; y--) {
            for (int x = i * bin_w; x < (i + 1) * bin_w; x++) {
                if (x < hist_w && y >= 0)
                    histImage.at<cv::Vec3b>(y, x) = cv::Vec3b(0,0,0);
            }
        }
    }
    return histImage;
}

/**
 * @brief Gera uma imagem de visualização do histograma colorido (BGR).
 * 
 * Esta função normaliza cada canal do histograma e desenha as barras correspondentes em uma imagem, usando azul para o canal B, verde para G e vermelho para R.
 * 
 * @param histograma Vetor de 3 vetores (um para cada canal), cada um com 256 posições.
 * @return cv::Mat Imagem do histograma (512x400 pixels, fundo branco, barras coloridas).
 */
cv::Mat visualizarHistogramaColorido(const std::vector<std::vector<int>>& histograma) {
    int hist_w = 512, hist_h = 400;
    int bin_w = hist_w / 256;
    cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(255,255,255));
    int max[3] = {1,1,1};
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 256; i++) {
            if (histograma[c][i] > max[c]) max[c] = histograma[c][i];
        }
    }
    std::vector<std::vector<int>> norm_hist(3, std::vector<int>(256));
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 256; i++) {
            norm_hist[c][i] = (int)(((double)histograma[c][i] / max[c]) * hist_h);
        }
    }
    for (int c = 0; c < 3; c++) {
        cv::Vec3b cor = c == 0 ? cv::Vec3b(255,0,0) : (c == 1 ? cv::Vec3b(0,255,0) : cv::Vec3b(0,0,255));
        for (int i = 0; i < 256; i++) {
            for (int y = hist_h - 1; y >= hist_h - norm_hist[c][i]; y--) {
                for (int x = i * bin_w; x < (i + 1) * bin_w; x++) {
                    if (x < hist_w && y >= 0)
                        histImage.at<cv::Vec3b>(y, x) = cor;
                }
            }
        }
    }
    return histImage;
}
