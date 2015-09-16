#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <QDialog>
#include "Pendulo.h"

namespace Ui {
class DataInput;
}

class DataInput : public QDialog
{
    Q_OBJECT

public:
    explicit DataInput(QWidget *parent = 0);
    ~DataInput();

private slots:

    void on_pushButton_clicked();

private:
    Ui::DataInput *ui;
};

#endif // DATAINPUT_H
