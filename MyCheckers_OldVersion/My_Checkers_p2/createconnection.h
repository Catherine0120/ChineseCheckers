#ifndef CREATECONNECTION_H
#define CREATECONNECTION_H

#include <QDialog>

namespace Ui {
class createconnection;
}

class createconnection : public QDialog
{
    Q_OBJECT

public:
    explicit createconnection(QWidget *parent = nullptr);
    ~createconnection();

private:
    Ui::createconnection *ui;
};

#endif // CREATECONNECTION_H
