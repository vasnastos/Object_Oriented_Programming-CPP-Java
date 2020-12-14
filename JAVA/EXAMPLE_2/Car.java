
public class Car extends Vehicle{
   private int nod;
   public Car(String m,String on,double c,int nd)
   {
	   super(m,on,c);
	   this.nod=nd;
   }  
   @Override
   public double traffic_tax() {
	  return 140+((int)(this.cc-1000.0)/100)*10;
   }
   public String toStr()
   {
	   return this.reg_num+"-"+this.owner+"-"+String.valueOf(this.cc)+"-"+String.valueOf(this.nod);
   }
}
