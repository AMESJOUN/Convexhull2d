#ifndef CONVEXHULLMANAGER_H
#define CONVEXHULLMANAGER_H

#include <QFrame>

#include <cg3/viewer/mainwindow.h>

namespace Ui {
    class ConvexHullManager;
}

class ConvexHullManager : public QFrame {
    Q_OBJECT

public:

    /* ----- Constructors/destructors ----- */

    explicit ConvexHullManager(QWidget *parent = nullptr);
    ~ConvexHullManager();


private:

    /* ----- Private fields ----- */

    //UI fields
    Ui::ConvexHullManager *ui;
    cg3::viewer::MainWindow& mainWindow;


    //Declare your attributes here (hint: data structures to save the convex hull)
    /*****************************************/


    /*****************************************/



    /* ----- Private main methods ----- */

    void computeConvexHull(const std::vector<cg3::Point2Dd>& points);
    void clearConvexHull();

    void drawConvexHull();
    void hideConvexHull();


    //Declare (if you need some) your private methods here
    /*****************************************/


    /*****************************************/



    /* ----- Private utility methods ----- */

    void launchAlgorithmAndMeasureTime(const std::vector<cg3::Point2Dd>& points);

    void fitScene();



private slots:

    /* ----- UI slots for loading points ----- */

    void on_loadPointsButton_clicked();
    void on_clearConvexHullButton_clicked();


    /* ----- UI slots for utilities ----- */

    void on_resetSceneButton_clicked();
    void on_generatePointsFileButton_clicked();
};

#endif // CONVEXHULLMANAGER_H
