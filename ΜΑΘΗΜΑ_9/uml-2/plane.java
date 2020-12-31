import java.util.ArrayList;
import java.util.List;

public class plane {
    private String airplane_type;
    private int maxspeed;
    private String tail_id;
    private List <flight> flights;
    public plane(String at,int ms,String tid)
    {
    	this.flights=new ArrayList<flight>();
    	this.airplane_type=at;
    	this.maxspeed=ms;
    	this.tail_id=tid;
    }
    public void add_flight(flight a_flight)
    {
    	this.flights.add(a_flight);
    }
    public List <flight> flights()
    {
    	return this.flights;
    }
    public String display()
    {
    	return "<tr><td>--></td><td>"+this.airplane_type+"</td><td>"+String.valueOf(this.maxspeed)+"</td><td>"+this.tail_id+"</td></tr>";
    }
}
