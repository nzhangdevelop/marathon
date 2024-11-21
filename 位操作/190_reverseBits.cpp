// 190. 颠倒二进制位。
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t m = 0;
        for (int i = 0; i < 32; i++)
        {
            m = m << 1;
            // m = (n & 1) + m;
            //  按位与的优先级低于加法运算的优先级。
            //  所以，最好写成如下形式：
            m += n & 1;
            n = n >> 1;
        }
        return m;
        // 赋值运算和移位运算的优先级。

        /*uint32_t m = 0;
        for (int i = 0; i < 32; ++i) {
            m <<= 1;
            m += n & 1;
            n >>= 1;
        }
        return m;*/
    }
};