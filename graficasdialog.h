#ifndef GRAFICASDIALOG_H
#define GRAFICASDIALOG_H

#include <QDialog>

namespace Ui {
class GraficasDialog;
}

class GraficasDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GraficasDialog(QWidget *parent = 0);
    ~GraficasDialog();

private:
    Ui::GraficasDialog *ui;
};

#endif // GRAFICASDIALOG_H
