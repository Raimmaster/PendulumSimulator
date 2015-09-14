#include "graficasdialog.h"
#include "ui_graficasdialog.h"

#include <QGraphicsView>

GraficasDialog::GraficasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraficasDialog)
{
    ui->setupUi(this);

    QGraphicsView* gView = ui->graphicsView;

    int dif = 0;
    gScene = new  GraphingScene(gView, 0, 0, gView->width() - dif, gView->height() - dif);
    gView->setScene(gScene);
}

GraficasDialog::~GraficasDialog()
{
    delete ui;
}
