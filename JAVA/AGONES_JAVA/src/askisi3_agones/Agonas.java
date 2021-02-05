
package askisi3_agones;


public class Agonas 
{
    private int home;//goal omadas pou paizei entos
    private int visitor;//goal omadas pou paizei ektos
    public Agonas(int h,int v)
    {
        sethome(h);
        setvisitor(v);
    }
    
    public boolean homewin()
    {
        return home>visitor;
    }
    
    public boolean visitorwin()
    {
        return visitor>home;
    }
    
    public boolean isdraw()
    {
        return home==visitor;
    }
    
    public void sethome(int h)
    {
        if(h>=0) home=h;
    }
    
    public int gethome()
    {
        return home;
    }
    
    public void setvisitor(int v)
    {
        if(v>=0) visitor=v;
    }
    
    public int getvisitor()
    {
        return visitor;
    }
    
    public String toString()
    {
        return home+"-"+visitor;
    }
}
