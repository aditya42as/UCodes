import java.util.Scanner;

class Aditya_case {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter String: ");
        String str = sc.nextLine();
        char arr[] = str.toCharArray();

        for(int i = 0 ; i < arr.length; i++) {
            if(arr[i] >= 65 && arr[i] <= 90) {
                arr[i] = arr[i] + '32'; 
            }
            else if(arr[i] >= 97 && arr[i] <= 122){
                arr[i] = arr[i] - 32; 
            }
        }

        System.out.println("Reslut: " + str);

        sc.close();
    }

}
