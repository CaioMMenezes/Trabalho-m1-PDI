#include <iostream>
#include <opencv2/opencv.hpp>

#include "grayscale.hpp"
#include "imageinfo.hpp"
#include "mediaAritmetica.hpp"
#include "mediaPonderada.hpp"

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
    

    
    cv::imshow("Ave 02", image);
    cv::imshow("Ave 02 - Gray Image", gray_image);
    cv::imshow("Ave 02 - Media Aritmetica", ImagemMediaAritmetica);
    cv::imshow("Ave 02 - Media Ponderada g", ImagemMediaPonderada);
    

    cv::waitKey(0);
    
    //GrayScale op;
    
    exit(EXIT_SUCCESS);
}