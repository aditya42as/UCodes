import java.util.Scanner;
class s1{
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter key: ");
        int key = sc.nextInt();

        System.out.println("Pairs: ");
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(arr[i] + arr[j] == key) {
                    System.out.println(arr[i] + "," + arr[j]);
                }
            }
        }


        sc.close();

    }
}