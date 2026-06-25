#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DBManager::DBManager() {
    // Говорим Qt, что работаем с локальной базой SQLite
    db = QSqlDatabase::addDatabase("QSQLITE");
    // Файл базы данных создастся прямо в папке сборки программы
    db.setDatabaseName("bank_system.sqlite");
}

bool DBManager::connectDB() {
    if (!db.open()) {
        qDebug() << "Ошибка открытия базы данных:" << db.lastError().text();
        return false;
    }
    return true;
}

bool DBManager::createTables() {
    QSqlQuery query;

    bool success1 = query.exec("CREATE TABLE IF NOT EXISTS Clients ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "fio TEXT NOT NULL, "
                               "passport TEXT, "
                               "phone TEXT)");

    bool success2 = query.exec("CREATE TABLE IF NOT EXISTS Credits ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "client_id INTEGER, "
                               "amount REAL, "
                               "months INTEGER, "
                               "payment REAL)");

    bool success3 = query.exec("CREATE TABLE IF NOT EXISTS Deposits ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "client_id INTEGER, "
                               "amount REAL, "
                               "months INTEGER, "
                               "profit REAL)");

    bool success4 = query.exec("CREATE TABLE IF NOT EXISTS Mortgages ("
                               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                               "client_id INTEGER, "
                               "property_price REAL, "
                               "down_payment REAL, "
                               "months INTEGER, "
                               "payment REAL)");

    // Умное автозаполнение базы при первом запуске
    if (success1 && success2 && success3 && success4) {
        QSqlQuery checkQuery("SELECT COUNT(*) FROM Clients");
        if (checkQuery.next() && checkQuery.value(0).toInt() == 0) {

            // База пуста, закидываем стартовых клиентов
            query.exec("INSERT INTO Clients (fio, passport, phone) "
                       "VALUES ('Даниил', '1234 567890', '+7 (999) 111-22-33')");

            query.exec("INSERT INTO Clients (fio, passport, phone) "
                       "VALUES ('Роман', '2345 678901', '+7 (999) 222-33-44')");

            query.exec("INSERT INTO Clients (fio, passport, phone) "
                       "VALUES ('Виктория', '3456 789012', '+7 (999) 333-44-55')");

            query.exec("INSERT INTO Clients (fio, passport, phone) "
                       "VALUES ('Иванов Иван', '4567 890123', '+7 (999) 444-55-66')");
        }
        return true;
    }

    return false;
}