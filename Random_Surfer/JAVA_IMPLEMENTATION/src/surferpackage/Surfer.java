package surferpackage;

import java.util.Random;
import java.util.Vector;

public class Surfer extends Matrix{
	 final static double DAMPING_FACTOR=0.85;
     private Random ran;
     public Surfer(int r)
     {
    	 super(r);
    	 ran=new Random();
     }
     private int go_to(int currentvertex)
     {
        Vector <Integer> neibourghs=this.getNeibourghs(currentvertex);
        double k=this.ran.nextDouble();
        System.out.println(k);
        if(k<=1-Surfer.DAMPING_FACTOR)
        {
        	int nextpage=ran.nextInt(this.rc);
        	while(nextpage==currentvertex)
        	{
        		nextpage=ran.nextInt(this.rc);
        	}
        	return nextpage;
        }
        else
        {
        	if(neibourghs.size()==0)
        	{
        		return this.ran.nextInt(this.rc);
        	}
        	return neibourghs.get(ran.nextInt(neibourghs.size()));
        }
     }
     public String random_surfer(int visitors,int iters)
     {
    	 int startingpoints[]=new int[visitors];
    	 Vector <navigate> surf=new Vector<navigate>();
    	 int nextpage=-1;
    	 for(int i=0;i<visitors;i++)
    	 {
    		 startingpoints[i]=this.ran.nextInt(this.rc);
    		 this.addVisit(startingpoints[i]);
    	 }
    	 for(int j=0;j<iters;j++)
    	 {
    		 for(int i=0;i<visitors;i++)
    		 {
    			 nextpage=this.go_to(startingpoints[i]);
    			 while(nextpage<0 || nextpage>=this.rc)
    			 nextpage=this.go_to(startingpoints[i]);
    		 	 surf.add(new navigate(i,"Web Page "+String.valueOf(startingpoints[i]),"Web Page "+String.valueOf(nextpage)));
    		     startingpoints[i]=nextpage;
    		     this.addVisit(nextpage);
    		 }
         }
    	 String htmlsource="<html><center><h2>Random Surfer Algo</h2><hr><table border=\"3\">";
    	 htmlsource+="<tr><th>VISITOR</th><th>FROM</th><th>TO</th></tr>";
    	 int counter=0;
    	 for(navigate n:surf)
    	 {
    		 if(counter%visitors==0 && counter!=0)
    		 {
    			 htmlsource+="<tr><td></td><td></td<td></td</tr>";
    		 }
    		 htmlsource+="<tr><td>"+String.valueOf(n.id)+"</td><td>"+n.from+"</td><td>"+n.to+"</td></tr>";
    	     counter++;
    	 }
    	 htmlsource+="</table></center></html>";
    	 counter=0;
    	 for(navigate n:surf)
    	 {
    		 if(counter%visitors==0)
    		 {
    			 System.out.println();
    		 }
    		 System.out.println(n);
    		 counter++;
    	 }
    	 this.rank();
    	 return htmlsource;
     }
}
