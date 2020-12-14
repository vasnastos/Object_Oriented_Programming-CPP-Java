import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import javax.swing.JOptionPane;

public class main {
    public static void print(List <Vehicle> vehicles)
    {
    	String htmlmessage="<html><body style=\"font-family:calibri;\"><h2 style=\"text-align:center; color:red\">List of Vehicles<h2><hr><ul>";
    	for(int i=0,t=vehicles.size();i<t;i++)
    	{
    		htmlmessage+="<li>"+vehicles.get(i).toStr()+"::Traffic Taxes:"+String.valueOf(vehicles.get(i).traffic_tax())+"</li>";
    	}
    	htmlmessage+="<hr>Total Taxes:"+String.valueOf(main.traffic_taxes(vehicles));
    	htmlmessage+="</ul></body></html>";
    	JOptionPane.showMessageDialog(null,htmlmessage);
    }
    public static void print_command(List <Vehicle> v)
    {
    	System.out.println("\t\tList of Vehicles");
    	System.out.println("=========================================================");
    	for(Vehicle d:v)
    	{
    		System.out.println(d.toStr());
    	}
    }
    public static void insertVehicle(List <Vehicle> v)
    {
    	String name,reg;
    	int nod;
    	double mw,c;
    	Scanner sc=new Scanner(System.in);
    	System.out.print("Select type(Car-c/Truck-t):");
   	    String choice=JOptionPane.showInputDialog(null,"Select Car(c)/Truck(t):");
   	while(choice!="c" && choice!="C" && choice!="t" && choice!="T")
	 {
   		choice=JOptionPane.showInputDialog(null,"Select Car(c)/Truck(t):");
	 }
	 if(choice.equals("c") || choice.equals("C"))
	 {
		 reg=JOptionPane.showInputDialog(null,"Give registration number  of car:");
		 name=JOptionPane.showInputDialog(null,"Give owner name of car:");
		 c=Double.parseDouble(JOptionPane.showInputDialog(null,"Give CC of car:"));
		 nod=Integer.parseInt(JOptionPane.showInputDialog(null,"Give number of doors of the car:"));
		 v.add(new Car(reg,name,c,nod));
	 }
	 else if(choice.equalsIgnoreCase("t"))
	 {
		 reg=JOptionPane.showInputDialog("Give registration number  of Truck:");
		 name=JOptionPane.showInputDialog("Give owner name of Truck:");
		 c=Double.parseDouble(JOptionPane.showInputDialog("Give CC of Truck:"));
		 mw=Double.parseDouble(JOptionPane.showInputDialog("Give weight of Truck:"));
		 v.add(new Truck(reg,name,c,mw));
	 }
    }
    public static void menu(List <Vehicle> v)
    {
    	Scanner sc=new Scanner(System.in);
    	int choice;
    	while(true)
    	{	
    	 System.out.println("\nVehicles Loaded!!!");
    	 System.out.println("=================================================");
    	 System.out.println("1-Give another Vehicle");
    	 System.out.println("2-Show Vehicles");
    	 System.out.println("3-Show Detail window");
    	 System.out.println("4-Exit App");
    	 System.out.print("Give choice:");
    	 choice=sc.nextInt();
    	 switch(choice)
    	 {
    	 case 1:
    		 main.insertVehicle(v);
    		 break;
    	 case 2:
    		 main.print_command(v);
    		 break;
    	 case 3:
    		 main.print(v);
    		 break;
    	 case 4:
    		 System.exit(0);
    		 break;
    	 }
    	}
    }
	public static double traffic_taxes(List <Vehicle> vehicles)
	{
		double summary=0.0;
		for(Vehicle v:vehicles)
		{
			summary+=v.traffic_tax();
		}
		return summary;
	}
	public static void main(String[] args) {
		List <Vehicle> vehicles=new ArrayList<Vehicle>();
         String name;
         String reg;
         double c;
         int nod;
         double mw;
         String choice;
         for(int i=0;i<5;i++)
         {
        	 choice=JOptionPane.showInputDialog(null,"Select Car(c)/Truck(t):");
        	 if(choice.equals("c") || choice.equals("C"))
        	 {
        		 reg=JOptionPane.showInputDialog(null,"Give registration number  of car:");
        		 name=JOptionPane.showInputDialog(null,"Give owner name of car:");
        		 c=Double.parseDouble(JOptionPane.showInputDialog(null,"Give CC of car:"));
        		 nod=Integer.parseInt(JOptionPane.showInputDialog(null,"Give number of doors of the car:"));
        		 vehicles.add(new Car(reg,name,c,nod));
        	 }
        	 else if(choice.equalsIgnoreCase("t"))
        	 {
        		 reg=JOptionPane.showInputDialog("Give registration number  of Truck:");
        		 name=JOptionPane.showInputDialog("Give owner name of Truck:");
        		 c=Double.parseDouble(JOptionPane.showInputDialog("Give CC of Truck:"));
        		 mw=Double.parseDouble(JOptionPane.showInputDialog("Give weight of Truck:"));
        		 vehicles.add(new Truck(reg,name,c,mw));
        	 }
        	 else
        	 {
        		 while(!choice.equalsIgnoreCase("c") && !choice.equalsIgnoreCase("t"))
        		 {
        			 choice=JOptionPane.showInputDialog(null,"Select Car(c)/Truck(t):");
        		 }
        	 }
         }
     	main.menu(vehicles);
	}

}
