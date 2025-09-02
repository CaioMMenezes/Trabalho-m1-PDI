/**
 * @file operacoesAritmeticas.cpp
 * @brief Implementação das operações aritméticas entre imagens usando OpenCV.
 * 
 * Este arquivo contém funções para realizar operações aritméticas (soma, subtração, multiplicação e divisão)
 * entre imagens ou entre imagem e escalar, suportando imagens em tons de cinza e coloridas.
 */

#include "operacoesAritmeticas.hpp"
#include <opencv2/opencv.hpp>

/**
 * @brief Soma duas imagens pixel a pixel.
 * 
 * Realiza a soma dos valores dos pixels das duas imagens, saturando o resultado para evitar overflow.
 * Suporta imagens em tons de cinza e coloridas.
 * 
 * @param img1 Primeira imagem de entrada.
 * @param img2 Segunda imagem de entrada.
 * @return cv::Mat Imagem resultante da soma.
 */
cv::Mat somaImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado = img1.clone();
    for (int y = 0; y < img1.rows; y++) {
        for (int x = 0; x < img1.cols; x++) {
            if (img1.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img1.at<uchar>(y, x) + img2.at<uchar>(y, x));
            } else {
                for (int c = 0; c < img1.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img1.at<cv::Vec3b>(y, x)[c] + img2.at<cv::Vec3b>(y, x)[c]);
                }
            }
        }
    }
    return resultado;
}

/**
 * @brief Subtrai a segunda imagem da primeira pixel a pixel.
 * 
 * Realiza a subtração dos valores dos pixels das duas imagens, saturando o resultado para evitar underflow.
 * Suporta imagens em tons de cinza e coloridas.
 * 
 * @param img1 Primeira imagem de entrada.
 * @param img2 Segunda imagem de entrada.
 * @return cv::Mat Imagem resultante da subtração.
 */
cv::Mat subtraiImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado = img1.clone();
    for (int y = 0; y < img1.rows; y++) {
        for (int x = 0; x < img1.cols; x++) {
            if (img1.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img1.at<uchar>(y, x) - img2.at<uchar>(y, x));
            } else {
                for (int c = 0; c < img1.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img1.at<cv::Vec3b>(y, x)[c] - img2.at<cv::Vec3b>(y, x)[c]);
                }
            }
        }
    }
    return resultado;
}

/**
 * @brief Multiplica duas imagens pixel a pixel.
 * 
 * Realiza a multiplicação dos valores dos pixels das duas imagens, saturando o resultado.
 * Suporta imagens em tons de cinza e coloridas.
 * 
 * @param img1 Primeira imagem de entrada.
 * @param img2 Segunda imagem de entrada.
 * @return cv::Mat Imagem resultante da multiplicação.
 */
cv::Mat multiplicaImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado = img1.clone();
    for (int y = 0; y < img1.rows; y++) {
        for (int x = 0; x < img1.cols; x++) {
            if (img1.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img1.at<uchar>(y, x) * img2.at<uchar>(y, x));
            } else {
                for (int c = 0; c < img1.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img1.at<cv::Vec3b>(y, x)[c] * img2.at<cv::Vec3b>(y, x)[c]);
                }
            }
        }
    }
    return resultado;
}

/**
 * @brief Divide a primeira imagem pela segunda pixel a pixel.
 * 
 * Realiza a divisão dos valores dos pixels das duas imagens. Caso o denominador seja zero, o resultado é zero.
 * Suporta imagens em tons de cinza e coloridas.
 * 
 * @param img1 Primeira imagem de entrada.
 * @param img2 Segunda imagem de entrada.
 * @return cv::Mat Imagem resultante da divisão.
 */
cv::Mat divideImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado = img1.clone();
    for (int y = 0; y < img1.rows; y++) {
        for (int x = 0; x < img1.cols; x++) {
            if (img1.channels() == 1) {
                resultado.at<uchar>(y, x) = img2.at<uchar>(y, x) == 0 ? 0 : cv::saturate_cast<uchar>(img1.at<uchar>(y, x) / img2.at<uchar>(y, x));
            } else {
                for (int c = 0; c < img1.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = img2.at<cv::Vec3b>(y, x)[c] == 0 ? 0 : cv::saturate_cast<uchar>(img1.at<cv::Vec3b>(y, x)[c] / img2.at<cv::Vec3b>(y, x)[c]);
                }
            }
        }
    }
    return resultado;
}

/**
 * @brief Soma um valor escalar a todos os pixels da imagem.
 * 
 * Realiza a soma do valor informado a cada pixel da imagem, saturando o resultado.
 * Suporta imagens em tons de cinza e coloridas.
 * 
 * @param img Imagem de entrada.
 * @param valor Valor escalar a ser somado.
 * @return cv::Mat Imagem resultante da soma.
 */
cv::Mat somaEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado = img.clone();
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            if (img.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img.at<uchar>(y, x) + valor);
            } else {
                for (int c = 0; c < img.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img.at<cv::Vec3b>(y, x)[c] + valor);
                }
            }
        }
    }
    return resultado;
}

/**
 * @brief Subtrai um valor escalar de todos os pixels da imagem.
 * 
 * Realiza a subtração do valor informado de cada pixel da imagem, saturando o resultado.
 * Suporta imagens em tons de cinza e coloridas.
 * 
 * @param img Imagem de entrada.
 * @param valor Valor escalar a ser subtraído.
 * @return cv::Mat Imagem resultante da subtração.
 */
cv::Mat subtraiEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado = img.clone();
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            if (img.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img.at<uchar>(y, x) - valor);
            } else {
                for (int c = 0; c < img.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img.at<cv::Vec3b>(y, x)[c] - valor);
                }
            }
        }
    }
    return resultado;
}

/**
 * @brief Multiplica todos os pixels da imagem por um valor escalar.
 * 
 * Realiza a multiplicação do valor informado por cada pixel da imagem, saturando o resultado.
 * Suporta imagens em tons de cinza e coloridas.
 * 
 * @param img Imagem de entrada.
 * @param valor Valor escalar a ser multiplicado.
 * @return cv::Mat Imagem resultante da multiplicação.
 */
cv::Mat multiplicaEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado = img.clone();
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            if (img.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img.at<uchar>(y, x) * valor);
            } else {
                for (int c = 0; c < img.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img.at<cv::Vec3b>(y, x)[c] * valor);
                }
            }
        }
    }
    return resultado;
}

/**
 * @brief Divide todos os pixels da imagem por um valor escalar.
 * 
 * Realiza a divisão de cada pixel da imagem pelo valor informado. Caso o valor seja zero, o resultado é zero.
 * Suporta imagens em tons de cinza e coloridas.
 * 
 * @param img Imagem de entrada.
 * @param valor Valor escalar divisor.
 * @return cv::Mat Imagem resultante da divisão.
 */
cv::Mat divideEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado = img.clone();
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            if (img.channels() == 1) {
                resultado.at<uchar>(y, x) = valor == 0 ? 0 : cv::saturate_cast<uchar>(img.at<uchar>(y, x) / valor);
            } else {
                for (int c = 0; c < img.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = valor == 0 ? 0 : cv::saturate_cast<uchar>(img.at<cv::Vec3b>(y, x)[c] / valor);
                }
            }
        }
    }
    return resultado;
}
