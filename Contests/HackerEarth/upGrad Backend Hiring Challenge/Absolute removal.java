import java.io.*;
import java.util.*;
 
 
public class TestClass {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        for(int t_i=0; t_i<T; t_i++)
        {
            int N = Integer.parseInt(br.readLine().trim());
            String[] arr_A = br.readLine().split(" ");
            long[] A = new long[N];
            for(int i_A=0; i_A<arr_A.length; i_A++)
            {
            	A[i_A] = Long.parseLong(arr_A[i_A]);
            }
 
            long out_ = solve(A,N);
            System.out.println(out_);
            System.out.println("");
         }
 
         wr.close();
         br.close();
    }
    static long solve(long[] A,int N){
        if(N==1) return 0;
        long sum=0,diff=0,sub=Math.abs(A[1]-A[0]);
        for(int i=1;i<N;i++){
            sum+=Math.abs(A[i]-A[i-1]);
            diff=Math.abs(A[i]-A[i-1]);
            if(i+1<N)
                diff=diff+Math.abs(A[i+1]-A[i])-Math.abs(A[i+1]-A[i-1]);
            sub=Math.max(sub,diff);
        }
        return sum-sub;
    }
}