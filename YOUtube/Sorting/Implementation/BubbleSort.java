package Sorting.Implementation;
import java.util.Arrays;

public class BubbleSort {
    public static void main(String[] args) {
        int[] arr = {5, 6, 1, 78, 45, 96};
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void bubbleSort(int[] arr) {
        boolean swapped;
        // run for n-1 times --> Acts as a counter
        for (int i = 0; i < arr.length; i++) {
            swapped = false;
            
            for (int j = 0; j < arr.length - i - 1; j++) {
                // Swap if the current item is smaller than the next one (Descending order)
                if (arr[j] < arr[j+1]) {
                    
                    // Call the new swap method
                    swap(arr, j, j+1);
                    swapped = true;
                }
            }
            
            // if you didn't swap for a particular value of i, it means the array is sorted
            if (!swapped) { 
                break;
            }
        }
    }

    // New helper method just for swapping
    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}