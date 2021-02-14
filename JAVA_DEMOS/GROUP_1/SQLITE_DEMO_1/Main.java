package example_project;

import java.sql.SQLException;
import java.util.ArrayList;

import javax.swing.JOptionPane;

public class Main {

	public static void main(String[] args) throws ClassNotFoundException, SQLException {
      ArrayList <String> models=database_1.getBrands();
      String message="<html><head><style>table{background-color:gray; text-align:center; width:80%; color:blue; font-size:14px;} th{background-color:red; color:white; font-size:17px;}</style><body><h2>Cars with price over 10000 and under 20000,model(TOYOTA,NISSAN,HONDA)</h2><hr><table border=\"3\"><tr><th>ID_ROW</th><th>MODEL</th></tr>";
      int counter=1;
      for(String k:models)
      {
    	  message+="<tr><td>"+String.valueOf(counter)+"</td><td>"+k+"</td></tr>";
    	  counter++;
      }
      message+="</table></body></html>";
      JOptionPane.showMessageDialog(null, message);
 	}

}
