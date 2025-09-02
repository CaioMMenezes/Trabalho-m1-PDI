#ifndef OPERATION_HPP
#define OPERATION_HPP
#include <opencv2/opencv.hpp>

/**
 * @class GrayScale
 * @brief Classe responsável por converter uma imagem colorida para escala de cinza utilizando OpenCV.
 *
 * Esta classe recebe uma imagem no formato cv::Mat e fornece um método para obter a versão em escala de cinza da imagem.
 */
class GrayScale 
{
    public:

        /**
         * @brief Construtor da classe GrayScale.
         * 
         * Inicializa a classe com a imagem fornecida.
         * @param img1 Imagem de entrada no formato cv::Mat.
         */
        GrayScale(const cv::Mat& img1);

        /**
         * @brief Obtém a imagem convertida para escala de cinza.
         * 
         * Retorna a imagem processada em escala de cinza.
         * @return cv::Mat Imagem em escala de cinza.
         */
        cv::Mat get_gray();

    private:
        /**
         * @brief Imagem original fornecida pelo usuário.
         */
        cv::Mat img1_;

        /**
         * @brief Imagem resultante após a conversão para escala de cinza.
         */
        cv::Mat result;
        
};
#endif  // OPERATION_HPP