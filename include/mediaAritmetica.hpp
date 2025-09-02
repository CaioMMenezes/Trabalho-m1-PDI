#include <opencv2/opencv.hpp>

/**
 * @class mediaAritmetica
 * @brief Classe responsável por aplicar a média aritmética em imagens.
 *
 * Esta classe fornece métodos para calcular a média aritmética dos pixels de uma imagem utilizando a biblioteca OpenCV.
 */
class mediaAritmetica
{
    public:

        /**
         * @brief Construtor da classe mediaAritmetica.
         *
         * Inicializa uma nova instância da classe mediaAritmetica.
         */
        mediaAritmetica();

        /**
         * @brief Destrutor da classe mediaAritmetica.
         *
         * Libera os recursos utilizados pela instância da classe.
         */
        ~mediaAritmetica();

        /**
         * @brief Calcula a média aritmética dos pixels de uma imagem.
         *
         * Este método recebe uma imagem do tipo cv::Mat e retorna uma nova imagem resultante da aplicação da média aritmética.
         *
         * @param imagem Imagem de entrada do tipo cv::Mat.
         * @return cv::Mat Imagem resultante após a aplicação da média aritmética.
         */
        static cv::Mat calcularMedia(const cv::Mat& imagem);

    private:
        
};