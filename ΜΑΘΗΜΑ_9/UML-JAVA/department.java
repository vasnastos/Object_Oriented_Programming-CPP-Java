import java.util.*

class employee
{
    private String name;
    private int age;
    private double salary;
    public employee(String n,int a,double s)
    {
        this.name=n;
        this.age=a;
        this.salary=s;
    }
    public String getName() {return this.name;}
    public int getAge() {return this.age;}
    public double getSalary() {return this.salary;}
    public void info()
    {
        System.out.println(this.name+"-"+String.valueOf(this.age)+"-"+String.valueOf(this.salary));
    }
    public String toString()
    {
        return this.name+"-"+String.valueOf(this.age)+"-"+String.valueOf(this.salary);
    }
}

class department
{
   private String id;
   private List <employee> emps;
   public employee(String id)
   {
       this.id;
       this.emps=new ArrayList<employee>();
   }
   public void add_Employee(employee e)
   {
      this.emps.add(e);
   }
   public void Print_Employees()
   {
      for(employee e:this.emps)
      {
          System.out.println(e);
      }
   }
}