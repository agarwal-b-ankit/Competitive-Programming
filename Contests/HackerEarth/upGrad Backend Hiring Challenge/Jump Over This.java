import java.io.*;
import java.util.*;
 
// INCORRECT SOLUTION 
public class TestClass {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        for(int t_i=0; t_i<T; t_i++)
        {
            int N = Integer.parseInt(br.readLine().trim());
            String[] arr_val = br.readLine().split(" ");
            int[] val = new int[N];
            for(int i_val=0; i_val<arr_val.length; i_val++)
            {
            	val[i_val] = Integer.parseInt(arr_val[i_val]);
            }
            String[] arr_h = br.readLine().split(" ");
            int[] h = new int[N];
            for(int i_h=0; i_h<arr_h.length; i_h++)
            {
            	h[i_h] = Integer.parseInt(arr_h[i_h]);
            }
            int M = Integer.parseInt(br.readLine().trim());
            String[] arr_I = br.readLine().split(" ");
            int[] I = new int[M];
            for(int i_I=0; i_I<arr_I.length; i_I++)
            {
            	I[i_I] = Integer.parseInt(arr_I[i_I]);
            }
            String[] arr_min_height = br.readLine().split(" ");
            int[] min_height = new int[M];
            for(int i_min_height=0; i_min_height<arr_min_height.length; i_min_height++)
            {
            	min_height[i_min_height] = Integer.parseInt(arr_min_height[i_min_height]);
            }
 
            int out_ = solve(I, h, min_height, val,N,M);
            System.out.println(out_);
            System.out.println("");
         }
 
         wr.close();
         br.close();
    }
    static int[][] dp = new int[1010][1010];
    static int solve(int ind, int N, int curh, int[] val, int[] h, int[] ht){
        if(ind==N) return 0;
        if(ht[ind]>curh) return -1;
        if(dp[ind][curh]!=-2)
            return dp[ind][curh];
        int temp=solve(ind+1,N,curh, val, h, ht);
        if(temp!=-1){
            temp+=val[ind];
        }
        int ans = Math.max(solve(ind+1, N, Math.min(1000,curh+h[ind]), val, h, ht),temp);
        dp[ind][curh]=ans;
        return ans;
    }
    
    static int solve(int[] I, int[] h, int[] min_height, int[] val, int N, int M){
        for(int i=0;i<1010;i++)
            for(int j=0;j<1010;j++)
                dp[i][j]=-2;
        int[] ht = new int[N];
        for(int i=0;i<N;i++)
            ht[i]=0;
        for(int i=0;i<M;i++)
            ht[I[i]]=min_height[i];
        return solve(0,N,0,val,h,ht);
    }
}