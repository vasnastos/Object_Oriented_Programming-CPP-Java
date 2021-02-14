public class driver 
{
    public static void main(String args[])
    {
        ArrayList <String> ids=database.getIds(); 
		String message="<html><h2>Students with semester above or equal to 4 and university country=Greece</h2><h4>Results found:"+String.valueOf(ids.size())+"</h4><hr><center><table border=\"3\" style=\"width=\"100%\"\"><tr><th>RESULT_ID</th></tr>";
		for(String x:ids)
		{
			message+="<tr><td>"+x+"</td></tr>";
		}
		message+="</table></center></html>";
		JOptionPane.showMessageDialog(null,message);
    } 
}