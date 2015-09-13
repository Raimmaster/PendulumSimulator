#include "graficasdialog.h"
#include "ui_graficasdialog.h"

GraficasDialog::GraficasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraficasDialog)
{
    ui->setupUi(this);
}

GraficasDialog::~GraficasDialog()
{
    delete ui;
}
