import java.util.Scanner;

public class RabinKarp {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        //taking input text string
        System.out.println("Enter the text string");
        String T = sc.next();

        //taking input pattern string
        System.out.println("Enter the pattern string");
        String P = sc.next();

        //calling the rabinKarp method to find the pattern in text
        //here d = 256 because there are total 256 characters
        //here we have taken q = 13 as the mod operator
        rabinKarp(T,P,256,13);
    }    

    public static void rabinKarp(String T,String P,int d,int q) {
        int n = T.length();  //length of the text string
        int m = P.length();  //length of the pattern string

        double h = (Math.pow(d, m-1))%q;  //hash value used for dynamic programming

        int p = 0;   //declaration of the hash values of pattern string and the text strings
        double t = 0;

        for(int i=0; i<m; i++) {
            p = (d*p + P.charAt(i))%q;   //hash value of the pattern string
            t = (d*t + T.charAt(i))%q;   //hash value of the current window of the text string
        }

        for(int s=0; s<n-m+1; s++) {   //loop for traversing the entire text string upto n-m
            if(p == t) {   //check the value of p and t
                if(check(P,T,s,m)) {   //if equal then check the strings character by character
                    System.out.println("Pattern occurs at index : "+s);   //if equal then the pattern matches at s
                }
            }

            if(s < n-m) { 
                t = (d*(t - T.charAt(s)*h) + T.charAt(s+m))%q;   //calculation of hash value of the 
                                                                 //next window of the text string
                if(t < 0)   //if t < 0 then reset it to t + q
                    t = t + q;
            }
        }
    }

    public static boolean check(String P,String T,int s,int m) {   //function to check the strings are equal or not
        int i,j;
        for(i=0,j=s; i<m; i++,j++) {
            if(P.charAt(i) != T.charAt(j))
                return false;   //if any character does not match then return false
        }
        return true;   //otherwise return true
    }
}
