package analiseempirica;

import java.util.ArrayList;
/**
 *
 * @author rodrigo
 */
public class MaxSubArray {
    
    public void enumeration(int[] v){
        int soma = 0;
        //int[] retorno = new int[3];
        //retorno[0] = v[0];
        int max = v[0];
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < v.length; i++) {
            for (int j = i; j < v.length; j++) {
                for (int k = i; k <= j; k++) {
                    soma+=v[k];
                }
                if (soma > max) {
                    max = soma;
                    start = i;
                    end = j;
                }
                soma=0;
            }
        }
        System.out.println("Max: "+max);
        System.out.println("Start: "+start);
        System.out.println("End: "+end);
    }
    
    public void betterEnumeration(int[] v){
        int soma = 0;
        //int[] retorno = new int[3];
        //retorno[0] = v[0];
        int max = v[0];
        int start = 0;
        int end = 0;
        
        
        for (int i = 0; i < v.length; i++) {
            for (int j = i; j < v.length; j++) {
                soma+=v[j];
                
                if(soma > max){
                    max = soma;
                    start=i;
                    end=j;
                }
            }
            soma=0;
        }
        System.out.println("Max: "+max);
        System.out.println("Start: "+start);
        System.out.println("End: "+end);
    }
    
    public void divideAndConquer(int[] v){
        int[] r = maxSubArray(v, 0, v.length-1);
        System.out.println("Max: "+r[2]);
        System.out.println("Start: "+r[0]);
        System.out.println("End: "+r[1]);
    }
    
    private int[] maxSubArray(int[] v, int e, int d){
        int[] r_esq = new int[3];
        int[] r_dir = new int[3];
        int[] r_cross = new int[3];
        if (e == d) {
            r_esq[0] = e;
            r_esq[1] = d;
            r_esq[2] = v[e];
            return r_esq;
        }
        
        int m = (e+d)/2;
        r_esq = maxSubArray(v, e, m);
        r_dir = maxSubArray(v, m+1, d);
        r_cross = maxCross(v, e, m, d);
        
        if (r_esq[2] >= r_dir[2] & r_esq[2] >= r_cross[2]) {
            return r_esq;
        }
        else if (r_dir[2] >= r_esq[2] & r_dir[2] >= r_cross[2]) {
            return r_dir;
        }
        else{
            return r_cross;
        }
    }
    
    private int[] maxCross(int[] v, int e, int m, int d){
        int l_sum = Integer.MIN_VALUE;
        int r_sum = Integer.MIN_VALUE;
        int sum = 0;
        int max_l = 0;
        int max_r = 0;
        
        for (int i = m; i >= e; i--) {
            sum += v[i];
            if (sum > l_sum) {
                l_sum = sum;
                max_l = i;
            }
        }
        
        sum = 0;
        for (int j = m+1; j <= d; j++) {
            sum += v[j];
            if (sum > r_sum) {
                r_sum = sum;
                max_r = j;
            }
            
        }
        
        int[] retorno = new int[3];
        retorno[0] = max_l;
        retorno[1] = max_r;
        retorno[2] = l_sum + r_sum;
        
        return retorno;
    }
    /*
    // Kadane's Algorithm
    public int dynamicProgramming(int[] arr) {
        int maxEndHere = arr[0];
        int maxSoFar = arr[0];
        for(int i=1;i<arr.length;i++){
            maxEndHere = Math.max(arr[i], maxEndHere+arr[i]);
            maxSoFar = Math.max(maxSoFar,maxEndHere);
        }
        return maxSoFar;
    }
    */
    //https://gist.github.com/arunma/3624849
    public void dynamicProgramming(int[] inputArray){

        int maxStartIndex=0;
        int maxEndIndex=0;
        int maxSum = inputArray[0]; 

        int cumulativeSum= 0;
        int maxStartIndexUntilNow=0;
        		
        for (int currentIndex = 0; currentIndex < inputArray.length; currentIndex++) {
        	
            int eachArrayItem = inputArray[currentIndex];
            
            cumulativeSum+=eachArrayItem;

            if(cumulativeSum>maxSum){
                maxSum = cumulativeSum;
                maxStartIndex=maxStartIndexUntilNow;
                maxEndIndex = currentIndex;
            }
            else if (cumulativeSum<0){
            	maxStartIndexUntilNow=currentIndex+1;
            	cumulativeSum=0;
            }
        }

        System.out.println("Max sum         : "+maxSum);
        System.out.println("Max start index : "+maxStartIndex);
        System.out.println("Max end index   : "+maxEndIndex);
    }
}
