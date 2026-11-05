import "fmt"

func twoSum(nums []int, target int) []int {
    mape := make(map[int]int)

    for i := range len(nums) {
        complement := target - nums[i]

        j, exists := mape[complement]
        fmt.Println(j, exists)

        if exists {
            return []int{i, j}
        }

        mape[nums[i]] = i
    }

    return []int{-1, -1}
}