/*Write a Java program to create a class called 
ArrayDemo and overload arrayFunc() function. 
*/
import java.util.Scanner;

class ArrayDemo {
    void arrayFunc(int arr[], int key) {

        int n = arr.length;
        boolean found = false;

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(arr[i] + arr[j] == key) {
                    System.out.println(arr[i] + " + " + arr[j] + " = " + key);
                    found = true;
                }
            }
        }

        if(!found) {
            System.out.println("No pair found");
        }
    }

    void arrayFunc(int A[], int p, int B[], int q) {

        int i = 0, j = 0, k = 0;
        int temp[] = new int[p + q];

        while(i < p && j < q) {
            if(A[i] < B[j]) {
                temp[k++] = A[i++];
            } else {
                temp[k++] = B[j++];
            }
        }

        while(i < p) {
            temp[k++] = A[i++];
        }

        while(j < q) {
            temp[k++] = B[j++];
        }

        for(i = 0; i < p; i++) {
            A[i] = temp[i];
        }

        for(j = 0; j < q; j++) {
            B[j] = temp[p + j];
        }

        System.out.println("Merged Array A:");
        for(i = 0; i < p; i++) {
            System.out.print(A[i] + " ");
        }

        System.out.println();

        System.out.println("Merged Array B:");
        for(j = 0; j < q; j++) {
            System.out.print(B[j] + " ");
        }

        System.out.println();
    }
}


class Aditya_Overload {

    public static void main(String arg[]) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size for array 1: ");
        int n = sc.nextInt();

        int arr1[] = new int[n];

        System.out.println("Enter elements of array 1:");
        for(int i = 0; i < n; i++) {
            arr1[i] = sc.nextInt();
        }

        System.out.print("Enter sum to find pair: ");
        int sum = sc.nextInt();

        System.out.print("Enter size for array 2: ");
        int p = sc.nextInt();

        int arr2[] = new int[p];

        System.out.println("Enter elements of sorted array 2:");
        for(int i = 0; i < p; i++) {
            arr2[i] = sc.nextInt();
        }

        System.out.print("Enter size for array 3: ");
        int q = sc.nextInt();

        int arr3[] = new int[q];

        System.out.println("Enter elements of sorted array 3:");
        for(int i = 0; i < q; i++) {
            arr3[i] = sc.nextInt();
        }

        ArrayDemo ar = new ArrayDemo();

        System.out.println("\nPairs whose sum is " + sum + ":");
        ar.arrayFunc(arr1, sum);

        System.out.println("\nAfter merging:");
        ar.arrayFunc(arr2, p, arr3, q);

        sc.close();
    }
}
