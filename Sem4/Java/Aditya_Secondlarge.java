/*Find and display second largest element in an array */
import java.util.Scanner;

class Aditya_Secondlarge {

	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter size of array: ");
		int n = sc.nextInt();

		int arr[];
		arr = new int[n];

		System.out.print("Enter array: ");
		for(int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		

		int max = 0, sec = 0;
		for(int i = 0; i < n; i++) {

			if(arr[i] > max) {
				max = arr[i];
			}
		}

		for(int i = 0; i < n; i++) {

			if(arr[i] > sec && arr[i] != max) {
				sec = arr[i];
			}
		}
		System.out.println("Max: " + max);
		System.out.println("Second Largest: " + sec);

		sc.close();
	
	}

}