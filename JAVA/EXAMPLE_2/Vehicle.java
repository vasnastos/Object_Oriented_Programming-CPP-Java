
public abstract class Vehicle {
    protected String reg_num;
    protected String owner;
    protected double cc;
    public Vehicle(String n,String on,double c)
    {
    	this.reg_num=n;
    	this.owner=on;
    	this.cc=c;
    }
    public abstract double traffic_tax();
    public abstract String toStr();
}
