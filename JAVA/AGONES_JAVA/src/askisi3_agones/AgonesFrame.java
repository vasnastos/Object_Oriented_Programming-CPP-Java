
package askisi3_agones;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class AgonesFrame extends JFrame
{
    private ArrayList<Agonas> A=new ArrayList<Agonas>();
    private JButton addButton,showButton;
    private JButton showPropoButton;
    private JButton showGoalsButton;
    private JButton removeButton;
    private JTextArea  showLabel;
    
    
    
    void addGame()
    {
        int a=Integer.parseInt(JOptionPane.showInputDialog("Enter home goals "));
        int b=Integer.parseInt(JOptionPane.showInputDialog("Enter visitor goals "));
        A.add(new Agonas(a,b));
    }
    
    void showGames()
    {
        String text="";
        for(Agonas x : A)
        {
           text+=x+"\n";
        }
       
        showLabel.setText(text);
    }
    
    void showPropo()
    {
        String htmlmessage="<html><head><style>table {background-color:gray; color:blue; font-size:14px; text-align:center;} th{background-color:blue; color:white; font-size:16px; text-decoration:underline;}</style></head><body><h2>PROPO</h2><hr style=\"border-top:2px red;\"><table border=\"3\"><tr><th>HOME</th><th>AWAY</th><th>PROPO</th></tr>";
        for(Agonas a:this.A)
        {
            htmlmessage+="<tr><td>"+String.valueOf(a.gethome())+"</td><td>"+String.valueOf(a.getvisitor())+"</td>";
            String res="";
            if(a.gethome()>a.getvisitor())
            {
               res="1";
            }
            else if(a.gethome()<a.getvisitor())
            {
                res="2";
            }
            else{
                res="X";
            }
            htmlmessage+="<td>"+res+"</td></tr>";
        }
        htmlmessage+="</table></body></html>";
        JOptionPane.showMessageDialog(null,htmlmessage);
    }
    
    void showGoals()
    {
        String htmlmessage="<html><head><style>table {background-color:gray; color:blue; font-size:14px; text-align:center;} th{background-color:blue; color:white; font-size:16px; text-decoration:underline;}</style></head><body><h2>PROPO</h2><hr style=\"border-top:2px red;\"><table border=\"3\"><tr><th>HOME</th><th>AWAY</th></tr>";
        for(Agonas a:this.A)
        {
            if(a.gethome()+a.getvisitor()>5)
            {
                htmlmessage+="<tr><td>"+String.valueOf(a.gethome())+"</td><td>"+String.valueOf(a.getvisitor())+"</td></tr>";
            }
        }
        htmlmessage+="</table></body></html>";
        JOptionPane.showMessageDialog(null,htmlmessage);
    }
    
    void removeGame()
    {
        int home=Integer.parseInt(JOptionPane.showInputDialog("Give home goals"));
        int away=Integer.parseInt(JOptionPane.showInputDialog("Give away goals"));
        int occs=0;
        for(int i=0,t=this.A.size();i<t;i++)
        {
            if(this.A.get(i).gethome()==home && this.A.get(i).getvisitor())
            {
                occs++;
                this.A.remove(i);
                i--;
            }
        }
        if(occs!=0)
        {
            JOptionPane.showMessageDialog(null,"<html><h2>No occurence for score:"+String.valueOf(home)+"-"+String.valueOf(away)+" found at the list</h2></html>");
        }
        else
        {
            JOptionPane.showMessageDialog(null,"<html><h2>"+String.valueOf(occs)+" occurences found with score:"+String.valueOf(home)+"-"+String.valueOf(away)+" found at the list</h2></html>");
        }
    }
    
    void makeButtons()
    {
        JPanel p=new JPanel();
        p.setLayout(new GridLayout(2,3));
        add(p);
        addButton=new JButton("Add game");
        addButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                addGame();
            }
            
        });
        p.add(addButton);
        showButton=new JButton("Show Games");
        p.add(showButton);
        showButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                showGames();
            }
            
        });
        showPropoButton=new JButton("Show Propo");
        p.add(showPropoButton);
        showPropoButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                showPropo();
            }
            
        });
        showGoalsButton=new JButton("Show Goals");
        p.add(showGoalsButton);
        showGoalsButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                showGoals();
            }
            
        });
        removeButton=new JButton("Remove a game");
        p.add(removeButton);
        removeButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae) 
            {
                removeGame();
            }
            
        });
        
    }
    
    public AgonesFrame(String title)
    {
        super(title);
        setSize(400,200);
        setResizable(false);
        setLayout(new FlowLayout());
        makeButtons();
        showLabel=new JTextArea("");
        showLabel.setRows(5);
        showLabel.setColumns(20);
        showLabel.setSize(200,200);
        JScrollPane sp=new JScrollPane(showLabel);
        add(sp);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }
}
