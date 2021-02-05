package askisi3_vathmoi;

public class Vathmos 
{
    private int id;//am spoudasti
    private int lab;//vathmos sto ergastirio
    private int lecture;//vathmos stin dialexi
    public Vathmos(int i,int l,int le)
    {
        id=i;
        setlab(l);
        setlecture(le);
    }
    
    public void setlab(int l)
    {
        if(l>=0 && l<=10) lab=l;
    }
    
    public int getlab()
    {
        return lab;
    }
    
    public void setlecture(int l)
    {
        if(l>=0 && l<=10) lecture=l;
    }
    
    public int getlecture()
    {
        return lecture;
    }
    
    public int getid()
    {
        return id;
        
    }
    
    public String toString()
    {
        return id+","+lab+","+lecture;
    }
}
