#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H

#include <QDialog>
#include <QValidator>

namespace Ui {
class connectserver;
}

class connectserver : public QDialog
{
    Q_OBJECT

public:
    explicit connectserver(QWidget *parent = nullptr);
    ~connectserver();

    void setValidator(const QRegularExpression &re);


private:
    Ui::connectserver *ui;
    QRegularExpressionValidator * Validator;

    const QRegularExpression IP = QRegularExpression("[0-9]{3}.[0-9]{3}.[0-9]{3}.[0-9]{3}");
};

#endif // CONNECTSERVER_H
