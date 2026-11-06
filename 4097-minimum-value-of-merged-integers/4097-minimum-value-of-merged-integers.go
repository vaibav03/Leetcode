import "math"
func pow(n int) int{
    ans:=0
    for n>0{
        ans+=1
        n = n/10
    }
    return ans
}
func minMergedInteger(nums []int) int {
    var ans int = 1e9
    for i:=0;i<len(nums)-1;i=i+2 {
        fmt.Println(nums[i]*int(math.Pow(10, float64(pow(nums[i+1])))) + nums[i+1])
        ans = min(ans, nums[i]*int(math.Pow(10, float64(pow(nums[i+1])))) + nums[i+1])
    }
    return ans
}