#include "histograma.hpp"
#include <opencv2/opencv.hpp>
#include <vector>

std::vector<int> calcularHistogramaGrayscale(const cv::Mat& imagem) {
    std::vector<int> histograma(256, 0);
    for (int y = 0; y < imagem.rows; y++) {
        for (int x = 0; x < imagem.cols; x++) {
            int valor = imagem.at<uchar>(y, x);
            histograma[valor]++;
        }
    }
    return histograma;
}

std::vector<std::vector<int>> calcularHistogramaColorido(const cv::Mat& imagem) {
    std::vector<std::vector<int>> histograma(3, std::vector<int>(256, 0));
    for (int y = 0; y < imagem.rows; y++) {
        for (int x = 0; x < imagem.cols; x++) {
            cv::Vec3b pixel = imagem.at<cv::Vec3b>(y, x);
            for (int c = 0; c < 3; c++) {
                histograma[c][pixel[c]]++;
            }
        }
    }
    return histograma;
}

cv::Mat visualizarHistogramaGrayscale(const std::vector<int>& histograma) {
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double) hist_w / 256);
    cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(255,255,255));
    int max = *std::max_element(histograma.begin(), histograma.end());
    std::vector<int> norm_hist(256);
    for (int i = 0; i < 256; i++) {
        norm_hist[i] = cvRound(((double)histograma[i] / max) * hist_h);
    }
    for (int i = 0; i < 256; i++) {
        cv::rectangle(histImage, cv::Point(i*bin_w, hist_h), cv::Point((i+1)*bin_w, hist_h - norm_hist[i]), cv::Scalar(0,0,0), -1);
    }
    return histImage;
}

cv::Mat visualizarHistogramaColorido(const std::vector<std::vector<int>>& histograma) {
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double) hist_w / 256);
    cv::Mat histImage(hist_h, hist_w, CV_8UC3, cv::Scalar(255,255,255));
    std::vector<int> max(3);
    for (int c = 0; c < 3; c++) {
        max[c] = *std::max_element(histograma[c].begin(), histograma[c].end());
    }
    std::vector<std::vector<int>> norm_hist(3, std::vector<int>(256));
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 256; i++) {
            norm_hist[c][i] = cvRound(((double)histograma[c][i] / max[c]) * hist_h);
        }
    }
    cv::Scalar cores[3] = {cv::Scalar(255,0,0), cv::Scalar(0,255,0), cv::Scalar(0,0,255)};
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < 256; i++) {
            cv::rectangle(histImage, cv::Point(i*bin_w, hist_h), cv::Point((i+1)*bin_w, hist_h - norm_hist[c][i]), cores[c], -1);
        }
    }
    return histImage;
}
