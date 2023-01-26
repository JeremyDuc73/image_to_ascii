------------------------------
DOC POUR L'ASCII VIDEO C++
------------------------------
AVANT : 
-> sudo apt install git (si pas déjà fait)
-> télécharger CLion
ETAPE 1 : installer OpenCV C++
-> sudo apt install -y g++ cmake make git libgtk2.0-dev pkg-config
-> git clone https://github.com/opencv/opencv.git
-> mkdir -p build && cd build
-> cmake ../opencv
-> make -j4
-> sudo make install
ETAPE 2 : git mon projet
-> se mettre dans le dossier CLionProjects
-> git clone https://github.com/JeremyDuc73/image_to_ascii.git
ETAPE 3 : tester le programme
-> cd image_to_ascii
-> cmake .
-> make
-> ./image_to_ascii
=> cela doit générer dans le terminal la vidéo en ascii en direct (dézoomer)
