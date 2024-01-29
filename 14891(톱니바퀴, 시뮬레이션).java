import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Gear{
    int[] arr;
    int top;
    int dir;

    public int getLeft(){
        int left = (top + 6) % 8;
        return arr[left];
    }

    public int getRight(){
        int right = (top + 2) % 8;
        return arr[right];
    }

    public int getTop(){
        return arr[top];
    }

    public void clockWise(){
        top--;
        if(top < 0)
            top = 7;
    }

    public void counterClockWise(){
        top = (top + 1) % 8;
    }

    public Gear(int[] arr) {
        this.arr = arr;
        top = 0;
        dir = 0;
    }
}

class Main{
    static Gear[] gears = new Gear[4];
    static int k;
    static int ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        ans = 0;
        for(int i = 0; i < 4; i++) {
            String str = br.readLine();
            int[] arr = new int[8];
            for (int j = 0; j < 8; j++) {
                arr[j] = str.charAt(j) - '0';
            }
            gears[i] = new Gear(arr);
        }
        k = Integer.parseInt(br.readLine());
        for(int a = 0; a < k; a++){
            for(int i = 0; i < 4; i++)
                gears[i].dir = 0;
            st = new StringTokenizer(br.readLine(), " ");
            int initGearIdx = Integer.parseInt(st.nextToken());
            initGearIdx--;
            gears[initGearIdx].dir = Integer.parseInt(st.nextToken());
            for (int gearIdx = initGearIdx - 1; gearIdx >= 0; gearIdx--) {
                //rightGear.dir == -1 or 1
                Gear leftGear = gears[gearIdx];
                Gear rightGear = gears[gearIdx + 1];
                if(leftGear.getRight() == rightGear.getLeft()){
                    break;
                }else{
                    if(rightGear.dir == -1)
                        leftGear.dir = 1;
                    else if(rightGear.dir == 1)
                        leftGear.dir = -1;
                    else{
                        int aa = 1;
                        throw new IllegalStateException();
                    }


                }
            }

            for (int gearIdx = initGearIdx + 1; gearIdx < 4; gearIdx++) {
                Gear leftGear = gears[gearIdx - 1];
                Gear rightGear = gears[gearIdx];
                if(leftGear.getRight() == rightGear.getLeft()){
                    break;
                }else{
                    if(leftGear.dir == -1)
                        rightGear.dir = 1;
                    else if(leftGear.dir == 1)
                        rightGear.dir = -1;
                    else
                        throw new ArrayIndexOutOfBoundsException();
                }
            }

            for (int gearIdx = 0; gearIdx < 4; gearIdx++) {
                Gear gear = gears[gearIdx];
                if(gear.dir == 0)
                    continue;
                else if(gear.dir == 1)
                    gear.clockWise();
                else
                    gear.counterClockWise();
            }
        }

        for (int i = 0; i < 4; i++) {
            if(gears[i].getTop() == 1){
                ans += Math.pow(2, i);
            }
        }
        System.out.println(ans);
    }
}