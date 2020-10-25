
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author nasto
 */
public class startclass {

    /**
     *
     * @param args
     */
    public static void main(String args[])
    {
        String datetime=java.time.LocalDateTime.now().toString();
        System.out.println("Local DateTime:"+datetime);
        System.out.print("Start the App(0/no,1/yes):");
        Scanner sc=new Scanner(System.in);
        if(sc.nextInt()==1)
        {
            MyFrame f=new MyFrame();
        }
        else
        {
            System.out.println("Thank for using the program!!Bye Bye!!!");
        }
    }
}
