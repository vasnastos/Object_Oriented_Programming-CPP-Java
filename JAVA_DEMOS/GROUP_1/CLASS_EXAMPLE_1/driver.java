import java.util.*;
public class driver
{
    public static void Main(String args[])
    {
        ArrayList <student> students=new ArrayList<student>();
		Random R=new Random(System.currentTimeMillis());
		for(int i=1;i<=10;i++)
		{
			student s=new student();
			s.setName("student_"+String.valueOf(i));
			s.setLastName("student_ln_"+String.valueOf(i));
			s.setId(String.valueOf(R.nextInt(20000)));
			s.setSemester(R.nextInt(16)+1);
			s.setUName("University_"+String.valueOf(R.nextInt(10000)));
			students.add(s);
		}
		String msg="<html><h2>Students</h2><hr><ul>";
		for(student s:students)
		{
			msg+="<li>"+s+"</li>";
		}
		msg+="</ul></html>";
		JOptionPane.showMessageDialog(null, msg);
    }
}