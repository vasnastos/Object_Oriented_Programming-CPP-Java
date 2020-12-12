#include "database.cpp"

int main()
{
    open_database();
    std::vector <order> ords=get_items();
    for(auto &x:ords)
    {
        insert_order(x.getnumber(),x.getordered(),x.getshipped(),x.getshpto());
        std::vector <line_item> itms=x.get_line_items();
        for(auto &y:itms)
        {
            insert_item(x.getnumber(),y.getproduct(),y.getquantity(),y.getprice());
        }
    }
    std::vector <order> totalorders=get_orders();
    std::cout<<"############## Products List ######################"<<std::endl;
    for(auto &od:totalorders)
    {
        std::cout<<od<<std::endl;
    }
    std::cout<<"####################################################"<<std::endl;
    return 0;
}