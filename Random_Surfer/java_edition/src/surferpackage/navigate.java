package surferpackage;

public class navigate {
     public int id;
     public String from;
     public String to;
     public navigate(int i,String f,String t)
     {
    	 this.id=i;
    	 this.from=f;
    	 this.to=t;
     }
	public String toString()
	{
		return "Visotor "+String.valueOf(this.id)+" goes from "+this.from+" to "+this.to;
	}
}
