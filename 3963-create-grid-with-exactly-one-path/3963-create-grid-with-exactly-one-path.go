func createGrid(m int, n int) []string {
    var ans []string 
    for i:=0;i<m;i++{
        var curr []byte
        for j:=0;j<n;j++{
            if i == 0{
                curr = append(curr, '.')
            }else if j == n-1{
                curr = append(curr,'.')
            }else{
                curr = append(curr, '#')
            }
        }
        ans = append(ans,string(curr))
    }
    return ans
}