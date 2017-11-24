package analiseempirica;
/**
 *
 * @author rodrigo
 */
public class AnaliseEmpirica {

    public static void main(String[] args) {
        
        RandomArray ra = new RandomArray();
        //ra.setSeed(139);
        int [] array = ra.generate(10, 10);
        for (int i : array) {
            System.out.println(i);
        }
        
        MaxSubArray msb = new MaxSubArray();
        //int[] ar = { -10, -8, -3, -7, -2, -7, -3, -9 };
        msb.dynamicProgramming(array);
        
        int[] a = msb.betterEnumeration(array);
        System.out.println(a[0]+", "+a[1]+", "+a[2]);
        
        a = msb.divideAndConquer(array);
        System.out.println(a[0]+", "+a[1]+", "+a[2]);

    }
    
}
