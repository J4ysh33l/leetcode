class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1= version1.length();
        int v2= version2.length();
        int num1=0,num2=0;
        
        int i=0,j=0;
        while(i<v1 || j<v2){
                num1=0; num2=0;
        while(i<v1 && version1[i]!= '.'){
                num1= num1*10 + (version1[i]-'0');
                i++;

        }
        i++;
        
        while(j<v2 && version2[j]!='.'){
                num2= num2*10 + (version2[j]-'0');
                j++;

        }
        j++;
    

        if(num1>num2){
            return 1;
        }else if(num1<num2){
            return -1;
        }
    }
        return 0;
    }
};