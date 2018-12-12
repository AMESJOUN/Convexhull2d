#include "convexhullmanager.h"
#include "ui_convexhullmanager.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>

#include <ctime>

#include "utils/fileutils.h"
#include <cg3/utilities/timer.h>


//----------------------------------------------------------------------------------------------
//                         You have to write your code in the area below.
//----------------------------------------------------------------------------------------------

/* ----- Constructors/Destructors ----- */

/**
 * @brief Default constructor of the manager
 */
ConvexHullManager::ConvexHullManager(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ConvexHullManager),
    mainWindow(static_cast<cg3::viewer::MainWindow&>(*parent))
{
    //***** NOTE: you probably need to initialize your objects in the constructor *****

    //UI setup
    ui->setupUi(this);

    //Setting options for the canvas
    mainWindow.canvas.set2DMode();

    //This updates the canvas (call it whenever you change or
    //add some drawable object)
    mainWindow.canvas.updateGL();
    fitScene();
}


/**
 * @brief Destructor of the manager
 */
ConvexHullManager::~ConvexHullManager() {
    //Try to avoid using dynamic objects whenever it is possible.
    //
    //In case you allocated dynamic objects in this manager, you
    //should delete (deallocate) all of them when the application
    //closes.
    //Remember that each class which allocates dynamic objects
    //should implement a destructor which deallocates them.    
    //
    //Example:
    //      delete dynamicObject;
    //      dynamicObject = nullptr;
    /*****************************************/

    /*****************************************/

    //When the manager is destroyed, the mainWindow should
    //not have any reference to drawable objects.
    //
    //Example:
    //      mainWindow.deleteObj(&convexHullDrawableObject);
    //  or
    //      mainWindow.deleteObj(pointerToConvexHullDrawableObject);
    //
    //Try to avoid using dynamic objects whenever it is possible.
    /*****************************************/

    /*****************************************/

    delete ui; //Delete interface
}



/* ----- Private main methods ----- */

/**
 * @brief Computer the convex hull for a set of points
 * @param[in] points Vector of points
 */
void ConvexHullManager::computeConvexHull(const std::vector<cg3::Point2Dd>& inputPoints) {
    //Launch your convex hull algorithm here on the vector "inputPoints" in input
    //(note that the vector could contain duplicates).
    //Here you should call an algorithm (obviously defined in another file!) which
    //fills your output Convex hull data structure.
    /*****************************************/

    /*****************************************/

    //You should delete the following line after you implement the algorithm: it is
    //just needed to suppress the unused-variable warning
    CG3_SUPPRESS_WARNING(inputPoints);
}

/**
 * @brief Clear data of the convex hull
 */
void ConvexHullManager::clearConvexHull() {
    //Clear here your convex hull data structures.
    /*****************************************/

    /*****************************************/
}



/**
 * @brief Draw the convex hull in the canvas
 */
void ConvexHullManager::drawConvexHull() {
    //Draw your convex hull in the canvas here
    /*****************************************/

    /*****************************************/

    //Canvas update
    mainWindow.canvas.updateGL();
}

/**
 * @brief Hide convex hull from the canvas
 */
void ConvexHullManager::hideConvexHull() {
    //Remove the convex hull object from the canvas (mainWindow.deleteObj() which
    //takes a reference). Deallocate it if you allocated it dynamically, even if you
    //should try to avoid using dynamic objects whenever it is possible.
    /*****************************************/

    /*****************************************/

    //Canvas update
    mainWindow.canvas.updateGL();
}



//Define (if you need some) your private methods here
/*****************************************/


/*****************************************/




//----------------------------------------------------------------------------------------------
//              You will probably not need to write/edit code in the area below.
//----------------------------------------------------------------------------------------------


/* ----- Private utility methods ----- */

/**
 * @brief Launch the algorithm for computing the convex hull
 * on the input points (a vector) of this manager and measure
 * its time efficiency.
 */
void ConvexHullManager::launchAlgorithmAndMeasureTime(const std::vector<cg3::Point2Dd>& points) { //Do not write code here
    //Output message
    std::cout << "Executing the algorithm for " << points.size() << " points..." << std::endl;

    //Timer for evaluating the efficiency of the algorithm
    cg3::Timer t("Convex hull algorithm");

    //Launch fortune algorithm on the vector of input points
    computeConvexHull(points);

    //Timer stop and visualization (both on console and UI)
    t.stopAndPrint();
    ui->timeLabel->setNum(t.delay());

    std::cout << std::endl;
}

/**
 * @brief Change camera of the canvas to fit the scene
 * on the bounding box in which the points can be added.
 */
void ConvexHullManager::fitScene() { //Do not write code here
    mainWindow.canvas.fitScene();
}




/* ----- UI slots for loading points ----- */

/**
 * @brief Load points event handler.
 *
 * Load input points from a file.
 */
void ConvexHullManager::on_loadPointsButton_clicked() { //Do not write code here
    //File selector
    QString filename = QFileDialog::getOpenFileName(nullptr,
                       "Open points",
                       ".",
                       "*.txt");

    if (!filename.isEmpty()) {
        //Clear current data
        clearConvexHull();

        //Delete from the canvas the convex hull
        hideConvexHull();

        //Load input points in the vector (deleting the previous ones)
        std::vector<cg3::Point2Dd> points = FileUtils::getPointsFromFile(filename.toStdString());

        //Launch the algorithm on the current vector of points and measure
        //its efficiency with a timer
        launchAlgorithmAndMeasureTime(points);

        //Draw convex hull
        drawConvexHull();
    }
}

/**
 * @brief Clear points button event handler.
 *
 * It allows us to clear our convex hull.
 */
void ConvexHullManager::on_clearConvexHullButton_clicked() { //Do not write code here
    //Clear current data
    clearConvexHull();

    //Delete from the canvas the convex hull
    hideConvexHull();

    //Clear timer data
    ui->timeLabel->setText("");
}




/* ----- UI slots for utilities ----- */


/**
 * @brief Reset scene event handler.
 *
 * It allows us to reset the camera of the canvas to
 * show/center the scene in the bounding box.
 */
void ConvexHullManager::on_resetSceneButton_clicked() { //Do not write code here
    fitScene();
}



/**
 * @brief Generate random points handler.
 *
 * With this button we can generate files that contains
 * points which are inside the bounding box.
 */
void ConvexHullManager::on_generatePointsFileButton_clicked() { //Do not write code here
    QString selectedFilter;
    QString filename = QFileDialog::getSaveFileName(nullptr,
                       "File containing points",
                       ".",
                       "TXT(*.txt)", &selectedFilter);

    if (!filename.isEmpty()){
        int number = QInputDialog::getInt(
                    this,
                    tr("Generate file"),
                    tr("Number of random points:"), 1000, 0, 1000000000, 1000);

        //Generate points and save them in the chosen file
        FileUtils::generateRandomPointFile(filename.toStdString(), 1000000000, number);
    }
}
