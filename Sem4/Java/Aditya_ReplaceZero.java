import java.util.Scanner;

class Aditya_ReplaceZero{
	public static void main(String arg[]) {

		Scanner sc = new Scanner(System.in);
		System.out.print("Enter any integer: ");
		int num = sc.nextInt();	
		int ans = 0;
		int place  = 1;
		
		while(num > 0) {
			int temp = num % 10;
			if(temp == 0) {
				temp = 1;
			}
			ans = temp * place + ans;	
			place = place * 10;
			num = num / 10;
		}
		System.out.println("Result: " + ans);
		sc.close();
	}
}