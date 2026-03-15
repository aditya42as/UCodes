import java.util.Scanner;

class SaddlePoint {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter rows: ");
        int r = sc.nextInt();
        System.out.print("Enter columns: ");
        int c = sc.nextInt();

        int[][] a = new int[r][c];

        System.out.println("Enter matrix elements:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        boolean found = false;

        for (int i = 0; i < r; i++) {
            int min = a[i][0];
            int col = 0;

            for (int j = 1; j < c; j++) {
                if (a[i][j] < min) {
                    min = a[i][j];
                    col = j;
                }
            }

            boolean isSaddle = true;
            for (int k = 0; k < r; k++) {
                if (a[k][col] > min) {
                    isSaddle = false;
                    break;
                }
            }

            if (isSaddle) {
                System.out.println("Saddle Point at: (" + i + ", " + col + ")");
                found = true;
            }
        }

        if (!found)
            System.out.println("No Saddle Point Found");
    }
}
