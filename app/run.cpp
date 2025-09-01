#include <iostream>
#include <opencv2/opencv.hpp>

#include "grayscale.hpp"
#include "imageinfo.hpp"
#include "mediaAritmetica.hpp"
#include "mediaPonderada.hpp"
#include "limiarizacao.hpp"
#include "InverterImagem.hpp"
// Novos includes
#include "histograma.hpp"
#include "isolarCanais.hpp"
#include "operacoesAritmeticas.hpp"

int main(int argc, char** argv)
{   
    system("clear"); // clear terminal    
    std::cout << "Implementacoes M1 (dominio do valor)" << std::endl;
  
    /**
    cv::Mat image = cv::Mat::zeros(300, 600, CV_8UC3);
    cv::putText(image, "OpenCV Funcionando!", cv::Point(100, 150), 
               cv::FONT_HERSHEY_COMPLEX, 1.0, cv::Scalar(0, 255, 0), 2);
    */
    
    cv::Mat image = cv::imread("../data/ave-02.jpeg", cv::IMREAD_COLOR);
    if (image.empty())
    {
        std::cerr << "Erro ao carregar a imagem!" << std::endl;
        exit(EXIT_FAILURE);
    }
    //cvtColor(image, image, cv::COLOR_BGR2RGB);

    
    ImageInfo::image_show(image, "Ave 02");
    GrayScale to_gray = GrayScale(image);
    cv::Mat gray_image = cv::Mat(to_gray.get_gray());
    cv::Mat ImagemMediaAritmetica = mediaAritmetica::calcularMedia(image);
    cv::Mat ImagemMediaPonderada = mediaPonderada::calcularMedia(image, 0, 1, 0);
    cv::Mat ImagemLimiarizada = limiarizacao::aplicarLimiar(gray_image, 128);
    cv::Mat ImagemInvertida = InverterImagem::inverter(image);
    // --- Exemplo: Histograma Grayscale ---
    std::vector<int> hist_gray = calcularHistogramaGrayscale(gray_image);
    cv::Mat hist_gray_img = visualizarHistogramaGrayscale(hist_gray);
    ImageInfo::image_show(hist_gray_img, "Histograma Grayscale");

    // --- Exemplo: Histograma Colorido ---
    std::vector<std::vector<int>> hist_color = calcularHistogramaColorido(image);
    cv::Mat hist_color_img = visualizarHistogramaColorido(hist_color);
    ImageInfo::image_show(hist_color_img, "Histograma Colorido");

    // --- Exemplo: Isolar canais ---
    cv::Mat canalR = isolarCanalR(image);
    cv::Mat canalG = isolarCanalG(image);
    cv::Mat canalB = isolarCanalB(image);
    ImageInfo::image_show(canalR, "Canal Vermelho (R)");
    ImageInfo::image_show(canalG, "Canal Verde (G)");
    ImageInfo::image_show(canalB, "Canal Azul (B)");

    // --- Exemplo: Operações aritméticas entre imagens ---
    cv::Mat somaImg = somaImagens(image, image);
    cv::Mat subtraiImg = subtraiImagens(image, image);
    cv::Mat multiplicaImg = multiplicaImagens(image, image);
    cv::Mat divideImg = divideImagens(image, image);
    ImageInfo::image_show(somaImg, "Soma Imagem + Imagem");
    ImageInfo::image_show(subtraiImg, "Subtrai Imagem - Imagem");
    ImageInfo::image_show(multiplicaImg, "Multiplica Imagem * Imagem");
    ImageInfo::image_show(divideImg, "Divide Imagem / Imagem");

    // --- Exemplo: Operações aritméticas com escalar ---
    cv::Mat somaEsc = somaEscalar(image, 50);
    cv::Mat subtraiEsc = subtraiEscalar(image, 50);
    cv::Mat multiplicaEsc = multiplicaEscalar(image, 2);
    cv::Mat divideEsc = divideEscalar(image, 2);
    ImageInfo::image_show(somaEsc, "Soma Imagem + Escalar");
    ImageInfo::image_show(subtraiEsc, "Subtrai Imagem - Escalar");
    ImageInfo::image_show(multiplicaEsc, "Multiplica Imagem * Escalar");
    ImageInfo::image_show(divideEsc, "Divide Imagem / Escalar");
    
    cv::imshow("Ave 02", image);
    cv::imshow("Ave 02 - Gray Image", gray_image);
    cv::imshow("Ave 02 - Media Aritmetica", ImagemMediaAritmetica);
    cv::imshow("Ave 02 - Media Ponderada g", ImagemMediaPonderada);
    cv::imshow("Ave 02 - Limiarizacao", ImagemLimiarizada);
    cv::imshow("Ave 02 - Invertida", ImagemInvertida);

    // Mostrar resultados das novas funcionalidades
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