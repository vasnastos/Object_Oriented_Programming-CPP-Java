package car_fill;

import java.util.ArrayList;
import java.util.Vector;

import javax.swing.JOptionPane;

public class car {
   public static void fillBrands(ArrayList <String> names)
   {
	   String a_brand=null;
	   while(true)
	   {
		   a_brand=JOptionPane.showInputDialog("Give brand");
		   if(a_brand.equalsIgnoreCase("none"))
		   {
			   break;
		   }
		   if(a_brand.length()<2) continue;
		   names.add(a_brand);
	   }
	   String message="<html><head><style>table{background-color:gray; color:blue; font-size:14px;} th{background-color:red; color:white; font-size:17px;}</style></head><body><h2>Insertions made:"+String.valueOf(names.size())+"</h2><hr><table border=\"3\"><tr><th>Brand</th><th>Insertions</th></tr>";
	   int counter=0;
	   Vector <String> checked=new Vector<String>();
	   for(String n:names)
	   {
		   counter=0;
		   if(checked.indexOf(n)!=-1) continue;
		   boolean found=false;
		   for(String k:checked)
		   {
			   if(k.equalsIgnoreCase(n))
			   {
				   found=true;
			   }
		   }
		   if(found) continue;
		   for(String l:names)
		   {
			   if(l.equalsIgnoreCase(n))
			   {
				   counter++;
			   }
		   }
		   if(counter>3)
		   {
			   message+="<tr><td>"+n+"</td><td>"+String.valueOf(counter)+"</td></tr>";
		   }
		   checked.add(n);
	   }
	   message+="</table></body></html>";
	   JOptionPane.showMessageDialog(null,message);
   }
}
