class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (int i = 0; i < s.length(); i++) {
            // إذا لم يكن الحرف قوس إغلاق، نضيفه للمكدس
            if (s[i] != ']') {
                st.push(string(1, s[i]));
            } 
            else {
                // 1. استخراج النص الموجود داخل الأقواس
                string substr = "";
                while (!st.empty() && st.top() != "[") {
                    substr = st.top() + substr;
                    st.pop();
                }
                
                // حذف القوس المفتوح "[" من المكدس
                if (!st.empty()) st.pop();

                // 2. استخراج الرقم الذي يسبق القوس
                string k_str = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    k_str = st.top() + k_str;
                    st.pop();
                }
                
                // تحويل النص الرقمي لرقم حقيقي وتكرار النص
                int k = stoi(k_str);
                string repeated_str = "";
                while (k--) {
                    repeated_str += substr;
                }
                
                // إعادة النص المكرر للمكدس ليتعامل مع الأقواس المتداخلة
                st.push(repeated_str);
            }
        }

        // 3. تجميع النتيجة النهائية من المكدس
        // يجب تعريف result خارج الـ for لكي يراها الـ return
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        
        return result;
        
    }
};