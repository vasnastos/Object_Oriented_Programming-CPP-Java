package surferpackage;

import java.util.*;

public class Matrix{
    protected int rc;
    protected int adj[][];
    protected int visits[];
    public static String ranking;
    public Matrix(int r)
    {
    	this.adj=new int[r][r];
    	Random ran=new Random();
    	this.rc=r;
    	visits=new int[r];
    	for(int i=0;i<r;i++)
    	{
    		visits[i]=0;
    		for(int j=0;j<r;j++)
    		{
    			if(i==j)
    			{
    				this.adj[i][j]=0;
    			    continue;
    			}
    			this.adj[i][j]=ran.nextInt(2);
    		}
    	}
    }
    public void addVisit(int r)
    {
    	System.out.println(r+"----"+this.visits.length);
    	this.visits[r]++;
    }
    public Vector <Integer> getNeibourghs(int r)
    {
    	Vector <Integer> nbs=new Vector<Integer>();
    	for(int j=0;j<this.rc;j++)
    	{
    		if(r==j) continue;
    		if(this.adj[r][j]!=0)
    		{
    			nbs.add(j);
    		}
    	}
    	return nbs;
    }
    public Vector <Integer> getNonNeibourghs(int r)
    {
    	Vector <Integer> nbs=new Vector<Integer>();
    	for(int j=0;j<this.rc;j++)
    	{
    		if(r==j) continue;
    		if(this.adj[r][j]==0)
    		{
    			nbs.add(j);
    		}
    	}
    	return nbs;
    }
    public String adjacencyMatrix()
    {
    	String htmlsource="<html><center><table border=\"4\"><tr><th></th>";
    	for(int i=0;i<this.rc;i++)
    	{
    		htmlsource+="<th>Web Page "+String.valueOf(i+1)+"</th>";
    	}
        htmlsource+="</tr>";
        for(int i=0;i<this.rc;i++)
        {
        	htmlsource+="<tr><td>Web Page "+String.valueOf(i+1)+"</td>";
        	for(int j=0;j<this.rc;j++)
        	{
        		htmlsource+="<td>"+String.valueOf(this.adj[i][j])+"</td>";
        	}
        	htmlsource+="</tr>";
        }
        htmlsource+="</table></center></html>";
        return htmlsource;
    }
    public void rank()
    {
    	List <grank> ranks=new ArrayList<grank>();
    	for(int i=0;i<this.rc;i++)
    	{
    		grank g=new grank();
    		g.vertex=i;
    		g.rank=this.visits[i]/Math.pow(this.rc,2.0);
    		ranks.add(g);
    	}
    	Collections.sort(ranks);
    	//creating and html table
    	String htmlsource="<html><table border=\"3\" style=\"width:100%; font-size:12px;\"><tr><th>PAGE</th><th>RANK</th></tr>";
    	for(int i=ranks.size()-1;i>=0;i--)
    	{
    		htmlsource+="<tr><td>"+String.valueOf(ranks.get(i).vertex)+"</td><td>"+String.valueOf(ranks.get(i).rank)+"</td></tr>";
    	}
    	htmlsource+="</table></html>";
    	Matrix.ranking=htmlsource;
    }
}
