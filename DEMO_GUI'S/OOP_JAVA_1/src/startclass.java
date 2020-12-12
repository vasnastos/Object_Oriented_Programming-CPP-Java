import java.util.Scanner;

public class startclass {
    final static int size=5;
	public static void main(String[] args) {
		cargo cargos[]=new cargo[5];
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<size;i++)
        {
        	System.out.print("Give cargo's id:");
        	int id=sc.nextInt();
        	System.out.print("Give cargo's destination:");
        	sc=new Scanner(System.in);
        	String des=sc.nextLine();
        	System.out.print("Give cargo's weight:");
        	double wgh=sc.nextDouble();
        	System.out.print("Is fragile(1/no,0/yes):");
        	int frg=sc.nextInt();
        	boolean fr;
        	if(frg==0)
        	{
        		fr=true;
        	}
        	else
        	{
        		fr=false;
        	}
        	cargos[i]=new cargo(id,des,wgh,fr);
        }
        for(int i=0;i<size;i++)
        {
        	cargos[i].show();
        }
        for(int i=0;i<size;i++)
        {
        	cargos[i].make_safe();
        }
        System.out.println("");
        for(int i=0;i<size;i++)
        {
        	cargos[i].show();
        }
	}
}
