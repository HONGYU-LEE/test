package test3_26;

import java.util.Scanner;
public class test {
	static int GetMonthDay(int year, int month)
	{
	    int []day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	    
	    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	        day[1] =  29;
	        
	    return day[month - 1];
	}
	public static void main(String[] args) 
	{Scanner sc=new Scanner(System.in);
	
	int year = sc.nextInt();
	int month = sc.nextInt();
	String []monthName = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	System.out.print(monthName[month + 1] + ", " + year);
	System.out.println(" has " + GetMonthDay(year, month) + "days");
	
	}

}



