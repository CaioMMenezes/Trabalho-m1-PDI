#include <opencv2/opencv.hpp>

/**
 * @class mediaPonderada
 * @brief Classe para cálculo da média ponderada de uma imagem.
 *
 * Esta classe fornece métodos para calcular a média ponderada dos canais de cor de uma imagem utilizando pesos específicos para cada canal (B, G, R).
 */
class mediaPonderada
{
    public:

        /**
         * @brief Construtor da classe mediaPonderada.
         *
         * Inicializa uma nova instância da classe mediaPonderada.
         */
        mediaPonderada();

        /**
         * @brief Destrutor da classe mediaPonderada.
         *
         * Libera os recursos utilizados pela instância da classe.
         */
        ~mediaPonderada();

        /**
         * @brief Calcula a média ponderada dos canais de uma imagem.
         *
         * Este método recebe uma imagem e os pesos para os canais azul, verde e vermelho, retornando uma nova imagem resultante da média ponderada.
         *
         * @param imagem Imagem de entrada do tipo cv::Mat.
         * @param b Peso para o canal azul.
         * @param g Peso para o canal verde.
         * @param r Peso para o canal vermelho.
         * @return cv::Mat Imagem resultante após aplicação da média ponderada.
         */
        static cv::Mat calcularMedia(const cv::Mat& imagem, float b, float g, float r);

    private:
        
};