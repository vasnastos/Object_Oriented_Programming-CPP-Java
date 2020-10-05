package cargo_with_FileOpener;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.util.Vector;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

public class startclass {
    
	public static void show_cargos(Vector <cargo> c)
	{
		String message="<html><h3 text-align:center;>Cargos</h3><ul>";
		for(cargo crs:c)
		{
			message+="<li>"+crs.to_String()+"</li>";
		}
		message+="</ul></html>";
		JOptionPane.showMessageDialog(null,message);
	}
	
	public static void main(String[] args) {
		Vector <cargo> cargos=new Vector<cargo>();
        JFileChooser ch=new JFileChooser();
        int retval=ch.showOpenDialog(null);
        if(retval==JFileChooser.APPROVE_OPTION)
        {
        	String fn=ch.getSelectedFile().getAbsolutePath();
        	try {
				FileReader fr=new FileReader(fn);
				Scanner sc=new Scanner(fr);
				while(sc.hasNextLine())
				{
					String line=sc.nextLine();
					String data[]=line.split(",");
					if(data.length!=4) continue;
					boolean f;
					if(Integer.parseInt(data[3])==0)
					{
						f=true;
					}
					else
					{
						f=false;
					}
					cargo newcargo=new cargo(Integer.parseInt(data[0]),data[1],Double.parseDouble(data[2]),f);
					cargos.add(newcargo);
				}
				sc.close();
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        	if(cargos.size()==0) {
        		JOptionPane.showMessageDialog(null,"No input detected!!");
        		return;
        	}
        	show_cargos(cargos);
        	for(cargo c:cargos)
        	{
        		c.make_safe();
        	}
        	show_cargos(cargos);
        }
	}

}
