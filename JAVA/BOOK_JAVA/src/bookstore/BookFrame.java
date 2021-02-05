package bookstore;

import javax.swing.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class BookFrame extends JFrame {

  private ArrayList<Book> B = new ArrayList<Book>();
  private JButton addButton, showButton;
  private JButton showPassedButton, showGroupButton, removeButton;
  private JTextArea showArea;

  public BookFrame(String title) {
    super(title);
    setSize(400, 300);
    setResizable(false);
    setLayout(new FlowLayout());
    makeButtons();
    showArea = new JTextArea("");
    showArea.setRows(5);
    showArea.setColumns(20);
    showArea.setEditable(false);
    JScrollPane sp = new JScrollPane(showArea);
    add(sp);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setVisible(true);
  }

  void makeButtons() {
    JPanel p = new JPanel();
    p.setLayout(new GridLayout(2, 3));
    add(p);
    addButton = new JButton("Add");
    p.add(addButton);
    addButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent ae) {
        addBook();
      }

    });
    showButton = new JButton("Show");
    p.add(showButton);
    showButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent ae) {
        showBooks();
      }

    });

    showPassedButton = new JButton("Show Passed");
    p.add(showPassedButton);
    showPassedButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent ae) {
        showPassed();
      }

    });

    showGroupButton = new JButton("Show Group");
    p.add(showGroupButton);
    showGroupButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent ae) {
        showGroup();
      }

    });

    removeButton = new JButton("Remove");
    p.add(removeButton);
    removeButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent ae) {
        removeBook();
      }

    });
  }

  void addBook() {
    String title = JOptionPane.showInputDialog("Enter title ");
    String author = JOptionPane.showInputDialog("Enter author ");
    int price = Integer.parseInt(JOptionPane.showInputDialog("Enter price "));
    B.add(new Book(title, author, price));
  }

  void showBooks() {
    String text = "";
    for (Book x : B) {
      text += x + "\n";
    }
    showArea.setText(text);
  }

  void showPassed() {
     String htmlmessage="<html><body><h2><u>Above 50 euro</u></h2><hr><table border=\"3\" style=\"background-color:gray; color:blue; font-size:15px; font-weight:bold; text-align:center; width:80%;\">"
     htmlmessage+="<tr style=\"background-color:red; color:white; font-size:18px;\"><th>TITLE</th><th>AUTHOR</th><th>PRICE</th></tr>";
     for(Book b:B)
     {
        if(b.getPrice()>50.0)
        {
          htmlmessage+="<tr><td>"+b.getTitle()+"</td><td>"+b.getAuthor()+"</td><td>"+String.valueOf(b.getPrice())+"</td></tr>";
        }
     }
     htmlmessage+="</table></body><html>";
     JOptionPane.showMessageDialog(null,htmlmessage);
    }

  void showGroup() {
    String htmlmessage="<html><body><h2><u>Title Starts With [a-k]</u></h2><hr><table border=\"3\" style=\"background-color:gray; color:blue; font-size:15px; font-weight:bold; text-align:center; width:80%;\">"
    htmlmessage+="<tr style=\"background-color:red; color:white; font-size:18px;\"><th>TITLE</th><th>AUTHOR</th><th>PRICE</th></tr>";
    Pattern p=Pattern.compile("[a-k].*");
    Matcher m=null;
    for(Book b:this.B)
    {
      m=p.matcher(b.getAuthor())
      if(m.find())
      {
        htmlmessage+="<tr><td>"+b.getTitle()+"</td><td>"+b.getAuthor()+"</td><td>"+String.valueOf(b.getPrice())+"</td></tr>";
      }
    }
    htmlmessage+="</table></body><html>";
     JOptionPane.showMessageDialog(null,htmlmessage);
  }

  void removeBook() {
       String name=JoptionPane.showInputDialog("Give Authors name you want to delete");
       int occs=0;
       for(Book b:this.B)
       {
         if(b.getAuthor().equals(name))
         {
            occs++;
         }
       }
       if(occs==0)
       {
         JOptionsPane.showMessageDialog(null,"<html><h3 style=\"color:red; font-weight:bold;\">Author "+name+" did not found on the list</h3></html>");
         return;
       }
       int counter;
       while(occs!=0)
       {
         counter=0;
         for(Book b:this.B)
         {
           if(b.getAuthor().equals(name))
           {
              this.B.remove(counter);
              occs--;
           }
           counter++;
         }
       }
       JOptionPane.showMessageDialog(null,"<html><h3 style=\"color:blue; font-weight:bold;\">Author "+name+" found "+String.valueOf(occs)+" times at the list<br>All occurences Deleted</h3></html>");
       int op=JOptionPane.showConfirmDialog(null,"Show Books","<html><h4>Do you want to Show all the books</h4></html>",JOptionPane.YES_NO_OPTION);
       if(op==JOptionPane.YES_OPTION)
       {
         this.showBooks();
       }
  }
}
