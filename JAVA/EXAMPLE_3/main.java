package occurences;

import java.awt.Image;
import java.util.Random;
import java.util.Vector;

import javax.swing.ImageIcon;
import javax.swing.JOptionPane;

public class main {
    public static <T> int occurence(Vector <T> input,T key)
    {
    	int counter=0;
    	for(T x:input)
    	{
    		if(x.equals(key))
    		{
    			counter++;
    		}
    	}
    	return counter;
    }
	public static void main(String[] args) {
		Vector <Integer> numbers=new Vector<Integer>();
		Vector <Double> floatvalues=new Vector<Double>();
		Vector <point> points=new Vector<point>();
		numbers.add(5);
		numbers.add(9);
		numbers.add(5);
		numbers.add(5);
		numbers.add(10);
		numbers.add(4);
		floatvalues.add(0.4);
		floatvalues.add(7.3);
		floatvalues.add(0.4);
		floatvalues.add(0.4);
		floatvalues.add(6.3);
		points.add(new point(2,3));
		points.add(new point(5,6));
		points.add(new point(2,3));
		points.add(new point(2,3));
		points.add(new point(2,8));
		//Randomize Data
		Random r=new Random();
		for(int i=0;i<10;i++)
		{
			numbers.add(r.nextInt(20));
			floatvalues.add(r.nextInt(20)+r.nextDouble());
			points.add(new point(r.nextInt(20),r.nextInt(20)));
		}
		int intoccurences=main.occurence(numbers,5);
		int floatoccurences=main.occurence(floatvalues,0.4);
		int pointoccurence=main.occurence(points,new point(2,3));
		String message="<html><h2 style=\"text-align:center; color:red;\">Results</h2><ul>";
		message+="<hr>";
		message+="<li>For int Values:"+String.valueOf(intoccurences)+"</li>";
		message+="<li>For Double Values:"+String.valueOf(floatoccurences)+"</li>";
		message+="<li>For Points:"+String.valueOf(pointoccurence)+"</li>";
		message+="</ul></html>";
		JOptionPane.showMessageDialog(null,message,"OCCURENCES",JOptionPane.INFORMATION_MESSAGE, new ImageIcon("occurence.png"));
		System.out.println("Row Output");
		System.out.println(message);
	}

}

class point
{
	private int x;
	private int y;
	public point(int x_,int y_)
	{
		this.x=x_;
		this.y=y_;
	}
	@Override
	public boolean equals(Object obj)
	{
		if(obj==null)
		{
			return false;
		}
		else if(this==obj) return true;
		else 
		return this.x==((point)obj).x && this.y==((point)obj).y;
	}
}
