package cargo_with_FileOpener;

public class cargo {
    private int id;
    private String destination;
    private double weight;
    private boolean fragile;
    public cargo()
    {
    	this.id=0;
    	this.destination="Undendified";
    	this.weight=0.0;
    	this.fragile=false;
    }
    public cargo(int i,String d,double w,boolean f)
    {
    	this.id=i;
    	this.destination=d;
    	this.weight=w;
    	this.fragile=f;
    }
    public void set_id(int i) {this.id=i;}
    public void set_destination(String des) {this.destination=des;}
    public void set_weight(double w) {this.weight=w;}
    public void set_fragile(boolean f) {this.fragile=f;}
    public int get_id() {return this.id;}
    public String get_destination() {return this.destination;}
    public double get_weight() {return this.weight;}
    public boolean is_fragile() {return this.fragile;}
    public String to_String()
    {
    	String str=String.valueOf(this.id)+"--"+this.destination+"--"+String.valueOf(this.weight)+"--";
    	if(this.fragile)
    	{
    		str+="Fragile";
    	}
    	else
    	{
    		str+="Not Fragile";
    	}
    	return str;
    }
    public void show()
    {
    	String str=String.valueOf(this.id)+"--"+this.destination+"--"+String.valueOf(this.weight)+"--";
    	if(this.fragile)
    	{
    		str+="Fragile";
    	}
    	else
    	{
    		str+="Not Fragile";
    	}
    	System.out.println(str);
    }
    public void make_safe()
    {
    	if(!this.fragile)
    	{
    		this.fragile=true;
    		this.weight+=5;
    	}
    }
}
