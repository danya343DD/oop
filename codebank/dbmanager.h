#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>

class DBManager {
public:
    DBManager();
    bool connectDB();    // Метод для открытия соединения с БД
    bool createTables();  // Метод для создания таблиц

private:
    QSqlDatabase db;
};

#endif // DBMANAGER_H
