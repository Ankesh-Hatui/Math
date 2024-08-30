// leetcode no : 592
class Solution {
public:
    string fractionAddition(string s) {
        int nom=0;
        int deno=1;
        int i=0;
        while(i<s.size()){
            int n,d;
            int neg=1;
            if(s[i]=='-' || s[i]=='+'){
                s[i]=='-'?neg=-1:neg=1;
                i++;
            }
            
            
            // find numerator
            int start_ind=i;
            while(i<s.size() && s[i]!='/'){
                i++;
            }
            n=stoi(s.substr(start_ind,i-start_ind));

            // find denominator
            int ending_ind=++i;
            while(i<s.size() && isdigit(s[i])){
                i++;
            }

            d=stoi(s.substr(ending_ind,(i-ending_ind)));

            nom=(d*nom)+(deno*(neg)*n);
            deno*=d;
            if(nom==0){
                deno=1;
            }
        }
        
        string ans="";
        int gcd=__gcd(abs(deno),abs(nom));
        deno/=gcd;
        nom/=gcd;
        ans+=to_string(nom);
        ans.push_back('/');
        ans+=to_string(deno);
        return ans;
    }
};
