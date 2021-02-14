package example_project;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class database_1 {
   public static ArrayList <String> getBrands() throws ClassNotFoundException, SQLException
   {
	   Class.forName("org.sqlite.JDBC");
	   Connection con=DriverManager.getConnection("jdbc:sqlite:test.db");
	   ArrayList <String> models=new ArrayList<String>();
	   Statement st=con.createStatement();
	   ResultSet rs=st.executeQuery("select distinct model from car where price between 10000 and 20000 and (brand='TOYOTA' or brand='NISSAN' or brand='HONDA')");
	   while(rs.next())
	   {
		   models.add(rs.getString(1));
	   }
	   rs.close();
	   st.close();
	   return models;
   }
}
