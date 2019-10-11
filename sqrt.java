import java.util.*;
import java.io.*;
import java.lang.*;
class sqrt
{
	public static void main(String args[])
	{
		System.out.println("Enter the values of a,b and c:");
		Scanner scan=new Scanner(System.in);
		double a=scan.nextDouble();
		double b=scan.nextDouble();
		double c=scan.nextDouble();
		double d=b*b-(4*a*c);
		if(d==0)
		{
			double r1=-b/(2*a);
			double r2=r1;
			System.out.println(r1);
			System.out.println(r2);
		}
		else if(d>0)
		{
			double r1=(-b+Math.sqrt(d))/(2*a);
			double r2=(-b-Math.sqrt(d))/(2*a);
			System.out.println(r1+""+r2);
		}
		else
		{
			double part1=-b/(2*a);
			double part2=(-Math.sqrt(d))/(2*a);
			System.out.println(part1+"+i"+part1);
			System.out.println(part2+"-i"+part2);
		}
	}
}