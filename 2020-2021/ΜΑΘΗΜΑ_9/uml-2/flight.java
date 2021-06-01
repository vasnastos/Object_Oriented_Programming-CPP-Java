
public class flight {
   private static String A="Athens";
   private static String B="Paris";
   private static String C="London";
   private static String D="Berlin";
   private static String E="Warsaw";
   private int flight_number;
   private String from;
   private String to;
   private int duration;
   public static String data[][] ={{A, B, "T1", "200"},{A, B, "T2", "180"},{A, C, "T1", "150"},{A, C, "T2", "140"},{A, D, "T2", "240"},{A,E,"T1","170"},{B,E,"T2","290"},{E,C,"T1","340"},{E,D,"T1","570"}};
   private int get_flight_duration(String from,String to,String airplane_type)
   {
	   for (int i = 0; i < data.length; i++)
	   {
		   if ((data[i][0] == from) && (data[i][1] == to) && (data[i][2] == airplane_type))
		   {
			   return Integer.parseInt(data[i][3]);
	   	   }
	   }
	   return -1;
    }

   public flight(int fn,String f,String t,String airplane_type)
   {
	   this.flight_number=fn;
	   this.from=f;
	   this.to=t;
	   this.duration=this.get_flight_duration(f, t, airplane_type);
   }
   void delay_flight(int minutes)
   {
	   this.duration+=minutes;
   }
   String display()
   {
      return "<tr><td>"+String.valueOf(this.flight_number)+"</td><td>"+this.from+"</td><td>"+this.to+"</td><td>"+String.valueOf(this.duration)+" minutes</td></tr>";	   
   }
}
