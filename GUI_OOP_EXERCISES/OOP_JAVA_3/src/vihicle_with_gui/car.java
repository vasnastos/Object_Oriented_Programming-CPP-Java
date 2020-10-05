package vihicle_with_gui;

public class car extends vihicle{
   private int nod;
   public car(String rn,String on,double c,int n)
   {
	   super(rn,on,c);
	   this.nod=n;
   }
   public int get_number_of_doors()
   {
	   return this.nod;
   }
@Override
public double traffic_taxes() {
	if(this.cc<1000.0) {return 140.0;}
	return 140+((this.cc-1000.0)/10)*5;
}
@Override
public String to_String() {
	return this.registration_number+"-"+this.registration_number+"-"+String.valueOf(this.cc)+"--"+String.valueOf(this.nod);
}
  
}
