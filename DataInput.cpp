#include "DataInput.h"
#include "ui_DataInput.h"

DataInput::DataInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataInput)
{
    ui->setupUi(this);
}

DataInput::~DataInput()
{
    delete ui;
}

void DataInput::on_pushButton_clicked()
{
    forza fuerza_alterna;
    double longitud = ui->tLongitud->text().toDouble();
    double amortiguamiento = ui->tAmortiguamiento->text().toDouble();
    double N = ui->tFuerza->text().toDouble();
    double frecuencia = ui->tFrecuencia->text().toDouble(); //de la fuerza impulsadora
    double theta = ui->tTheta->text().toDouble(), omega = ui->tOmega->text().toDouble();
    double a = ui->tInicio->text().toDouble(), b = ui->tFin->text().toDouble(), F = ui->tAmplitud->text().toDouble();


}
