package example_project;

public class student {
  private String name;
  private String lastname;
  private String id;
  private int semester;
  private String uname;
  public void setName(String n)
  {
	  this.name=n;
  }
  public final String getName()
  {
	  return this.name;
  }
  public void setLastName(String ln)
  {
	  this.lastname=ln;
  }
  public final String getLastname()
  {
	  return this.lastname;
  }
  public void  setId(String i)
  {
	  this.id=i;
  }
  public final String getId()
  {
	  return this.id;
  }
  public void setSemester(int sem)
  {
	  this.semester=sem;
  }
  public final int getSemester()
  {
	  return this.semester;
  }
  public void setUName(String u)
  {
	  this.uname=u;
  }
  public final String getUName()
  {
	  return this.uname;
  }
  @Override
  public String toString()
  {
	  return this.name+"-"+this.lastname+"-"+this.id+"-"+String.valueOf(this.semester)+"-"+this.uname;
  }
}

