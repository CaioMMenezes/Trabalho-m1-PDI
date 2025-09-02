#include <opencv2/opencv.hpp>

/**
 * @class InverterImagem
 * @brief Classe responsável por inverter as cores de uma imagem utilizando OpenCV.
 *
 * Esta classe fornece métodos para inverter as cores de uma imagem representada por um objeto cv::Mat.
 */
class InverterImagem
{
    public:
        /**
         * @brief Construtor padrão da classe InverterImagem.
         *
         * Inicializa uma nova instância da classe InverterImagem.
         */
        InverterImagem();

        /**
         * @brief Destrutor da classe InverterImagem.
         *
         * Libera os recursos utilizados pela instância da classe InverterImagem.
         */
        ~InverterImagem();

        /**
         * @brief Inverte as cores de uma imagem.
         *
         * Este método estático recebe uma imagem (cv::Mat) e retorna uma nova imagem com as cores invertidas.
         * @param imagem Imagem de entrada a ser invertida.
         * @return cv::Mat Imagem resultante com as cores invertidas.
         */
        static cv::Mat inverter(const cv::Mat& imagem);

    private:
        
};