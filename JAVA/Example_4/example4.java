
import java.util.*;

import javax.swing.JOptionPane;

public class example4 {
    private static example4 A=new example4();
    public static void ImportDialog(String input)
    {
    	int op=JOptionPane.showConfirmDialog(null,"Show MessageBoxData" , "Show Message Data",JOptionPane.INFORMATION_MESSAGE,JOptionPane.YES_NO_OPTION);
	    if(op==JOptionPane.YES_OPTION)
	    {
	    	JOptionPane.showMessageDialog(null, input);
	    }
    }
	public static void main(String[] args) {
		Random r=new Random();
		Integernum in=A.new Integernum();
		doublenum din=A.new doublenum();
		for(int i=0;i<13;i++)
		{
			in.add(r.nextInt(45));
			din.add(r.nextInt(87)+r.nextDouble());
		}
		String input=JOptionPane.showInputDialog("Select:\n 1-Integers \n2-Floats");
		input=input.equals("1")?in.Show():din.Show();
		ImportDialog(input);
		System.out.println("\t\tImplementation of Interface");
		System.out.println("=======================================================");
		System.out.println("\t\tIntegers board");
		System.out.println("Max:"+String.valueOf(in.max_element()));
		System.out.println("Min:"+String.valueOf(in.min_element()));
		System.out.println("Average:"+String.format("%.3f",in.average()));
		System.out.println("========================================================\n");
		System.out.println("********************************************************");
		System.out.println("\t\tDouble's board");
		System.out.println("Max:"+String.format("%.3f",din.max_element()));
		System.out.println("Min:"+String.format("%.3f",din.min_element()));
		System.out.println("Average:"+String.format("%.3f",din.average()));
		System.out.println("********************************************************");
	}

public <T>String show(List <T> nums)
{
	String message="";
	message+="<html><h2>Contents</h2><hr><ul>";
	for(T x:nums)
	{
		message+="<li>"+String.valueOf(x)+"</li>";
	}
	message+="</ul></html>";
	return message;
}

interface number<T>
{
  void add(T x);
  T max_element();
  T min_element();
  double average();
}

public class Integernum implements number
{
    private List <Integer> numbers=new ArrayList<Integer>();
	@Override
	public Object max_element() {
		int max=numbers.get(0);
		for(Integer r:numbers)
		{
			if(r>max)
			{
				max=r;
			}
		}
		return max;
	}

	@Override
	public Object min_element() {
		int min=numbers.get(0);
		for(Integer r:numbers)
		{
			min=Math.min(min,r);
		}
		return min;
	}

	@Override
	public double average() {
		Integer summary=0;
		for(Integer r:numbers)
		{
			summary+=r;
		}
		return (double)summary/this.numbers.size();
	}
	public String Show()
	{
		return show(this.numbers);
	}

	@Override
	public void add(Object x) {
		this.numbers.add(Integer.parseInt(String.valueOf(x)));
	}
  }
class doublenum implements number
{
	private List <Double> numbers=new ArrayList<Double>();

	@Override
	public void add(Object x) {
        this.numbers.add(Double.parseDouble(String.valueOf(x)));
	}

	@Override
	public Object max_element() {
		double max=numbers.get(0);
		for(Double r:numbers)
		{
			if(r>max)
			{
				max=r;
			}
		}
		return max;
	}

	@Override
	public Object min_element() {
		double min=numbers.get(0);
		for(Double r:this.numbers)
		{
			min=Math.min(min,r);
		}
		return min;
	}

	@Override
	public double average() {
		double summary=0;
		for(Double r:numbers)
		{
			summary+=r;
		}
		return summary/this.numbers.size();
	}
	public String Show()
	{
		return show(this.numbers);
	}
	
}
}
