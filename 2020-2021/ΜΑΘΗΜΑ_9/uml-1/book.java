
public class book extends document{

	private String title;
	public book(String a_date,String a_title)
	{
		super(a_date);
		this.title=a_title;
	}
	public String get_title()
	{
		return this.title;
	}
	@Override
	public String info() {
		String msg="<html><center><div style=\"border:2px solid; width=auto;\">";
		   msg+="Book:<b>"+this.date+"--"+this.title+"</b></div>";
		   msg+="<hr>";
		   msg+="<h4>Authors</h4>";
		   msg+="<hr><ul>";
		   for(String a:this.authors)
		   {
			   msg+="<li>"+a+"</li>";
		   }
		   msg+="</ul></center>";
		   return msg;
	}
    
}
