class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        if(n % 2 != 0) return false;
        Stack<Character> st = new Stack<>();
        for(int i=0; i<n; i++){
            char c = s.charAt(i);
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else if(c == ')'){
                if(st.isEmpty() == true || st.peek() != '('){
                    return false;
                }
                st.pop();
            }
            else if(c == '}'){
                if(st.isEmpty() == true || st.peek() != '{'){
                    return false;
                }
                st.pop();
            }
            else if(c == ']'){
                if(st.isEmpty() == true || st.peek() != '['){
                    return false;
                }
                st.pop();
            }    
        }

        return st.isEmpty();
    }
}