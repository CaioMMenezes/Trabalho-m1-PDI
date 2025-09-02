/**
 * @file grayscale.cpp
 * @brief Implementação da classe GrayScale para conversão de imagens coloridas para escala de cinza.
 */

#include "grayscale.hpp"

/**
 * @class GrayScale
 * @brief Classe responsável por converter uma imagem colorida em escala de cinza.
 *
 * Esta classe recebe uma imagem colorida (cv::Mat) e permite obter sua versão em escala de cinza.
 */
 
/**
 * @brief Construtor da classe GrayScale.
 * 
 * Inicializa a matriz de resultado com o mesmo tamanho da imagem de entrada, porém com apenas um canal (escala de cinza).
 * 
 * @param img1 Imagem colorida de entrada (cv::Mat).
 */
GrayScale::GrayScale (const cv::Mat& img1)
{
    // Inicializa a matriz de resultado com o mesmo tamanho e tipo da imagem de entrada, mas com 1 canal.
    img1_ = img1;
    result = cv::Mat(img1.rows, img1.cols, CV_8UC(1));
}

/**
 * @brief Executa a conversão de uma imagem colorida para escala de cinza.
 * 
 * Percorre todos os pixels da imagem de entrada, calcula a média dos canais BGR e atribui o valor ao pixel correspondente na imagem de saída.
 * 
 * @return cv::Mat Imagem resultante em escala de cinza.
 */
cv::Mat GrayScale::get_gray()
{
    for (int linha = 0; linha < img1_.rows; linha++)
    {
        cv::Vec3b* pixel__in = img1_.ptr<cv::Vec3b>(linha);
        uchar* pixel_out = result.ptr<uchar>(linha);

        for (int coluna = 0; coluna < img1_.cols; coluna++)
        {
            pixel_out[coluna] = static_cast<uchar>( (pixel__in[coluna][0] + pixel__in[coluna][1] + pixel__in[coluna][2]) / 3 );
            //pixel_out[coluna] = (pixel__in[coluna][0] + pixel__in[coluna][1] + pixel__in[coluna][2]) / 3 ;
            //std::cout << "Linha: " << linha << ", Coluna: " << coluna << ", Pixel: " << static_cast<int>(pixel_out[coluna]) << std::endl;
        }
    }
    return result;
}