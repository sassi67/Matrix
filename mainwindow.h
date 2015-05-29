#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QVBoxLayout;
class QPushButton;
class MatrixDialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow  *ui;
    QVBoxLayout     *lay_;
    QPushButton     *btnInt_;
    QPushButton     *btnDouble_;
    QPushButton     *btnString_;
    QPushButton     *btnScientific_;

    void openAndPrint(MatrixDialog *dlg);

private slots:
    void onBtnIntClicked();
    void onBtnDoubleClicked();
    void onBtnStringClicked();
    void onBtnScientificClicked();
};

#endif // MAINWINDOW_H
