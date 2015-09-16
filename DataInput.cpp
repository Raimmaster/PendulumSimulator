#include "DataInput.h"
#include "ui_DataInput.h"

DataInput::DataInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataInput)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animar()));
    timer->start(100);
    int scale = 1;
    ui->qgvAnimacion->scale(scale*0.3, scale*.3);
}

DataInput::~DataInput()
{
    delete ui;
}

void DataInput::on_pushButton_clicked()
{
//    double longitud = ui->tLongitud->text().toDouble();
//    double amortiguamiento = ui->tAmortiguamiento->text().toDouble();
//    double N = ui->tFuerza->text().toDouble();
//    double frecuencia = ui->tFrecuencia->text().toDouble(); //de la fuerza impulsadora
//    double theta = ui->tTheta->text().toDouble(), omega = ui->tOmega->text().toDouble();
//    double a = ui->tInicio->text().toDouble(), b = ui->tFin->text().toDouble(), F = ui->tAmplitud->text().toDouble();

    double longitud = 2;
    double amortiguamiento = 0.14;
    double N = 1000;
    double frecuencia = 0.5; //de la fuerza impulsadora
    double theta = 34.38, omega = 0;
    double a = 0, b = 100, F = 0.6;

    Pendulo p;
    p.a = a;
    p.amortiguamiento = amortiguamiento;
    p.b = b;
    p.frecuencia = frecuencia;
    p.longitud = longitud;
    p.N = N;
    p.omega = omega;
    p.theta = p.deg2rad(theta);
    p.h = (b-a)/N;

    cout<<"Llego aki"<<endl;
    animacion = p.getData();
    cout<<"Llego aki"<<endl;

    QGraphicsScene *scene = new QGraphicsScene();
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    circulo = scene->addEllipse(0, 10, 100, 100, blackPen, redBrush);
    ui->qgvAnimacion->setScene(scene);
    x = 0;
}

void DataInput::animar(){
    if(x>=0 && x < animacion.x.size()){
        cout<<x<<" . "<< animacion.x.size()<<endl;
        circulo->setPos(animacion.x[x], animacion.y[x]);

        ui->xpos->setText("X:" + QString::number(animacion.x[x]));
        ui->ypos->setText("Y:" + QString::number(animacion.y[x]));
        x++;
    }
}
