#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QMainWindow>
#include <QSqlTableModel> // Библиотека для связи базы с таблицей на экране
#include "dbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateSessionTime();
    void on_btn_addClient_clicked();

    void on_btn_deleteClient_clicked();

    void on_btn_calcCredit_clicked();

    void on_btn_saveCredit_clicked();

    void on_btn_deleteCredit_clicked();

    void on_btn_calcDep_clicked();

    void on_btn_saveDep_clicked();

    void on_btn_deleteDeposit_clicked();

    void on_btn_calcMortgage_clicked();

    void on_btn_saveMortgage_clicked();

    void on_btn_deleteMortgage_clicked();

    void on_line_search_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QTimer *sessionTimer;
    QTime sessionTime;
    QLabel *sessionLabel;
    DBManager *dbManager;
    QSqlTableModel *clientModel;
    QSqlTableModel *creditModel;
    QSqlTableModel *depositModel;
    QSqlTableModel *mortgageModel;

    void updateClientComboBox();
};
#endif // MAINWINDOW_H
