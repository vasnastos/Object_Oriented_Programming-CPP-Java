
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author nasto
 */
public class MyFrame extends JFrame{
    JPanel p1,p2,p3,p4;
    Bank b;
    double amms[]={20.0,40.0,60.0,80.0,100.0};
    JComboBox <String> daccs=new JComboBox<String>();
    JComboBox <String> waccs=new JComboBox<String>();
    void fillCombos()
    {
        daccs.removeAll();
        waccs.removeAll();
        Vector <String> accouns=b.get_Accounts();
        for(String s:accouns)
        {
            daccs.addItem(s);
            waccs.addItem(s);
        }
    }
    void panel1()
    {
        p1=new JPanel();
        p1.setLayout(new FlowLayout());
        JLabel lb=new JLabel("Insert Account",JLabel.CENTER);
        lb.setSize((int)(0.2*this.getWidth()),(int)(0.1*this.getHeight()));
        lb.setBackground(Color.blue);
        lb.setForeground(Color.red);
        JTextField name=new JTextField(5);
        JTextField balance=new JTextField(5);
        JButton b1=new JButton("INSERT");
        b1.addActionListener(new ActionListener()
        {
           @Override
           public void actionPerformed(ActionEvent e)
           {
               if(name.getText().length()==0 || balance.getText().length()==0)
               {
                   JOptionPane.showMessageDialog(null,"<h2>Please fill all the blanks</h2>");
                   return;
               }
               String nm=name.getText();
               double bal=Double.parseDouble(balance.getText());
               if(b.exists(nm))
               {
                   JOptionPane.showMessageDialog(null,"Account already exists in the bank!!!");
                   return;
               }
               Account newaccount=new Account(nm,bal);
               b.add_Account(newaccount);
               fillCombos();
           }
        });        
        p1.add(lb);
        p1.add(name);
        p1.add(balance);
        p1.add(b1);
        this.add(p1);
    }
    void panel2()
    {
        p2=new JPanel();
        p2.setLayout(new FlowLayout());
        JLabel lb=new JLabel("Deposit Blank",JLabel.CENTER);
        lb.setSize((int)(0.2*this.getWidth()),(int)(0.1*this.getHeight()));
        lb.setBackground(Color.blue);
        lb.setForeground(Color.red);
        JButton but=new JButton("DEPOSIT");
        but.addActionListener(new ActionListener()
        {
           @Override
           public void actionPerformed(ActionEvent e)
           {
               String id=daccs.getSelectedItem().toString();
               String input="<html><h2 text-align:center;>Select a deposit Amount</h2><b>1.20    .2.40\n3.60    4.80\n5.100   6.Cancel</b></html>";
               int choice=Integer.parseInt(JOptionPane.showInputDialog(input));
               if(choice==6) {return;}
               if(choice<=0 || choice>6) {JOptionPane.showMessageDialog(null,"Invallid Choice!!!");}
               b.deposit(id,amms[choice-1]);
           }
        });
        p2.add(lb);
        p2.add(daccs);
        p2.add(but);
        this.add(p2);
    }
    void panel3()
    {
        p3=new JPanel();
        p3.setLayout(new FlowLayout());
        JLabel lb=new JLabel("Withdraw Blank",JLabel.CENTER);
        lb.setSize((int)(0.2*this.getWidth()),(int)(0.1*this.getHeight()));
        lb.setBackground(Color.blue);
        lb.setForeground(Color.red);
        JButton but=new JButton("WITHDRAW");
        but.addActionListener(new ActionListener()
        {
           @Override
           public void actionPerformed(ActionEvent e)
           {
               String id=waccs.getSelectedItem().toString();
               String input="<h2 text-align:center;>Select a Withdraw Amount</h2><b>1.20\t.2.40\n3.60\t4.80\n5.100\t6.Cancel</b>";
               int choice=Integer.parseInt(JOptionPane.showInputDialog(input));
               if(choice==6) {return;}
               if(choice<=0 || choice>6) {JOptionPane.showMessageDialog(null,"Invallid Choice!!!"); return;}
               b.withdraw(id,amms[choice-1]);
           }
        });
        p3.add(lb);
        p3.add(waccs);
        p3.add(but);
        this.add(p3);
    }
    void showpanel()
    {
      p4=new JPanel();
      p4.setLayout(new FlowLayout());
      JLabel hnd=new JLabel("Handler Form",JLabel.CENTER);
      hnd.setSize((int)(0.2*this.getWidth()),(int)(0.1*this.getHeight()));
      hnd.setBackground(Color.blue);
      hnd.setForeground(Color.red);
      JButton b1=new JButton("SHOW");
      JButton b2=new JButton("SAVE");
      JButton b3=new JButton("EARNINGS");
      b1.addActionListener(new ActionListener()
      {
          @Override
          public void actionPerformed(ActionEvent e)
          {
              b.print();
          }
      });
      b2.addActionListener(new ActionListener()
      {
         @Override
         public void actionPerformed(ActionEvent e)
         {
             JFileChooser ch=new JFileChooser();
             int rval=ch.showSaveDialog(null);
             if(rval==JFileChooser.APPROVE_OPTION)
             {
                 String fn=ch.getSelectedFile().getAbsolutePath();
                 FileWriter fw=null;
                 try
                 {
                     fw=new FileWriter(fn);
                     PrintWriter pw=new PrintWriter(fw);
                     int size=b.total();
                     for(int i=0;i<size;i++)
                     {
                       pw.println(b.get(i));
                     }
                     pw.close();
                 } catch (IOException ex) {
                     Logger.getLogger(MyFrame.class.getName()).log(Level.SEVERE, null, ex);
                 }
             }
         }
      });    
      b3.addActionListener(new ActionListener()
      {
          @Override
          public void actionPerformed(ActionEvent e)
          {
              int earn=Integer.parseInt(JOptionPane.showInputDialog("Give Earnings ammount:"));
              b.add_Earnings(earn);
              JOptionPane.showMessageDialog(null,"Earnings inserted!!!");
              b.print();
              b3.setEnabled(false);
          }
      });
      p4.add(hnd);
      p4.add(b1);
      p4.add(b2);
      p4.add(b3);
      this.add(p4);
    }
    public MyFrame()
    {
        super("Bank System");
        b=new Bank();
        this.setSize(500,500);
        this.setResizable(false);
        this.setLayout(new GridLayout(0,1));
        JLabel showlb=new JLabel();
        showlb.setSize((int)(0.98*this.getWidth()),(int)(0.46*this.getHeight()));
        showlb.setBorder(BorderFactory.createLineBorder(Color.black));
        ImageIcon ic=new ImageIcon(new ImageIcon("bank.png").getImage().getScaledInstance(showlb.getWidth(),showlb.getHeight(),Image.SCALE_REPLICATE));
        showlb.setIcon(ic);
        this.add(showlb);
        this.panel1();
        this.panel2();
        this.panel3();
        this.showpanel();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }
}
