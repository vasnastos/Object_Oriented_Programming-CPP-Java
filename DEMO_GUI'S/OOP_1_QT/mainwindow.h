#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QTextStream>
#include <QInputDialog>
#include <QFileDialog>
#include <QLineEdit>
#include <QMovie>
#include "cargo.h"
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QWidget *mw;
    QVBoxLayout *ml;
    QLabel *lb;
    QLineEdit *ed;
    QVector <cargo> cargos;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void add_cargo();
    void show_cargo();
    void save();
    void search_cargo();
};
#endif // MAINWINDOW_H
