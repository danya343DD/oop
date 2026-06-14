#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>
#include <QTextStream>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnOpen_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите текстовый файл", "", "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    QFileInfo fileInfo(fileName);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для чтения");
        return;
    }

    QString info;
    info += "Путь к файлу: " + fileInfo.absoluteFilePath() + "\n";
    info += "Дата создания: " + fileInfo.birthTime().toString("dd.MM.yyyy hh:mm:ss") + "\n";
    info += "Размер: " + QString::number(fileInfo.size()) + " байт\n";

    info += "Только для чтения: " + QString(fileInfo.isWritable() ? "Нет" : "Да") + "\n";

    info += "Скрытый файл: " + QString(fileInfo.isHidden() ? "Да" : "Нет");

    ui->labelInfo->setText(info);
}