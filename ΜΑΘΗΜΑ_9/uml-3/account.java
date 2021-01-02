import java.math.BigDecimal;

public class account {
  private String name;
  private BigDecimal balance;
  public account(String n,double d)
  {
	  this.name=n;
	  this.balance=new BigDecimal(d);
  }
  public double get_balance()
  {
	  return this.balance.doubleValue();
  }
  public void deposit(double am)
  {
	  double bal=this.balance.doubleValue()+am;
	  this.balance=new BigDecimal(bal);
  }
  public void withdraw(double am)
  {
	  double bal=this.balance.doubleValue()-am;
	  if(bal<0)
	  {
		  System.err.format("Unacceptable exchange!!!");
		  return;
	  }
	  this.balance=new BigDecimal(bal);
  }
  public String info()
  {
	  return "<tr><td>"+this.name+"</td><td>"+String.format("%.3f",this.balance.doubleValue())+"</td></tr>";
  }
}
