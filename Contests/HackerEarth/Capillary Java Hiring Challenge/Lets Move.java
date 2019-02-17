import java.io.*;
import java.util.*;
 
 
public class TestClass {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        for(int t_i=0; t_i<T; t_i++)
        {
            String S = br.readLine();
            int Q = Integer.parseInt(br.readLine().trim());
            String[] arr_x = br.readLine().split(" ");
            int[] x = new int[Q];
            for(int i_x=0; i_x<arr_x.length; i_x++)
            {
            	x[i_x] = Integer.parseInt(arr_x[i_x]);
            }
            String[] arr_y = br.readLine().split(" ");
            int[] y = new int[Q];
            for(int i_y=0; i_y<arr_y.length; i_y++)
            {
            	y[i_y] = Integer.parseInt(arr_y[i_y]);
            }
 
            int out_ = solve(y, x,Q, S);
            System.out.println(out_);
            System.out.println("");
         }
 
         wr.close();
         br.close();
    }
    
    static int solve(int[] y, int[] x,int Q, String S){
        int a,b,ans=0;
        for(int i=0;i<Q;i++){
            a=0;
            b=0;
            Map<Integer, Map<Integer, Integer>> map = new HashMap<>();
            Map<Integer, Integer> temp = new HashMap<>();
            temp.put(0,1);
            map.put(0,temp);
            for(int j=0;j<S.length();j++){
                if(S.charAt(j)=='L') a-=1;
                else if(S.charAt(j)=='R') a+=1;
                else if(S.charAt(j)=='U') b+=1;
                else b-=1;
                if(map.containsKey(a-x[i]) && map.get(a-x[i]).containsKey(b-y[i])){
                    ans++;
                    break;
                }
                if(map.containsKey(a)){
                    map.get(a).put(b,1);
                } else{
                    temp = new HashMap<>();
                    temp.put(b,1);
                    map.put(a,temp);
                }
            }
        }
        return ans;
    }
}