package company;

public class employee {
    private String name;
    private String code;
    private String depid;
    private double salary;
    public employee(String n,String cd,String did,double s)
    {
    	this.name=n;
    	this.code=cd;
    	this.depid=did;
    	this.salary=s;
    }
    public String get_name() {return this.name;}
    public String get_code() {return this.code;}
    public String get_department_id() {return this.depid;}
    public double get_salary() {return this.salary;}
    public String to_String()
    {
    	return this.name+"-"+this.code+"-"+String.valueOf(this.salary);
    }
}
