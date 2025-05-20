import java.util.Scanner;
public class Program7 {
public static void main(String[] args) {
Scanner myObj = new Scanner(System.in);
System.out.print("Enter the first number: ");
int a = myObj.nextInt();
System.out.print("Enter the second number: ");
int b = myObj.nextInt();
int sum = a + b;
System.out.println("The sum is "+ sum+ ".");
}
}
// This program takes two numbers as input from the user and prints their sum.