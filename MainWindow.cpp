#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DataInput.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bDataInput_clicked()
{
    DataInput di;
    di.setModal(true);
    di.exec();
}
