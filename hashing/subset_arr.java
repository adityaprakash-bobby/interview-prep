import java.util.HashSet;

public class Hashing {
    
    /*
        Function to return whether array B is a subset of array A
    */
    public static boolean isSubset(int[] A, int[] B) {

        HashSet<Integer> keys = new HashSet<Integer>();

        for (int i = 0; i < A.length; i++) {

            if (!keys.contains(A[i])) {
                keys.add(A[i]);
            }

        }

        for (int i = 0; i < B.length; i++) {

            if (!keys.contains(B[i])) {
                return false;
            }

        }

        return true;

    }

    /*
        Driver function to test the hashing function 
    */
    public static void main(String[] args) {

        int arr1[] = {10, 5, 2, 23, 19};
        int arr2[] = {19, 5, 3};

        System.out.print(isSubset(arr1, arr2) + "\n");

    }
}