/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rockpaperscissors;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.Border;

/**
 *
 * @author nasto
 */
public class MyFrame extends JFrame{
    JButton b1=null,bagain=null;
    String choices[]={"Rock","Paper","Scissors"};
    JLabel scorelabel=null;
    JComboBox <String> choice=new JComboBox<String>(choices);
    JPanel p1,p2,p3;
    String icons[]={""};
    ImageIcon img,cimg;
    JLabel label;
    private int rounds;
    private String winner;
    private int countrounds;
    private int player=0;
    private int computer=0;
    private void calculatescore()
    {
        if(winner.equals("player"))
        {
            this.player++;
        }
        else if(winner.equals("computer"))
        {
            this.computer++;
        }
        String message="<html><h2>Statistics</h2>";
        message+="<h3>Player:"+String.valueOf(this.player)+"</h3>";
        message+="<h3>Computer:"+String.valueOf(this.computer)+"</h3>";
        message+="</html>";
        scorelabel.setText(message);
        if(rounds-countrounds<this.player-this.computer)
        {
            b1.setEnabled(false);
            JOptionPane.showMessageDialog(null,"Player Wins");
        }
        if(rounds-countrounds<this.computer-this.player)
        {
            b1.setEnabled(false);
            JOptionPane.showMessageDialog(null,"Computer Winns");
        }
        countrounds++;
        if(countrounds>rounds)
        {
            JOptionPane.showMessageDialog(null,"Game Over");
            bagain.setEnabled(true);
        }
    }
    void panel1()
    {
        p1=new JPanel();
        p1.setLayout(new FlowLayout());
        JLabel l1=new JLabel();
        l1.setSize((int)(0.3*this.getWidth()),(int)(0.1*this.getHeight()));
        Border b=BorderFactory.createLineBorder(Color.RED);
        l1.setBorder(b);
        p1.add(choice);
        p1.add(l1);
        b1=new JButton("Play");
        b1.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                Random r=new Random();
                int ch=r.nextInt()%3;
                if(ch<0) {
                    ch=-ch;
                }
                String computerschoice=choices[ch];
                l1.setText("Computer:"+choices[ch]);
                String playerschoice=choice.getSelectedItem().toString();
                //cimg=new ImageIcon(choices[ch]);
                int j=-1;
                for(int k=0;k<choices.length;k++)
                {
                    if(choices[k].equals(playerschoice))
                    {
                        j=k;
                        break;
                    }
                }
                //img=new ImageIcon(choices[j]);
                if(playerschoice=="Rock" && computerschoice=="Scissors")
                {
                    winner="player";
                } 
                else if(playerschoice=="Scissors" && computerschoice=="Paper")
                {
                    winner="player";
                }
                else if(playerschoice=="Paper" && computerschoice=="Rock")
                {
                    winner="player";
                }
                else if(playerschoice.equals(computerschoice))
                {
                    winner="tie";
                }
                else
                {
                    winner="computer";
                }
                calculatescore();
            }
        });
        p1.add(b1);
        this.add(p1);
    }
    void panel2()
    {
        p2=new JPanel();
        p2.setLayout(new FlowLayout());
        JLabel icon1=new JLabel();
        icon1.setSize((int)(0.3*this.getWidth()),(int)(0.2*this.getHeight()));
        Border b1=BorderFactory.createLineBorder(Color.blue);
        icon1.setBorder(b1);
        JLabel icon2=new JLabel();
        icon2.setSize((int)(0.3*this.getWidth()),(int)(0.2*this.getHeight()));
        icon2.setBorder(b1);
        p2.add(icon1);
        p2.add(icon2);
        this.add(p2);
    }
    void panel3()
    {
        p3=new JPanel();
        p3.setLayout(new FlowLayout());
        scorelabel=new JLabel();
        scorelabel.setSize((int)(0.3*this.getWidth()),(int)(0.1*this.getHeight()));
        scorelabel.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        bagain=new JButton();
        bagain.setText("Play Again");
        bagain.setEnabled(false);
        bagain.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                player=0;
                computer=0;
                countrounds=0;
                bagain.setEnabled(false);
                b1.setEnabled(true);
            }
        });
        JButton b2=new JButton("Save");
        b2.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                
            }
        });
        p3.add(scorelabel);
        p3.add(bagain);
        p3.add(b2);
        this.add(p3);
    }
    public MyFrame(int rounds)
    {
        this.countrounds=0;
        this.rounds=rounds;
        this.setSize(500,500);
        this.setTitle("RockPaperScissors");
        this.setLayout(new GridLayout(0,1));
        this.setResizable(false);
        panel1();
        panel2();
        panel3();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }
}