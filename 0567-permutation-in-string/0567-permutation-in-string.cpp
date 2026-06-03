class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // تكرارات s1
        for (char c : s1)
            freq1[c - 'a']++;

        int l = 0, r = 0;

        // نبني أول window
        while (r < n) {
            freq2[s2[r] - 'a']++;
            r++;
        }

        if (freq1 == freq2) return true;

        // نحرك الـ window
        while (r < m) {

            // ندخل عنصر جديد من اليمين
            freq2[s2[r] - 'a']++;

            // نشيل عنصر من الشمال
            freq2[s2[l] - 'a']--;

            // نحرك الاتنين
            l++;
            r++;

            if (freq1 == freq2) return true;
        }

        return false;
    }
};