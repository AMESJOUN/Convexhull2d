#include <cg3/viewer/mainwindow.h>

#include "managers/convexhullmanager.h"

int main(int argc, char *argv[]) {
    CG3_SUPPRESS_WARNING(argc);
    CG3_SUPPRESS_WARNING(argv);

    QApplication app(argc, argv);

    //Main window, it contains QGLViewer canvas
    cg3::viewer::MainWindow gui;

    //Voronoi manager initialization
    ConvexHullManager cm(&gui);
    gui.addManager(&cm, "Convex hull Manager");

    //Show the GUI    
    gui.show();

    return app.exec();
}
