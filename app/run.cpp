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
    
    cv::Mat image1 = cv::imread("../data/andando_cachorro.jpg", cv::IMREAD_COLOR);
    cv::Mat image2 = cv::imread("../data/cachorro_sentado.jpg", cv::IMREAD_COLOR);
    cv::Mat image3 = cv::imread("../data/carinho_cachorro.jpg", cv::IMREAD_COLOR);
    cv::Mat image4 = cv::imread("../data/olhando_cachorro.jpg", cv::IMREAD_COLOR);

    if (image1.empty() || image2.empty() || image3.empty() || image4.empty()) {
        std::cerr << "Erro ao carregar uma das imagens!" << std::endl;
        exit(EXIT_FAILURE);
    }
    //cvtColor(image1, image1, cv::COLOR_BGR2RGB);
    //cvtColor(image2, image2, cv::COLOR_BGR2RGB);
    //cvtColor(image3, image3, cv::COLOR_BGR2RGB);
    //cvtColor(image4, image4, cv::COLOR_BGR2RGB);

    // Exibe as imagens originais
    ImageInfo::image_show(image1, "cachorro andando");
    ImageInfo::image_show(image2, "cachorro sentado");
    ImageInfo::image_show(image3, "carinho cachorro");
    ImageInfo::image_show(image4, "olhando cachorro");

    // Conversão para escala de cinza
    GrayScale to_gray1 = GrayScale(image1);
    cv::Mat gray_image1 = cv::Mat(to_gray1.get_gray());
    GrayScale to_gray2 = GrayScale(image2);
    cv::Mat gray_image2 = cv::Mat(to_gray2.get_gray());
    GrayScale to_gray3 = GrayScale(image3);
    cv::Mat gray_image3 = cv::Mat(to_gray3.get_gray());
    GrayScale to_gray4 = GrayScale(image4);
    cv::Mat gray_image4 = cv::Mat(to_gray4.get_gray());
    

    // Cálculo de médias
    cv::Mat ImagemMediaAritmetica1 = mediaAritmetica::calcularMedia(image1);
    cv::Mat ImagemMediaPonderada1 = mediaPonderada::calcularMedia(image1, 0, 1, 0);
    cv::Mat ImagemMediaAritmetica2 = mediaAritmetica::calcularMedia(image2);
    cv::Mat ImagemMediaPonderada2 = mediaPonderada::calcularMedia(image2, 1, 0, 0);
    cv::Mat ImagemMediaAritmetica3 = mediaAritmetica::calcularMedia(image3);
    cv::Mat ImagemMediaPonderada3 = mediaPonderada::calcularMedia(image3, 0, 0, 1);
    cv::Mat ImagemMediaAritmetica4 = mediaAritmetica::calcularMedia(image4);
    cv::Mat ImagemMediaPonderada4 = mediaPonderada::calcularMedia(image4, 0.25, 0.25, 0.5);

    // Limiarização
    cv::Mat ImagemLimiarizada1 = limiarizacao::aplicarLimiar(gray_image1, 128);
    cv::Mat ImagemLimiarizada2 = limiarizacao::aplicarLimiar(gray_image2, 200);
    cv::Mat ImagemLimiarizada3 = limiarizacao::aplicarLimiar(gray_image3, 50);
    cv::Mat ImagemLimiarizada4 = limiarizacao::aplicarLimiar(gray_image4, 170);

    // Inversão de imagem
    cv::Mat ImagemInvertida1 = InverterImagem::inverter(image1);
    cv::Mat ImagemInvertida2 = InverterImagem::inverter(image2);
    cv::Mat ImagemInvertida3 = InverterImagem::inverter(image3);
    cv::Mat ImagemInvertida4 = InverterImagem::inverter(image4);

    // Histograma grayscale
    std::vector<int> hist_gray1 = calcularHistogramaGrayscale(gray_image1);
    cv::Mat hist_gray_img1 = visualizarHistogramaGrayscale(hist_gray1);
    std::vector<int> hist_gray2 = calcularHistogramaGrayscale(gray_image2);
    cv::Mat hist_gray_img2 = visualizarHistogramaGrayscale(hist_gray2);
    std::vector<int> hist_gray3 = calcularHistogramaGrayscale(gray_image3);
    cv::Mat hist_gray_img3 = visualizarHistogramaGrayscale(hist_gray3);
    std::vector<int> hist_gray4 = calcularHistogramaGrayscale(gray_image4);
    cv::Mat hist_gray_img4 = visualizarHistogramaGrayscale(hist_gray4);
    

    // Histograma colorido
    std::vector<std::vector<int>> hist_color1 = calcularHistogramaColorido(image1);
    cv::Mat hist_color_img1 = visualizarHistogramaColorido(hist_color1);
    std::vector<std::vector<int>> hist_color2 = calcularHistogramaColorido(image2);
    cv::Mat hist_color_img2 = visualizarHistogramaColorido(hist_color2);
    std::vector<std::vector<int>> hist_color3 = calcularHistogramaColorido(image3);
    cv::Mat hist_color_img3 = visualizarHistogramaColorido(hist_color3);
    std::vector<std::vector<int>> hist_color4 = calcularHistogramaColorido(image4);
    cv::Mat hist_color_img4 = visualizarHistogramaColorido(hist_color4);
    

    // Isolamento de canais
    cv::Mat canalR = isolarCanalR(image1);
    cv::Mat canalG = isolarCanalG(image2);
    cv::Mat canalB = isolarCanalB(image3);
    

    // Operações aritméticas entre imagens
    cv::Mat somaImg = somaImagens(image1, image2);
    cv::Mat subtraiImg = subtraiImagens(image3, image4);
    cv::Mat multiplicaImg = multiplicaImagens(image1, image3);
    cv::Mat divideImg = divideImagens(image2, image4);
    

    // Operações aritméticas com escalar
    cv::Mat somaEsc = somaEscalar(image1, 50);
    cv::Mat subtraiEsc = subtraiEscalar(image2, 50);
    cv::Mat multiplicaEsc = multiplicaEscalar(image3, 2);
    cv::Mat divideEsc = divideEscalar(image4, 2);
    
    
     // Exibição das imagens processadas
     //imagem 1
    ImageInfo::image_show(gray_image1, "cachorro andando - Gray");
    cv::imshow("cachorro andando - Gray", gray_image1);
    ImageInfo::image_show(ImagemMediaAritmetica1, "cachorro andando - Media Aritmetica");
    cv::imshow("cachorro andando - Media Aritmetica", ImagemMediaAritmetica1);
    ImageInfo::image_show(ImagemMediaPonderada1, "cachorro andando - Media Ponderada");
    cv::imshow("cachorro andando - Media Ponderada", ImagemMediaPonderada1);
    ImageInfo::image_show(ImagemLimiarizada1, "cachorro andando - Limiarizada");
    cv::imshow("cachorro andando - Limiarizada", ImagemLimiarizada1);
    ImageInfo::image_show(ImagemInvertida1, "cachorro andando - Invertida");
    cv::imshow("cachorro andando - Invertida", ImagemInvertida1);
    ImageInfo::image_show(hist_gray_img1, "Histograma Gray - cachorro andando");
    cv::imshow("Histograma Gray - cachorro andando", hist_gray_img1);
    ImageInfo::image_show(hist_color_img1, "Histograma Colorido - cachorro andando");
    cv::imshow("Histograma Colorido - cachorro andando", hist_color_img1);

    //imagem 2
    // ImageInfo::image_show(gray_image2, "cachorro sentado - Gray");
    // cv::imshow("cachorro sentado - Gray", gray_image2);
    // ImageInfo::image_show(ImagemMediaAritmetica2, "cachorro sentado - Media Aritmetica");
    // cv::imshow("cachorro sentado - Media Aritmetica", ImagemMediaAritmetica2);
    // ImageInfo::image_show(ImagemMediaPonderada2, "cachorro sentado - Media Ponderada");
    // cv::imshow("cachorro sentado - Media Ponderada", ImagemMediaPonderada2);
    // ImageInfo::image_show(ImagemLimiarizada2, "cachorro sentado - Limiarizada");
    // cv::imshow("cachorro sentado - Limiarizada", ImagemLimiarizada2);
    // ImageInfo::image_show(ImagemInvertida2, "cachorro sentado - Invertida");
    // cv::imshow("cachorro sentado - Invertida", ImagemInvertida2);
    // ImageInfo::image_show(hist_gray_img2, "Histograma Gray - cachorro sentado");
    // cv::imshow("Histograma Gray - cachorro sentado", hist_gray_img2);
    // ImageInfo::image_show(hist_color_img2, "Histograma Colorido - cachorro sentado");
    // cv::imshow("Histograma Colorido - cachorro sentado", hist_color_img2);

    //imagem 3
    // ImageInfo::image_show(gray_image3, "carinho cachorro - Gray");
    // cv::imshow("carinho cachorro - Gray", gray_image3);
    // ImageInfo::image_show(ImagemMediaAritmetica3, "carinho cachorro - Media Aritmetica");
    // cv::imshow("carinho cachorro - Media Aritmetica", ImagemMediaAritmetica3);
    // ImageInfo::image_show(ImagemMediaPonderada3, "carinho cachorro - Media Ponderada");
    // cv::imshow("carinho cachorro - Media Ponderada", ImagemMediaPonderada3);
    // ImageInfo::image_show(ImagemLimiarizada3, "carinho cachorro - Limiarizada");
    // cv::imshow("carinho cachorro - Limiarizada", ImagemLimiarizada3);
    // ImageInfo::image_show(ImagemInvertida3, "carinho cachorro - Invertida");
    // cv::imshow("carinho cachorro - Invertida", ImagemInvertida3);
    // ImageInfo::image_show(hist_gray_img3, "Histograma Gray - carinho cachorro");
    // cv::imshow("Histograma Gray - carinho cachorro", hist_gray_img3);
    // ImageInfo::image_show(hist_color_img3, "Histograma Colorido - carinho cachorro");
    // cv::imshow("Histograma Colorido - carinho cachorro", hist_color_img3);

    //imagem 4
    // ImageInfo::image_show(gray_image4, "olhando cachorro - Gray");
    // cv::imshow("olhando cachorro - Gray", gray_image4);
    // ImageInfo::image_show(ImagemMediaAritmetica4, "olhando cachorro - Media Aritmetica");
    // cv::imshow("olhando cachorro - Media Aritmetica", ImagemMediaAritmetica4);
    // ImageInfo::image_show(ImagemMediaPonderada4, "olhando cachorro - Media Ponderada");
    // cv::imshow("olhando cachorro - Media Ponderada", ImagemMediaPonderada4);
    // ImageInfo::image_show(ImagemLimiarizada4, "olhando cachorro - Limiarizada");
    // cv::imshow("olhando cachorro - Limiarizada", ImagemLimiarizada4);
    // ImageInfo::image_show(ImagemInvertida4, "olhando cachorro - Invertida");
    // cv::imshow("olhando cachorro - Invertida", ImagemInvertida4);
    // ImageInfo::image_show(hist_gray_img4, "Histograma Gray - olhando cachorro");
    // cv::imshow("Histograma Gray - olhando cachorro", hist_gray_img4);
    // ImageInfo::image_show(hist_color_img4, "Histograma Colorido - olhando cachorro");
    // cv::imshow("Histograma Colorido - olhando cachorro", hist_color_img4);

    // Exibição dos resultados das operações extras
    ImageInfo::image_show(canalR, "Canal Vermelho (R)");
    cv::imshow("Canal Vermelho (R)", canalR);
    ImageInfo::image_show(canalG, "Canal Verde (G)");
    cv::imshow("Canal Verde (G)", canalG);
    ImageInfo::image_show(canalB, "Canal Azul (B)");
    cv::imshow("Canal Azul (B)", canalB);
    ImageInfo::image_show(somaImg, "Soma Imagem 1 + Imagem 2");
    cv::imshow("Soma Imagem 1 + Imagem 2", somaImg);
    ImageInfo::image_show(subtraiImg, "Subtrai Imagem 3 - Imagem 4");
    cv::imshow("Subtrai Imagem 3 - Imagem 4", subtraiImg);
    ImageInfo::image_show(multiplicaImg, "Multiplica Imagem 1 * Imagem 3");
    cv::imshow("Multiplica Imagem 1 * Imagem 3", multiplicaImg);
    ImageInfo::image_show(divideImg, "Divide Imagem 2 / Imagem 4");
    cv::imshow("Divide Imagem 2 / Imagem 4", divideImg);
    ImageInfo::image_show(somaEsc, "Soma Imagem 1 + Escalar");
    cv::imshow("Soma Imagem 1 + Escalar", somaEsc);
    ImageInfo::image_show(subtraiEsc, "Subtrai Imagem 2 - Escalar");
    cv::imshow("Subtrai Imagem 2 - Escalar", subtraiEsc);
    ImageInfo::image_show(multiplicaEsc, "Multiplica Imagem 3 * Escalar");
    cv::imshow("Multiplica Imagem 3 * Escalar", multiplicaEsc);
    ImageInfo::image_show(divideEsc, "Divide Imagem 4 / Escalar");
    cv::imshow("Divide Imagem 4 / Escalar", divideEsc);


    cv::waitKey(0);
    
    
    
    exit(EXIT_SUCCESS);
}