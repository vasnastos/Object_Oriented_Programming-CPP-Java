package askisi3_vathmoi;
import javax.swing.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;

public class VathmoiFrame extends JFrame
{
    private ArrayList<Vathmos> V=new ArrayList<Vathmos>();
    private JButton addButton,showButton;
    private JButton showPassedButton,showHighButton,removeButton;
    private JTextArea showArea;
    
    
    void addVathmos()
    {
        int id=Integer.parseInt(JOptionPane.showInputDialog("Enter id "));
        int lab=Integer.parseInt(JOptionPane.showInputDialog("Enter lab "));
        int lecture=Integer.parseInt(JOptionPane.showInputDialog("Enter lecture "));
        V.add(new Vathmos(id,lab,lecture));
    }
    
    void showVathmos()
    {
        String text="";
        for(Vathmos x : V)
        {
            text+=x+"\n";
        }
        showArea.setText(text);
    }
    
    void showPassed()
    {
        String message="<html><head><style>table{background-color:gray; color:blue; font-size:14px; text-align:center;} th{background-color:blue; color:white; font-size:18px; text-decoration:underline;}</style></head><body><h2>PASSED</h2><hr style=\"border-top:2px solid;\"><table><tr>ID</th><th>LECTURE</th><th>LABORATORY</th></tr>";
        for(Vathmos v:this.V)
        {
            if(v.getlab()>=5 && v.getlecture()>=5)
            {
                message+="<tr><td>"+String.valueOf(v.getid())+"</td><td>"+String.valueOf(v.getlecture())+"</td><td>"+String.valueOf(v.getlab())+"</td></tr>";
            }
        }
        message+="</table></body></html>";
        JOptionPane.showMessageDialog(null,message);
    }
    
    void showHigh()
    {
        String message="<html><head><style>table{background-color:gray; color:blue; font-size:14px; text-align:center;} th{background-color:blue; color:white; font-size:18px; text-decoration:underline;}</style></head><body><h2>PASSED</h2><hr style=\"border-top:2px solid;\"><table><tr>ID</th><th>LECTURE</th><th>LABORATORY</th></tr>";
        for(Vathmos v:this.V)
        {
            if((v.getlab()+v.getlecture())/2)
            {
                message+="<tr><td>"+String.valueOf(v.getid())+"</td><td>"+String.valueOf(v.getlecture())+"</td><td>"+String.valueOf(v.getlab())+"</td></tr>";
            }
        }
        message+="</table></body></html>";
        JOptionPane.showMessageDialog(null,message);
    }
    
    void removeVathmos()
    {
        int id=Integer.parseInt(JOptionPane.showInputDialog("Give removal id"));
        int i;
        for(i=0,t=this.V.size();i<t;i++)
        {
            if(this.V.get(i).getid()==id)
            {
                this.V.remove(i);
            }
        }
        if(i==this.V.size())
        {
            JOptionPane.showMessageDialog(null,"<html><h2>Student id:"+String.valueOf(id)+" not found</h2></html>");
            return;
        }
        JOptionPane.showMessageDialog(null,"<html><h2>Student id:"+String.valueOf(id)+" deleted</h2></html>");
    }
    
    void makeButtons()
    {
      JPanel p=new JPanel();
      p.setLayout(new GridLayout(2,3));
      add(p);
      addButton=new JButton("Add");
      p.add(addButton);
      addButton.addActionListener(new ActionListener()
      {
          @Override
          public void actionPerformed(ActionEvent ae) 
          {
              addVathmos();
          }
          
      });
      showButton=new JButton("Show");
      p.add(showButton);
      showButton.addActionListener(new ActionListener()
      {
          @Override
          public void actionPerformed(ActionEvent ae) 
          {
              showVathmos();
          }
          
      });
      
      showPassedButton=new JButton("Show Passed");
      p.add(showPassedButton);
      showPassedButton.addActionListener(new ActionListener()
      {
          @Override
          public void actionPerformed(ActionEvent ae) 
          {
            showPassed();
          }
          
      });
      
      showHighButton=new JButton("Show High");
      p.add(showHighButton);
      showHighButton.addActionListener(new ActionListener()
      {
          @Override
          public void actionPerformed(ActionEvent ae) 
          {
              showHigh();
          }
          
      });
     
      removeButton=new JButton("Remove");
      p.add(removeButton);
      removeButton.addActionListener(new ActionListener()
      {
          @Override
          public void actionPerformed(ActionEvent ae) 
          {
              removeVathmos();
          }
          
      });
    }
    
    public VathmoiFrame(String title)
    {
        super(title);
        setSize(400,300);
        setResizable(false);
        setLayout(new FlowLayout());
        makeButtons();
        showArea=new JTextArea("");
        showArea.setRows(5);
        showArea.setColumns(20);
        showArea.setEditable(false);
        JScrollPane sp=new JScrollPane(showArea);
        add(sp);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
