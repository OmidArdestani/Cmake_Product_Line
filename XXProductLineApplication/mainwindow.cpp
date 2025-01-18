#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , productLineAPI(this)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buildPtoduct()
{


    buildMenu();
}

void MainWindow::buildMenu()
{

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

