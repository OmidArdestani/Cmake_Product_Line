#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <uniqueasset1.h>
#include <uniqueasset2.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , productLineAPI(this)
{
    ui->setupUi(this);

    buildProduct();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buildProduct()
{
#ifdef UAsset1
    productAssetMap.insert("feature1", new UniqueAsset1());
#endif

#ifdef UAsset2
    productAssetMap.insert("feature2", new UniqueAsset2());
#endif

#ifdef UAsset3

#endif

#ifdef UAsset4

#endif

    buildMenu();
}

void MainWindow::buildMenu()
{

}

QJsonObject MainWindow::getFeature1(QJsonObject)
{
    auto feature = productAssetMap.value("feature1");
    if(feature)
    {
        quint64 instanceId = reinterpret_cast<quintptr>(feature);
        productLineAPI.insertInstance(instanceId, feature);
        return QJsonObject{
            {"instanceId", QString::number(instanceId)},
            {"error", ""}
        };
    }

    return QJsonObject{
        {"error", "This feature is not exist!"}
    };
}

APIFunctionMap MainWindow::getAPIFunctionMap()
{
    APIFunctionMap apiFunctionMap;

    apiFunctionMap.insert("getFeature1", BIND_API_FUNC(&MainWindow::getFeature1));


    return apiFunctionMap;
}

void MainWindow::on_actionRun_API_triggered()
{
    if(ui->actionRun_API->text().toLower() == "run")
    {
        productLineAPI.start();
        ui->actionRun_API->setText("Stop");
    }
    else
    {
        productLineAPI.stop();
        ui->actionRun_API->setText("Run");
    }
}

