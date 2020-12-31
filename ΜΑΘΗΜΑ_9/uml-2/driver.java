import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.swing.JOptionPane;

public class driver {
	private static Random r=new Random();
	private String cities[]= {"Athens","Paris","London","Berlin","Warsaw"};
	private static final int size=4;
    public static String type()
    {
    	return r.nextInt(2)==0?"T1":"T2";
    }
	public static void main(String[] args) {
		List <plane> planes=new ArrayList<plane>();
		List <flight> flights=new ArrayList<flight>();
		for(int i=0;i<size;i++)
		{
			plane p=new plane(("A"+r.nextInt(26))+("A"+r.nextInt())+("A"+r.nextInt())+String.valueOf(r.nextInt()),r.nextInt(),"AZ"+String.valueOf(r.nextInt()));
		    planes.add(p);
		}
		final int size=flight.data.length;
		for(int i=0;i<size;i++)
		{
			flight f=new flight(r.nextInt(),flight.data[i][0],flight.data[i][1],flight.data[i][2]);
			flights.add(f);
		}
		for(int i=0;i<flights.size();i++)
		{
			planes.get(r.nextInt(planes.size()-1)).add_flight(flights.get(i));
		}
		String htmlsource="<html><center><table border=\"3\">";
		htmlsource+="<tr><td>PLANE_NUMBER</td><td>FROM</td><td>TO</td><td>TAIL_ID</td></tr>";
		for(int i=0,t=planes.size();i<t;i++)
		{
			htmlsource+=planes.get(i).display();
			for(flight f:planes.get(i).flights())
			{
				htmlsource+=f.display();
			}
		}
		htmlsource+="</table></center></html>";
		JOptionPane.showMessageDialog(null,htmlsource);
	}

}
