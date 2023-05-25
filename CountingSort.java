import java.util.Arrays;
import java.util.Scanner;

public class CountingSort {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        //taking the number of elements of the array
        System.out.println("Enter the number of elements of the array");
        int n = sc.nextInt();

        //declaration of the input array
        int A[] = new int[n+1];

        //taking the input of the range of the elements
        System.out.println("Enter the range of elements");
        int k = sc.nextInt();

        //taking the array elements as input
        System.out.println("Enter the elements");
        for(int i=1; i<n+1; i++)   //storing from index 1
            A[i] = sc.nextInt();

        int[] B = sort(A,k);   //calling the sort method to sort the elements using counting sort

        System.out.println("\nThe sorted array is : "+Arrays.toString(B));   //printing the resultant B array
    }

    public static int[] sort(int[] A,int k) {
        int[] C = new int[k+1];   //declaration of the C arry of length equal to the range of the elements
        int[] B = new int[A.length-1];   //declaration of the resultant sorted array
        
        for(int i=0; i<k+1; i++)   //initializing every element of C array to 0
            C[i] = 0;
             
        for(int i=1; i<A.length; i++)   //incrementing the A index of the C array 
            C[A[i]]++;

        for(int i=1; i<k+1; i++)   //calculation of the consecutive addition of the elements of C array
            C[i] = C[i] + C[i-1];
        
        for(int i=A.length-1; i>0; i--) {   //storing the elements in B array
            B[C[A[i]]-1] = A[i];   //finding the exact index of element from A array in B array
            C[A[i]]--;   //decrementing the counter of that index
        }
        return B;   //returning the resultant B array
    }
}
