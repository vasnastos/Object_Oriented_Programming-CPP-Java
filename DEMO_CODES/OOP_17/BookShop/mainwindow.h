#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include "book.h"
#include <vector>
#include <QMessageBox>
#include <QInputDialog>
#include <QPushButton>


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QWidget *mw;
    QVBoxLayout *ml;
    QLabel *lb;
    std::vector <Book> books;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void insert();
    void search();
    void showrecs();
};
#endif // MAINWINDOW_H
