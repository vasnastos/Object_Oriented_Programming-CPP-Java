#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(400,400);
    this->setWindowTitle("Book Store");
    mw=new QWidget;
    mw->setFixedSize(width(),height());
    this->setCentralWidget(mw);
    ml=new QVBoxLayout;
    mw->setLayout(ml);
    QPushButton *b=new QPushButton("INSERT");
    QPushButton *b1=new QPushButton("SHOW");
    QPushButton *b2=new QPushButton("SEARCH");
    b->setFixedWidth(0.2*this->width());
    b1->setFixedWidth(0.2*this->width());
    b2->setFixedWidth(0.2*this->width());
    QHBoxLayout *row=new QHBoxLayout;
    ml->addLayout(row);
    row->addWidget(b);
    row->addWidget(b1);
    row->addWidget(b2);
    connect(b,SIGNAL(clicked(bool)),this,SLOT(insert()));
    connect(b1,SIGNAL(clicked(bool)),this,SLOT(showrecs()));
    connect(b2,SIGNAL(clicked(bool)),this,SLOT(search()));
    lb=new QLabel;
    lb->setAlignment(Qt::AlignCenter);
    lb->setFixedSize(0.95*this->width(),0.4*this->height());
    lb->setStyleSheet("border:2px solid;");
    ml->addWidget(lb);
}

MainWindow::~MainWindow()
{
}

void MainWindow::insert()
{
    std::string author=QInputDialog::getText(this,"Author","Give author").toStdString();
    std::string title=QInputDialog::getText(this,"Title","Give title").toStdString();
    for(auto &x:books)
    {
        if(x.get_author()==author && x.get_title()==title)
        {
           QMessageBox::critical(this,"ERROR","Records already exists");
           return;
        }
    }
    double price=QInputDialog::getDouble(this,"Price","Give Price");
    Book newbook(author,title,price);
    books.push_back(newbook);
}

void MainWindow::search()
{
    std::string searchname=QInputDialog::getText(this,"Authors Name","Give search author name").toStdString();
     QString sh="<h3>Search Results</h3><ul>";
    for(auto &x:books)
    {
        if(x.get_author()==searchname)
        {
            sh+="<li style=color:#331223;>"+x.get_title_qt()+"----"+QString::number(x.get_price())+"</li>";
        }
    }
    sh+="</ul>";
    lb->setText(sh);
}

void MainWindow::showrecs()
{
    QString msg="<h3>Books</h3><ul>";
    for(auto &x:books)
    {
        msg+="<li>"+x.get_author_qt()+"--"+x.get_title_qt()+"--"+QString::number(x.get_price())+"</li>";
    }
    msg+="</ul>";
    lb->setText(msg);
}
