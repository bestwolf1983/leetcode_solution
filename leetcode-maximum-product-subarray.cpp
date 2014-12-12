c class Solution {
    public int maxProduct(int[] A) {
        int bmsp = 0;
        int p = 0;
        int msp = A[0];
        for(int i = 0; i < A.length; i++){
            if(A[i] == 0){
                p = 0;
            }else if(p == 0){
                p = A[i];
            }else{
                p *= A[i];
            }
            msp = p > msp ? p :msp;
        }
        bmsp = msp;
        p = 0;
        msp = A[A.length - 1];
        for(int i = A.length - 1; i >= 0; i--){
            if(A[i] == 0){
                p = 0;
            }else if(p == 0){
                p = A[i];
            }else{
                p *= A[i];
            }
            msp = p > msp ? p :msp;
        }
        return bmsp > msp ? bmsp : msp;
        
    }
    
}
