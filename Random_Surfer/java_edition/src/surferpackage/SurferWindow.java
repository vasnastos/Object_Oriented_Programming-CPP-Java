package surferpackage;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Vector;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class SurferWindow extends JFrame{
       private JTextField vs,itrs,pgs;
       private void panel1()
       {
    	   JPanel panel=new JPanel();
    	   panel.setLayout(new GridLayout(0,2,10,10));
    	   JLabel lb=new JLabel("VISITORS");
    	   lb.setSize((int)(0.3*this.getWidth()),(int)(0.07*this.getHeight()));
    	   lb.setBorder(BorderFactory.createLineBorder(Color.RED));
    	   vs=new JTextField(7);
    	   panel.add(lb);
    	   panel.add(vs);
    	   this.add(panel);
       }
       private void panel2()
       {
    	   JPanel panel=new JPanel();
    	   panel.setLayout(new GridLayout(0,2,10,10));
    	   JLabel lb=new JLabel("ITERATIONS");
    	   lb.setSize((int)(0.3*this.getWidth()),(int)(0.07*this.getHeight()));
    	   lb.setBorder(BorderFactory.createLineBorder(Color.RED));
    	   itrs=new JTextField(7);
    	   panel.add(lb);
    	   panel.add(itrs);
    	   this.add(panel);
       }
       private void panel3()
       {
    	   JPanel panel=new JPanel();
    	   panel.setLayout(new GridLayout(0,2,10,10));
    	   JLabel lb=new JLabel("PAGES");
    	   lb.setSize((int)(0.3*this.getWidth()),(int)(0.07*this.getHeight()));
    	   lb.setBorder(BorderFactory.createLineBorder(Color.RED));
    	   pgs=new JTextField(7);
    	   panel.add(lb);
    	   panel.add(pgs);
    	   this.add(panel);
       }
       private void buttonsPanel()
       {
    	   JPanel panel=new JPanel();
    	   panel.setLayout(new GridLayout(0,3,10,10));
    	   JButton b1=new JButton("SURFER");
    	   JButton b2=new JButton("RANK");
    	   JButton b3=new JButton("CLEAR");
    	   b1.addActionListener(new ActionListener()
    	   {
    		   public void actionPerformed(ActionEvent e)
    		   {
    			   if(vs.getText().isEmpty() || SurferWindow.this.itrs.getText().isEmpty() || pgs.getText().isEmpty())
    			   {
    				   JOptionPane.showMessageDialog(null,"Fill all the blanks","Error Message",JOptionPane.ERROR_MESSAGE);
    				   return;
    			   }
    			   int nv,ni,np;
    			   try
    			   {
    				   nv=Integer.parseInt(vs.getText());
    				   ni=Integer.parseInt(itrs.getText());
    				   np=Integer.parseInt(pgs.getText());
    			   }catch(NumberFormatException ex)
    			   {
    				   JOptionPane.showMessageDialog(null,"please try to Insert only numbers");
    				   return;
    			   }
    			   Surfer s=new Surfer(np);
    			   JOptionPane.showMessageDialog(null,s.adjacencyMatrix());
    			   JOptionPane.showMessageDialog(null,s.random_surfer(nv,ni));
    		   }
    	   });
    	   b2.addActionListener(new ActionListener()
    	   {
    		   public void actionPerformed(ActionEvent ae)
    		   {
    			   if(Matrix.ranking.isEmpty()) return;
    			   
    			   JOptionPane.showMessageDialog(null,Matrix.ranking);
    		   }
    	   });
    	   b3.addActionListener(new ActionListener()
    	   {
    		   public void actionPerformed(ActionEvent ae)
    		   {
    			   SurferWindow.this.itrs.setText("");
    			   SurferWindow.this.pgs.setText("");
    			   SurferWindow.this.vs.setText("");
    		   }   
    	   });
    	   panel.add(b1);
    	   panel.add(b2);
    	   panel.add(b3);
    	   this.add(panel);
       }
      public SurferWindow()
      {
    	  this.setSize(500,500);
    	  this.setTitle("Random Surfer");
    	  this.setResizable(false);
    	  this.setLayout(new GridLayout(0,1,40,40));
    	  JLabel lb1=new JLabel("RANDOM SURFER RESULTS",JLabel.CENTER);
    	  lb1.setSize(new Dimension((int)(0.98*this.getWidth()),(int)(0.4*this.getHeight())));
    	  lb1.setBackground(Color.GREEN);
    	  lb1.setForeground(Color.RED);
    	  this.add(lb1);
    	  this.panel1();
    	  this.panel2();
    	  this.panel3();
    	  this.buttonsPanel();
    	  this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	  this.setVisible(true);
      }
}
