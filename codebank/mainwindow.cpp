#include <QInputDialog>
#include <QSqlQuery>
#include <cmath>
#include "addclientdialog.h"
#include <QSqlRecord>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QHeaderView> // Нужна для растягивания столбцов

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sessionTime = QTime(0, 0, 0);

    sessionLabel = new QLabel("Время сессии: 00:00:00", this);

    ui->statusbar->addWidget(sessionLabel);

    sessionTimer = new QTimer(this);
    connect(sessionTimer, &QTimer::timeout, this, &MainWindow::updateSessionTime);

    sessionTimer->start(1000);

    dbManager = new DBManager();

    if (dbManager->connectDB()) {
        dbManager->createTables();
    } else {
        QMessageBox::critical(this, "Критическая ошибка", "Не удалось запустить базу данных проекта!");
        return;
    }

    // Создаем модель и привязываем её к нашей базе данных
    clientModel = new QSqlTableModel(this);
    clientModel->setTable("Clients"); // Указываем имя таблицы из БД
    clientModel->select();            // Выбираем (загружаем) все данные

    // Делаем красивые заголовки для столбцов вместо системных ID, fio и т.д.
    clientModel->setHeaderData(1, Qt::Horizontal, "ФИО Клиента");
    clientModel->setHeaderData(2, Qt::Horizontal, "Паспортные данные");
    clientModel->setHeaderData(3, Qt::Horizontal, "Номер телефона");

    // Передаем эту модель в наш TableView, который мы нарисовали в интерфейсе
    ui->table_clients->setModel(clientModel);

    // Скрываем столбец с ID (индекс 0), пользователю банка его видеть необязательно
    ui->table_clients->setColumnHidden(0, true);

    // Заставляем столбцы автоматически растягиваться по всей ширине таблицы
    ui->table_clients->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    creditModel = new QSqlTableModel(this);
    creditModel->setTable("Credits");
    creditModel->select();

    creditModel->setHeaderData(1, Qt::Horizontal, "ID Клиента");
    creditModel->setHeaderData(2, Qt::Horizontal, "Сумма");
    creditModel->setHeaderData(3, Qt::Horizontal, "Месяцы");
    creditModel->setHeaderData(4, Qt::Horizontal, "Платеж");

    ui->table_credits->setModel(creditModel);
    ui->table_credits->setColumnHidden(0, true);
    ui->table_credits->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    depositModel = new QSqlTableModel(this);
    depositModel->setTable("Deposits");
    depositModel->select();

    depositModel->setHeaderData(1, Qt::Horizontal, "ID Клиента");
    depositModel->setHeaderData(2, Qt::Horizontal, "Сумма");
    depositModel->setHeaderData(3, Qt::Horizontal, "Месяцы");
    depositModel->setHeaderData(4, Qt::Horizontal, "Доход");

    ui->table_deposits->setModel(depositModel);
    ui->table_deposits->setColumnHidden(0, true);
    ui->table_deposits->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_clients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_clients->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->table_credits->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_credits->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->table_deposits->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_deposits->setSelectionBehavior(QAbstractItemView::SelectRows);
    mortgageModel = new QSqlTableModel(this);
    mortgageModel->setTable("Mortgages");
    mortgageModel->select();

    mortgageModel->setHeaderData(1, Qt::Horizontal, "ID Клиента");
    mortgageModel->setHeaderData(2, Qt::Horizontal, "Цена жилья");
    mortgageModel->setHeaderData(3, Qt::Horizontal, "Взнос");
    mortgageModel->setHeaderData(4, Qt::Horizontal, "Месяцы");
    mortgageModel->setHeaderData(5, Qt::Horizontal, "Платеж");

    ui->table_mortgages->setModel(mortgageModel);
    ui->table_mortgages->setColumnHidden(0, true);
    ui->table_mortgages->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->table_mortgages->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_mortgages->setSelectionBehavior(QAbstractItemView::SelectRows);

    updateClientComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dbManager;
    // clientModel удалится автоматически, так как мы указали для нее родителя (this)
}

void MainWindow::on_btn_addClient_clicked() {
    AddClientDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {
        int row = clientModel->rowCount();
        clientModel->insertRow(row);

        clientModel->setData(clientModel->index(row, 1), dialog.getFio());
        clientModel->setData(clientModel->index(row, 2), dialog.getPassport());
        clientModel->setData(clientModel->index(row, 3), dialog.getPhone());

        clientModel->submitAll();
        clientModel->select();
        updateClientComboBox();

        ui->statusbar->showMessage("Новый клиент успешно добавлен в базу", 3000);
    }
}

void MainWindow::on_btn_deleteClient_clicked() {
    int selectedRow = ui->table_clients->currentIndex().row();

    if (selectedRow >= 0) {
        if (QMessageBox::question(this, "Удаление", "Вы уверены, что хотите удалить клиента, все его кредиты и вклады?") == QMessageBox::Yes) {

            int clientId = clientModel->data(clientModel->index(selectedRow, 0)).toInt();

            QSqlQuery query;
            query.prepare("DELETE FROM Credits WHERE client_id = :id");
            query.bindValue(":id", clientId);
            query.exec();

            query.prepare("DELETE FROM Deposits WHERE client_id = :id");
            query.bindValue(":id", clientId);
            query.exec();

            query.prepare("DELETE FROM Mortgages WHERE client_id = :id"); // Добавили
            query.bindValue(":id", clientId); // Добавили
            query.exec(); // Добавили

            clientModel->removeRow(selectedRow);
            clientModel->submitAll();
            clientModel->select();

            creditModel->select();
            depositModel->select();
            mortgageModel->select(); // Добавили
            updateClientComboBox();

            ui->statusbar->showMessage("Данные клиента и все его продукты удалены", 3000);

        }
    } else {
        QMessageBox::warning(this, "Внимание", "Выберите клиента в таблице для удаления!");
    }
}

void MainWindow::on_btn_calcCredit_clicked() {
    double S = ui->line_creditSum->text().toDouble();
    int n = ui->line_creditMonths->text().toInt();
    double rate = ui->line_creditRate->text().toDouble();

    if (S <= 0 || n <= 0 || rate <= 0) {
        ui->label_creditResult->setText("Ошибка данных");
        ui->statusbar->showMessage("Ошибка: проверьте корректность ввода параметров кредита", 3000);
        return;
    }

    double r = rate / 100.0 / 12.0;
    double M = S * (r * std::pow(1 + r, n)) / (std::pow(1 + r, n) - 1);

    ui->label_creditResult->setText(QString::number(M, 'f', 2) + " руб/мес");
    ui->statusbar->showMessage("Расчет ежемесячного платежа успешно выполнен", 3000);
}

void MainWindow::updateClientComboBox() {
    ui->combo_clients->clear();
    ui->combo_clients_deposit->clear();
    ui->combo_clients_mortgage->clear(); // Новая строка

    QSqlQuery query("SELECT id, fio FROM Clients");
    while (query.next()) {
        QString id = query.value(0).toString();
        QString fio = query.value(1).toString();

        ui->combo_clients->addItem(fio + " (ID: " + id + ")", query.value(0));
        ui->combo_clients_deposit->addItem(fio + " (ID: " + id + ")", query.value(0));
        ui->combo_clients_mortgage->addItem(fio + " (ID: " + id + ")", query.value(0)); // Новая строка
    }
}

void MainWindow::on_btn_saveCredit_clicked() {
    if (ui->combo_clients->currentIndex() < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите клиента!");
        return;
    }

    double S = ui->line_creditSum->text().toDouble();
    int n = ui->line_creditMonths->text().toInt();
    double rate = ui->line_creditRate->text().toDouble();

    if (S <= 0 || n <= 0 || rate <= 0) {
        QMessageBox::warning(this, "Ошибка", "Заполните все данные кредита!");
        return;
    }

    // Расчет платежа
    double r = rate / 100.0 / 12.0;
    double M = S * (r * std::pow(1 + r, n)) / (std::pow(1 + r, n) - 1);

    // БЛОК АНДЕРРАЙТИНГА (СКОРИНГ)
    bool ok;
    double income = QInputDialog::getDouble(this, "Андеррайтинг (Скоринг)",
                                            "Введите подтвержденный доход клиента (руб/мес):",
                                            50000, 0, 10000000, 2, &ok);

    // Если менеджер нажал "Отмена" в окошке ввода дохода
    if (!ok) {
        ui->statusbar->showMessage("Оформление кредита прервано", 3000);
        return;
    }

    // Жесткая проверка: платеж не должен превышать 50% от дохода
    if (M > income * 0.5) {
        QMessageBox::critical(this, "Система безопасности: ОТКАЗ",
                              QString("Ежемесячный платеж (%1 руб) превышает 50% от дохода клиента (%2 руб).\n\nВыдача кредита заблокирована!")
                                  .arg(M, 0, 'f', 2).arg(income, 0, 'f', 2));
        ui->statusbar->showMessage("Скоринг: Отказ (слишком высокая долговая нагрузка)", 4000);
        return; // Блокируем дальнейшее сохранение в базу!
    }

    // Если проверка пройдена, сохраняем в базу
    int clientId = ui->combo_clients->currentData().toInt();

    int row = creditModel->rowCount();
    creditModel->insertRow(row);

    creditModel->setData(creditModel->index(row, 1), clientId);
    creditModel->setData(creditModel->index(row, 2), S);
    creditModel->setData(creditModel->index(row, 3), n);
    creditModel->setData(creditModel->index(row, 4), M);

    creditModel->submitAll();
    creditModel->select();

    ui->line_creditSum->clear();
    ui->line_creditMonths->clear();
    ui->line_creditRate->clear();
    ui->label_creditResult->clear();

    ui->statusbar->showMessage("Кредит одобрен и внесен в реестр", 3000);
}

void MainWindow::on_btn_deleteCredit_clicked() {
    int selectedRow = ui->table_credits->currentIndex().row();

    if (selectedRow >= 0) {
        if (QMessageBox::question(this, "Удаление", "Вы уверены, что хотите удалить этот кредит?") == QMessageBox::Yes) {
            creditModel->removeRow(selectedRow);
            creditModel->submitAll();
            creditModel->select();

            ui->statusbar->showMessage("Запись о кредите успешно удалена", 3000);
        }
    } else {
        QMessageBox::warning(this, "Внимание", "Выберите кредит в таблице для удаления!");
    }
}


void MainWindow::on_btn_calcDep_clicked() {
    double S = ui->line_depSum->text().toDouble();
    int n = ui->line_depMonths->text().toInt();
    double rate = ui->line_depRate->text().toDouble();

    if (S <= 0 || n <= 0 || rate <= 0) {
        ui->label_depResult->setText("Ошибка данных");
        ui->statusbar->showMessage("Ошибка: проверьте корректность ввода параметров вклада", 3000);
        return;
    }

    double profit = S * (rate / 100.0) * (n / 12.0);
    ui->label_depResult->setText("Доход: " + QString::number(profit, 'f', 2) + " руб");
    ui->statusbar->showMessage("Расчет доходности вклада успешно выполнен", 3000);
}

void MainWindow::on_btn_saveDep_clicked() {
    if (ui->combo_clients_deposit->currentIndex() < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите клиента!");
        return;
    }

    double S = ui->line_depSum->text().toDouble();
    int n = ui->line_depMonths->text().toInt();
    double rate = ui->line_depRate->text().toDouble();

    if (S <= 0 || n <= 0 || rate <= 0) {
        QMessageBox::warning(this, "Ошибка", "Заполните все данные!");
        return;
    }

    double profit = S * (rate / 100.0) * (n / 12.0);
    int clientId = ui->combo_clients_deposit->currentData().toInt();

    int row = depositModel->rowCount();
    depositModel->insertRow(row);

    depositModel->setData(depositModel->index(row, 1), clientId);
    depositModel->setData(depositModel->index(row, 2), S);
    depositModel->setData(depositModel->index(row, 3), n);
    depositModel->setData(depositModel->index(row, 4), profit);

    depositModel->submitAll();
    depositModel->select();

    ui->line_depSum->clear();
    ui->line_depMonths->clear();
    ui->line_depRate->clear();
    ui->label_depResult->clear();

    ui->statusbar->showMessage("Банковский вклад успешно открыт", 3000);
}

void MainWindow::on_btn_deleteDeposit_clicked() {
    int selectedRow = ui->table_deposits->currentIndex().row();

    if (selectedRow >= 0) {
        if (QMessageBox::question(this, "Удаление", "Вы уверены, что хотите удалить этот вклад?") == QMessageBox::Yes) {
            depositModel->removeRow(selectedRow);
            depositModel->submitAll();
            depositModel->select();

            ui->statusbar->showMessage("Запись о вкладе успешно удалена", 3000);
        }
    } else {
        QMessageBox::warning(this, "Внимание", "Выберите вклад в таблице для удаления!");
    }
}


void MainWindow::on_btn_calcMortgage_clicked()
{
    double price = ui->line_mortPrice->text().toDouble();
    double downPayment = ui->line_mortDownPayment->text().toDouble();
    int n = ui->line_mortMonths->text().toInt();
    double rate = ui->line_mortRate->text().toDouble();

    double S = price - downPayment; // Сумма самого займа

    if (price <= 0 || downPayment < 0 || S <= 0 || n <= 0 || rate <= 0) {
        ui->label_mortResult->setText("Ошибка данных");
        ui->statusbar->showMessage("Ошибка: проверьте суммы и ставки", 3000);
        return;
    }

    double r = rate / 100.0 / 12.0;
    double M = S * (r * std::pow(1 + r, n)) / (std::pow(1 + r, n) - 1);

    ui->label_mortResult->setText(QString::number(M, 'f', 2) + " руб/мес");
    ui->statusbar->showMessage("Расчет ипотеки успешно выполнен", 3000);
}


void MainWindow::on_btn_saveMortgage_clicked() {
    if (ui->combo_clients_mortgage->currentIndex() < 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите клиента!");
        return;
    }

    double price = ui->line_mortPrice->text().toDouble();
    double downPayment = ui->line_mortDownPayment->text().toDouble();
    int n = ui->line_mortMonths->text().toInt();
    double rate = ui->line_mortRate->text().toDouble();

    // Сумма самого займа (цена минус взнос)
    double S = price - downPayment;

    if (price <= 0 || S <= 0 || n <= 0 || rate <= 0) {
        QMessageBox::warning(this, "Ошибка", "Проверьте данные ипотеки!");
        return;
    }

    // Расчет платежа
    double r = rate / 100.0 / 12.0;
    double M = S * (r * std::pow(1 + r, n)) / (std::pow(1 + r, n) - 1);

    // БЛОК АНДЕРРАЙТИНГА (ИПОТЕЧНЫЙ СКОРИНГ)
    bool ok;
    double income = QInputDialog::getDouble(this, "Ипотечный Скоринг",
                                            "Введите подтвержденный доход клиента (руб/мес):",
                                            80000, 0, 10000000, 2, &ok);

    // Если менеджер нажал "Отмена"
    if (!ok) {
        ui->statusbar->showMessage("Оформление ипотеки прервано", 3000);
        return;
    }

    // Проверка: платеж по ипотеке не должен превышать 50% от дохода
    if (M > income * 0.5) {
        QMessageBox::critical(this, "Система безопасности: ОТКАЗ",
                              QString("Ежемесячный платеж (%1 руб) превышает 50% от дохода клиента (%2 руб).\n\nВыдача ипотеки заблокирована!")
                                  .arg(M, 0, 'f', 2).arg(income, 0, 'f', 2));
        ui->statusbar->showMessage("Скоринг: Отказ по ипотеке (высокая долговая нагрузка)", 4000);
        return;
    }

    int clientId = ui->combo_clients_mortgage->currentData().toInt();

    int row = mortgageModel->rowCount();
    mortgageModel->insertRow(row);
    mortgageModel->setData(mortgageModel->index(row, 1), clientId);
    mortgageModel->setData(mortgageModel->index(row, 2), price);
    mortgageModel->setData(mortgageModel->index(row, 3), downPayment);
    mortgageModel->setData(mortgageModel->index(row, 4), n);
    mortgageModel->setData(mortgageModel->index(row, 5), M);
    mortgageModel->submitAll();
    mortgageModel->select();

    ui->line_mortPrice->clear();
    ui->line_mortDownPayment->clear();
    ui->line_mortMonths->clear();
    ui->line_mortRate->clear();
    ui->label_mortResult->clear();

    ui->statusbar->showMessage("Ипотека успешно одобрена и внесена в реестр", 3000);
}

void MainWindow::on_btn_deleteMortgage_clicked()
{
    int selectedRow = ui->table_mortgages->currentIndex().row();
    if (selectedRow >= 0) {
        if (QMessageBox::question(this, "Удаление", "Удалить ипотеку?") == QMessageBox::Yes) {
            mortgageModel->removeRow(selectedRow);
            mortgageModel->submitAll();
            mortgageModel->select();
            ui->statusbar->showMessage("Запись об ипотеке удалена", 3000);
        }
    } else {
        QMessageBox::warning(this, "Внимание", "Выберите ипотеку в таблице!");
    }
}


void MainWindow::on_line_search_textChanged(const QString &arg1)
{
    clientModel->setFilter(QString("fio LIKE '%%1%'").arg(arg1));
    clientModel->select();
}

// Реализация нашей функции
void MainWindow::updateSessionTime()
{
    // Добавляем ровно 1 секунду к нашему времени сессии
    sessionTime = sessionTime.addSecs(1);

    // Обновляем текст в левом нижнем углу.
    // .toString("hh:mm:ss") автоматически сделает красиво: 00:01:05
    sessionLabel->setText("Время сессии: " + sessionTime.toString("hh:mm:ss"));
}

