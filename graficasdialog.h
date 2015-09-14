#ifndef GRAFICASDIALOG_H
#define GRAFICASDIALOG_H

#include <QDialog>

#include "graphingscene.h"

namespace Ui {
class GraficasDialog;
}

class GraficasDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraficasDialog(QWidget *parent = 0);
    ~GraficasDialog();

    GraphingScene* gScene;

private slots:
    void on_graficarBtn_clicked();

private:
    Ui::GraficasDialog *ui;
};

#endif // GRAFICASDIALOG_H
