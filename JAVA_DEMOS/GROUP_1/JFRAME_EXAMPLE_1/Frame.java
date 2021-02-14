package example_project;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class Frame extends JFrame{
  private JButton loadbutton;
  private JTextArea showarea;
  public Frame()
  {
	  this.setSize(300,300);
	  this.setTitle("Thema");
	  this.setLayout(new FlowLayout(FlowLayout.CENTER));
	  this.loadbutton=new JButton();
	  this.loadbutton.setText("Load");
	  this.showarea=new JTextArea();
	  this.showarea.setSize((int)(0.99*this.getWidth()),(int)(0.5*this.getHeight()));
	  this.showarea.setBorder(BorderFactory.createLineBorder(Color.blue));
	  this.loadbutton.addActionListener(new ActionListener()
	  {
		  @Override
		  public void actionPerformed(ActionEvent ae)
		  {
			  JFileChooser ch=new JFileChooser();
			  int rval=ch.showOpenDialog(null);
			  if(rval==JFileChooser.APPROVE_OPTION)
			  {
				  String filename=ch.getSelectedFile().getAbsolutePath();
				  FileReader fr=null;
				try {
					fr = new FileReader(filename);
				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				  BufferedReader br=new BufferedReader(fr);
				  String max_lastname=null;
				  double maxsalary=0.0;
				  try {
					String line=br.readLine();
					String data[]=line.split(",");
					max_lastname=data[0];
					maxsalary=Double.parseDouble(data[1])-(Double.parseDouble(data[1])*Double.parseDouble(data[2])/100.0);
					line=br.readLine();
					while(line!=null)
					{
						data=line.split(",");
						if(data.length!=3) continue;
						double mx=Double.parseDouble(data[1])-(Double.parseDouble(data[1])*Double.parseDouble(data[2])/100.0);
						if(mx>maxsalary)
						{
							maxsalary=mx;
							max_lastname=data[0];
						}
						line=br.readLine();
					}
					br.close();
					fr.close();
				} catch (IOException e) {
					JOptionPane.showMessageDialog(null,"<html><h2 style=\"color:blue;\">Error on opening the file</h2></html>");
				}
				String message="<html><div><h2>";
				if(maxsalary>2000.0)
				{
					message+="*"+max_lastname+"</h2><h4>Salary:"+String.valueOf(maxsalary)+"</h4></div></html>";
				}
				else
				{
					message+=max_lastname+"</h2><h4>Salary:"+String.valueOf(maxsalary)+"</h4></div></html>";
				}
				Frame.this.showarea.setText(message);
			  }
		  }
	  });
	  this.add(this.loadbutton);
	  this.add(this.showarea);
	  this.setResizable(false);
	  this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	  this.setVisible(true);
  }
}
