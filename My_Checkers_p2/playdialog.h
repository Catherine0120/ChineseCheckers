#ifndef PLAYDIALOG_H
#define PLAYDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class PlayDialog;
}

class PlayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlayDialog(QMainWindow *parent = nullptr);
    ~PlayDialog();

private slots:
    void on_yesButton_clicked();

signals:
    void start_new_game();

private:
    Ui::PlayDialog *ui;
};

#endif // PLAYDIALOG_H
