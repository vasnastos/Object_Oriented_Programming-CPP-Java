#include "sqlite3.h"
#include "items.cpp"

std::string dbname="products.db";

void open_database()
{
    sqlite3 *db=nullptr;
    std::string sql;
    char *error=nullptr;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_free(error);
        sqlite3_close(db);
        return;
    }
    sql="CREATE TABLE IF NOT EXISTS ORDERS(NUMBER TEXT, ORDERED TEXT, SHIPPED TEXT, SHIP_TO TEXT);"
        "CREATE TABLE IF NOT EXISTS LINE_ITEMS(PRODUCT TEXT, QUANTITY INT, PRICE DOUBLE, ORDER_FK TEXT);";
    res=sqlite3_exec(db,sql.c_str(),0,0,&error);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_free(error);
        sqlite3_close(db);
        return;
    }
    std::cout<<"Hello World from products database!!"<<std::endl;
    sqlite3_free(error);
    sqlite3_close(db);
}

bool product_in(std::string num,std::string pr);

void insert_item(std::string number,std::string pr,int qnt,double prc)
{
    if(product_in(number,pr))
    {
        std::cout<<"Product is in"<<std::endl;
        return;
    }
    sqlite3 *db=nullptr;
    sqlite3_stmt *q;
    std::string sql;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sql="insert into LINE_ITEMS(PRODUCT,QUANTITY,PRICE,ORDER_FK) values(?,?,?,?);";
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_free(db);
        return ;
    }
    sqlite3_bind_text(q,1,pr.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_int(q,2,qnt);
    sqlite3_bind_double(q,3,prc);
     sqlite3_bind_text(q,4,number.c_str(),-1,SQLITE_STATIC);
    sqlite3_step(q);
    sqlite3_close(db);
    std::cout<<"Product inserted on the database"<<std::endl;
}

bool order_in(std::string number)
{
    sqlite3 *db=nullptr;
    std::string sql;
    sqlite3_stmt *q=nullptr;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_errmsg(db);
        return false;
    }
    sql="select * from ORDERS where NUMBER=?;";
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_errmsg(db);
        return false;
    }
    sqlite3_bind_text(q,1,number.c_str(),-1,SQLITE_STATIC);
    bool result=sqlite3_step(q)==SQLITE_ROW;
    sqlite3_close(db);
    return result;
}

bool product_in(std::string num,std::string pr)
{
    sqlite3 *db=nullptr;
    sqlite3_stmt *q=nullptr;
    std::string sql;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_errmsg(db);
        return false;
    }
    sql="select * from LINE_ITEMS where ORDER_FK=? and PRODUCT=?;";
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_errmsg(db);
        return false;
    }
    sqlite3_bind_text(q,1,num.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(q,2,pr.c_str(),-1,SQLITE_STATIC);
    bool result=sqlite3_step(q)==SQLITE_ROW;
    sqlite3_close(db);
    return result;
}

void insert_order(std::string n,std::string od,std::string sh,std::string sht)
{
    if(order_in(n))
    {
        std::cout<<"Order is in"<<std::endl;
        return;
    }
    sqlite3 *db=nullptr;
    sqlite3_stmt *q;
    std::string sql;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sql="insert into ORDERS(NUMBER,ORDERED,SHIPPED,SHIP_TO) values(?,?,?,?);";
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_text(q,1,n.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(q,2,od.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(q,3,sh.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(q,4,sht.c_str(),-1,SQLITE_STATIC);
    sqlite3_step(q);
    sqlite3_close(db);
    std::cout<<"Order inserted on the database"<<std::endl;
}

std::vector <order> get_orders()
{
    std::vector <order> orders;
    sqlite3 *db=nullptr;
    sqlite3_stmt *q=nullptr;
    sqlite3_stmt *qpr=nullptr;
    std::string sql;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return orders;
    }
    sql="select * from ORDERS;";
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return orders;
    }
    while(sqlite3_step(q)==SQLITE_ROW)
    {
        std::string number=(const char *)sqlite3_column_text(q,0);
        std::string ord=(const char *)sqlite3_column_text(q,1);
        std::string shpd=(const char *)sqlite3_column_text(q,2);
        std::string spdt=(const char *)sqlite3_column_text(q,3);
        order aorder(number,ord,shpd,spdt);
        std::string findpr="select PRODUCT,QUANTITY,PRICE from LINE_ITEMS where ORDER_FK=?";
        res=sqlite3_prepare_v2(db,findpr.c_str(),-1,&qpr,nullptr);
        if(res!=SQLITE_OK)
        {
          std::cout<<sqlite3_errmsg(db)<<std::endl;
          sqlite3_close(db);
          return orders; 
        }
        sqlite3_bind_text(qpr,1,number.c_str(),-1,SQLITE_STATIC);
        while(sqlite3_step(qpr)==SQLITE_ROW)
        {
            std::string prd=(const char *)sqlite3_column_text(qpr,0);
            int qnt=sqlite3_column_int(qpr,1);
            double price=sqlite3_column_double(qpr,2);
            line_item it(prd,qnt,price);
            aorder.add_item(it);
        }
        orders.push_back(aorder);
    }
    sqlite3_close(db);
    return orders;
} 