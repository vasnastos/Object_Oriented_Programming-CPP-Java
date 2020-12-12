package company;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class MyFrame extends JFrame{
   JPanel p1,p2;
   List <employee> employees=new ArrayList<employee>();
   JComboBox <String> deps=new JComboBox<String>();
   void panel1()
   {
	   p1=new JPanel();
	   p1.setLayout(new FlowLayout());
	   final int width=this.getWidth();
	   JTextField name=new JTextField(5);
	   name.setToolTipText("Employee Name");
	   JTextField code=new JTextField(5);
	   code.setToolTipText("Employee's code");
	   JTextField dep=new JTextField(5);
	   dep.setToolTipText("Department's id");
	   JTextField sal=new JTextField(5);
	   sal.setToolTipText("Employee's salary");
	   JButton but=new JButton("ADD");
	   but.addActionListener(new ActionListener()
	   {
		   public void actionPerformed(ActionEvent e)
		   {
			   if(name.getText().length()==0 || code.getText().length()==0 || dep.getText().length()==0 || sal.getText().length()==0)
			   {
				   JOptionPane.showMessageDialog(null,"Fill all the blanks");
				   return;
			   }
			   for(employee e1:employees)
			   {
				   if(e1.get_code().equals(code.getText()) && e1.get_department_id().equals(dep.getText()))
				   {
					   JOptionPane.showMessageDialog(null, "Employee already exists in the list");
					   return;
				   }
			   }
			   employee emp=new employee(name.getText(),code.getText(),dep.getText(),Double.parseDouble(sal.getText()));
			   employees.add(emp);
			   for(int i=0;i<deps.getItemCount();i++)
			   {
				   if(deps.getItemAt(i).equals(emp.get_department_id()))
				   {
					   return;
				   }
			   }
			   deps.addItem(emp.get_department_id());
		   }
	   });
	   p1.add(name);
	   p1.add(code);
	   p1.add(dep);
	   p1.add(sal);
	   p1.add(but);
	   this.add(p1);
   }
   void panel2()
   {
	   p2=new JPanel();
	   p2.setLayout(new FlowLayout());
	   JButton search=new JButton();
	   search.setText("SEARCH");
	   search.setBorder(BorderFactory.createLineBorder(Color.BLACK));
	   search.setForeground(Color.RED);
	   search.addActionListener(new ActionListener()
	   {
		   public void actionPerformed(ActionEvent e)
		   {
			   String src=deps.getSelectedItem().toString();
			   String message="<html><h3 style=text-align:center; color:red;>DEP RESULTS</h3><hr><ul>";
			   for(employee emp:employees)
			   {
				   if(emp.get_department_id().equals(src))
				   {
					   message+="<li>"+emp.to_String()+"</li>";
				   }
			   }
			   message+="</ul></html>";
			   JOptionPane.showMessageDialog(null, message);
		   }
	   });
	   JButton exp=new JButton("EXPORT");
	   exp.setBorder(BorderFactory.createLineBorder(Color.BLACK));
	   exp.setForeground(Color.RED);
	   exp.addActionListener(new ActionListener()
	   {
		   public void actionPerformed(ActionEvent e)
		   {
			   String comp=deps.getSelectedItem().toString();
			   JFileChooser ch=new JFileChooser();
			   int retval=ch.showSaveDialog(MyFrame.this);
			   if(retval==JFileChooser.APPROVE_OPTION)
			   {
				   String fn=ch.getSelectedFile().getAbsolutePath();
				   FileWriter fw;
				try {
					fw = new FileWriter(fn);
					PrintWriter pw=new PrintWriter(fw);
					pw.println("      Department:"+comp+"      ");
					pw.println("---------------------------------------------------------------------");
					for(employee emp:employees)
					{
						if(emp.get_department_id().equals(comp))
						{
							pw.println(emp.to_String());
						}
					}
					pw.println("---------------------------------------------------------------------");
					pw.close();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			   }
		   }
	   });
	   p2.add(deps);
	   p2.add(search);
	   p2.add(exp);
	   this.add(p2);
   }
   void make_menu()
   {
	   JMenuBar bar=new JMenuBar();
	   this.setJMenuBar(bar);
	   JMenu menu=new JMenu("OPTIONS");
	   JMenuItem ld=new JMenuItem("LOAD");
	   ld.setIcon(new ImageIcon(new ImageIcon("upload.png").getImage().getScaledInstance(20,20,Image.SCALE_SMOOTH)));
	   JMenuItem qt=new JMenuItem("QUIT");
	   qt.setIcon(new ImageIcon(new ImageIcon("quit.png").getImage().getScaledInstance(20,20,Image.SCALE_SMOOTH)));
	   ld.addActionListener(new ActionListener()
	   {
		   public void actionPerformed(ActionEvent e)
		   {
			   JFileChooser ch=new JFileChooser();
			   int retval=ch.showOpenDialog(MyFrame.this);
			   if(retval==JFileChooser.APPROVE_OPTION)
			   {
				   String fn=ch.getSelectedFile().getAbsolutePath();
				   try {
					FileReader fr=new FileReader(fn);
					Scanner sc=new Scanner(fr);
					while(sc.hasNextLine())
					{
						String line=sc.nextLine();
						String data[]=line.split(",");
						if(data.length!=4)
						{
							continue;
						}
						employee emp=new employee(data[0],data[1],data[2],Double.parseDouble(data[3]));
						boolean found=false;
						for(employee check:employees)
						{
							if(check==emp)
							{
								JOptionPane.showMessageDialog(MyFrame.this,"employee already exists in the list");
								found=true;
								break;
							}
						}
						if(!found) {employees.add(emp);}
					}
					sc.close();
				} catch (FileNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			   }
		   }
	   });
	   qt.addActionListener(new ActionListener()
	   {
		   public void actionPerformed(ActionEvent e)
		   {
			   System.exit(0);
		   }
	   });
	   menu.add(ld);
	   menu.add(qt);
	   bar.add(menu);
   }
public MyFrame()
{
	this.setSize(400,200);
	this.setResizable(false);
	this.setTitle("Employees Form");
	this.setLayout(new GridLayout(0,1));
    make_menu();
	panel1();
    panel2();
	this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	this.setVisible(true);
}
}