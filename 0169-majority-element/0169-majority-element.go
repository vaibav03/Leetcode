import "fmt"
func majorityElement(nums []int) int {
    mape := make(map[int]int)
    for i := range nums{
        mape[nums[i]] += 1
    }

    for i,j := range mape {
        fmt.Println(i,j)
        if j >= (len(nums) + 1)/2{
            return i
        }
    }
    return -1
}