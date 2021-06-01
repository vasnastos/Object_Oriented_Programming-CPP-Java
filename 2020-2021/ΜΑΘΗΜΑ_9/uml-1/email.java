import java.util.ArrayList;
import java.util.List;

public class email extends document{
  private String sender;
  private String subject;
  private List <String> recipients;
  public email(String a_date,String a_sender,String a_subject)
  {
	  super(a_date);
	  this.sender=a_sender;
	  this.subject=a_subject;
	  this.recipients=new ArrayList<String>();
  }
  public String get_sender()
  {
	  return this.sender;
  }
  public String get_subject()
  {
	  return this.subject;
  }
  public List <String> get_recipients()
  {
	  return this.recipients;
  }
  public void add_recipient(String name)
  {
	  this.recipients.add(name);
  }
  	@Override
	public String info() {
  		String msg="<html><center><div style=\"border:2px solid; width=auto;\">";
 	   msg+="Email:<b>"+this.date+"--"+this.sender+"--"+this.subject+"</b></div>";
 	   msg+="<hr>";
 	   msg+="<h4>Authors</h4></center>";
 	   msg+="<hr><ul>";
 	   for(String a:this.authors)
 	   {
 		   msg+="<li>"+a+"</li>";
 	   }
 	   msg+="</ul>";
 	   msg+="<hr><center><h4>Recipients</h4></center><ul>";
 	   for(String r:this.recipients)
 	   {
 		   msg+="<li>"+r+"</li>";
 	   }
 	   msg+="</ul></html>";
 	   return msg;
	}
}
