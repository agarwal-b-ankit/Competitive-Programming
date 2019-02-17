import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        //Scanner
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        while(t-->0){
            int n = s.nextInt();
            int a[] = new int[n+1];
            for(int i=1;i<=n;i++)
                a[i]=s.nextInt();
            long max=a[n],min=a[n];
            for(int i=n-1;i>0;i--){
                long max1=max,min1=min;
                max=Math.max(max,a[i]-min1);
                min=Math.min(min,a[i]-max1);
            }
            System.out.println(max);
        }
    }
}