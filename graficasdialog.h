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

    void on_skipSlider_valueChanged(int value);

    void on_gravityRadio_toggled(bool checked);

    void on_lengthRadio_toggled(bool checked);

    void on_freqRadio_toggled(bool checked);

    void on_periodRadio_toggled(bool checked);

private:
    Ui::GraficasDialog *ui;
};

#endif // GRAFICASDIALOG_H
