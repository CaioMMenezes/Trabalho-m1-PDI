/**
 * @file run.cpp
 * @brief Arquivo principal para execução das operações de processamento de imagens.
 *
 * Este arquivo contém a função principal que executa diversas operações de processamento de imagens
 * utilizando a biblioteca OpenCV, incluindo conversão para escala de cinza, cálculo de médias,
 * limiarização, inversão, cálculo e visualização de histogramas, isolamento de canais de cor e
 * operações aritméticas entre imagens e escalares.
 */

#include <iostream>
#include <opencv2/opencv.hpp>

#include "grayscale.hpp"
#include "imageinfo.hpp"
#include "mediaAritmetica.hpp"
#include "mediaPonderada.hpp"
#include "limiarizacao.hpp"
#include "InverterImagem.hpp"
#include "histograma.hpp"
#include "isolarCanais.hpp"
#include "operacoesAritmeticas.hpp"

/**
 * @brief Função principal do programa.
 *
 * Realiza o carregamento de uma imagem, aplica diversas operações de processamento de imagens
 * e exibe os resultados utilizando janelas do OpenCV.
 *
 * As operações realizadas incluem:
 * - Conversão para escala de cinza
 * - Cálculo de média aritmética e ponderada
 * - Limiarização
 * - Inversão de imagem
 * - Cálculo e visualização de histogramas (grayscale e colorido)
 * - Isolamento dos canais R, G e B
 * - Operações aritméticas entre imagens (soma, subtração, multiplicação, divisão)
 * - Operações aritméticas com escalares
 *
 * @param argc Número de argumentos da linha de comando.
 * @param argv Vetor de argumentos da linha de comando.
 * @return int Código de status da execução.
 */
int main(int argc, char** argv)
{   
    system("clear"); // Limpa o terminal    
    std::cout << "Implementacoes M1 (dominio do valor)" << std::endl;
  
    /**
     * Exemplo de criação de imagem e texto (comentado).
     * cv::Mat image = cv::Mat::zeros(300, 600, CV_8UC3);
     * cv::putText(image, "OpenCV Funcionando!", cv::Point(100, 150), 
     *            cv::FONT_HERSHEY_COMPLEX, 1.0, cv::Scalar(0, 255, 0), 2);
     */
    
    cv::Mat image = cv::imread("../data/ave-02.jpeg", cv::IMREAD_COLOR);
    if (image.empty())
    {
        std::cerr << "Erro ao carregar a imagem!" << std::endl;
        exit(EXIT_FAILURE);
    }
    //cvtColor(image, image, cv::COLOR_BGR2RGB);

    // Exibe a imagem original
    ImageInfo::image_show(image, "Ave 02");

    // Conversão para escala de cinza
    GrayScale to_gray = GrayScale(image);
    cv::Mat gray_image = cv::Mat(to_gray.get_gray());

    // Cálculo de médias
    cv::Mat ImagemMediaAritmetica = mediaAritmetica::calcularMedia(image);
    cv::Mat ImagemMediaPonderada = mediaPonderada::calcularMedia(image, 0, 1, 0);

    // Limiarização
    cv::Mat ImagemLimiarizada = limiarizacao::aplicarLimiar(gray_image, 128);

    // Inversão de imagem
    cv::Mat ImagemInvertida = InverterImagem::inverter(image);

    // Histograma grayscale
    std::vector<int> hist_gray = calcularHistogramaGrayscale(gray_image);
    cv::Mat hist_gray_img = visualizarHistogramaGrayscale(hist_gray);
    ImageInfo::image_show(hist_gray_img, "Histograma Grayscale");

    // Histograma colorido
    std::vector<std::vector<int>> hist_color = calcularHistogramaColorido(image);
    cv::Mat hist_color_img = visualizarHistogramaColorido(hist_color);
    ImageInfo::image_show(hist_color_img, "Histograma Colorido");

    // Isolamento de canais
    cv::Mat canalR = isolarCanalR(image);
    cv::Mat canalG = isolarCanalG(image);
    cv::Mat canalB = isolarCanalB(image);
    ImageInfo::image_show(canalR, "Canal Vermelho (R)");
    ImageInfo::image_show(canalG, "Canal Verde (G)");
    ImageInfo::image_show(canalB, "Canal Azul (B)");

    // Operações aritméticas entre imagens
    cv::Mat somaImg = somaImagens(image, image);
    cv::Mat subtraiImg = subtraiImagens(image, image);
    cv::Mat multiplicaImg = multiplicaImagens(image, image);
    cv::Mat divideImg = divideImagens(image, image);
    ImageInfo::image_show(somaImg, "Soma Imagem + Imagem");
    ImageInfo::image_show(subtraiImg, "Subtrai Imagem - Imagem");
    ImageInfo::image_show(multiplicaImg, "Multiplica Imagem * Imagem");
    ImageInfo::image_show(divideImg, "Divide Imagem / Imagem");

    // Operações aritméticas com escalar
    cv::Mat somaEsc = somaEscalar(image, 50);
    cv::Mat subtraiEsc = subtraiEscalar(image, 50);
    cv::Mat multiplicaEsc = multiplicaEscalar(image, 2);
    cv::Mat divideEsc = divideEscalar(image, 2);
    ImageInfo::image_show(somaEsc, "Soma Imagem + Escalar");
    ImageInfo::image_show(subtraiEsc, "Subtrai Imagem - Escalar");
    ImageInfo::image_show(multiplicaEsc, "Multiplica Imagem * Escalar");
    ImageInfo::image_show(divideEsc, "Divide Imagem / Escalar");
    
    // Exibição das imagens processadas
    cv::imshow("Ave 02", image);
    cv::imshow("Ave 02 - Gray Image", gray_image);
    cv::imshow("Ave 02 - Media Aritmetica", ImagemMediaAritmetica);
    cv::imshow("Ave 02 - Media Ponderada g", ImagemMediaPonderada);
    cv::imshow("Ave 02 - Limiarizacao", ImagemLimiarizada);
    cv::imshow("Ave 02 - Invertida", ImagemInvertida);

    // Exibição dos resultados das novas funcionalidades
    cv::imshow("Histograma Grayscale", hist_gray_img);
    cv::imshow("Histograma Colorido", hist_color_img);
    cv::imshow("Canal Vermelho (R)", canalR);
    cv::imshow("Canal Verde (G)", canalG);
    cv::imshow("Canal Azul (B)", canalB);
    cv::imshow("Soma Imagem + Imagem", somaImg);
    cv::imshow("Subtrai Imagem - Imagem", subtraiImg);
    cv::imshow("Multiplica Imagem * Imagem", multiplicaImg);
    cv::imshow("Divide Imagem / Imagem", divideImg);
    cv::imshow("Soma Imagem + Escalar", somaEsc);
    cv::imshow("Subtrai Imagem - Escalar", subtraiEsc);
    cv::imshow("Multiplica Imagem * Escalar", multiplicaEsc);
    cv::imshow("Divide Imagem / Escalar", divideEsc);

    cv::waitKey(0);
    
    //GrayScale op;
    
    exit(EXIT_SUCCESS);
}