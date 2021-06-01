import java.util.*;
import java.util.Random;

import javax.swing.JOptionPane;

public class driver {
	public static void main(String[] args) {
		Random r=new Random();
        List <document> docs=new ArrayList<document>();
        final int total=r.nextInt(50);
        int choice;
        int days,months,years;
        for(int i=0;i<total;i++)
        {
        	choice=r.nextInt(2);
        	final int authors=r.nextInt(10);
        	months=r.nextInt(12)+1;
        	days=r.nextInt(31)+1;
        	years=r.nextInt(10)+2010;
        	String date=String.valueOf(days)+"/"+String.valueOf(months)+"/"+String.valueOf(years);
        	switch(choice)
        	{
        	   case 0:
        		   
        		   book b=new book(date,"title "+String.valueOf(i+1));
        		   for(int j=0;j<authors;j++)
        		   {
        			   b.add_author("author"+String.valueOf(j));
        		   }
        		   docs.add(b);
        		   break;
        	    case 1:
        	    	email e=new email(date,"sender "+String.valueOf(i),"subject "+String.valueOf(r.nextInt()));
        	    	final int rec=r.nextInt(10);
        	    	for(int j=0;j<authors;j++)
         		   {
         			   e.add_author("author"+String.valueOf(j));
         		   }
        	       for(int j=0;j<rec;j++)
         		   {
         			   e.add_recipient("recipient "+String.valueOf(j+1));
         		   }
        	       docs.add(e);
        	       break;
        	}
        }
        	while(true)
        	{
        		String menu="<html><center><h3>Options</center></h3>";
        		menu+="<li>1-Documents</li>";
        		menu+="<li>2-Exit</li>";
        		menu+="</ul></html>";
        		int op=Integer.parseInt(JOptionPane.showInputDialog(menu));
        		if(op==2)
        		{
        			System.exit(0);
        		}
        		String opt="<html><h3><center>Select Doc</h3>";
        		opt+="<hr><ul>";
        		for(int k=0,t=docs.size();k<t;k++)
        		{
        			opt+="<li>"+String.valueOf(k+1)+"-Document</li>";
        		}
        		opt+="</ul></html>";
        		int showid=Integer.parseInt(JOptionPane.showInputDialog(opt));
        		JOptionPane.showMessageDialog(null,docs.get(showid-1).info());
        	}
	}

}
