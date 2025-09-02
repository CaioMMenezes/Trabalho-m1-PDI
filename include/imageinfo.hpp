#ifndef IMAGEINFO_H
#define IMAGEINFO_H

#pragma once

#include <opencv2/opencv.hpp>

/**
 * @class ImageInfo
 * @brief Classe utilitária para exibição e análise de imagens usando OpenCV.
 *
 * Esta classe fornece métodos estáticos para exibir imagens e converter tipos de dados
 * do OpenCV em strings legíveis, facilitando o desenvolvimento e depuração de aplicações
 * de processamento de imagens.
 */
class ImageInfo
{
    public:

        /**
         * @brief Construtor padrão da classe ImageInfo.
         *
         * Inicializa uma nova instância da classe ImageInfo.
         */
        ImageInfo();

        /**
         * @brief Destrutor da classe ImageInfo.
         *
         * Libera os recursos associados à instância de ImageInfo.
         */
        ~ImageInfo();

        /**
         * @brief Exibe uma imagem em uma janela.
         *
         * Mostra a imagem fornecida em uma janela nomeada. Útil para visualização rápida
         * durante o processamento de imagens.
         *
         * @param image Matriz de imagem do OpenCV a ser exibida.
         * @param nomeImagem Nome da janela onde a imagem será exibida (padrão: "Imagem").
         */
        static void image_show (const cv::Mat& image, const std::string& nomeImagem = "Imagem");

    private:

        /**
         * @brief Converte o identificador de tipo de um cv::Mat para uma string legível.
         *
         * A função recebe o inteiro retornado por `cv::Mat::type()` e extrai a informação
         * de profundidade (depth), como CV_8U, CV_32F, etc., retornando-a como uma 
         * std::string descritiva.
         *
         * @param tipo O inteiro que representa o tipo da matriz, obtido de `imagem.type()`.
         * @return std::string Uma string contendo a representação legível da profundidade da matriz.
         * Retorna "Tipo desconhecido" se a profundidade não for reconhecida.
         */
        static std::string tipo_to_string(int tipo);
};

#endif