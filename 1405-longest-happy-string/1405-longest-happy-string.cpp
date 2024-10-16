class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string  str;
        if(a==0 && b==0 && c==0){
            return str;
        }
        while(a || b || c){
            int maxChar = max(max(a,b),c);
            cout<<a<<" "<<b<<" "<<c<<endl;
            int i=2;
            if(maxChar==a){
                while(a && i){
                    str+='a';
                    a--;
                    i--;
                }
                if(b!=0 || c!=0){
                    if(b>c){
                        str+='b';
                        b--;
                    }else{
                        str+='c';
                        c--;
                    }
                }else{
                    return str;;
                }
            }else if(maxChar==b){
                while(b && i){
                    str+='b';
                    b--;
                    i--;
                }
                if(a!=0 || c!=0){
                    if(c>a){
                        str+='c';
                        c--;
                    }else{
                        str+='a';
                        a--;
                    }
                }else{
                    return str;;
                }
            }else if(maxChar==c){
                while(c && i){
                    str+='c';
                    c--;
                    i--;
                }
                if(b!=0 || a!=0){
                    if(b>a){
                        str+='b';
                        b--;
                    }else{
                        str+='a';
                        a--;
                    }
                }else{
                    return str;;
                }
            }
        }
        return str;
    }
};