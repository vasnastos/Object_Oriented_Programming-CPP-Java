public class driver
{
    public static void main(String args[])
    {
        ArrayList <stracture> stds=new ArrayList<stracture>();
			Random R=new Random(System.currentTimeMillis());
			String msg="<html><h2>Stractures</h2><hr><ul>";
			for(int i=1;i<=10;i++)
			{
				stracture s=new stracture();
				s.setKind(String.valueOf(R.nextInt(5)+1)+" rooms");
				s.setMeters(R.nextInt(130)+R.nextDouble());
				s.setRegion("Region_"+String.valueOf(R.nextInt(170)));
				s.setPrice(R.nextInt(50000)+R.nextDouble());
				stds.add(s);
				msg+="<li>"+s+"</li>";
			}
			msg+="</ul><hr><h4>"+String.valueOf(stds.size())+"</h4>+"</html>";
			JOptionPane.showMessageDialog(null, msg);
    }
}