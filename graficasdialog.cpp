#include "graficasdialog.h"
#include "ui_graficasdialog.h"

#include <QGraphicsView>
#include <QValidator>
#include <QtGui>
#include <QDebug>

#include <sstream>

using std::stringstream;
using std::string;

GraficasDialog::GraficasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraficasDialog)
{
    ui->setupUi(this);

    setWindowTitle("Graficador -- Frecuencia Angular");

    ui->puntoIniLE->setValidator(new QDoubleValidator(-100, 100, 1 ));
    ui->puntoFinLE->setValidator(new QDoubleValidator(-100, 100, 1 ));
    ui->const1LE->setValidator(new QDoubleValidator(-100, 100, 1 ));
    ui->const2LE->setValidator(new QDoubleValidator(-100, 100, 1 ));
    ui->const3LE->setValidator(new QDoubleValidator(-100, 100, 1 ));

    for (int i = 0; i < 4; i++) housed[i] = i;

    QGraphicsView* gView = ui->graphicsView;

    ui->skipSlider->setMinimum(1);
    ui->skipSlider->setValue(1);

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
    float puntoInicial = 1,
              puntoFinal = 1,
              skip = 1;

    if( ui->puntoIniLE->text().length())
    {
        puntoInicial = ui->puntoIniLE->text().toFloat();
    }

    if( ui->puntoFinLE->text().length())
    {
         puntoFinal = ui->puntoFinLE->text().toFloat();
    }

    if(puntoInicial == puntoFinal ||
            !ui->skipSlider->value()) return;

    if( ui->skipSlider->value() <= puntoFinal - puntoInicial)
        skip = ui->skipSlider->value();

    QString lbls[2][3];

    lbls[0][0] = ui->const1Lbl->text();
    lbls[1][0] = ui->const1LE->text();
    lbls[0][1] = ui->const2Lbl->text();
    lbls[1][1] = ui->const2LE->text();
    lbls[0][2] = ui->const3Lbl->text();
    lbls[1][2] = ui->const3LE->text();

    if( ui->lengthRadio->isChecked() )
    {
        float gravity = 1,
                   freq = 1,
                    period = 1;

        for(int i = 0; i < 3; i++)
        {
            if(lbls[0][i] == "Gravedad") gravity = lbls[1][i].toFloat();
            if(lbls[0][i] == "Frecuencia") freq = lbls[1][i].toFloat();
            if(lbls[0][i] == "Periodo") period = lbls[1][i].toFloat();
        }

        gScene->graphAngularFreqForLength(puntoInicial, puntoFinal, skip, gravity, freq);
    }

    else if( ui->freqRadio->isChecked() )
    {
        float gravity = 1,
                   length = 1,
                    period = 1;

        for(int i = 0; i < 3; i++)
        {
            if(lbls[0][i] == "Gravedad") gravity = lbls[1][i].toFloat();
            if(lbls[0][i] == "Longitud") length = lbls[1][i].toFloat();
            if(lbls[0][i] == "Periodo") period = lbls[1][i].toFloat();
        }

        gScene->graphAngularFreqForFreq(puntoInicial, puntoFinal, skip, length, gravity);
    }

    else if( ui->periodRadio->isChecked() )
    {
        float gravity = 1,
                   freq = 1,
                    length = 1;

        for(int i = 0; i < 3; i++)
        {
            if(lbls[0][i] == "Gravedad") gravity = lbls[1][i].toFloat();
            if(lbls[0][i] == "Frecuencia") freq = lbls[1][i].toFloat();
            if(lbls[0][i] == "Longitud") length = lbls[1][i].toFloat();
        }

        gScene->graphAngularFreqForPeriod(puntoInicial, puntoFinal, skip, length, gravity);
    }

    else
    {
        float length = 1,
                   freq = 1,
                    period = 1;

        for(int i = 0; i < 3; i++)
        {
            if(lbls[0][i] == "Longitud") length = lbls[1][i].toFloat();
            if(lbls[0][i] == "Frecuencia") freq = lbls[1][i].toFloat();
            if(lbls[0][i] == "Periodo") period = lbls[1][i].toFloat();
        }

        gScene->graphAngularFreqForGravity(puntoInicial, puntoFinal, skip, length, freq);
    }

}

void GraficasDialog::on_skipSlider_valueChanged(int value)
{
    stringstream strm("");
    string str("");
    strm << value;
    strm >> str;

    ui->slideValLbl->setText(QString(str.c_str()));
}

void GraficasDialog::on_gravityRadio_toggled(bool checked)
{
    if(checked)
    {
        houseLbl(1);
        ui->varControlGB->setTitle("Gravedad");
        lastChecked = 1;
    }
}

void GraficasDialog::on_lengthRadio_toggled(bool checked)
{
    if(checked)
    {
        houseLbl(0);
        ui->varControlGB->setTitle("Longitud");
        lastChecked = 0;
    }
}

void GraficasDialog::on_freqRadio_toggled(bool checked)
{
    if(checked)
    {
         houseLbl(2);
        ui->varControlGB->setTitle("Frecuencia");
        lastChecked = 2;
    }
}

void GraficasDialog::on_periodRadio_toggled(bool checked)
{
    if(checked)
    {
         houseLbl(3);
        ui->varControlGB->setTitle("Periodo");
         lastChecked = 3;
    }
}

void GraficasDialog::houseLbl(int indx)
{
    if(housed[indx] == 1)
    {
        ui->const1Lbl->setText(ui->varControlGB->title());
        housed[lastChecked] = 1;
    }
    else if(housed[indx] == 2)
    {
         ui->const2Lbl->setText(ui->varControlGB->title());
        housed[lastChecked] = 2;
    }
   else if(housed[indx] == 3)
    {
         ui->const3Lbl->setText(ui->varControlGB->title());
        housed[lastChecked] = 3;
    }
}
