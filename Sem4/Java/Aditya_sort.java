class Aditya_sort{
    public static void main(String arg[]) {
        int arr[] = {12, 4, 54, 66, 22, 73};
        int idx = 0;
        int key = 66;

        for(int i = 0; i < 6; i++) {
            if(arr[i] == key) {
                idx = i;
            }
        }

        for(int i = 0; i < idx; i++) {
            for(int j = 0; j < idx; j++) {
                if(arr[i] < arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp; 
                }
            }
        }

        for(int i = idx+1; i < 6; i++) {
            for(int j = idx+1; j < 6; j++) {
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp; 
                }
            }
        }

        System.out.println("Updated array: ");
        for(int i = 0; i < 6; i++) {
            System.out.println(arr[i]);
        }
    }
}