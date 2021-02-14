package car_fill;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class database {
   public static ArrayList <String> getIds() throws SQLException, ClassNotFoundException
   {
	   ArrayList <String> ids=new ArrayList<String>();
	   Class.forName("org.sqlite.JDBC");
	   Connection con=DriverManager.getConnection("jdbc:sqlite:Car.db");
	   Statement st=con.createStatement();
	   ResultSet rs=st.executeQuery("select id from student where semester>=4 and country='Greece'");
	   while(rs.next())
	   {
		   ids.add(rs.getString(1));
	   }
	   rs.close();
	   st.close();
	   return ids;
   }
}
