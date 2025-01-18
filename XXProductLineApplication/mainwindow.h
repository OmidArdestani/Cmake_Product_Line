#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sharedassets.h>
#include "ProductLineAPI/productlineapi.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend ProductLineAPI;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionRun_API_triggered();

private:
    void buildPtoduct();
    void buildMenu();

private:
    Ui::MainWindow *ui;

    ProductLineAPI productLineAPI;

    QMap<QString, IPLAsset *> productAssetMap{};
};
#endif // MAINWINDOW_H
