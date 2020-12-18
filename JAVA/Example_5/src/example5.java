import java.awt.Image;
import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JOptionPane;

public class example5 {
   private static HashMap <Account,String> accounts=new HashMap<Account,String>();
   private static  HashMap <String,String> admin=new HashMap<String,String>();
   private static String connectedusername;
   private static boolean isAdmin=false;
   private static example5 A=new example5();
   private static boolean find(String u,String p)
   {
	   if(isAdmin)
	   {	for(String i:admin.keySet())
	   		{
		   		if(i.equals(u) && admin.get(i).equals(p))
		   		{
		   			return true;
		   		}
	   		}
	   }
	   else
	   {
		   for(Account acc:accounts.keySet())
		   {
			   if(acc.getId().equals(u) && accounts.get(acc).equals(p))
			   {
				   return true;
			   }
		   }
	   }
	   return false;
   }
   private static void demo()
   {
	   admin.put("admin","hjkl90");
	   admin.put("sadmin","ityqw21");
	   String codes[]= {"ghj12_t","jhg12er","poi7yr1@","jhgqo98&","vcb12^","lkj1234","789035*","gfd12","1999","2345tyi"};
	   Random r=new Random();
	   for(int i=1;i<=10;i++)
	   {
		   ACCOUNT_TYPE t;
		   switch(r.nextInt(2))
		   {
		       case 0: 
		    	   t=ACCOUNT_TYPE.CHECKING;
		    	   break;
		       case 1:
		    	   t=ACCOUNT_TYPE.SAVINGS;
		    	   break;
		       case 2:
		    	   t=ACCOUNT_TYPE.MONEY_MARKET;
		    	   break;
		       default:
		    	   t=ACCOUNT_TYPE.CHECKING;
		   }
		   accounts.put(A.new Account("id"+String.valueOf(i), r.nextInt(3000)+r.nextDouble()+r.nextInt(2000),t),codes[i-1]);
	   }
   }
   private static void printAccounts()
   {
	   String pass=JOptionPane.showInputDialog("Give "+example5.connectedusername+" password");
	   String message="<html>";
	   if(example5.find(example5.connectedusername, pass))
	   {
		   message+="<h2>List of Accounts</h2><ul><hr>";
		   for(Account acc:accounts.keySet())
		   {
			   message+="<li>Account:"+acc+"</li>";
		   }
	   }
	   else 
	   {
		   message+="<marquee style=\"width=60%; color:red;\">Wrong credentials in order to Sign in Please try again</marquee></html>";
	   }
	   ImageIcon ic=new ImageIcon(new ImageIcon("account.png").getImage().getScaledInstance(60, 60,Image.SCALE_SMOOTH));
	   JOptionPane.showMessageDialog(null,"BANKINFOSYSTEM",message,JOptionPane.OK_OPTION,ic);
   }
	enum  ACCOUNT_TYPE
	{
		CHECKING(2),SAVINGS(2.5),MONEY_MARKET(3.2);
        
		double val;
		ACCOUNT_TYPE(double i) {
			val=i;
		}
		String getPercent()
		{
			return String.valueOf(this.val)+"%";
		}
	}
	public class Account implements Comparable<String>
	{
		private String id;
	    private BigDecimal balance;
	    public ACCOUNT_TYPE type;
	    public Account(String n,double b,ACCOUNT_TYPE t)
	    {
	    	this.id=n;
	    	this.balance=new BigDecimal(b);
	    	this.type=t;
	    }
	    public String getId()
	    {
	    	return this.id;
	    }
	    public double getBalance()
	    {
	    	return this.balance.doubleValue();
	    }
	    public void deposit(double amount)
	    {
	    	double startbalance=this.balance.doubleValue()+amount;
	    	this.balance=new BigDecimal(startbalance);
	    }
	    public void WithDraw(double amount)
	    {
	    	if(this.balance.doubleValue()<amount)
	    	{
	    		JOptionPane.showMessageDialog(null,"You cant withdraw that amount of money");
	    		return;
	    	}
	    	double bal=this.balance.doubleValue()-amount;
	    }
	    String extrapercent()
	    {
	    	return this.type.getPercent();
	    }
		@Override
		public int compareTo(String id) {
			return this.id.compareTo(id);
		}
		@Override
		public String toString()
		{
			return this.id+"-->"+String.format("Balance:%.3f",this.balance.doubleValue())+"::"+this.type.getPercent();
		}
	}
	public static int menu()
	{
		String mes="<html><h3>Bank Menu</h2>";
		mes+="<b>1-Deposit</b><br><b>2-WithDraw</b><br><b>3-Show Balance</b><br><b>4-Exit</b><br><hr></html>";
	    String value=JOptionPane.showInputDialog(mes);
	    return Integer.parseInt(value);
	}
	public static boolean signin()
	{
		String username=JOptionPane.showInputDialog("<html><h3>Give your username</h3></html>");
		String password=JOptionPane.showInputDialog("<html><h3>Give your password</h3></html>");
		example5.connectedusername=username;
		return example5.find(username, password);
	}
	public static int userswitch()
	{
		String message="<html><h2>Check User</h2><hr><ul>";
		message+="<li>1-User</li>";
		message+="<li>2-Admin</li>";
		String input=JOptionPane.showInputDialog(message);
		return Integer.parseInt(input);
	}
	public static void transactions(int action)
	{
		double withdraw[]= {20,40,80,100,120};
		for(Account acc:accounts.keySet())
		{
			if(acc.compareTo(example5.connectedusername)==0)
			{
				if(action==1)
			    {
				   double price=Double.parseDouble(JOptionPane.showInputDialog("Give amount of money you want to insert into your account"));
				   acc.deposit(price);
			    }
				else if(action==2)
				{
					String message="<html><h3>Select withdraw amount</h3><hr>";
					message+="<i>1-20          4-100<br>2-40          5-120<br>3-80          6-Cancel</i></html>";
					int amount=Integer.parseInt(JOptionPane.showInputDialog(message));
					if(amount==6)
					{
						return;
					}
					else
						acc.WithDraw(withdraw[amount-1]);
				}
				else if(action==3)
				{
					String message="<html><h3>Your Balance:"+String.format("%.3f", acc.getBalance())+"<h3></html>";
					JOptionPane.showMessageDialog(null, message);
				}
			}
		}
		
	}
	public static void centralMenu()
	{
		int action;
		int choice=example5.userswitch();
		switch(choice)
		{
		case 1:
			example5.isAdmin=false;
			if(example5.signin())
			{
				while(true)
				{
					action=example5.menu();
					if(action==4)
					{
						example5.connectedusername="";
					}
					else
					{
						example5.transactions(action);
					}
					String option=JOptionPane.showInputDialog("Execute another transaction");
					if(!option.equalsIgnoreCase("yes"))
					{
						break;
					}
				}
			}
			else
			{
				JOptionPane.showMessageDialog(null,"ERROR","Wrong Credentials Please Try again",JOptionPane.ERROR_MESSAGE);
			}
			break;
		case 2:
			example5.isAdmin=true;
			if(example5.signin())
				example5.printAccounts();
			else
			{
				JOptionPane.showMessageDialog(null,"ERROR","Wrong Credentials Please Try again",JOptionPane.ERROR_MESSAGE);
			}
			break;
		}
	}
	public static void main(String[] args) {
		while(true)
		{
			example5.demo();
			example5.centralMenu();
		}
	}

}
