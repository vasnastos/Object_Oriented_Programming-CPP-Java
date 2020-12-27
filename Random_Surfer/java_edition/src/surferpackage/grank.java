package surferpackage;

public class grank implements Comparable{
    public int vertex;
    public double rank;
	@Override
	public int compareTo(Object o) {
		grank temp=(grank)o;
		return Double.compare(this.rank,temp.rank);
	}
	@Override
	public String toString()
	{
		return String.valueOf(vertex)+"---"+String.valueOf(rank);
	}
}
