import java.util.*;
import java.io.*;
import java.lang.*;
class book
{
	String name;
	String author;
	float price;
	int num;
	book(){}
	book(String name,String author,float price,int num)
	{
		name=name;
		author=author;
		price=price;
		num=num;
	}
	void getdata()
	{
		Scanner scan=new Scanner(System.in);
		System.out.println("Enter the name:\n");
		name=scan.next();
		System.out.println("Enter the author:\n");
		author=scan.next();
		System.out.println("Enter the price:\n");
		price=scan.nextFloat();
		System.out.println("Enter the number of pages:");
		num=scan.nextInt();
	}
	public String toString()
	{	

		return(name+""+author+""+price+""+num);
	}

}
class bookmain
{
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		System.out.println("Enter the number of books:");
		int n=scan.nextInt();
		book b[]=new book[n];
		for(int i=0;i<n;i++)
		{	
			b[i]=new book();
			b[i].getdata();
			System.out.println(b[i]);
		}
	}
}