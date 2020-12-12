
import javax.swing.JOptionPane;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author nasto
 */
public class Account {
    private String name;
    private double balance;
    public Account(String n)
    {
        this.name=n;
        this.balance=0.0;
    }
    public Account(String n,double b)
    {
        this.name=n;
        this.balance=b;
    }
    public void setName(String n) {this.name=n;}
    public String getName() {return this.name;}
    public void setBalance(double b) {this.balance=b;}
    public double getBalance() {return this.balance;}
    public void deposit(double nb)
    {
        this.balance+=nb;
    }
    public void withdraw(double bal)
    {
       if(this.balance<bal)
       {
           JOptionPane.showMessageDialog(null,"Invalid money balance<br><ul><li>Your Balance:"+String.valueOf(this.balance)+"</li><li>Withdraw Amount:"+String.valueOf(bal)+"</li></ul>");
           return;
       }
       this.balance-=bal;
    }
    public void earnings(int am)
    {
        this.balance+=(this.balance*am*0.01);
    }
    public String to_String()
    {
        return this.name+"--"+String.valueOf(this.balance);
    }
}
