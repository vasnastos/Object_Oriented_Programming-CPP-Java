package car_fill;

public class stracture {
   private String kind;
   private double meters;
   private String region;
   private double price;
   public void setKind(String k)
   {
	   this.kind=k;
   }
   public final String getKind()
   {
	   return this.kind;
   }
   public void setMeters(double m)
   {
	   this.meters=m;
   }
   public final double getMeters()
   {
	   return  this.meters;
   }
   public void setRegion(String r)
   {
	   this.region=r;
   }
   public final String getRegion()
   {
	   return this.region;
   }
   public void setPrice(double p)
   {
	   this.price=p;
   }
   public final double getPrice()
   {
	   return this.price;
   }
   @Override
   public String toString()
   {
	   return this.kind+"-"+String.format("%.3f",this.meters)+"m^2-"+this.region+"-"+String.format("%.3f",this.price)+"$";
   }
}
