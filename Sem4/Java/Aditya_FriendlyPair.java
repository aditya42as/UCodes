import java.util.Scanner;

class Aditya_FriendlyPair {
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter num1: ");
		int num1 = sc.nextInt();

		System.out.print("Enter num2: ");
		int num2 = sc.nextInt();
		int sum1 = 0, sum2 = 0;

		for(int i = 1; i < num1; i++) {
			if(num1 % i == 0) {
				sum1 = sum1 + i;
			}
		}
		for(int i = 1; i < num2; i++) {
			if(num2 % i == 0) {
				sum2 = sum2 + i;
			}
		}
		float ans1 = sum1/num1;
		float ans2 = sum2/num2;

		if(ans1 == ans2) {
			System.out.println("Friendly Pair");
		}
		else{
			System.out.println("Not a Friendly Pair");
		}
		sc.close();
	}
}