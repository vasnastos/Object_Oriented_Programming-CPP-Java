#include <iostream>
class object
{
   int x;
   std::string k;
   public:
    object(int a,std::string b):x(a),k(b) {}
    void set_x(int a) {this->x=a;}
    int get_x()const {return this->x;}
    void set_b(std::string v) {this->k=v;}
    std::string get_k()const {return this->k;}
    friend std::ostream &operator<<(std::ostream &os,const object &obj)
    {
        os<<"Str:"<<obj.k<<"\t"<<"Int:"<<obj.x<<std::endl;
        return os;
    }
};

int main(int argc,char **argv)
{
    object obj(1,"vasilis");
    object *pobj=&obj;
    std::cout<<(*pobj)<<std::endl;
    object *ob=new object(2,"Kostas");
    ob->set_b("Petros");
    std::cout<<ob->get_x()<<"\t"<<ob->get_k()<<std::endl;
    delete pobj;
    delete ob;
    return 0;
}