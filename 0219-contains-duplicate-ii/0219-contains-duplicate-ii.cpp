class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        map<int, int> freq;

        // المرحلة الأولى: بناء النافذة الابتدائية لحجم يساوي k
        while (r < n && r <= k) {
            freq[nums[r]]++;
            if (freq[nums[r]] > 1) {
                return true;
            }
            r++;
        }

        // المرحلة الثانية: تحريك النافذة (Sliding Window) لبقية عناصر المصفوفة
        while (r < n) {
            // إزالة العنصر الخارج من النافذة من جهة اليسار
            freq[nums[l]]--;
            l++;

            // إضافة العنصر الجديد الداخل إلى النافذة من جهة اليمين
            freq[nums[r]]++;
            if (freq[nums[r]] > 1) {
                return true;
            }
            r++;
        }

        return false;
    }
};