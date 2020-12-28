
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
}