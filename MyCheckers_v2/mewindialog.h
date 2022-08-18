#ifndef MEWINDIALOG_H
#define MEWINDIALOG_H

#include <QDialog>

namespace Ui {
class MeWinDialog;
}

class MeWinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MeWinDialog(QWidget *parent = nullptr);
    ~MeWinDialog();

    Ui::MeWinDialog *ui;
};

#endif // MEWINDIALOG_H
