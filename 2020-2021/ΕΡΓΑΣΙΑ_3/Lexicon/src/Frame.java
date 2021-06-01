import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.Vector;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.ScrollPaneConstants;

public class Frame extends JFrame{
   private Lexicon l;
   private JPanel p1,p2,p3,p4,p5;
   private void panel1()
   {
	   p1=new JPanel();
	   p1.setLayout(new GridLayout(0,3,5,5));
	   JLabel l1=new JLabel();
	   l1.setSize(new Dimension((int)(0.3*this.getWidth()),(int)(0.1*this.getHeight())));
	   l1.setAutoscrolls(true);
	   l1.setBorder(BorderFactory.createLineBorder(Color.red));
	   l1.setText("Search By Size");
	   l1.setForeground(Color.blue);
	   JTextField f1=new JTextField(5);
	   f1.setBorder(BorderFactory.createLineBorder(Color.red));
	   JButton b1=new JButton("SEARCH");
	   b1.addActionListener(new ActionListener()
	   {
		   @Override
		   public void actionPerformed(ActionEvent ae)
		   {
			   int sz=Integer.parseInt(f1.getText());
			   Vector <String> words=l.equal(sz);
			   JOptionPane.showMessageDialog(null,"File Opened:"+l.getFileName()+"<br><hr>Words Size:"+String.valueOf(words.size()));
			   int option=JOptionPane.showConfirmDialog(null,"Show Records" ,"Total Records",JOptionPane.YES_NO_OPTION);
			   if(option==JOptionPane.YES_OPTION)
			   {
				   String message="<html>Words with size "+String.valueOf(sz)+":"+String.valueOf(words.size());
				   message+="<p style=color:red>List of Words!!!</p><ul>";
			       for(String x:words)
			       {
			    	   message+="<li>"+x+"</li>";
			       }
			       message+="</ul></html>";
			       JEditorPane tx=new JEditorPane();
			       tx.setText(message);
			       tx.setSize((int)(0.4*Frame.this.getWidth()),(int)(0.4*Frame.this.getHeight()));
			       tx.setContentType("text/html");
			       JScrollPane sp = new JScrollPane(tx);
			       sp.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
			       JOptionPane.showMessageDialog(null,sp);
			   }
		   }
	   });
	   p1.add(l1);
	   p1.add(f1);
	   p1.add(b1);
	   this.add(p1);
   }
   private void panel2()
   {
	   p2=new JPanel();
	   p2.setLayout(new GridLayout(0,3,5,5));
	   JLabel l1=new JLabel();
	   l1.setSize(new Dimension((int)(0.3*this.getWidth()),(int)(0.1*this.getHeight())));
	   l1.setAutoscrolls(true);
	   l1.setBorder(BorderFactory.createLineBorder(Color.red));
	   l1.setText("Search By Start Word");
	   l1.setForeground(Color.blue);
	   JTextField f1=new JTextField(5);
	   f1.setBorder(BorderFactory.createLineBorder(Color.red));
	   JButton b1=new JButton("SEARCH");
	   b1.addActionListener(new ActionListener()
	   {
		   @Override
		   public void actionPerformed(ActionEvent ae)
		   {
			   if(f1.getText().isEmpty()) 
			   {
				   JOptionPane.showMessageDialog(null,"File Saerch gap");
				   return;
			   }
			   Vector <String> words=l.startswith(f1.getText());
			   JOptionPane.showMessageDialog(null,"File Opened:"+l.getFileName()+"<br><hr>Words Size:"+String.valueOf(words.size()));
			   int option=JOptionPane.showConfirmDialog(null,"Show Records" ,"Total Records",JOptionPane.YES_NO_OPTION);
			   if(option==JOptionPane.YES_OPTION)
			   {
				   String message="<html>Words with "+f1.getText()+":"+String.valueOf(words.size());
				   message+="<p style=color:red>List of Words!!!</p><ul>";
			       for(String x:words)
			       {
			    	   message+="<li>"+x+"</li>";
			       }
			       message+="</ul></html>";
			       JOptionPane.showMessageDialog(null,message);
			   }
		   }
	   });
	   p2.add(l1);
	   p2.add(f1);
	   p2.add(b1);
	   this.add(p2);
   }
   private void panel3()
   {
	   p3=new JPanel();
	   p3.setLayout(new GridLayout(0,3,5,5));
	   JLabel l1=new JLabel();
	   l1.setSize(new Dimension((int)(0.3*this.getWidth()),(int)(0.1*this.getHeight())));
	   l1.setAutoscrolls(true);
	   l1.setBorder(BorderFactory.createLineBorder(Color.red));
	   l1.setText("Search By EndString");
	   l1.setForeground(Color.blue);
	   JTextField f1=new JTextField(5);
	   f1.setBorder(BorderFactory.createLineBorder(Color.red));
	   JButton b1=new JButton("SEARCH");
	   b1.addActionListener(new ActionListener()
	   {
		   @Override
		   public void actionPerformed(ActionEvent ae)
		   {
			   if(f1.getText().isEmpty())
			   {
				   JOptionPane.showMessageDialog(null, "Fill all the blanks");
				   return;
			   }
			   Vector <String> words=l.endswith(f1.getText());
			   JOptionPane.showMessageDialog(null,"File Opened:"+l.getFileName()+"<br><hr>Words Size:"+String.valueOf(words.size()));
			   int option=JOptionPane.showConfirmDialog(null,"Show Records" ,"Total Records",JOptionPane.YES_NO_OPTION);
			   if(option==JOptionPane.YES_OPTION)
			   {
				   String message="<html>Words ends with "+f1.getText()+":"+String.valueOf(words.size())+"<br>";
				   message+="<p style=color:red>List of Words!!!</p><ul>";
			       for(String x:words)
			       {
			    	   message+="<li>"+x+"</li>";
			       }
			       message+="</ul></html>";
			       JOptionPane.showMessageDialog(null,message);
			   }
		   }
	   });
	   p3.add(l1);
	   p3.add(f1);
	   p3.add(b1);
	   this.add(p3);
   }
   private void panel4()
   {
	   p4=new JPanel();
	   p4.setLayout(new GridLayout(0,3,5,5));
	   JLabel l1=new JLabel();
	   l1.setSize(new Dimension((int)(0.3*this.getWidth()),(int)(0.1*this.getHeight())));
	   l1.setAutoscrolls(true);
	   l1.setBorder(BorderFactory.createLineBorder(Color.red));
	   l1.setText("Search By Word show frequency");
	   l1.setForeground(Color.blue);
	   JTextField f1=new JTextField(5);
	   f1.setBorder(BorderFactory.createLineBorder(Color.red));
	   JButton b1=new JButton("SEARCH");
	   b1.addActionListener(new ActionListener()
	   {
		   @Override
		   public void actionPerformed(ActionEvent ae)
		   {
			   if(f1.getText().isEmpty())
			   {
				   JOptionPane.showMessageDialog(null, "Fill all the blanks");
				   return;
			   }
			   int frequency=Integer.parseInt(JOptionPane.showInputDialog("Give number of word shows"));
			   Vector <String> words=l.replay(f1.getText(),frequency);
			   JOptionPane.showMessageDialog(null,"File Opened:"+l.getFileName()+"<br><hr>Words Size:"+String.valueOf(words.size()));
			   int option=JOptionPane.showConfirmDialog(null,"Show Records" ,"Total Records",JOptionPane.YES_NO_OPTION);
			   if(option==JOptionPane.YES_OPTION)
			   {
				   String message="<html>Words ends with "+f1.getText()+":"+String.valueOf(words.size())+"<br>";
				   message+="<p style=color:red>List of Words!!!</p><ul>";
			       for(String x:words)
			       {
			    	   message+="<li>"+x+"</li>";
			       }
			       message+="</ul></html>";
			       JOptionPane.showMessageDialog(null,message);
			   }
		   }
	   });
	   p4.add(l1);
	   p4.add(f1);
	   p4.add(b1);
	   this.add(p4);
   }
   private void panel5()
   {
	   p5=new JPanel();
	   p5.setLayout(new GridLayout(0,3,5,5));
	   JLabel l1=new JLabel();
	   l1.setSize(new Dimension((int)(0.3*this.getWidth()),(int)(0.1*this.getHeight())));
	   l1.setAutoscrolls(true);
	   l1.setBorder(BorderFactory.createLineBorder(Color.red));
	   l1.setText("Search A Given SEQUENCE");
	   l1.setForeground(Color.blue);
	   JTextField f1=new JTextField(5);
	   f1.setBorder(BorderFactory.createLineBorder(Color.red));
	   JButton b1=new JButton("SEARCH");
	   b1.addActionListener(new ActionListener()
	   {
		   @Override
		   public void actionPerformed(ActionEvent ae)
		   {
			   if(f1.getText().isEmpty())
			   {
				   JOptionPane.showMessageDialog(null, "Fill all the blanks");
				   return;
			   }
			   Vector <String> words=l.sequence(f1.getText());
			   JOptionPane.showMessageDialog(null,"File Opened:"+l.getFileName()+"<br><hr>Words Size:"+String.valueOf(words.size()));
			   int option=JOptionPane.showConfirmDialog(null,"Show Records" ,"Total Records",JOptionPane.YES_NO_OPTION);
			   if(option==JOptionPane.YES_OPTION)
			   {
				   String message="<html>Words ends with "+f1.getText()+":"+String.valueOf(words.size())+"<br>";
				   message+="<p style=color:red>List of Words!!!</p><ul>";
			       for(String x:words)
			       {
			    	   message+="<li>"+x+"</li>";
			       }
			       message+="</ul></html>";
			       JOptionPane.showMessageDialog(null,message);
			   }
		   }
	   });
	   p5.add(l1);
	   p5.add(f1);
	   p5.add(b1);
	   this.add(p5);
   }
   public Frame() throws IOException
   {
	   super("Lexicon App");
	   l=new Lexicon();
	   this.setSize(400,400);
	   this.setResizable(false);
	   this.setLayout(new GridLayout(0,1,20,20));
	   this.panel1();
	   this.panel2();
	   this.panel3();
	   this.panel4();
	   this.panel5();
	   this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	   this.setVisible(true);
   }
}
