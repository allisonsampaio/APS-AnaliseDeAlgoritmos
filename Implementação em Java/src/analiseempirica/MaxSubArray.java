package analiseempirica;

import java.util.ArrayList;
/**
 *
 * @author rodrigo
 */
public class MaxSubArray {
    
    public int[] enumeration(int[] v){
        int soma = 0;
        int[] retorno = new int[3];
        retorno[0] = v[0];
        
        for (int i = 0; i < v.length; i++) {
            for (int j = 0; j < v.length; j++) {
                for (int k = i; k <= j; k++) {
                    soma+=v[k];
                }
                if (soma > retorno[0]) {
                    retorno[0] = soma;
                    retorno[1] = i;
                    retorno[2] = j;
                }
                soma=0;
            }
        }
        return retorno;
    }
    
    public int[] betterEnumeration(int[] v){
        int soma = 0;
        int[] retorno = new int[3];
        retorno[0] = v[0];
        
        
        for (int i = 0; i < v.length; i++) {
            for (int j = i; j < v.length; j++) {
                soma+=v[j];
                
                if(soma > retorno[0]){
                    retorno[0] = soma;
                    retorno[1]=i;
                    retorno[2]=j;
                }
            }
            soma=0;
        }
        return retorno;
    }
    
    public int[] divideAndConquer(int[] v){
        return maxSubArray(v, 0, v.length-1);
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
}
