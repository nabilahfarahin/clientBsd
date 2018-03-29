import java.io.*;
import java.net.Socket;
import java.util.Scanner;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.text.DateFormat;

public class tcpClient
{
	public static void main(String[] args)
	{
		try
		{
		 System.out.println("Client Started");
		Socket so = new Socket("192.168.61.128",7778);

		Date a = new Date();
		String strDateFormat = "HH";
		DateFormat dateformat = new 
SimpleDateFormat(strDateFormat);
		String formattedDate = dateformat.format(a);

		PrintWriter out = new 
PrintWriter(so.getOutputStream(),true);
		out.println(formattedDate);
		BufferedReader in = new BufferedReader(new 
InputStreamReader(so.getInputStream()));
		String message = in.readLine();
		System.out.println(message);

	so.close();
}
	catch(Exception e)
	{
		e.printStackTrace();
	}

}
}
