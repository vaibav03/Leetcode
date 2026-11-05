import "fmt"
import "math"
func majorityElement(nums []int) int {
    mape := make(map[int]int)
    for i := range nums{
        mape[nums[i]] += 1
    }

    for i,j := range mape {
        fmt.Println(i,j)
        if j >= int(math.Ceil( float64(len(nums))/2.0)){
            return i
        }
    }
    return -1
}