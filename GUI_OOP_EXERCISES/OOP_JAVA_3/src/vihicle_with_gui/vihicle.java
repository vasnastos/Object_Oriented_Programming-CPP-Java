package vihicle_with_gui;

public abstract class vihicle {
    protected String registration_number;
    protected String owner_name;
    protected double cc;
    public vihicle(String rn,String on,double c)
    {
    	this.registration_number=rn;
    	this.owner_name=on;
    	this.cc=c;
    }
    public String get_registration_number() {return this.registration_number;}
    public String get_owner_name() {return this.owner_name;}
    public double get_cc() {return this.cc;}
    public abstract double traffic_taxes();
    public abstract String to_String();
}
