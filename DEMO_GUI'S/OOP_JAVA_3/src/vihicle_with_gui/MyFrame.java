package vihicle_with_gui;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Vector;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.Border;

import javafx.scene.layout.BorderStrokeStyle;

public class MyFrame extends JFrame{
    JPanel p1,p2;
    Vector <vihicle> vihicles=new Vector<vihicle>();
    JComboBox <String> rns=new JComboBox<String>();
    private void make_gif()
    {
    	ImageIcon icon=new ImageIcon("car.gif");
    	JLabel showlabel=new JLabel();
    	showlabel.setSize((int)(0.98*this.getWidth()),(int)(0.3*this.getHeight()));
    	icon.setImage(new ImageIcon("car.gif").getImage().getScaledInstance(showlabel.getWidth(),showlabel.getHeight(),Image.SCALE_REPLICATE));
        showlabel.setIcon(icon);
    	this.add(showlabel);
    }
    private void row1()
    {
    	p1=new JPanel();
    	p1.setLayout(new FlowLayout());
        JButton b1=new JButton("ADD CAR");
        b1.addActionListener(new ActionListener()
        {
        	public void actionPerformed(ActionEvent ae)
        	{
        		String rn=JOptionPane.showInputDialog("Give Registration number of car:");
        		String on=JOptionPane.showInputDialog("Give owner name of car:");
        		double cc=Double.parseDouble(JOptionPane.showInputDialog("Give cc of car:"));
        		int nd=Integer.parseInt(JOptionPane.showInputDialog("Give number of doors of the car:"));
        		for(vihicle v:vihicles)
        		{
        			if(v.get_cc()==cc && v.get_owner_name().equals(on))
        			{
        				JOptionPane.showMessageDialog(null,"Car already exists in the list");
        				return;
        			}
        		}
        		car input=new car(rn,on,cc,nd);
        		vihicles.add(input);
        		rns.addItem(rn);
        	}
        });
        JButton b2=new JButton("ADD TRUCK");
        b2.addActionListener(new ActionListener()
        {
        	public void actionPerformed(ActionEvent ae)
        	{
        		String rn=JOptionPane.showInputDialog("Give Registration number of truck:");
        		String on=JOptionPane.showInputDialog("Give owner name of truck:");
        		double cc=Double.parseDouble(JOptionPane.showInputDialog("Give cc of truck:"));
        		double mw=Double.parseDouble(JOptionPane.showInputDialog("Give max weight of truck:"));
        		for(vihicle v:vihicles)
        		{
        			if(v.get_cc()==cc && v.get_owner_name().equals(on))
        			{
        				JOptionPane.showMessageDialog(null,"Car already exists in the list");
        				return;
        			}
        		}
        		truck input=new truck(rn,on,cc,mw);
        		vihicles.add(input);
        		rns.addItem(rn);
        	}
        });
        JButton b3=new JButton("SHOW");
        b3.addActionListener(new ActionListener()
        {
        	public void actionPerformed(ActionEvent ae)
        	{
        		String message="<html><h2 text-align:center;>VIHICLES</h2><ul>";
        		for(vihicle v:vihicles)
        		{
        			message+="<li>"+v.to_String()+"</li>";
        		}
        		message+="</ul></html>";
        		JOptionPane.showMessageDialog(null,message);
        	}
        });
        JButton b4=new JButton("TOTAL TAXES");
        b4.addActionListener(new ActionListener()
        {
        	public void actionPerformed(ActionEvent ae)
        	{
        		double taxes=0.0;
        		for(vihicle v:vihicles)
        		{
        			taxes+=v.traffic_taxes();
        		}
        		String message="<html><h3>Total Taxes of Registered cars:</h2><p style=color:red>"+String.valueOf(taxes)+"</p>";
        		JOptionPane.showMessageDialog(null, message);
        	}
        });
        p1.add(b1);
        p1.add(b2);
        p1.add(b3);
        p1.add(b4);
        this.add(p1);
    }
    
    private void row2()
    {
    	p2=new JPanel();
    	p2.setLayout(new FlowLayout());
    	JLabel showlb=new JLabel();
    	showlb.setSize((int)(0.4*this.getWidth()),(int)(0.24*this.getHeight()));
    	Border border=BorderFactory.createLineBorder(Color.BLUE);
    	showlb.setBorder(border);
    	JButton search=new JButton("SEARCH");
    	search.addActionListener(new ActionListener()
    	{
    		public void actionPerformed(ActionEvent e)
    		{
    			String message="<html><h3 text-align:center;>Search Results</h3><ul>";
    			String rn=rns.getSelectedItem().toString();
    			for(vihicle r:vihicles)
    			{
    				if(r.get_registration_number().equals(rn))
    				{
    				   message+="<li>"+r.to_String()+"</li>";
    				   message+="<li>Taxes:"+String.valueOf(r.traffic_taxes())+"</li>";
    				   break;
    				}
    			}
    			message+="</ul></html>";
    			showlb.setText(message);
    		}
    	});
    	p2.add(rns);
    	p2.add(search);
    	p2.add(showlb);
    	this.add(p2);
    }
    public MyFrame()
    {
    	this.setSize(400,400);
    	this.setResizable(false);
    	this.setTitle("Vihicle demo App");
    	this.setLayout(new GridLayout(0,1));
    	make_gif();
    	row1();
    	row2();
    	this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	this.setVisible(true);
    }
}
