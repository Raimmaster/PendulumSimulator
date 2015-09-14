#include "graficasdialog.h"
#include "ui_graficasdialog.h"

#include <QGraphicsView>
#include <QValidator>
#include <QtGui>
#include <QDebug>

GraficasDialog::GraficasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraficasDialog)
{
    ui->setupUi(this);

    ui->puntoIniLE->setValidator(new QDoubleValidator(-100, 100, 1 ));
    ui->puntoFinLE->setValidator(new QDoubleValidator(-100, 100, 1 ));

    QGraphicsView* gView = ui->graphicsView;

    int dif = 0; // Un pequeno offset
    gScene = new  GraphingScene(gView, 0, 0, gView->width() - dif, gView->height() - dif);
    gView->setScene(gScene);
}

GraficasDialog::~GraficasDialog()
{
    delete ui;
}

void GraficasDialog::on_graficarBtn_clicked()
{
    // Default params
    float puntoInicial = 0,
              puntoFinal = 0,
              skip = 0;

    if( ui->puntoIniLE->text().length())
    {
        puntoInicial = ui->puntoIniLE->text().toFloat();
    }

    if( ui->puntoFinLE->text().length())
    {
         puntoFinal = ui->puntoFinLE->text().toFloat();
    }

    if( ui->skipSlider->value() <= puntoFinal - puntoInicial)
        skip = ui->skipSlider->value();

    if( ui->lengthRadio->isChecked() )
    {
        gScene->graphAngularFreqForLength(puntoInicial, puntoFinal, skip, 0, 0);
    }

    else if( ui->freqRadio->isChecked() )
    {
        gScene->graphAngularFreqForFreq(puntoInicial, puntoFinal, skip, 0, 0);
    }

    else if( ui->periodRadio->isChecked() )
    {
        gScene->graphAngularFreqForPeriod(puntoInicial, puntoFinal, skip, 0, 0);
    }

    else
    {
        gScene->graphAngularFreqForGravity(puntoInicial, puntoFinal, skip, 0, 0);
    }

       qDebug() << puntoInicial << "\n";
       qDebug() << puntoFinal << "\n";
       qDebug() <<  skip << "\n";
}
