import "slices"

func getMax(n int) int {
    var cnt [10]int
    for n > 0 {
        cnt[n%10]++
        n /= 10
    }
    ans := 0
    for d := 9; d >= 0; d-- {
        for c := 0; c < cnt[d]; c++ {
            ans = ans*10 + d
        }
    }
    return ans
}

func maximizeSum(nums []int, k int) int64 {
    var sum int64
    gains := make([]int, len(nums))
    for i, x := range nums {
        sum += int64(x)
        gains[i] = getMax(x) - x // computed once per number
    }
    slices.SortFunc(gains, func(a, b int) int { return b - a }) // descending
    for i := 0; i < k && i < len(gains) && gains[i] > 0; i++ {
        sum += int64(gains[i])
    }
    return sum
}