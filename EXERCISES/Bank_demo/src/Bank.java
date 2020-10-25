
import java.util.List;
import java.util.ArrayList;
import java.util.Vector;
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
public class Bank {
    private List <Account> accounts;

    public Bank() {
        this.accounts = new ArrayList<Account>();
    }
    void add_Account(Account acc)
    {
        this.accounts.add(acc);
    }
    void deposit(String id,double bal)
    {
        boolean found=false;
        for(Account acc:accounts)
        {
            if(acc.getName().equals(id))
            {
                acc.deposit(bal);
                found=true;
            }
        }
        if(!found)
        {
            JOptionPane.showMessageDialog(null,"<h2>Account with Id:"+id+" din not found!!</h2>");
        }
    }
    void withdraw(String id,double bal)
    {
        boolean found=false;
        for(Account acc:accounts)
        {
            if(acc.getName().equals(id))
            {
                acc.withdraw(bal);
                found=true;
            }
        }
        if(!found)
        {
            JOptionPane.showMessageDialog(null,"<h2>Account with Id:"+id+" din not found!!</h2>");
        }
    }
    public boolean exists(String id)
    {
        for(Account acc:this.accounts)
        {
            if(acc.getName().equals(id)) {return true;}
        }
        return false;
    }
    public void print()
    {
        String message="<html><h2 style=text-align:center;>Accounts</h2><ul>";
        for(Account acc:this.accounts)
        {
            message+="<li>"+acc.to_String()+"</li>";
        }
        message+="</ul><html>";
        JOptionPane.showMessageDialog(null,message);
    }
    public Vector<String> get_Accounts()
    {
        Vector <String> accnms=new Vector<String>();
        for(Account acc:this.accounts)
        {
            accnms.add(acc.getName());
        }
        return accnms;
    }
    public void add_Earnings(int earn)
    {
        for(Account a:this.accounts)
        {
            a.earnings(earn);
        }
    }
    public int total() {return this.accounts.size();}
    public String get(int i)
    {
        try
        {
            if(i>=accounts.size() || i<0)
            {
                throw new Exception();
            }
            return accounts.get(i).to_String();
        }catch(Exception e)
        {
            JOptionPane.showMessageDialog(null,"Invalid Position");
        }
        return null;
    }
}
