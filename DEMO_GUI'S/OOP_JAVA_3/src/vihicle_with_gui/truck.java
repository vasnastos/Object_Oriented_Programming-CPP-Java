package vihicle_with_gui;

public class truck extends vihicle{
   private double mw;
   public truck(String rn,String on,double c,double mw)
   {
	   super(rn,on,c);
	   this.mw=mw;
   }
@Override
public double traffic_taxes() {
	if(this.cc<3000.0)
	{
		return 300.0;
	}
	else if(this.cc<6000.0)
	{
		return 400.0;
	}
	else
	{
		return 600.0;
	}
}
@Override
public String to_String() {
	return this.registration_number+"-"+this.registration_number+"-"+String.valueOf(this.cc)+String.valueOf(this.mw);
}
}
