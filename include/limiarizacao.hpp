#include <opencv2/opencv.hpp>

/**
 * @class limiarizacao
 * @brief Classe responsável por realizar operações de limiarização em imagens.
 *
 * Esta classe fornece métodos para aplicar limiarização em imagens utilizando a biblioteca OpenCV.
 */
class limiarizacao
{
    public:

        /**
         * @brief Construtor da classe limiarizacao.
         *
         * Inicializa uma nova instância da classe limiarizacao.
         */
        limiarizacao();

        /**
         * @brief Destrutor da classe limiarizacao.
         *
         * Libera os recursos utilizados pela instância da classe limiarizacao.
         */
        ~limiarizacao();

        /**
         * @brief Aplica a limiarização em uma imagem.
         *
         * Este método aplica um limiar à imagem fornecida, convertendo os pixels conforme o valor do limiar.
         *
         * @param imagem Imagem de entrada do tipo cv::Mat.
         * @param limiar Valor do limiar (uchar) a ser aplicado.
         * @return Uma nova imagem cv::Mat resultante da limiarização.
         */
        static cv::Mat aplicarLimiar(const cv::Mat& imagem, uchar limiar);

    private:
        
};