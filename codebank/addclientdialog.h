#ifndef ADDCLIENTDIALOG_H
#define ADDCLIENTDIALOG_H

#include <QDialog>

namespace Ui { class AddClientDialog; }

class AddClientDialog : public QDialog {
    Q_OBJECT
public:
    explicit AddClientDialog(QWidget *parent = nullptr);
    ~AddClientDialog();

    QString getFio() const;
    QString getPassport() const;
    QString getPhone() const;

private slots:
    void on_btn_ok_clicked();
    void on_btn_cancel_clicked();

private:
    Ui::AddClientDialog *ui;
};

#endif