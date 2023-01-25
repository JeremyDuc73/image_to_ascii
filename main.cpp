#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Ouvrir la webcam
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Problème avec la webcam" << endl;
        return -1;
    }

    // Définir les caractères ASCII pour les différents niveaux de gris
    char asciiChars[] = {'#', 'A', '@', '%', 'S', '+', '<', '*', ':', '.'};

    while (true) {
        // Capturer une image de la webcam
        Mat image;
        cap >> image;

        // Convertir l'image en niveaux de gris
        cvtColor(image, image, COLOR_BGR2GRAY);

        int height = image.rows, width = image.cols;

        // Boucler sur chaque groupe de pixels
        for (int i = 0; i < height-2; i += 6) {
            for (int j = 0; j < width-2; j += 2) {
                // Récupérer le sous-rectangle de l'image pour le groupe de pixels en cours
                Rect rect(j, i, 3, 3);
                Mat group = image(rect);

                // Calculer la moyenne des valeurs de gris pour le groupe de pixels
                Scalar mean, stddev;
                meanStdDev(group, mean, stddev);

                // Utiliser la moyenne pour déterminer le caractère ASCII correspondant
                int meanValue = (int)mean.val[0];
                int index = meanValue / 25;
                cout << asciiChars[index];
            }
            cout << endl;
        }

        // Afficher l'image en ASCII
        cout << endl;

        // Attendre pour le prochain cadre
        waitKey(60);
    }

    return 0;
}