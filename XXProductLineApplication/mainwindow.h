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

class MainWindow : public QMainWindow, public IPLAsset
{
    Q_OBJECT

    friend ProductLineAPI;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionRun_API_triggered();

private:
    void buildProduct();
    void buildMenu();

    // API Functions
private:
    QJsonObject getFeature1(QJsonObject);

private:
    Ui::MainWindow *ui;
    ProductLineAPI productLineAPI;
    QMap<QString, IPLAsset*> productAssetMap{};

    // IPLAsset interface
public:
    void enableAsset(bool value) override{}
    APIFunctionMap getAPIFunctionMap() override;
};
#endif // MAINWINDOW_H
