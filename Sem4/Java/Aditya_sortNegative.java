import java.util.Scanner;

class Aditya_sortNegative {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int arr[] = new int[n];
        System.out.println("Enter arraY: ");
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int c = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0) {
                int temp = arr[i];
                arr[i] = arr[c];
                arr[c] = temp;
                c++;
            }
        }
        System.out.println("Updated array: ");
        for(int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}