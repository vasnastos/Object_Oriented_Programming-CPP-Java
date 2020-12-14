
public class Truck extends Vehicle{
   private double max_weight;
   public Truck(String n,String on,double c,double mw)
   {
	   super(n,on,c);
	   this.max_weight=mw;
   }
    @Override
   public double traffic_tax() {
	  if(this.cc<=3000)
	  {
		  return 300.0;
	  }
	  else if(this.cc<=6000)
	  {
		  return 400.0;
	  }
	  else 
	  {
		  return 600.0;
	  }
   }
    public String toStr()
    {
    	return this.reg_num+"-"+this.owner+"-"+String.valueOf(this.cc)+"-"+String.valueOf(this.max_weight);
    }
}
