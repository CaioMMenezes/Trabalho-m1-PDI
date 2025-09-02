#include "operacoesAritmeticas.hpp"
#include <opencv2/opencv.hpp>


cv::Mat somaImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado = img1.clone();
    for (int y = 0; y < img1.rows; y++) {
        for (int x = 0; x < img1.cols; x++) {
            if (img1.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img1.at<uchar>(y, x) + img2.at<uchar>(y, x));
            } else {
                for (int c = 0; c < img1.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img1.at<cv::Vec3b>(y, x)[c] + img2.at<cv::Vec3b>(y, x)[c]);
                }
            }
        }
    }
    return resultado;
}

cv::Mat subtraiImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado = img1.clone();
    for (int y = 0; y < img1.rows; y++) {
        for (int x = 0; x < img1.cols; x++) {
            if (img1.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img1.at<uchar>(y, x) - img2.at<uchar>(y, x));
            } else {
                for (int c = 0; c < img1.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img1.at<cv::Vec3b>(y, x)[c] - img2.at<cv::Vec3b>(y, x)[c]);
                }
            }
        }
    }
    return resultado;
}

cv::Mat multiplicaImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado = img1.clone();
    for (int y = 0; y < img1.rows; y++) {
        for (int x = 0; x < img1.cols; x++) {
            if (img1.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img1.at<uchar>(y, x) * img2.at<uchar>(y, x));
            } else {
                for (int c = 0; c < img1.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img1.at<cv::Vec3b>(y, x)[c] * img2.at<cv::Vec3b>(y, x)[c]);
                }
            }
        }
    }
    return resultado;
}

cv::Mat divideImagens(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat resultado = img1.clone();
    for (int y = 0; y < img1.rows; y++) {
        for (int x = 0; x < img1.cols; x++) {
            if (img1.channels() == 1) {
                resultado.at<uchar>(y, x) = img2.at<uchar>(y, x) == 0 ? 0 : cv::saturate_cast<uchar>(img1.at<uchar>(y, x) / img2.at<uchar>(y, x));
            } else {
                for (int c = 0; c < img1.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = img2.at<cv::Vec3b>(y, x)[c] == 0 ? 0 : cv::saturate_cast<uchar>(img1.at<cv::Vec3b>(y, x)[c] / img2.at<cv::Vec3b>(y, x)[c]);
                }
            }
        }
    }
    return resultado;
}

cv::Mat somaEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado = img.clone();
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            if (img.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img.at<uchar>(y, x) + valor);
            } else {
                for (int c = 0; c < img.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img.at<cv::Vec3b>(y, x)[c] + valor);
                }
            }
        }
    }
    return resultado;
}

cv::Mat subtraiEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado = img.clone();
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            if (img.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img.at<uchar>(y, x) - valor);
            } else {
                for (int c = 0; c < img.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img.at<cv::Vec3b>(y, x)[c] - valor);
                }
            }
        }
    }
    return resultado;
}

cv::Mat multiplicaEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado = img.clone();
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            if (img.channels() == 1) {
                resultado.at<uchar>(y, x) = cv::saturate_cast<uchar>(img.at<uchar>(y, x) * valor);
            } else {
                for (int c = 0; c < img.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(img.at<cv::Vec3b>(y, x)[c] * valor);
                }
            }
        }
    }
    return resultado;
}

cv::Mat divideEscalar(const cv::Mat& img, double valor) {
    cv::Mat resultado = img.clone();
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            if (img.channels() == 1) {
                resultado.at<uchar>(y, x) = valor == 0 ? 0 : cv::saturate_cast<uchar>(img.at<uchar>(y, x) / valor);
            } else {
                for (int c = 0; c < img.channels(); c++) {
                    resultado.at<cv::Vec3b>(y, x)[c] = valor == 0 ? 0 : cv::saturate_cast<uchar>(img.at<cv::Vec3b>(y, x)[c] / valor);
                }
            }
        }
    }
    return resultado;
}
