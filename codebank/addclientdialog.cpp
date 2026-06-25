#include "addclientdialog.h"
#include "ui_addclientdialog.h"
#include <QMessageBox>

AddClientDialog::AddClientDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddClientDialog) {
    ui->setupUi(this);
    setWindowTitle("Добавить нового клиента");
    ui->line_phone->setInputMask("+7 (999) 999-99-99");
    ui->line_passport->setInputMask("9999 999999");
}

AddClientDialog::~AddClientDialog() {
    delete ui;
}

QString AddClientDialog::getFio() const {
    return ui->line_fio->text();
}

QString AddClientDialog::getPassport() const {
    return ui->line_passport->text();
}

QString AddClientDialog::getPhone() const {
    return ui->line_phone->text();
}

void AddClientDialog::on_btn_ok_clicked() {
    if (ui->line_fio->text().isEmpty()) {
        QMessageBox::warning(this, "Внимание", "Поле ФИО не может быть пустым!");
        return;
    }
    accept();
}

void AddClientDialog::on_btn_cancel_clicked() {
    reject();
}