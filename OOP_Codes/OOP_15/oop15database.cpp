#include "oop15.cpp"
#include "sqlite3.h"

std::string dbname="apps.db";

void create_database()
{
    sqlite3 *db=nullptr;
    sqlite3_stmt *q=nullptr;
    std::string sql;
    char *errmsg=nullptr;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return;
    }
    sql="create table if not exists app(code varchar(40),name varchar(40),description text,category varchar(50),price double,primary key(code));"
        "create table if not exists evaluation(user varchar(40),comments text,stars integer,code varchar(40));";
    res=sqlite3_exec(db,sql.c_str(),0,0,&errmsg);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_free(errmsg);
        sqlite3_close(db);
        return;
    }
    else
    {
        std::cout<<"Hello world from apps database!!!!"<<std::endl;
    }
    sqlite3_free(errmsg);
    slite3_close(db);
}

void insert_app(std::string cd,std::string nm,std::string des,std::string cat,double pr)
{
    sqlite3 *db=nullptr;
    sqlite3_stmt *q=nullptr;
    std::string sql;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sql="insert into app(code,name,description,category,price) values(?,?,?,?,?);";
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    if(res=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_text(q,1,cd.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(q,2,nm.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(q,3,des.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(q,4,cat.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_double(q,5,pr);
    if(sqlite3_step(q)==SQLITE_ROW)
    {
        std::cout<<"Record inserted!!!!!!"<<std::endl;
    }
    else
    {
        std::cout<<"Error!!!!!"<<std::endl;
    }
    sqlite3_close(db);
}

void insert_evaluation(std::string cd,std::string user,std::string coms,int strs)
{
    sqlite3 *db=nullptr;
    sqlite3_stmt *q=nullptr;
    std::string sql;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sql="insert into evaluation(user,comments,stars,code) values(?,?,?,?);";
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_text(q,1,user.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_text(q,2,coms.c_str(),-1,SQLITE_STATIC);
    sqlite3_bind_int(q,3,strs);
    sqlite3_bind_text(q,4,cd.c_str(),-1,SQLITE_STATIC);
    if(sqlite3_step(q)==SQLITE_ROW)
    {
        std::cout<<"Evaluation inserted!!!"<<std::endl;
    }
    else
    {
        std::cout<<"ERROR!!!!"<<std::endl;
    }
    sqlite3_close(db);
}

std::vector <app> get_recs()
{
    std::vector <app> vec;
    sqlite3 *db=nullptr;
    sqlite_stmt *q=nullptr;
    std::string sql;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return vec;
    }
    sql="select * from app;";
    sqlite3_stmt *qr=nullptr;
    std::string evs;
    sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    while(sqlite3_step(q)==SQLITE_ROW)
    {
        std::string code=(const char *)sqlite3_column_text(q,0);
        std::string name=(const char *)sqlite3_column_text(q,1);
        std::string desc=(const char *)sqlite3_column_text(q,2);
        std::string cat=(const char *)sqlite3_column_text(q,3);
        double pr=sqlite3_column_double(q,4);
        app newapp(code,name,desc,cat,pr);
        evs="select user,comments,stars from evaluation where=?;";
        res=sqlite3_prepare_v2(db,evs.c_str(),-1,&qr,nullptr);
        if(res!=SQLITE_OK)
        {
            std::cout<<sqlite3_errmsg(db)<<std::endl;
            sqlite3_close(db);
            return vec;
        }
        while(sqlite3_step(qr)==SQLITE_ROW)
        {
            std::string usr=(const char *)sqlite3_column_text(q,0);
            std::string coms=(const char *)sqlite3_column_text(q,1);
            int sts=sqlite3_column_int(q,2);
            evaluation ev(usr,coms,sts);
            newapp.add_evaluation(ev);
        }
        vec.push_back(newapp);
    }
    sqlite3_close(db);
    return vec;
}

app search(std::string appcode)
{
    app *newapp=nullptr;
    sqlite3 *db=nullptr;
    sqlite3_stmt *q=nullptr;
    std::string sql;
    int res=sqlite3_open(dbname.c_str(),&db);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sql="select * from app where code=?;";
    res=sqlite3_prepare_v2(db,sql.c_str(),-1,&q,nullptr);
    if(res!=SQLITE_OK)
    {
        std::cout<<sqlite3_errmsg(db)<<std::endl;
        sqlite3_close(db);
        return;
    }
    sqlite3_bind_text(q,1,appcode.c_str(),-1,SQLITE_STATIC);
    sqlite3_stmt *qr=nullptr;
    std::string evs;
    if(sqlite3_step(q)==SQLITE_ROW)
    {
        std::string code=(const char *)sqlite3_column_text(q,0);
        std::string name=(const char *)sqlite3_column_text(q,1);
        std::string desc=(const char *)sqlite3_column_text(q,2);
        std::string cat=(const char *)sqlite3_column_text(q,3);
        double pr=sqlite3_column_double(q,4);
        newapp=new app(code,name,desc,cat,pr);
        evs="select user,comments,stars from evaluation where code=?";
        res=sqlite3_prepare_v2(db,evs.c_str(),-1,&qr,nullptr);
        if(res!=SQLITE_OK)
        {
            std::cout<<sqlite3_errmsg(db)<<std::endl;
            sqlite3_close(db);
            return;
        }
        while(sqlite3_step(qr)==SQLITE_ROW)
        {
            std::string usr=(const char *)sqlite3_column_text(qr,0);
            std::string coms=(const char *)sqlite3_column_text(qr,1);
            int srs=sqlite3_column_int(qr,2);
            evaluation ev(usr,coms,srs);
            if(newapp!=nullptr)
            {
                newapp->add_evaluation(ev);
            }
        } 
    }
     sqlite3_close(db);
     return *newapp;
}