import java.net.*;
import java.util.Scanner;
import java.io.*;

public class client
{
	public static void main(String[]args) throws 
UnknownHostException, IOException

	{
		String text,temp;
		Scanner sc = new Scanner(System.in);
		Socket s = new Socket("192.168.61.129",52051);
		Scanner sc1 = new Scanner(s.getInputStream());
		
		System.out.println("Please enter your text : ");
		text = sc.next();
		PrintStream pr = new PrintStream(s.getOutputStream());
		pr.println(text);
		
		temp = sc1.nextLine();
		System.out.println(temp);
	}
}
# clientBsd
