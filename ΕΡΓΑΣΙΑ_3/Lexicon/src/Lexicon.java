import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Vector;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.JFileChooser;

public class Lexicon {
    private Vector <String> words;
    private String filename;
    public Lexicon() throws IOException
    {
    	this.words=new Vector<String>();
    	JFileChooser fc=new JFileChooser();
    	int rval=fc.showOpenDialog(null);
    	if(rval==JFileChooser.APPROVE_OPTION)
    	{
    		String file=fc.getSelectedFile().getAbsolutePath();
    		this.filename=file;
    		try {
				FileReader fr=new FileReader(file);
				BufferedReader br=new BufferedReader(fr);
				String line=br.readLine();
				while(line!=null)
				{
				   this.words.add(line);
				   line=br.readLine();
				}
				br.close();
				System.out.println("Total Words:"+this.words.size());
			} catch (FileNotFoundException e) {
			}
    	}
    }
    public Vector <String> equal(int size)
    {
    	Vector <String> match=new Vector<String>();
    	for(String x:this.words)
    	{
    		if(x.length()==size)
    		{
    			match.add(x);
    		}
    	}
    	System.out.println("Size:"+match.size());
    	return match;
    }
    public String getFileName() {return this.filename;}
    public Vector <String> startswith(String word)
    {
    	Vector <String> match=new Vector<String>();
    	Pattern p=Pattern.compile("^"+word+"[.]*");
    	Matcher m=null;
    	for(String x:this.words)
    	{
    		m=p.matcher(x);
    		if(m.find())
    		{
    			match.add(x);
    		}
    	}
    	return match;
    }
    public Vector <String> endswith(String word)
    {
    	Vector <String> match=new Vector<String>();
    	Pattern p=Pattern.compile("[.]*"+word+"$");
    	Matcher m=null;
    	for(String x:this.words)
    	{
    		m=p.matcher(x);
    		if(m.find())
    		{
    			match.add(x);
    		}
    	}
    	return match;
    }
    public Vector <String> replay(String word,int size)
    {
    	Vector <String> match=new Vector<String>();
    	String regex="";
    	if(word.length()==1)
    	{
    		if(word.charAt(0)=='a')
    		regex="([b-zA-Z]*"+word+"[b-zA-Z]*{"+String.valueOf(size)+"})";
    		else if(word.charAt(0)=='A')
    			regex="([a-zB-Z]*"+word+"[a-zB-Z]*{"+String.valueOf(size)+"})";
    		else
    		{
    			if(word.charAt(0)>'a' && word.charAt(0)<='z')
    			{
    				char v=word.charAt(0);
    				char temp=v;
    				v-=1;
    				temp+=1;
    				regex="([a-"+v+temp+"-zA-Z]*"+word+"[a-"+v+temp+"-zA-Z]*){"+String.valueOf(size)+"}";
    			}
    			else if(word.charAt(0)>'A' && word.charAt(0)<='Z')
    			{
    				char v=word.charAt(0);
    				char temp=v;
    				v-=1;
    				temp+=1;
    				regex="([a-zA-"+v+temp+"-Z]*"+word+"[a-zA-"+v+temp+"-Z]*){"+String.valueOf(size)+"}";
    			}
    		}
    	}
    	else
    	{
    		regex="([.]*"+word+"[.]*){"+String.valueOf(size)+"}";
    	}
    	Pattern p=Pattern.compile(regex);
    	Matcher m=null;
    	for(String x:this.words)
    	{
            m=p.matcher(x);
    		if(m.find())
    		{
    			match.add(x);
    		}
    	}
    	return match;
    }
    public Vector <String> sequence(String word)
    {
    	Vector <String> match=new Vector<String>();
    	String regex="^";
    	for(int i=0;i<word.length();i++)
    	{
    		if(word.charAt(i)=='-')
    		{
    			regex+=".";
    		}
    		else
    		{
    			regex+=word.charAt(i);
    		}
    	}
    	regex+="$";
    	System.out.println(regex);
    	Pattern p=Pattern.compile(regex);
    	for(String x:this.words)
    	{
    		Matcher m=p.matcher(x);
    		if(m.find())
    		{
    			match.add(x);
    	    }
    	}
    	return match;
    }
}
