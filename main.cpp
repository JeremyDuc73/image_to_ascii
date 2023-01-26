#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // Initialiser la webcam
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "Erreur lors de l'initialisation de la webcam" << endl;
        return -1;
    }

    // Définir les caractères ASCII à utiliser
    string asciiChars = "@B%8WM#*oahkbdpwmZO0QlJUYxzcvnxrjft/\\|()1{}[]-_+~<>i!lI;:,";

    while (true)
    {
        Mat frame;
        cap >> frame; // Capturer une frame de la webcam

        // Réduire la taille de l'image à 3x3 pixels pour chaque caractère
        Mat smallFrame;
        cv::resize(frame, smallFrame, cv::Size(), 1.0 / 2, 1.0 / 6, INTER_NEAREST);

        // Convertir l'image en niveaux de gris
        Mat grayFrame;
        cvtColor(smallFrame, grayFrame, COLOR_BGR2GRAY);

        // Boucle sur chaque pixel de l'image réduite
        for (int y = 0; y < grayFrame.rows; y++)
        {
            for (int x = 0; x < grayFrame.cols; x++)
            {
                // Récupérer la luminosité du pixel (entre 0 et 255)
                int pixelValue = grayFrame.at<uchar>(y, x);

                // Calculer l'index du caractère ASCII correspondant (entre 0 et 19)
                int asciiIndex = (pixelValue * asciiChars.size()) / 256;

                // Afficher le caractère ASCII correspondant
                cout << asciiChars[asciiIndex];
            }
            cout << endl;
        }

        // Attendre une touche pour quitter
        if (waitKey(30) >= 0) break;
    }

    return 0;
}
