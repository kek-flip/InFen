#include <QCoreApplication>
#include <QTextStream>
#include <QImage>
#include <QString>
#include <QList>
#include <vector>

#include "imgparse.h"

using namespace Qt;

int main() {
    QTextStream in(stdin);
    QTextStream out(stdout);

    QString imgName;
    out << "Input full image name: " << endl;
    imgName = in.readLine();

    QImage img(imgName);
    if (img.isNull()) {
        out << "Cannot open image" << endl;
        return -1;
    }

    img = normalizeImage(img);
    if (img.isNull()) {
        out << "Cannot normalize image" << endl;
        return -1;
    }

    QList<QImage> cells = imgParse(img);
    if (cells.isEmpty()) {
        out << "Cannot parse image" << endl;
        return -1;
    }

    std::vector<std::vector<int>> objects = imgsToObjects(cells);
}
