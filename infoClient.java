import java.net.Socket;
import java.net.*;
import java.io.*;

public class infoClient
{
	public static void main(String[]args) throws IOException
	{
	     Socket a = new Socket();
	     String host = "192.168.61.129";
	     PrintWriter a_out = null;
	     BufferedReader a_in = null;

	     try
	     {
	        a.connect(new InetSocketAddress(host, 80));
		System.out.println("Successfully Connected");
		
		a_out = new PrintWriter(a.getOutputStream(), true);
		a_in  = new BufferedReader(new 
InputStreamReader(a.getInputStream()));
	     }

	     catch (UnknownHostException e)
	     {
		System.err.println("Don't know about the host: " +host);
		System.exit(1);
	     }
		String message= "Hello!";
		a_out.println(message);

		System.out.println("Message Successfuly Send");

		String response;
		while ((response = a_in.readLine()) != null)
		{
			System.out.println(response);
		}

	}
}
