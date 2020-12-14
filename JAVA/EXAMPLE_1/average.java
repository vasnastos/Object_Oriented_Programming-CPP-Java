import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Vector;

import javax.swing.JOptionPane;

import javafx.util.*;

/*
 A. Κατασκευάστε μια templated συνάρτηση που να δέχεται ένα διάνυσμα Vector και να
επιστρέφει τoν μεσο όρο του διανύσματος. 
1. Για ένα διάνυσμα ακεραίων.
2. Για ένα διάνυσμα με αντικείμενα student (σπουδαστής).
 */

public class max_min {
	private static max_min A=new max_min();
	public class student
	{
		private String name;
		private double grade;
		public student(String n,double g)
		{
			this.name=n;
			this.grade=g;
		}
		public double getGrade()
		{
			return this.grade;
		}
		public String getName()
		{
		   return this.name;
		}
	}
	public static double average(Vector <Integer> vec)
	{
		int sum=vec.get(0);
		for(int i=0,size=vec.size();i<size;i++)
		{
			sum=sum+vec.get(i);
		}
		return (double)(sum)/vec.size();
	}
	public static double average(List <student> students)
	{
		double sum=0.0;
		for(student s:students)
		{
			sum+=s.getGrade();
		}
		sum/=students.size()*1.0;
		return sum;
	}
	public static void initiate(Vector <Integer> numbers,List <student> students)
	{
		String name[]= {"Christos","vasilis","Ioannis","Maria","Katerina","Kostas","Eleni","Nikoleta","Vaggelis"};
		Random r=new Random();
		final int size=r.nextInt(40);
		for(int i=0;i<size;i++)
		{
			numbers.add(r.nextInt(200));
		}
		String n;
		double g;
		for(int i=0;i<size;i++)
		{
			n=name[r.nextInt(name.length)];
			g=r.nextFloat();
			g+=r.nextInt(10);
            while(g>10)
            {
            	g=r.nextFloat();
    			g+=r.nextInt(10);	
            }
			students.add(max_min.A.new student(n, g));
		}
	}
	public static void main(String[] args) {
		List <student> students=new ArrayList<student>();
		Vector <Integer> numbers=new Vector<Integer>();
		max_min.initiate(numbers, students);
		double average1=max_min.average(students);
		double average2=max_min.average(numbers);
		String htmltext="<html><h2>Random Data Results</h2><ul>";
		htmltext+="<li>Average(Students):"+String.format("%.3f",average1)+"</li>";
		htmltext+="<li>Average(Numbers)"+String.format("%.3f",average2)+"</li>";
		htmltext+="</ul></html>";
		JOptionPane.showMessageDialog(null, htmltext);
	}

}
