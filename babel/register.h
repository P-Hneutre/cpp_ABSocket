#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:
    void on_cancel_clicked();
    void on_register_2_clicked();

private:
    Ui::Register *ui;
    void createAccount(const char *_pseudo, const char *_pass);
    void failPwdConfirmation();
    void incompleteForm();

};

#endif // REGISTER_H
