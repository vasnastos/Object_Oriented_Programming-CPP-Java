package example_project;

import java.util.ArrayList;

import javax.swing.JOptionPane;

public class temperature {
    public static void fillTemp(ArrayList <Integer> low,ArrayList <Integer> up)
    {
    	while(true)
    	{
    		int ltemp=Integer.parseInt(JOptionPane.showInputDialog("Give low Temperature"));
    		int uptemp=Integer.parseInt(JOptionPane.showInputDialog("Give highest temperature:"));
    		if(ltemp==-100 && uptemp==-100)
    		{
                break;    		
    		}
    		if(ltemp>uptemp) continue;
    		low.add(ltemp);
    		up.add(uptemp);
    	}
    	String message="<html><h2><u>Temperature information</u><h2><hr><ul><li>"+String.valueOf(up.size()+low.size())+"</li><li>";
    	int max=Math.abs(up.get(0)-low.get(0));
    	int position=0;
    	for(int i=1,t=low.size();i<t;i++)
    	{
    		if(Math.abs(up.get(i)-low.get(i))>max)
    		{
    			max=Math.abs(up.get(i)-low.get(i));
    			position=i;
    		}
    	}
    	message+="Highest difference Day:"+String.valueOf(position+1)+"</li>";
    	message+="<ul><li>Low Temp:"+String.valueOf(low.get(position))+"</li><li>"+String.valueOf(up.get(position))+"</li></ul>";
    	message+="</ul></html>";
    	JOptionPane.showMessageDialog(null, message);
    }
}
