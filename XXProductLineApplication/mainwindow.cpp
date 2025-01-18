#include "mainwindow.h"
#include "ui_mainwindow.h"


#ifdef UAsset1
#include <uniqueasset1.h>
#endif

#ifdef UAsset2
#include <uniqueasset2.h>
#endif

#ifdef UAsset3
#include <uniqueasset3.h>
#endif

#ifdef UAsset4
#include <uniqueasset4.h>
#endif

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
    productAssetMap.insert("feature3", new UniqueAsset3());
#endif

#ifdef UAsset4
    productAssetMap.insert("feature4", new UniqueAsset4());
#endif

    buildMenu();
}

void MainWindow::buildMenu()
{
    QMenu *menu = menuBar()->addMenu("Product Menu");

#ifdef Product_1
    QMenu *product1Menu = menu->addMenu("Product 1");
    product1Menu->addAction("Action 1 for Product 1", this, SLOT(onProduct1MenuActionTriggered()));
    product1Menu->addAction("Action 2 for Product 1", this, SLOT(onProduct1MenuActionTriggered()));
#endif

#ifdef Product_2
    QMenu *product2Menu = menu->addMenu("Product 2");
    product2Menu->addAction("Action 1 for Product 2", this, SLOT(onProduct2MenuActionTriggered()));
    product2Menu->addAction("Action 2 for Product 2", this, SLOT(onProduct2MenuActionTriggered()));
#endif

#ifdef Product_3
    QMenu *product3Menu = menu->addMenu("Product 3");
    product3Menu->addAction("Action 1 for Product 3", this, SLOT(onProduct3MenuActionTriggered()));
    product3Menu->addAction("Action 2 for Product 3", this, SLOT(onProduct3MenuActionTriggered()));
#endif

#ifdef Product_4
    QMenu *product4Menu = menu->addMenu("Product 4");
    product4Menu->addAction("Action 1 for Product 4", this, SLOT(onProduct4MenuActionTriggered()));
    product4Menu->addAction("Action 2 for Product 4", this, SLOT(onProduct4MenuActionTriggered()));
#endif

#ifdef Product_5
    QMenu *product5Menu = menu->addMenu("Product 5");
    product5Menu->addAction("Action 1 for Product 5", this, SLOT(onProduct5MenuActionTriggered()));
    product5Menu->addAction("Action 2 for Product 5", this, SLOT(onProduct5MenuActionTriggered()));
#endif
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

void MainWindow::onProduct1MenuActionTriggered()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString actionText = action->text();
        qDebug() << "Triggered action for Product 1: " << actionText;
        // You can now use the actionText as needed
    }
}

void MainWindow::onProduct2MenuActionTriggered()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString actionText = action->text();
        qDebug() << "Triggered action for Product 1: " << actionText;
        // You can now use the actionText as needed
    }
}

void MainWindow::onProduct3MenuActionTriggered()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString actionText = action->text();
        qDebug() << "Triggered action for Product 1: " << actionText;
        // You can now use the actionText as needed
    }
}

void MainWindow::onProduct4MenuActionTriggered()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString actionText = action->text();
        qDebug() << "Triggered action for Product 1: " << actionText;
        // You can now use the actionText as needed
    }
}

void MainWindow::onProduct5MenuActionTriggered()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
    {
        QString actionText = action->text();
        qDebug() << "Triggered action for Product 1: " << actionText;
        // You can now use the actionText as needed
    }
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

