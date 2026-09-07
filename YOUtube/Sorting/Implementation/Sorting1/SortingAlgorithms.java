package Sorting.Implementation.Sorting1;

import java.util.Arrays;

public class SortingAlgorithms {
    public static void main(String[] args) {
        // Create three separate arrays so each algorithm has an unsorted list to work with
        int[] arr1 = {5, 6, 1, 78, 45, 96};
        int[] arr2 = {5, 6, 1, 78, 45, 96};
        int[] arr3 = {5, 6, 1, 78, 45, 96};

        System.out.println("Original array: " + Arrays.toString(arr1) + "\n");

        insertionSort(arr1);
        System.out.println("Insertion Sort: " + Arrays.toString(arr1));

        bubbleSort(arr2);
        System.out.println("Bubble Sort:    " + Arrays.toString(arr2));

        selectionSort(arr3);
        System.out.println("Selection Sort: " + Arrays.toString(arr3));
    }

    // --- 1. INSERTION SORT ---
    static void insertionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j > 0; j--) {
                // If current item is smaller than previous, swap them
                if (arr[j] < arr[j - 1]) {
                    swap(arr, j, j - 1);
                } else {
                    break;
                }
            }
        }
    }

    // --- 2. BUBBLE SORT ---
    static void bubbleSort(int[] arr) {
        boolean swapped;
        for (int i = 0; i < arr.length; i++) {
            swapped = false;
            for (int j = 0; j < arr.length - i - 1; j++) {
                // If current item is larger than the next, swap them
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                    swapped = true;
                }
            }
            // Stop early if array is already sorted
            if (!swapped) {
                break;
            }
        }
    }

    // --- 3. SELECTION SORT ---
    static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            // Assume the first unsorted item is the smallest
            int minIndex = i;
            
            // Scan the rest of the array to find if there is an even smaller item
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j; // Update minIndex if a smaller item is found
                }
            }
            // Swap the smallest item found with the first unsorted item
            swap(arr, minIndex, i);
        }
    }

    // --- SHARED HELPER METHOD ---
    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}
