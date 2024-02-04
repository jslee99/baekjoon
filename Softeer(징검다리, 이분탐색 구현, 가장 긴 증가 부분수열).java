import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main{
    static int n;
    static int[] a = new int[3005];
    static int[] list = new int[3005];
    static int last;

    static int lowerBound(int v){
        //left 은 v보다 작거나 같음, right은 v보다 큼
        if(list[1] > v){
            return 0;
        } else if (list[last] <= v) {
            return last;
        }

        int left = 1;
        int right = last;
        while(left + 1 < right){
            int mid = (left + right) / 2;
            if(list[mid] > v){
                right = mid;
            }else{
                left = mid;
            }
        }
        return left;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for(int i = 1; i <= n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        list[1] = a[1];
        last = 1;

        for(int i = 2; i <= n; i++){
            int idx = lowerBound(a[i]);
            if(idx == 0){
                list[1] = a[i];
            } else if (idx == last) {
                if(list[last] < a[i]){
                    list[++last] = a[i];
                }
            }else{
                if(list[idx] == a[i]){

                }else{
                    list[idx + 1] = a[i];
                }
            }
        }
        System.out.println(last);
    }
}