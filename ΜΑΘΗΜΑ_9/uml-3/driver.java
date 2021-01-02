import java.util.*;

import javax.swing.JOptionPane;

public class driver {
	private static Random r=new Random();
	public static String nameCreator()
	{
		int letters=r.nextInt(20);
		while(letters<4)
		{
			letters=r.nextInt(20);
		}
		int choice;
		String name="";
		for(int i=0;i<letters;i++)
		{
			choice=r.nextInt(2);
			switch(choice)
			{
			case 0:
				name+='a'+r.nextInt(26);
				break;
			case 1:
				name+="A"+r.nextInt(26);
			}
		}
		return name;
	}
	public static String show(List <account> accs)
	{
		String html="<html><center><table border=\"3\" style=\"background-color:#e0edbb; color:red; font-size:15px; text-decoration:none;\"><tr><td>NAME</td><td>BALANCE</td></tr>";
		for(account a:accs)
		{
			html+=a.info();
		}
		html+="</table></center></html>";
		return html;
	}
	public static void Transactions(List <account> accs)
	{
		int number=r.nextInt(30);
		int choice;
		while(number<5)
		{
	      number=r.nextInt(30);
		}
		for(int i=0;i<number;i++)
		{
			choice=r.nextInt(2);
			switch(choice)
			{
			case 0:
				accs.get(r.nextInt(accs.size())).withdraw(r.nextDouble()+r.nextInt(800));
				break;
			case 1:
				accs.get(r.nextInt(accs.size())).deposit(r.nextDouble()+r.nextInt(800));
				break;
			}
		}
	}
    final static int SIZE=20;
	public static void main(String[] args) {
         List <account> accounts=new ArrayList<account>();
         for(int i=0;i<driver.SIZE;i++)
         {
        	 accounts.add(new account(driver.nameCreator(),r.nextInt(5000)+r.nextDouble()));
         }
         String show=driver.show(accounts);
         JOptionPane.showMessageDialog(null,show);
         driver.Transactions(accounts);
         JOptionPane.showMessageDialog(null,show);
	}

}
