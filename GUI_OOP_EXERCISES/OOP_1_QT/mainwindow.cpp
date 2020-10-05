#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(400,400);
    this->setWindowTitle("Cargos Project");
    mw=new QWidget;
    mw->setFixedSize(width(),height());
    this->setCentralWidget(mw);
    ml=new QVBoxLayout;
    mw->setLayout(ml);
    QLabel *gif=new QLabel;
    QMovie *m=new QMovie;
    m->setFileName(":/cargo.gif");
    gif->setFixedSize(0.98*this->width(),0.3*this->height());
    QSize ms(gif->width(),gif->height());
    m->setScaledSize(ms);
    gif->setMovie(m);
    ml->addWidget(gif);
    gif->movie()->start();
    QPushButton *b=new QPushButton("ADD CARGO");
    b->setStyleSheet("border:2px solid;"
                     "border-color:#948250;"
                     "background-color:#a2a9b0;"
                     "color:#590d2e;");
    b->setFixedWidth(0.28*this->width());
    QPushButton *b2=new QPushButton("SHOW CARGOS");
    b2->setStyleSheet("border:2px solid;"
                      "border-color:#948250;"
                      "background-color:#a2a9b0;"
                      "color:#590d2e;");
    b2->setFixedWidth(0.28*this->width());
    QPushButton *b3=new QPushButton("SAVE CARGOS");
    b3->setStyleSheet("border:2px solid;"
                      "border-color:#948250;"
                      "background-color:#a2a9b0;"
                      "color:#590d2e;");
    b3->setFixedWidth(0.28*this->width());
    QHBoxLayout *row=new QHBoxLayout;
    ml->addLayout(row);
    row->addWidget(b);
    row->addWidget(b2);
    row->addWidget(b3);
    connect(b,SIGNAL(clicked(bool)),this,SLOT(add_cargo()));
    connect(b2,SIGNAL(clicked(bool)),this,SLOT(show_cargo()));
    connect(b3,SIGNAL(clicked(bool)),this,SLOT(save()));
    ed=new QLineEdit;
    ed->setFixedWidth(0.2*this->width());
    ed->setStyleSheet("background-color:#c9c1c5;"
                      "color:#4d0529;"
                      "border:1px solid;");
    QPushButton *src=new QPushButton("SEARCH");
    src->setStyleSheet("border:2px solid;"
                       "border-color:#948250;"
                       "background-color:#a2a9b0;"
                       "color:#590d2e;");
    src->setFixedWidth(0.2*this->width());
    lb=new QLabel;
    lb->setFixedSize(0.3*this->width(),0.2*this->height());
    lb->setStyleSheet("border:2px solid;");
    QHBoxLayout *row1=new QHBoxLayout;
    ml->addLayout(row1);
    row1->addWidget(ed);
    row1->addWidget(src);
    row1->addWidget(lb);
    connect(src,SIGNAL(clicked(bool)),this,SLOT(search_cargo()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::add_cargo()
{
    int id=QInputDialog::getInt(this,"Cargo's Id","Give cargo's id");
    QString dest=QInputDialog::getText(this,"Cargo's Destination","Give cargo's destination");
    double weight=QInputDialog::getDouble(this,"Cargo's weight","Give cargo's weight");
    double price=QInputDialog::getDouble(this,"Cargo's Price","Give cargo's price");
    for(auto &x:cargos)
    {
        if(x.get_id()==id)
        {
            QMessageBox::critical(this,"ERROR","Cargo already exists in the list");
            return;
        }
    }
    cargo nc(id,dest,weight,price);
    cargos<<nc;
}

void MainWindow::show_cargo()
{
    QString msg="<h3 text-align:center;>Cargos</h3>";
    for(auto &x:cargos)
    {
        msg+="<li>"+x.to_String()+"</li>";
    }
    msg+="</ul>";
    QMessageBox::information(this,"SHOW RESULTS",msg);
}


void MainWindow::search_cargo()
{
  if(ed->text().isEmpty())
  {
      QMessageBox::critical(this,"ERROR","No search id detected");
      return;
  }
  QString msg="<h4>Search Results</h4><ul>";
  QString time=__TIME__;
  msg+="<li>Search made at:"+time+"</li>";
  int srch=ed->text().toInt();
  for(auto &x:cargos)
  {
      if(x.get_id()==srch)
      {
          msg+="<li>"+x.to_String()+"</li>";
          break;
      }
  }
  msg+="</ul>";
  lb->setAlignment(Qt::AlignCenter);
  lb->setText(msg);
}

void MainWindow::save()
{
   QString fn=QFileDialog::getSaveFileName(this,"Save cargos",".","text files (*.txt *.csv)");
   if(fn.size()==0)
   {
       QMessageBox::critical(this,"Error","No file selected");
       return;
   }
   QFile fp(fn);
   fp.open(QIODevice::WriteOnly);
   QTextStream st(&fp);
   st<<"File Created:"<<__TIME__<<"--date:"<<__DATE__<<endl;
   st<<"Cargos exist on file"<<endl;
   for(auto &x:cargos)
   {
       st<<x.to_String()<<endl;
   }
   fp.close();
}
