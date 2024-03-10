auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ofstream out("user.out");
    for (std::string str; getline(std::cin, str); out << '\n') {
        if (str.size() == 2) {
            continue;
        }

        char* __restrict l = str.data() + 1;
       
        char* __restrict r = str.data() + str.size() - 2;
        uint64_t max_volume = 0;

        int num1 = 0;
        int num2 = 0;

        bool read_r = true;
        bool read_l = true;

        int len = std::count(str.begin(), str.end(), ',');

        while (l < r) [[likely]] {
            if (read_l) {
                read_l = false;
                num1 = (*l) & 15;
                ++l;
               
                while (((*l) & 15) < 10) {
                   
                    num1 = num1 * 10 + ((*l) & 15);
                    l += 1;
                }
             
            }
            if (read_r) {
                read_r = false;
                num2 = (*r) & 15;
                --r;
                int ten_deg = 10;
                while (((*r) & 15) < 10) [[likely]] {
                    num2 = num2 + ((*r) & 15) * ten_deg;
                    ten_deg *= 10;
                    --r;
                }
            }
           
            max_volume = std::max((int)max_volume, len * std::min(num1, num2));
            if (num1 < num2) {
                ++l;
                read_l = true;
            }
            else {
                --r;
                read_r = true;
            }
            --len;
        }
        out << max_volume;
     
    }
    out.flush();
    exit(0);
    return 0;
}();

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        return std::numeric_limits<int>::max();
    }
};