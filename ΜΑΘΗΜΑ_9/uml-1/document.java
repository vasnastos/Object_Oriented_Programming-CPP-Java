import java.util.*;

public abstract class document {
   protected String date;
   protected List <String> authors;
   public document(String a_date)
   {
	   this.date=a_date;
	   this.authors=new ArrayList<String>();
   }
   public List<String> get_authors()
   {
	   return this.authors;
   }
   public String get_date()
   {
	   return this.date;
   }
   public void add_author(String name)
   {
	   this.authors.add(name);
   }
   public abstract String info();
}
